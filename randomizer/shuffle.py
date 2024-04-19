import random
import shared.classr as classr
from shared.functions import * 
from randomizer.spoiler import *
from randomizer.accessLogic import *

#constants
blacklistRegion = 'Sanctuary Crypt'
duplicateChests = [47,48,49,179] #dawn versions of large shoreline for great river valley and valley of kings

def shuffleLocations(parameters):
    #take standard location list built from the locations.csv and build out shuffle locations and inventory lists
    #filter out locations that are not currently being shuffled.
    global chestsToCopy
    global goal
    goal = classr.goal(parameters.goal,parameters.numGoal)
    random.seed(parameters.seed)
    vanillaLocations =  getLocations() #location list built from locations table
    inventory = [] #list of all items in the shuffle pool
    preShuffleLoc = [] #locations only, pulled out and ready for shuffling
    shuffledLocations = [] #finalized list of locations and items at the location
    chestsToCopy = []
    
    while len(vanillaLocations) != 0:
        if vanillaLocations[0].locID in duplicateChests: #pop out duplicated locations, we'll copy these from the normal version of great river valley and valley of kings after we're done.
            chestsToCopy.append(vanillaLocations.pop(0))
        elif not parameters.shuffleItems and vanillaLocations[0].item: #if we're not shuffling items then add them to the final list
            shuffledLocations.append(vanillaLocations.pop(0))
        elif not parameters.shuffleCrew and vanillaLocations[0].crew and not vanillaLocations[0].party: #if we're not shuffling crew then add them to the final list
            shuffledLocations.append(vanillaLocations.pop(0))
        elif not parameters.shuffleParty and vanillaLocations[0].party: #if we're not shuffling party then add them to the final list
            shuffledLocations.append(vanillaLocations.pop(0))
        elif vanillaLocations[0].locRegion.find(blacklistRegion) == -1 and vanillaLocations[0].mapCheckID != 'Goal':
            locToBeShuffled = vanillaLocations.pop(0)
            inventoryObject = classr.inventory(locToBeShuffled)

            if locToBeShuffled.mapID != 'none': #for 'new to the randomizer' progression items we set their map to none, these locations will not exist. There will be fewer locations than items to shuffle.
                shuffleLocationObject = classr.shuffledLocation(locToBeShuffled)

            inventory.append(inventoryObject)
            preShuffleLoc.append(shuffleLocationObject)
        else:
            #for locations not being shuffled go ahead and add them to the finalized list of shuffled locations
            shuffledLocations.append(vanillaLocations.pop(0))

    random.shuffle(preShuffleLoc)
    fillShuffledLocations(inventory,preShuffleLoc,shuffledLocations,parameters)

    return shuffledLocations

def fillShuffledLocations(inventory, fillLocations, shuffledLocations,parameters):
    progressionInventory = [] #progression items only
    niceItems = [] #nice to have items that will always exist in the world but don't contain logic
    junkItems = [] #filler items, not all will be placed. Some new progression items, like the Dana past event trigger items, will take their place in the pool of vanilla items.
    accessibleInventory = []
    accessibleLocation = []
    progressionBanList = progressionBans(parameters)

    #pull out progression items to place first for easier processing
    while len(inventory) != 0:
        if inventory[0].progression:    
            progressionItem = inventory.pop(0)
            progressionInventory.append(progressionItem)
        elif inventory[0].nice:
            niceItem = inventory.pop(0)
            niceItems.append(niceItem)
        else:
            junk = inventory.pop(0)
            junkItems.append(junk)

    #let's shuffle the inventory just to randomize the party order then run through the intventory until we find the first party member, store it, then pop it from inventory.
    #this will be our starting character.
    random.shuffle(progressionInventory) 
    index = 0
    for partyMember in progressionInventory:
        if partyMember.party:
            startingPartyMember = partyMember
            progressionInventory.pop(index)
            break
        index+=1

    #let's find the opening cutscene real quick and make sure we fill is with a playable character
    if parameters.shuffleParty:
        locNum = 0
        for location in fillLocations:
            if location.locName == 'Opening Cutscene':
                fillLocation = location
                fillLocations.pop(locNum)
                break
            locNum+=1

        filledLocation = combineShuffledLocAndItem(fillLocation,startingPartyMember)
        shuffledLocations.append(filledLocation)
             
    #loop through progression items and place them by first pulling out the item at index 0
    #this fill algorithim is based in large part of the fill algorithim used by most modern randos
    #AmazingAmpharos helped guide me on how to set it up, it should be similar to the fill alogorithims for both OoT and lttp
    while len(progressionInventory) != 0:
        itemToPlace = progressionInventory.pop(0)
        for location in shuffledLocations:
            accessibleLocation.append(location)
        for item in progressionInventory:
            accessibleInventory.append(item)

        #loop through the world and find what all the player can access without the current item to place, this will be the ultimate list that determines accessibility
        while True:     
            itemFound = 0

            for index,location in enumerate(accessibleLocation):
                if location.progression and canAccess(accessibleInventory,location,goal):
                    accessibleItem = classr.inventory(accessibleLocation.pop(index))
                    accessibleInventory.append(accessibleItem)
                    itemFound+=1

                
            if itemFound == 0: break

        #loop through locations and test if the player can access them. If they can access them then queue the location to be filled and remove from pool
        for index,location in enumerate(fillLocations):
            if canAccess(accessibleInventory,fillLocations[index],goal) and location.locID not in progressionBanList:
                fillLocation = fillLocations.pop(index)
                filledLocation = combineShuffledLocAndItem(fillLocation, itemToPlace)
                shuffledLocations.append(filledLocation)
                break

        accessibleInventory = []
        accessibleLocation = []
    
    #run through all nice to have items and place them first in the remaining locations, in order, until the items are exhausted
    while len(niceItems) != 0:
        locToFill = fillLocations.pop(0)
        itemToPlace = niceItems.pop(0)
        filledLocation = combineShuffledLocAndItem(locToFill, itemToPlace) 
        shuffledLocations.append(filledLocation)
    
    #take what's left of the fill locations and place all junk items, there will be leftover items
    placedItems = 0
    for fillLocation in fillLocations:
        if len(junkItems) <= 0:
            raise Exception("Whoops! Ran out of items. Locations left to fill: " + str(len(fillLocations)-placedItems))
                            
        itemToPlace = junkItems.pop(0)
        filledLocation = combineShuffledLocAndItem(fillLocation, itemToPlace) 
        shuffledLocations.append(filledLocation)
        placedItems+=1



    #after everything is done take the chests from the great river valley shoreline and valley of kings camp at dawn and set them equal to the normal time of day version then
    #add them back to list.
    for index,location in enumerate(shuffledLocations):
        if shuffledLocations[index].locID == 44:
            chestsToCopy[0] = copyLocationToNewLoc(shuffledLocations[index])
            chestsToCopy[0].locID = 47
            shuffledLocations.append(chestsToCopy[0])
        elif shuffledLocations[index].locID == 45:
            chestsToCopy[1] = copyLocationToNewLoc(shuffledLocations[index])
            chestsToCopy[1].locID = 48
            shuffledLocations.append(chestsToCopy[1])
        elif shuffledLocations[index].locID == 46:
            chestsToCopy[2] = copyLocationToNewLoc(shuffledLocations[index])
            chestsToCopy[2].locID = 49
            shuffledLocations.append(chestsToCopy[2])
        elif shuffledLocations[index].locID == 178:
            chestsToCopy[3] = copyLocationToNewLoc(shuffledLocations[index])
            chestsToCopy[3].locID = 179
            shuffledLocations.append(chestsToCopy[3])

    generateSpoiler(shuffledLocations,parameters,goal,blacklistRegion,duplicateChests)
        
    return shuffledLocations

def progressionBans(parameters):
    locationBans =[]
    locationsToAdd = []

    if parameters.jewelTrades == 'None':
        locationsToAdd = [461,462,463,464,465,466,467,468,469,470]
    elif parameters.jewelTrades == 'Jewel Trades Costing 1':
        locationsToAdd = [463,464,465,468,469,470]
    elif parameters.jewelTrades == 'Jewel Trades Costing <= 2':
        locationsToAdd = [464,465,470]
    elif parameters.jewelTrades == 'Jewel Trades Costing <= 3':
        locationsToAdd = [464,465]
    elif parameters.jewelTrades == 'Jewel Trades Costing <= 10':
        locationsToAdd = [465]

    locationBans = addLocations(locationsToAdd,locationBans)

    if parameters.fishTrades == 'None':
        locationsToAdd = [472,473,474,475,476,477]
    elif int(parameters.fishTrades) > 0:
        locationsToAdd = [472,473,474,475,476,477]
        for index in range(1,int(parameters.fishTrades)):
            locationsToAdd.pop(0)

    locationBans = addLocations(locationsToAdd,locationBans)

    if parameters.foodTrades == 'None':
        locationsToAdd = [480,481,482,483,484,485]
    elif int(parameters.foodTrades) > 0:
        locationsToAdd = [480,481,482,483,484,485]
        for index in range(1,int(parameters.foodTrades)):
            locationsToAdd.pop(0)

    locationBans = addLocations(locationsToAdd,locationBans)

    if parameters.discoveries == 'None':
        locationsToAdd = [478,479]
    elif parameters.discoveries == 'Half(12)':
        locationsToAdd = [479]

    locationBans = addLocations(locationsToAdd,locationBans)

    if parameters.mapCompletion == 'None':
        locationsToAdd = [451,452,453,454,455,456,457,458,459]
    elif parameters.mapCompletion == '10%':
        locationsToAdd = [452,453,454,455,456,457,458,459]
    elif parameters.mapCompletion == '20%':
        locationsToAdd = [453,454,455,456,457,458,459]
    elif parameters.mapCompletion == '30%':
        locationsToAdd = [454,455,456,457,458,459]
    elif parameters.mapCompletion == '40%':
        locationsToAdd = [455,456,457,458,459]
    elif parameters.mapCompletion == '50%':
        locationsToAdd = [456,457,458,459]
    elif parameters.mapCompletion == '60%':
        locationsToAdd = [457,458,459]
    elif parameters.mapCompletion == '70%':
        locationsToAdd = [458,459]
    elif parameters.mapCompletion == '80%':
        locationsToAdd = [459]

    locationBans = addLocations(locationsToAdd,locationBans)

    if not parameters.dogiRewards:
        locationsToAdd = [446,447,448,449,450]

    locationBans = addLocations(locationsToAdd,locationBans)

    return locationBans

def addLocations(locationsToAdd,locationBans):
    for location in locationsToAdd:
        locationBans.append(location)

    return locationBans


        


