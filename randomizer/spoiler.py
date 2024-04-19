import shared.classr as classr
from randomizer.accessLogic import *

def generateSpoiler(shuffledLocations,parameters,goal,blacklistRegion,duplicateChests):
    sphere = 0
    newInventory = []
    foundLocations = []
    accessibleLocation = []
    progressionInventory = []
    win = False
    spoilerLog = open('Ys_8_' + str(parameters.seed) + '.txt', 'w')

    spoilerLog.write("Seed# " + str(parameters.seed) + '\n')
    spoilerLog.write('\n')
    spoilerLog.write('Goal: ' + goal.goal + '\t Number: ' + str(goal.numGoal))
    spoilerLog.write('\n \n \n')
    
    spoilerLog.write("Locations:\n")
    spoilerLog.write('\n')
    spoilerLog.write('\n')
                     
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
    spoilerLog.write('\n')
    
    while len(accessibleLocation) != 0 and not win:
        itemFound = 0
        spoilerLog.write(str(sphere) + ': \n')
        spoilerLog.write('\n')
        spoilerLog.write('{ \n')
        if sphere == 0:
            openingCutscene.writeSpoiler(spoilerLog)

        itemFound = False
        while True:
            itemFound = 0
            for index,location in enumerate(accessibleLocation):
                if canAccess(progressionInventory,location,goal) or location.locRegion.find(blacklistRegion) >= 0:
                    newLocation = accessibleLocation.pop(index)
                    accessibleItem = classr.inventory(newLocation)
                    
                    if accessibleItem.progression and newLocation.locID not in duplicateChests:
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
    
    spoilerLog.close()
