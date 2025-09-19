import random
import shared.classr as classr
from shared.functions import * 
from randomizer.spoiler import *
from randomizer.accessLogic import *
from randomizer.hint import createHints, generateHint

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
    entrances = [] #list of entrances to be shuffled if entrance shuffle is on
    exits = [] #list of exits to be shuffled if entrance shuffle is on
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
        elif vanillaLocations[0].landmark and not parameters.discoverySanity: #if we're not shuffling discoveries then add them to the final list
            shuffledLocations.append(vanillaLocations.pop(0))
        elif not parameters.shuffleSkills and vanillaLocations[0].skill: #if we're not shuffling skills then discard them
            vanillaLocations.pop(0)
        elif (vanillaLocations[0].mapCheckID == 'Psyches' and parameters.goal != 'Release the Psyches') or \
              any(vanillaLocations[0].locRegion.find(region) == 0 for region in blacklistRegion): #if goal isn't release the psyches and location is a psyche or the location we're looking at is blacklisted just discard it completely
            vanillaLocations.pop(0)
        elif parameters.goal == 'Release the Psyches' and vanillaLocations[0].mapCheckID in ['Psyche-Ura','Psyche-Nestor','Psyche-Minos','Psyche-Hydra']: #if goal is release the psyches discard warden bosses, their defeats will be tracked with the psyches
            vanillaLocations.pop(0)
        elif vanillaLocations[0].entrance and parameters.entranceShuffle:
            entrances.append(vanillaLocations.pop(0))
        elif vanillaLocations[0].exit and parameters.entranceShuffle:
            exits.append(vanillaLocations.pop(0))
        elif not vanillaLocations[0].crew and not vanillaLocations[0].party and not vanillaLocations[0].item \
            and not vanillaLocations[0].skill and not vanillaLocations[0].landmark and vanillaLocations[0].mapCheckID not in ['Psyches']: #if the location has no randomizable property don't randomize it, mostly used for bosses. This will also catch entrances when not shuffled.
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

    if parameters.entranceShuffle:
        shuffledEntrances = shuffleEntrancesAndExits(entrances,exits,parameters.northSideOpen,parameters.discoverySanity)

        for entrance in shuffledEntrances:
            shuffledLocations.append(entrance)

    random.shuffle(preShuffleLoc)
    shuffledLocations, playthrough, playthroughAllProgression = fillShuffledLocations(inventory,preShuffleLoc,shuffledLocations,parameters,blacklistRegion)

    return shuffledLocations, playthrough, playthroughAllProgression

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
                
def fillShuffledLocations(inventory,fillLocations,shuffledLocations,parameters,blacklistRegion):
    progressionInventory = [] #progression items only
    niceItems = [] #nice to have items that will always exist in the world but don't contain logic
    junkItems = [] #filler items, not all will be placed. Some new progression items, like the Dana past event trigger items, will take their place in the pool of vanilla items.
    psycheItems = [] #currently only used for filling in release the psyche goal mode
    accessibleInventory = []
    accessibleLocation = []
    progressionBanList = progressionBans(parameters)

    for item in inventory:
        # If former sanctuary crypt is on, Essence key stones are progression
        if parameters.formerSanctuaryCrypt and item.itemID in [703, 206]:  # Essence key stone, jade pendant
            item.progression = True

        # If intercept rewards are off, make the T-memos not progression
        if not parameters.dogiRewards and item.itemID in [760, 761, 762, 763]:  # T memos
            item.progression = False

        # If we're doing Seiren Escape, make Mistilteinn and Seiren Area Map progression items
        if parameters.goal == 'Seiren Escape' and item.itemID in [9, 795]:
            item.progression = True

        # If battle logic is on, make specific items progression
        if parameters.battleLogic and item.itemID in [155, 171, 156, 542, 157, 169, 172, 271, 727, 548, 209, 436, 720, 13, 9]:
            item.progression = True

        # Make 'Empty Psyches\Magma Fight(DANA)' item progression only if in Past Dana mode with Release the Psyches goal
        if parameters.charMode == 'Past Dana' and parameters.goal == 'Release the Psyches' and item.itemName == 'Empty Psyches\Magma Fight(DANA)':
            item.progression = True

        # If progressive super weapons are on, rename specific items
        if parameters.progressiveSuperWeapons:
            if item.itemID == 9:
                item.itemName = 'Broken Mistilteinn'
            elif item.itemID == 13:
                item.itemName = 'Broken Spirit Ring'

        if parameters.memoHints and item.itemID in [750,751,752,753,754,755,760,761,762,763] and not item.progression:
            item.nice = True

    #pull out progression items to place first for easier processing
    #for release the psyches goal we need to pull those into their own list too
    while len(inventory) != 0:
        if inventory[0].itemName in ['Empty Psyches','Psyches of the Sky Era\Braziers Fight(DANA)','Psyches of the Insectoid Era\Stone Fight(DANA)',\
                                     'Psyches of the Frozen Era\Clairvoyance Fight(DANA)','Psyches of the Ocean Era\Frost Fight(DANA)','Empty Psyches\Magma Fight(DANA)']:
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
        psycheInOctus = 0
        while len(psycheItems) != 0:
            psycheToPlace = psycheItems.pop(0)

            for locIndex,location in enumerate(fillLocations):
                if location.mapCheckID == 'Psyches' and not (psycheToPlace.progression and (location.locID in progressionBanList or 
                                                                                            (location.locRegion == 'Octus Overlook' and
                                                                                             psycheInOctus >= parameters.numOctus))):
                    if location.locRegion == 'Octus Overlook':
                        psycheInOctus += 1
                    psycheToFill = fillLocations.pop(locIndex)
                    filledLocation = combineShuffledLocAndItem(psycheToFill,psycheToPlace)
                    shuffledLocations.append(filledLocation)
                    break
    
    #let's shuffle the inventory just to randomize the party order then run through the intventory until we find the first party member, store it, then pop it from inventory.
    #this will be our starting character.
    #this needs to be done before the main shuffle to avoid things that aren't character being placed here.
    random.shuffle(progressionInventory)
    if parameters.charMode == 'Past Dana':
        # Select Dana as starting character
        for index,partyMember in enumerate(progressionInventory):
            if partyMember.itemName == 'Dana':
                startingPartyMember = progressionInventory.pop(index)
                break
    if parameters.shuffleParty and not parameters.charMode == 'Past Dana':
        #Select random party member as starting character
        for index,partyMember in enumerate(progressionInventory):
            if partyMember.party and partyMember.itemName in parameters.partyPool:
                startingPartyMember = progressionInventory.pop(index)
                break

    if parameters.shuffleParty or parameters.charMode == 'Past Dana':
        for locNum,location in enumerate(fillLocations):
            if location.locName == 'Opening Cutscene':
                partyFillLocation = fillLocations.pop(locNum)
                filledLocation = combineShuffledLocAndItem(partyFillLocation,startingPartyMember)
                shuffledLocations.append(filledLocation)
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
            if ( parameters.essenceKeySanity or ( (itemToPlace.itemID != 703) or (location.locRegion.find('Former Sanctuary Crypt') == 0) ) ) and \
                canAccess(accessibleInventory,fillLocations[index],parameters) and location.locID not in progressionBanList:
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
    random.shuffle(junkItems)
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

    playthrough, playthroughAllProgression = generateSpoiler(shuffledLocations,parameters,blacklistRegion,duplicateChests)
    #This function will be responsible for clearing hints in case hints are toggled off
    hints = {'standard': [], 'memo': []}

    if parameters.hint:
        hints = createHints(shuffledLocations, parameters, playthrough)   
    
    generateHint(hints['standard'], parameters, hintType = 'quest')
    generateHint(hints['memo'], parameters, hintType = 'memo')
        
    return shuffledLocations, playthrough, playthroughAllProgression

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

    if not parameters.Mephorash:
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

def shuffleEntrancesAndExits(entrances,exits,northSideOpen,discoverySanity):
    shuffledEntrances = []
    itemizedEntrances = []
    entranceLocations = []
    itemizedExits = []
    exitLocations = []
    shuffledExits = []
    print("Shuffling Entrances and Exits")
    
    #keep shuffling until we get a valid configuration
    while not feasibilityCheck(shuffledEntrances,northSideOpen,discoverySanity):
        shuffledEntrances.clear()

        for entrance in entrances:
            itemizedEntrances.append(classr.inventory(entrance))
            entranceLocations.append(classr.shuffledLocation(entrance))
            
        random.shuffle(itemizedEntrances)
        while len(itemizedEntrances) != 0:
            entranceToPlace = itemizedEntrances.pop(0)
            entranceToFill = entranceLocations.pop(0)
            filledEntrance = combineShuffledLocAndItem(entranceToFill,entranceToPlace)
            shuffledEntrances.append(filledEntrance)

        for entrance in shuffledEntrances:
            print("Entrance: " + entrance.locName + " in " + entrance.locRegion + '-' + entrance.mapCheckID + " leads to " + entrance.itemName)

    for exit in exits:
            print(exit.locName)
            itemizedExits.append(classr.inventory(exit))
            exitLocations.append(classr.shuffledLocation(exit))

    #entrance mapCheckID:exit itemName pairs for identifying connected entrances and exits
    entranceExitItemPairs = {'Octus Entrance':'Temple of the Great Tree - Great Tree Garden', 
                         'Towering Coral Forest Front Entrance':'Nameless Coast - Camp',
                         'Towering Coral Forest Back Entrance':'Roaring Seashore - Metavolicalis', 
                         'Schlamm Jungle Front Entrance':'Beast Hills - Camp South',
                         'Schlamm Jungle Back Entrance':'Odd Rock Coast - Odd Rock Coast',
                         'Waterdrop Cave Entrance':'Calm Inlet - Castaway Village Area',
                         'Eroded Valley Front Entrance':'Beast Hills - Camp North',
                         'Eroded Valley Back Entrance':'Sunrise Beach - Sunrise Beach',
                         'Pirate Ship Eleftheria Entrance':'East Coast Cave - East Coast Cave',
                         'Mont Gendarme Front Entrance':'Primordial Passage - Camp',
                         'Mont Gendarme Back Entrance':'Mountain Pinnacle Trail - Top',
                         'Baja Tower Entrance':'Towal Highway - Camp',
                         'Archeozoic Chasm Entrance':'The Ruins of Eternia - Palace Ruins',
                         'Valley of Kings Entrance':'Valley of Kings - Camp',}
    
    #entrance itemName:exit mapCheckID pairs for identifying connected entrances and exits
    entranceItemExitPairs = {'Octus Dungeon':'Exit to Temple of the Great Tree', 
                         'Towering Coral Forest Dungeon Front':'Exit to Nameless Coast',
                         'Towering Coral Forest Dungeon Back':'Exit to Roaring Seashore', 
                         'Schlamm Jungle Dungeon Front':'Exit to Beast Hills South',
                         'Schlamm Jungle Dungeon Back':'Exit to Odd Rock Coast',
                         'Waterdrop Cave Dungeon':'Exit to Calm Inlet',
                         'Eroded Valley Dungeon Front':'Exit to Beast Hills North',
                         'Eroded Valley Dungeon Back':'Exit to Sunrise Beach',
                         'Pirate Ship Eleftheria Dungeon':'Exit to East Coast Cave',
                         'Mont Gendarme Dungeon Front':'Exit to Primordial Passage',
                         'Mont Gendarme Dungeon Back':'Exit to Mountain Pinnacle Trail',
                         'Baja Tower Dungeon':'Exit to Towal Highway',
                         'Archeozoic Chasm Dungeon':'Exit to The Ruins of Eternia',
                         'Valley of Kings Dungeon':'Exit to Valley of Kings - Camp',}
    
    for entrance in shuffledEntrances:
        print("Entrance: " + entrance.locName + " in " + entrance.locRegion + '-' + entrance.mapCheckID + " leads to " + entrance.itemName)
        exitLocation = findPairedExitLocation(entranceItemExitPairs[entrance.itemName],exitLocations)
        exitItem = findPairedExitItem(entranceExitItemPairs[entrance.mapCheckID],itemizedExits)
        shuffledExits.append(combineShuffledLocAndItem(exitLocation,exitItem))

    for exit in shuffledExits:
        shuffledEntrances.append(exit)

    return shuffledEntrances

def findPairedExitLocation(exitName,exitLocations):
    for exit in exitLocations:
        print(exit.mapCheckID)
        print(exitName)
        if exit.mapCheckID == exitName:
            return exit
                    
def findPairedExitItem(itemName,itemizedExits):
    for item in itemizedExits:
        print(item.itemName)
        print(itemName)
        if item.itemName == itemName:
            return item
        
def feasibilityCheck(shuffledEntrances,northSideOpen,discoverySanity):
    northsideEntrances = ['Octus Entrance','Mont Gendarme Back Entrance','Baja Tower Entrance','Archeozoic Chasm Entrance','Valley of Kings Entrance']
    connectedChecks = {'Towering Coral Forest Dungeon Front':'Towering Coral Forest Dungeon Back',
                       'Towering Coral Forest Dungeon Back':'Towering Coral Forest Dungeon Front',
                       'Schlamm Jungle Dungeon Front':'Schlamm Jungle Dungeon Back',
                       'Schlamm Jungle Dungeon Back':'Schlamm Jungle Dungeon Front',
                       'Eroded Valley Dungeon Front':'Eroded Valley Dungeon Back',
                       'Eroded Valley Dungeon Back':'Eroded Valley Dungeon Front',
                       'Mont Gendarme Dungeon Front':'Mont Gendarme Dungeon Back',
                       'Mont Gendarme Dungeon Back':'Mont Gendarme Dungeon Front',}
    isolatedEntrances = ['Schlamm Jungle Back Entrance']
    isolatedEntrancesNoLandmarks = ['Schlamm Jungle Back Entrance','Towering Coral Forest Back Entrance','Eroded Valley Back Entrance']
    northSideAccess = False
    noIsolatedAreas = False

    if northSideOpen or discoverySanity:
        northSideAccess = True

    for entrance in shuffledEntrances:
        if entrance.mapCheckID in northsideEntrances and not northSideAccess and entrance.itemName in connectedChecks:
            for connectedEntrance in shuffledEntrances:
                if connectedChecks[entrance.itemName] == connectedEntrance.itemName and connectedEntrance.mapCheckID not in northsideEntrances\
                    and connectedEntrance.mapCheckID not in isolatedEntrances:
                    northSideAccess = True
                    break
        if entrance.mapCheckID in isolatedEntrances and entrance.itemName in connectedChecks and discoverySanity:
            noIsolatedAreas = True

        if entrance.mapCheckID in isolatedEntrancesNoLandmarks and entrance.itemName in connectedChecks and not discoverySanity:
            for connectedEntrance in shuffledEntrances:
                if connectedChecks[entrance.itemName] == connectedEntrance.itemName and connectedEntrance.mapCheckID not in isolatedEntrancesNoLandmarks:
                    noIsolatedAreas = True
                    break
                elif connectedChecks[entrance.itemName] == connectedEntrance.itemName and connectedEntrance.mapCheckID in isolatedEntrancesNoLandmarks:
                    noIsolatedAreas = False
                    break
        elif entrance.mapCheckID in isolatedEntrancesNoLandmarks and entrance.itemName not in connectedChecks:
            noIsolatedAreas = False
            break
    
    print("North Side Access: " + str(northSideAccess))
    print("No Isolated Areas: " + str(noIsolatedAreas))

    return northSideAccess and noIsolatedAreas
        
                    