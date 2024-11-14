import random
import shared.classr as classr
from shared.functions import * 
from randomizer.spoiler import *
from randomizer.accessLogic import *

#constants
blacklistRegion = ['Sanctuary Crypt']
duplicateChests = [47,48,49,179] #dawn versions of large shoreline for great river valley and valley of kings

def shuffleLocations(parameters):
    #take standard location list built from the locations.csv and build out shuffle locations and inventory lists
    #filter out locations that are not currently being shuffled.
    global chestsToCopy
    
    random.seed(parameters.seed)
    vanillaLocations =  getLocations() #location list built from locations table
    inventory = [] #list of all items in the shuffle pool
    preShuffleLoc = [] #locations only, pulled out and ready for shuffling
    shuffledLocations = [] #finalized list of locations and items at the location
    chestsToCopy = []

    if not parameters.formerSanctuaryCrypt:
        blacklistRegion.append('Former Sanctuary Crypt')
    
    
    while len(vanillaLocations) != 0:
        if vanillaLocations[0].locID in duplicateChests: #pop out duplicated locations, we'll copy these from the normal version of great river valley and valley of kings after we're done.
            chestsToCopy.append(vanillaLocations.pop(0))
        elif not parameters.extraFlameStones and vanillaLocations[0].itemID == 778 and vanillaLocations[0].mapID == 'none': #if extra flames stones isn't turned on then discard these items.
            vanillaLocations.pop(0)
        elif not parameters.shuffleCrew and vanillaLocations[0].crew and not vanillaLocations[0].party: #if we're not shuffling crew then add them to the final list
            shuffledLocations.append(vanillaLocations.pop(0))
        elif not parameters.shuffleParty and vanillaLocations[0].party: #if we're not shuffling party then add them to the final list
            shuffledLocations.append(vanillaLocations.pop(0))
        elif not parameters.shuffleSkills and vanillaLocations[0].skill: #if we're not shuffling skills then discard them
            vanillaLocations.pop(0)
        elif (vanillaLocations[0].mapCheckID == 'Psyches' and parameters.goal != 'Release the Psyches') or any(vanillaLocations[0].locRegion.find(region) == 0 for region in blacklistRegion): #if goal isn't release the psyches and location is a psyche or the location we're looking at is blacklisted just discard it completely
            vanillaLocations.pop(0)
        elif parameters.goal == 'Release the Psyches' and vanillaLocations[0].mapCheckID in ['Psyche-Ura','Psyche-Nestor','Psyche-Minos','Psyche-Hydra']: #if goal is release the psyches discard warden bosses, their defeats will be tracked with the psyches
            vanillaLocations.pop(0)
        elif not vanillaLocations[0].crew and not vanillaLocations[0].party and not vanillaLocations[0].item and not vanillaLocations[0].skill and vanillaLocations[0].mapCheckID != 'Psyches': #if the location has no randomizable property don't randomize it, mostly used for bosses
            shuffledLocations.append(vanillaLocations.pop(0))
        elif vanillaLocations[0].mapCheckID != 'Goal':
            locToBeShuffled = vanillaLocations.pop(0)
            inventoryObject = classr.inventory(locToBeShuffled)

            if locToBeShuffled.mapID != 'none': #for 'new to the randomizer' progression items we set their map to none, these locations will not exist. There will be fewer locations than items to shuffle.
                shuffleLocationObject = classr.shuffledLocation(locToBeShuffled)
                preShuffleLoc.append(shuffleLocationObject)
            inventory.append(inventoryObject)
            
        else:
            #for locations not being shuffled go ahead and add them to the finalized list of shuffled locations
            shuffledLocations.append(vanillaLocations.pop(0))

    random.shuffle(preShuffleLoc)
    fillShuffledLocations(inventory,preShuffleLoc,shuffledLocations,parameters)

    return shuffledLocations

#these functions take locations and item lists and find the index of the specified characters skills and starting skills for locations.
def findStartSkillSlot(fillLocations,character):
    characterRegion = character + ' Starting Skill'
    for index,location in enumerate(fillLocations):
        if location.mapID == 'startingSkill' and location.locRegion == characterRegion:
            return index

def findSkill(niceItem,character):
        characterSkill = character.upper()
        for index,item in enumerate(niceItem):
            if item.itemName.find(characterSkill) > -1:
                return index
                
def fillShuffledLocations(inventory,fillLocations,shuffledLocations,parameters):
    progressionInventory = [] #progression items only
    niceItems = [] #nice to have items that will always exist in the world but don't contain logic
    junkItems = [] #filler items, not all will be placed. Some new progression items, like the Dana past event trigger items, will take their place in the pool of vanilla items.
    psycheItems = [] #currently only used for filling in release the psyche goal mode
    accessibleInventory = []
    accessibleLocation = []
    progressionBanList = progressionBans(parameters)

    if not parameters.formerSanctuaryCrypt:
        blacklistRegion.append('Former Sanctuary Crypt')

    # if former sanctuary crypt is on, Essence key stones are progression
    if parameters.formerSanctuaryCrypt:
        for index, item in enumerate(inventory):
            if item.itemID == 703: #Essence key stone
                inventory[index].progression = True

    #if we're doing seiren escape then make Mistilteinn and the Seiren Area Map progression items
    if parameters.goal == 'Seiren Escape':
        for index,item in enumerate(inventory):
            if item.itemID in [9,795]:
                inventory[index].progression = True

    #if battle logic is on we have a number of items to make progression
    if parameters.battleLogic:
        for index,item in enumerate(inventory):
            if item.itemID in [155,171,156,542,157,169,172,271,727,548,209,436,720]:
                inventory[index].progression = True

    #if progressive super weapons are on then we'll change the names of these to match our in-game signage for the flags being set to acquire the super weapons at max shop level. 
    #This will also help adjust the display for Dina's shops
    if parameters.progressiveSuperWeapons:
        for item in inventory:
            if item.itemID == 9:
                item.itemName = 'Broken Mistilteinn'
            elif item.itemID == 13:
                item.itemName = 'Broken Spirit Ring'

    #pull out progression items to place first for easier processing
    #for release the psyches goal we need to pull those into their own list too
    while len(inventory) != 0:
        if inventory[0].itemName in ['Empty Psyches','Psyches of the Sky Era','Psyches of the Insectoid Era','Psyches of the Frozen Era','Psyches of the Ocean Era']:
            psycheItem = inventory.pop(0)
            psycheItems.append(psycheItem)
        elif inventory[0].progression:    
            progressionItem = inventory.pop(0)
            progressionInventory.append(progressionItem)
        elif inventory[0].nice:
            niceItem = inventory.pop(0)
            niceItems.append(niceItem)
        else:
            junk = inventory.pop(0)
            junkItems.append(junk)

    #if skill shuffle is turned on we go ahead and pull the skill starting locations and find a skill for the corresponding character to place there. 
    #we do these before the main shuffle to avoid things being placed there that aren't skills
    if parameters.shuffleSkills:
        random.shuffle(niceItems) 
        startingSkills = 2
        for character in ['Adol','Laxia','Sahad','Hummel','Ricotta','Dana']:
            for startingSkill in range(0,startingSkills):
                locationIndex = findStartSkillSlot(fillLocations,character)
                skillIndex = findSkill(niceItems,character)
                skillLocToFill = fillLocations.pop(locationIndex)
                skillToPlace = niceItems.pop(skillIndex)
                filledLocation = combineShuffledLocAndItem(skillLocToFill,skillToPlace)
                shuffledLocations.append(filledLocation)

    #for release the psyches game goal we'll build our list here.
    if parameters.goal == 'Release the Psyches':
        while len(psycheItems) != 0:
            psycheToPlace = psycheItems.pop(0)
            for locIndex,location in enumerate(fillLocations):
                if location.mapCheckID == 'Psyches' and not (psycheToPlace.progression and location.locID in progressionBanList):
                    psycheToFill = fillLocations.pop(locIndex)
                    filledLocation = combineShuffledLocAndItem(psycheToFill,psycheToPlace)
                    shuffledLocations.append(filledLocation)
                    break
    
    #let's shuffle the inventory just to randomize the party order then run through the intventory until we find the first party member, store it, then pop it from inventory.
    #this will be our starting character.
    #this needs to be done before the main shuffle to avoid things that aren't character being placed here.
    random.shuffle(progressionInventory) 
    if parameters.shuffleParty:
        for index,partyMember in enumerate(progressionInventory):
            if partyMember.party:
                startingPartyMember = progressionInventory.pop(index)
                #let's find the opening cutscene real quick and make sure we fill is with a playable character
                for locNum,location in enumerate(fillLocations):
                    if location.locName == 'Opening Cutscene':
                        partyFillLocation = fillLocations.pop(locNum)
                        filledLocation = combineShuffledLocAndItem(partyFillLocation,startingPartyMember)
                        shuffledLocations.append(filledLocation)
                        break 
                break      
             
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
                if location.progression and canAccess(accessibleInventory,location,parameters):
                    accessibleItem = classr.inventory(accessibleLocation.pop(index))
                    accessibleInventory.append(accessibleItem)
                    itemFound+=1

            if itemFound == 0: break

        #loop through locations and test if the player can access them. If they can access them then queue the location to be filled and remove from pool
        for index,location in enumerate(fillLocations):
            if ( parameters.essenceKeySanity or ( (itemToPlace.itemID != 703) or (location.locRegion.find('Former Sanctuary Crypt') == 0) ) ) and canAccess(accessibleInventory,fillLocations[index],parameters) and location.locID not in progressionBanList:
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
            for fillLocation in fillLocations:
                print(fillLocation.locName + fillLocation.locRegion)
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

    generateSpoiler(shuffledLocations,parameters,blacklistRegion,duplicateChests)
        
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

    if not parameters.maphorash:
        locationsToAdd = [532,533,617,268]

    locationBans = addLocations(locationsToAdd,locationBans)

    if not parameters.mkRewards:
        locationsToAdd = [428,580,581,582,583,584,585]

    locationBans = addLocations(locationsToAdd,locationBans)

    if not parameters.silvia:
        locationsToAdd = [542,543,591]

    locationBans = addLocations(locationsToAdd,locationBans)

    return locationBans

def addLocations(locationsToAdd,locationBans):
    for location in locationsToAdd:
        locationBans.append(location)

    return locationBans


        


