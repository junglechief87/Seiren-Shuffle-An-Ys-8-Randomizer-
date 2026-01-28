import shared.classr as classr
from randomizer.accessLogic import *

shuffledEntranceList = []


def generateSpoiler(shuffledLocations,parameters,blacklistRegion,duplicateChests):
    sphere = 0
    newInventory = []
    progressionLocations = []
    foundLocations = []
    accessibleLocation = []
    progressionInventory = []
    win = False
    spoilerLog = open("Ys_8_" + str(parameters.seed) + ".txt", "w")

    spoilerLog.write("Seed#: " + str(parameters.seed) + "\n")
    spoilerLog.write("Goal: " + parameters.goal + "\n")
    spoilerLog.write("Number: " + str(parameters.numGoal) + '\n')
    spoilerLog.write("Goal count to open Octus: " + str(parameters.numOctus))
    spoilerLog.write("\n \n")
    spoilerLog.write("Settings:\n")
    spoilerLog.write("Game Mode: " + str(parameters.charMode) + "\n")
    spoilerLog.write("Shuffle Party: " + str(parameters.shuffleParty) + "\n")
    spoilerLog.write("Shuffle Crew: " + str(parameters.shuffleCrew) + "\n")
    spoilerLog.write("Skills w/ Boss Bonuses: " + str(parameters.shuffleSkills) + "\n")
    spoilerLog.write("Discovery-Sanity: " + str(parameters.discoverySanity) + "\n")
    spoilerLog.write("Jewel Trades: " + str(parameters.jewelTrades) + "\n")
    spoilerLog.write("Discoveries: " + str(parameters.discoveries) + "\n")
    spoilerLog.write("Map Completion: " + str(parameters.mapCompletion) + "\n")
    spoilerLog.write("Food Trades: " + str(parameters.foodTrades) + "\n")
    spoilerLog.write("Fish Trades: " + str(parameters.fishTrades) + "\n")
    spoilerLog.write("Dogi Intercept Rewards: " + str(parameters.dogiRewards) + "\n")
    spoilerLog.write("Master Kong: " + str(parameters.mkRewards) + "\n")
    spoilerLog.write("Silvia: " + str(parameters.silvia) + "\n")
    spoilerLog.write("Mephorash: " + str(parameters.Mephorash) + "\n")
    spoilerLog.write("Former Sanctuary Crypt: " + str(parameters.formerSanctuaryCrypt) + "\n")
    spoilerLog.write("Additional Intercept Rewards: " + str(parameters.intRewards) + "\n")
    spoilerLog.write("Experience Multiplier: " + str(parameters.expMult) + "\n")
    spoilerLog.write("Battle Logic: " + str(parameters.battleLogic) + "\n")
    spoilerLog.write("Progressive Super Weapons: " + str(parameters.progressiveSuperWeapons) + "\n")
    spoilerLog.write("Open Octus Paths: " + str(parameters.openOctusPaths) + "\n")
    spoilerLog.write("Extra Flame Stones: " + str(parameters.extraFlameStones) + "\n")
    spoilerLog.write("Recipes Come w\ Ingredients: " + str(parameters.extraIngredients) + "\n")
    spoilerLog.write("North Side Open: " + str(parameters.northSideOpen) + "\n")
    spoilerLog.write("Infinity Mode: " + str(parameters.infinityMode) + "\n")
    spoilerLog.write("Scale EXP Items: " + str(parameters.expItems) + "\n")
    spoilerLog.write("Final Boss: " + str(parameters.finalBoss) + "\n")
    spoilerLog.write("Theos Start Phase: " + str(parameters.theosPhase) + "\n")
    spoilerLog.write("Origin Start Phase: " + str(parameters.originPhase) + "\n")
    spoilerLog.write("Origin Care Package: " + str(parameters.carePackage) + "\n")
    spoilerLog.write("BGM shuffle: " + str(parameters.shuffleBgm) + "\n")
    spoilerLog.write("Essence Key Sanity: " + str(parameters.essenceKeySanity) + "\n")
    spoilerLog.write("Hints: " + str(parameters.hint) + "\n")
    spoilerLog.write("Adventuring Gear Hints: " + str(parameters.adventuringGearHints) + "\n")
    spoilerLog.write("Castaway Hints: " + str(parameters.castawayHints) + "\n")
    spoilerLog.write("Foolish Location Hints: " + str(parameters.foolishHints) + "\n")
    spoilerLog.write("Pirate Memo Hints: " + str(parameters.memoHints) + "\n")
    spoilerLog.write("Starting Loadout: \n\t")
    spoilerLog.write("Starting Level: " + str(parameters.startingLevel) + "\n\t")
    spoilerLog.write("Shop Level: " + str(parameters.shopLevel) + "\n\t")
    spoilerLog.write("Weapon Level: " + str(parameters.weaponLevel) + "\n\t")
    spoilerLog.write("Armor Level: " + str(parameters.armorLevel) + "\n\t")
    spoilerLog.write("Trade Shop: " + str(parameters.tradeShop) + "\n\t")
    spoilerLog.write("Tailor Shop: " + str(parameters.tailorShop) + "\n\t")
    spoilerLog.write("Craft Shop: " + str(parameters.craftShop) + "\n\t")
    spoilerLog.write("Medical Shop: " + str(parameters.medicalShop) + "\n\t")
    spoilerLog.write("Discovery Shop: " + str(parameters.discoveryShop) + "\n\t")
    spoilerLog.write("All Recipes: " + str(parameters.allRecipes) + "\n\t")
    spoilerLog.write("Max Ingredients: " + str(parameters.maxIngredients) + "\n\t")
    spoilerLog.write("Adventure Gear Slots: " + str(parameters.gearSlots) + "\n\t")
    spoilerLog.write("Grip Gloves: " + str(parameters.gloves) + "\n\t")
    spoilerLog.write("Glow Stone: " + str(parameters.glowStone) + "\n\t")
    spoilerLog.write("Archaeopteryx Wing: " + str(parameters.wing) + "\n\t")
    spoilerLog.write("Floating Shoes: " + str(parameters.floatShoes) + "\n\t")
    spoilerLog.write("Hermit's Scale: " + str(parameters.hermitsScale) + "\n\t")
    spoilerLog.write("Purifying Bell: " + str(parameters.purifyingBell) + "\n\t")
    spoilerLog.write("Gale Feather: " + str(parameters.galeFeather) + "\n\t")
    spoilerLog.write("Windy Vestment: " + str(parameters.windyVestment) + "\n\t")
    spoilerLog.write("Ares Seal: " + str(parameters.aresSeal) + "\n\t")
    spoilerLog.write("Aeolus Urn: " + str(parameters.aeolusUrn) + "\n\t")
    spoilerLog.write("Eagle Eye Orb: " + str(parameters.eagleEyeOrb) + "\n")
    spoilerLog.write("Party Pool: \n")

    fullParty = ['Adol','Laxia','Sahad','Hummel','Ricotta','Dana']
    for char in fullParty:
        if char in parameters.partyPool:
            spoilerLog.write("\t" + str(char) + ": True\n")
        else:
            spoilerLog.write("\t" + str(char) + ": False\n")
    
    locationsSorted = sorted(shuffledLocations, key=lambda x: (x.locRegion, x.locName, x.mapCheckID))
    spoilerLog.write("\n")
    spoilerLog.write("Entrance Shuffle: " + str(parameters.entranceShuffle) + "\n")

    for location in locationsSorted:
        if location.entrance or location.exit:
            shuffledEntranceList.append(location)
        if location.entrance:
            location.writeSpoiler(spoilerLog)

    spoilerLog.write("\n")
    spoilerLog.write("Locations:\n")

    for location in locationsSorted:
        #location.printSpoiler()
        if not location.entrance and not location.exit:
            location.writeSpoiler(spoilerLog)

    playthroughAllProgression = classr.playthrough()

    for location in shuffledLocations:
        if location.locName == 'Opening Cutscene':
            openingCutscene = location
            progressionInventory.append(classr.inventory(location))
            playthroughAllProgression.build(location,sphere)
        else:
            accessibleLocation.append(location)

    spoilerLog.write('\n \n \n')
    spoilerLog.write("Playthrough:\n")
    print('Beginning playthrough')
    #We build an initial list of progression items on the way to the goal
    testSphere = 0
    while len(accessibleLocation) != 0 and not win:
        while True:
            itemFound = 0
            for index,location in enumerate(accessibleLocation):
                if canAccess(progressionInventory, location, parameters):
                    newLocation = accessibleLocation.pop(index)
                    accessibleItem = classr.inventory(newLocation)
                    if accessibleItem.progression and newLocation.locID not in duplicateChests:
                        newInventory.append(accessibleItem)
                        progressionLocations.append(newLocation)
                        itemFound+=1
                        
                        playthroughAllProgression.build(newLocation,testSphere)
                        if accessibleItem.itemName == 'End the Lacrimosa':
                            win = True
                            break
            if itemFound == 0 or win: break
        
        """
        print('unreached locations:')
        for location in accessibleLocation:
            if location.progression:
                location.printSpoiler()
        print('reached locations:')
        for location in progressionLocations:
            location.printSpoiler()
        """
            
        while len(newInventory) != 0:
            progressionInventory.append(newInventory.pop(0))
        testSphere+=1

    
    #We trim down the list by removing each progression location one at a time and seeing if the seed is still beatable, if it is then we remove the location completely
    print('testing playthrough')
    for location in progressionLocations:
        location.printSpoiler()

    progressionLocations.insert(0,openingCutscene)
    progressionLocations.reverse() #Reverse to try removing later items first, as they are more likely to be non-essential
    for location in progressionLocations:
        location.printSpoiler()
    while True:
        removed = False
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
    progressionLocations.reverse() #Reverse back to original order for our final playthrough build
    print('building playthrough')
    playthrough = classr.playthrough()
    win = False
    progressionInventory = []
    for index,location in enumerate(progressionLocations):
        if location.locName == 'Opening Cutscene':
            openingCutscene = progressionLocations.pop(index)
            startingCharacter = classr.inventory(openingCutscene)
            progressionInventory.append(startingCharacter)
            break

    while len(progressionLocations) != 0 and not win:
        itemFound = 0
        spoilerLog.write(str(sphere) + ': \n')
        spoilerLog.write('{ \n')
        if sphere == 0:
            openingCutscene.writeSpoiler(spoilerLog)
            playthrough.build(openingCutscene,sphere)

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

            playthrough.build(location,sphere)
        spoilerLog.write('} \n')

        while len(newInventory) != 0:
            progressionInventory.append(newInventory.pop(0))
        sphere+=1
        
        if sphere >= 100: #Added this safety check in case there are other bugs in spoiler generation
            break 
    
    return playthrough, playthroughAllProgression

def testSeed(progressionLocations,parameters):
    progressionInventory = []
    progressionLocationsToTest = []
    for location in progressionLocations:
        progressionLocationsToTest.append(location)

    while True:
        itemFound = False
        for index,location in enumerate(progressionLocationsToTest):
            if canAccess(progressionInventory,location,parameters) or location.locName == 'Opening Cutscene':
                newLocation = progressionLocationsToTest.pop(index)
                accessibleItem = classr.inventory(newLocation)
                progressionInventory.append(accessibleItem)
                itemFound = True
                if accessibleItem.itemName == 'End the Lacrimosa':
                    return True
                break   
        if not itemFound:
            return False
    