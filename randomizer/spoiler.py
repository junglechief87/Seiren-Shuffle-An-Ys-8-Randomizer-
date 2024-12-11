import shared.classr as classr
from randomizer.accessLogic import *

def generateSpoiler(shuffledLocations,parameters,blacklistRegion,duplicateChests):
    sphere = 0
    newInventory = []
    progressionLocations = []
    foundLocations = []
    accessibleLocation = []
    progressionInventory = []
    win = False
    spoilerLog = open('Ys_8_' + str(parameters.seed) + '.txt', 'w')

    spoilerLog.write("Seed# " + str(parameters.seed) + '\n')
    spoilerLog.write('Goal: ' + parameters.goal + '\t \t Number: ' + str(parameters.numGoal))
    spoilerLog.write('Goal count to open Octus: ' + str(parameters.numOctus))
    spoilerLog.write('\n \n')
    spoilerLog.write("Settings:\n")
    spoilerLog.write("Game Mode: " + str(parameters.charMode) + "\n")
    spoilerLog.write("Shuffle Party: " + str(parameters.shuffleParty) + "\n")
    spoilerLog.write("Shuffle Crew: " + str(parameters.shuffleCrew) + "\n")
    spoilerLog.write("Skills w/ Boss Bonuses: " + str(parameters.shuffleSkills) + "\n")
    spoilerLog.write("Jewel Trades: " + str(parameters.jewelTrades) + "\n")
    spoilerLog.write("Discoveries: " + str(parameters.discoveries) + "\n")
    spoilerLog.write("Map Completion: " + str(parameters.mapCompletion) + "\n")
    spoilerLog.write("Food Trades: " + str(parameters.foodTrades) + "\n")
    spoilerLog.write("Fish Trades: " + str(parameters.fishTrades) + "\n")
    spoilerLog.write("Dogi Intercept Rewards: " + str(parameters.dogiRewards) + "\n")
    spoilerLog.write("Master Kong: " + str(parameters.mkRewards) + "\n")
    spoilerLog.write("Silvia: " + str(parameters.silvia) + "\n")
    spoilerLog.write("Maphorash: " + str(parameters.maphorash) + "\n")
    spoilerLog.write("Former Sanctuary Crypt: " + str(parameters.formerSanctuaryCrypt) + "\n")
    spoilerLog.write("Additional Intercept Rewards: " + str(parameters.intRewards) + "\n")
    spoilerLog.write("Skills w/ Boss Bonuses: " + str(parameters.shuffleSkills) + "\n")
    spoilerLog.write("Experience Multiplier: " + str(parameters.expMult) + "\n")
    spoilerLog.write("Exp Mult Growth Rate (%): " + str(int((parameters.expGrowth - 1)*100)) + "%\n")
    spoilerLog.write("Battle Logic: " + str(parameters.battleLogic) + "\n")
    spoilerLog.write("Progressive Super Weapons: " + str(parameters.progressiveSuperWeapons) + "\n")
    spoilerLog.write("Open Octus Paths: " + str(parameters.openOctusPaths) + "\n")
    spoilerLog.write("Extra Flame Stones: " + str(parameters.extraFlameStones) + "\n")
    spoilerLog.write("Recipes Come w\ Ingredients: " + str(parameters.extraIngredients) + "\n")
    spoilerLog.write("Final Boss: " + str(parameters.finalBoss) + "\n")
    spoilerLog.write("Theos Start Phase: " + str(parameters.theosPhase) + "\n")
    spoilerLog.write("Origin Start Phase: " + str(parameters.originPhase) + "\n")
    spoilerLog.write("Origin Care Package: " + str(parameters.carePackage) + "\n")
    spoilerLog.write("BGM shuffle: " + str(parameters.shuffleBgm) + "\n")
    spoilerLog.write("Essence Key Sanity: " + str(parameters.essenceKeySanity) + "\n")
    spoilerLog.write("Locations:\n")

    for location in shuffledLocations:
        location.writeSpoiler(spoilerLog)

    for location in shuffledLocations:
        if location.locName == 'Opening Cutscene':
            openingCutscene = location
            progressionInventory.append(location)
        else:
            accessibleLocation.append(location)
        
    spoilerLog.write('\n \n \n')
    spoilerLog.write("Playthrough:\n")
    
    #We build an initial list of progression items on the way to the goal
    while len(accessibleLocation) != 0 and not win:
        while True:
            itemFound = 0
            for index,location in enumerate(accessibleLocation):
                if canAccess(progressionInventory,location,parameters) and not any(location.locRegion.find(region) >= 0 for region in blacklistRegion): #Returns true if you can access the location and it is not blacklisted
                    newLocation = accessibleLocation.pop(index)
                    accessibleItem = classr.inventory(newLocation)
                    if accessibleItem.progression and newLocation.locID not in duplicateChests:
                        newInventory.append(accessibleItem)
                        progressionLocations.append(newLocation)
                        itemFound+=1
                        
                        if accessibleItem.itemName == 'End the Lacrimosa':
                            win = True
                            break
                        
            if itemFound == 0 or win: break
        
        while len(newInventory) != 0:
            progressionInventory.append(newInventory.pop(0))

    #We trim down the list by removing each progression location one at a time and seeing if the seed is still beatable, if it is then we remove the location completely
    progressionLocations.append(openingCutscene)
    while True:
        removed = False
        locIndex = 0
        for locIndex,location in enumerate(progressionLocations):
            itemToTest = progressionLocations.pop(locIndex)
            beatable = testSeed(progressionLocations,parameters)
            if not beatable:
                progressionLocations.append(itemToTest)
            else:
                removed = True
                break
        if not removed: break

    #We take the final list and do our playthrough using only the minimum required items
    win = False
    progressionInventory = []
    for location in progressionLocations:
        if location.locName == 'Opening Cutscene':
            openingCutscene = location
            progressionInventory.append(openingCutscene)

    while len(progressionLocations) != 0 and not win:
        itemFound = 0
        spoilerLog.write(str(sphere) + ': \n')
        spoilerLog.write('{ \n')
        if sphere == 0:
            openingCutscene.writeSpoiler(spoilerLog)

        while True:
            itemFound = 0
            for index,location in enumerate(progressionLocations):
                if canAccess(progressionInventory,location,parameters):
                    newLocation = progressionLocations.pop(index)
                    accessibleItem = classr.inventory(newLocation)
                    newInventory.append(accessibleItem)
                    foundLocations.append(newLocation)
                    itemFound+=1
                        
                    if accessibleItem.itemName == 'End the Lacrimosa':
                        win = True
                        break
                        
            if itemFound == 0 or win: break

        while len(foundLocations) != 0:
            location = foundLocations.pop(0)
            location.writeSpoiler(spoilerLog)
        spoilerLog.write('} \n')

        while len(newInventory) != 0:
            progressionInventory.append(newInventory.pop(0))
        sphere+=1
        
        if sphere >= 100: #Added this safety check in case there are other bugs in spoiler generation
            break 

    spoilerLog.close()

def testSeed(progressionLocations,parameters):
    progressionInventory = []
    progressionLocationsToTest = []
    for location in progressionLocations:
        progressionLocationsToTest.append(location)

    while True:
        itemFound = 0
        for index,location in enumerate(progressionLocationsToTest):
            if canAccess(progressionInventory,location,parameters) or location.locName == 'Opening Cutscene':
                newLocation = progressionLocationsToTest.pop(index)
                accessibleItem = classr.inventory(newLocation)
                progressionInventory.append(accessibleItem)
                itemFound+=1
                if accessibleItem.itemName == 'End the Lacrimosa':
                    return True   
        if itemFound == 0:
            return False