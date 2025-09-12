import os.path
import csv
import sys
import shared.classr as classr
import random
from shared.functions import *

YS8 = getExecutable()
parent_directory = os.path.join(os.path.dirname(sys.executable))

#right now this is only to get rid of some logically problematic beehives but could do more later
def miscFixes():
    deleteHives = ['mons47','mons48','mons49']
    locFile = getLocFile('mp1302t2','map')
    monsIDOffset = 26
    monsFlagsOffset = 68
    monsScriptOffset = 92
    
    fileBytes = readFileIntoBuffer(locFile)

    for hive in deleteHives:
        hiveLoc = fileBytes.find(hive.encode('utf-8'))
        fileBytes = bytearray(fileBytes)
        fileBytes = writeStringToBytes(fileBytes,hiveLoc + monsIDOffset,'M0225')
        fileBytes = writeStringToBytes(fileBytes,hiveLoc + monsFlagsOffset,'---------P-------')
        fileBytes = writeStringToBytes(fileBytes,hiveLoc + monsScriptOffset,'m0225:m0225')
    
    writeBufferIntoFile(locFile,fileBytes)
    
    #executable patches
    exeBytes = readFileIntoBuffer(YS8)

    """
    # remove exp level scaling: old but might be useful in the future so commenting it out
    exeBytes[0x29B61C:0x29B61E] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B64F:0x29B651] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B632:0x29B634] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B665:0x29B667] = [0x29,0xC0] #convert opcode sub eax, ebp to sub eax, eax
    """
    # Caps min exp to enemy base exp
    exeBytes[0x28FCFC:0x28FD04] = [0xF3,0x0F,0x10,0x05,0xDC,0x83,0x31,0x00]
    exeBytes[0x28FD0E:0x28FD16] = [0xF3,0x0F,0x10,0x05,0xCA,0x83,0x31,0x00]
    exeBytes[0x29B698:0x29B6A0] = [0xF3,0x0F,0x10,0x05,0x40,0xCA,0x30,0x00]
    
    writeBufferIntoFile(YS8,exeBytes)
    
    # speeds up respawn time of exploding plants to reduce downtime in Oceanus fight
    explosivePlant = parent_directory + "/chr/enemy/m0660/m0660.mtb"
    plantRespawn = readFileIntoBuffer(explosivePlant)
    plantRespawn[0xE05:0xE07] = [0x3C,0x00] #Sets respawn timer on explosive plants in Archeozic Chasme to 1 second instead of 8

    writeBufferIntoFile(explosivePlant,plantRespawn)

def randomizeOctoBosses(parameters):
    random.seed(parameters.seed)
    octus1 = getLocFile('mp6301','map')
    octus2 = getLocFile('mp6302','map')
    octus3 = getLocFile('mp6303','map')
    octus4 = getLocFile('mp6304','map')

    octoMonData = {
        'M0881':{'script':'m0881:m0881', 'data':'m0881/m0881'},
        'M0882':{'script':'m0882:m0882', 'data':'m0882/m0882'},
        'M0883':{'script':'m0883:m0883', 'data':'m0883/m0883'},
        'M0884':{'script':'m0884:m0884', 'data':'m0884/m0884'},
        'M0885':{'script':'m0885:m0885', 'data':'m0885/m0885'},
        'M0886':{'script':'m0886:m0886', 'data':'m0886/m0886'},
        'M0887':{'script':'m0887:m0887', 'data':'m0887/m0887'},
        'M0888':{'script':'m0888:m0888', 'data':'m0888/m0888'},
        'M0889':{'script':'m0889:m0889', 'data':'m0889/m0889'},
        'M0890':{'script':'m0890:m0890', 'data':'m0890/m0890'},
        }
    
    monsIDOffset = 29
    monsScriptOffset = 91

    #values specific to octus1 map
    dataOffsets = [837,869]
    eventOffsets = [5484,5647]
    octus1bytes = readFileIntoBuffer(octus1)
    octus1Mons = ['ev_mons09','ev_mons10']
    for index,octoMon in enumerate(octus1Mons):
        octoMonLoc = octus1bytes.find(octoMon.encode('utf-8'))
        if parameters.openOctusPaths:
            selectedOctoMon = random.choice(list(octoMonData.items()))
        else:
            #this is to restore the original values
            selectedOctoMon = tuple(octoMonData.items())[index+8]
        octus1bytes = writeStringToBytes(octus1bytes, dataOffsets[index], selectedOctoMon[1]['data'])
        octus1bytes = writeStringToBytes(octus1bytes, octoMonLoc + monsIDOffset, selectedOctoMon[0])
        octus1bytes = writeStringToBytes(octus1bytes, octoMonLoc + monsScriptOffset, selectedOctoMon[1]['script'])
        octus1bytes = writeStringToBytes(octus1bytes, eventOffsets[index], selectedOctoMon[1]['script'])

    writeBufferIntoFile(octus1,octus1bytes)

    #values specific to octus2 map
    dataOffsets = [837,869,901]
    eventOffsets = [7426,7589,7752]
    octus2bytes = readFileIntoBuffer(octus2)
    octus2Mons = ['ev_mons01','ev_mons02','ev_mons03']
    for index,octoMon in enumerate(octus2Mons):
        octoMonLoc = octus2bytes.find(octoMon.encode('utf-8'))
        if parameters.openOctusPaths:
            selectedOctoMon = random.choice(list(octoMonData.items()))
        else:
            #this is to restore the original values
            selectedOctoMon = tuple(octoMonData.items())[index]
        octus2bytes = writeStringToBytes(octus2bytes, dataOffsets[index], selectedOctoMon[1]['data'])
        octus2bytes = writeStringToBytes(octus2bytes, octoMonLoc + monsIDOffset, selectedOctoMon[0])
        octus2bytes = writeStringToBytes(octus2bytes, octoMonLoc + monsScriptOffset, selectedOctoMon[1]['script'])
        octus2bytes = writeStringToBytes(octus2bytes, eventOffsets[index], selectedOctoMon[1]['script'])
    
    writeBufferIntoFile(octus2,octus2bytes)

    #values specific to octus3 map
    dataOffsets = [837,869,901]
    eventOffsets = [9460,9623,9786]
    octus3bytes = readFileIntoBuffer(octus3)
    octus3Mons = ['ev_mons04','ev_mons05','ev_mons06']
    for index,octoMon in enumerate(octus3Mons):
        octoMonLoc = octus3bytes.find(octoMon.encode('utf-8'))
        if parameters.openOctusPaths:
            selectedOctoMon = random.choice(list(octoMonData.items()))
        else:
            #this is to restore the original values
            selectedOctoMon = tuple(octoMonData.items())[index+3]
        octus3bytes = writeStringToBytes(octus3bytes, dataOffsets[index], selectedOctoMon[1]['data'])
        octus3bytes = writeStringToBytes(octus3bytes, octoMonLoc + monsIDOffset, selectedOctoMon[0])
        octus3bytes = writeStringToBytes(octus3bytes, octoMonLoc + monsScriptOffset, selectedOctoMon[1]['script'])
        octus3bytes = writeStringToBytes(octus3bytes, eventOffsets[index], selectedOctoMon[1]['script'])
    
    writeBufferIntoFile(octus3,octus3bytes)

    #values specific to octus4 map
    dataOffsets = [837,869]
    eventOffsets = [6037,6200]
    octus4bytes = readFileIntoBuffer(octus4)
    octus4Mons = ['ev_mons07','ev_mons08']
    for index,octoMon in enumerate(octus4Mons):
        octoMonLoc = octus4bytes.find(octoMon.encode('utf-8'))
        if parameters.openOctusPaths:
            selectedOctoMon = random.choice(list(octoMonData.items()))
        else:
            #this is to restore the original values
            selectedOctoMon = tuple(octoMonData.items())[index+6]
        octus4bytes = writeStringToBytes(octus4bytes, dataOffsets[index], selectedOctoMon[1]['data'])
        octus4bytes = writeStringToBytes(octus4bytes, octoMonLoc + monsIDOffset,selectedOctoMon[0])
        octus4bytes = writeStringToBytes(octus4bytes, octoMonLoc + monsScriptOffset, selectedOctoMon[1]['script'])
        octus4bytes = writeStringToBytes(octus4bytes, eventOffsets[index], selectedOctoMon[1]['script'])
    
    writeBufferIntoFile(octus4,octus4bytes)

def pastDanaFixes(enable):
    bullfrodon = parent_directory + "/chr/enemy/m2102/m2102.mtb"
    lonbrius = parent_directory + "/chr/enemy/b101/b101b.mtb"
    deanafrog = parent_directory + "/chr/enemy/m0884/m0884.mtb"
    melaiduma = parent_directory + "/chr/enemy/b170/b170.mtb"
    originOfLife = parent_directory + "/chr/enemy/b010/b010.mtb"
    theos = parent_directory + "/chr/enemy/b021/b021.mtb"

    # Remove Bullfrodon swallow if Past Dana Mode on or restore script names if not ######
    disableSwallow = readFileIntoBuffer(bullfrodon)

    if enable:
        disableSwallow[0xCA6:0xCAA] = [0x5F,0x4F,0x46,0x46] #Spells _OFF so it's easy to find in the file, changes the function name so it won't be able to call it from the enemy script
    else:
        disableSwallow[0xCA6:0xCAA] = [0x00,0x00,0x00,0x00] #Restores original script name

    writeBufferIntoFile(bullfrodon,disableSwallow)

    # Remove Lonbrius bites if Past Dana Mode on or restore script names if not ######
    disableBites = readFileIntoBuffer(lonbrius)

    if enable:
        disableBites[0x3753:0x3757] = [0x5F,0x4F,0x46,0x46] #Spells _OFF so it's easy to find in the file, changes the function name so it won't be able to call it from the enemy script
        disableBites[0x3BFE:0x3C02] = [0x5F,0x4F,0x46,0x46]
        disableBites[0x4222:0x4226] = [0x5F,0x4F,0x46,0x46]
    else:
        disableBites[0x3753:0x3757] = [0x00,0x00,0x00,0x00] #Restores original script name
        disableBites[0x3BFE:0x3C02] = [0x00,0x00,0x00,0x00] 
        disableBites[0x4222:0x4226] = [0x00,0x00,0x00,0x00] 

    writeBufferIntoFile(lonbrius,disableBites)

    # Remove Deanafrog swallow if Past Dana Mode on or restore script names if not ######
    disableSwallow2 = readFileIntoBuffer(deanafrog)

    if enable:
        disableSwallow2[0xCA7:0xCAB] = [0x5F,0x4F,0x46,0x46] #Spells _OFF so it's easy to find in the file, changes the function name so it won't be able to call it from the enemy script
    else:
        disableSwallow2[0xCA7:0xCAB] = [0x00,0x00,0x00,0x00] #Restores original script name

    writeBufferIntoFile(deanafrog,disableSwallow2)

    # Remove Origin of Life vanish if Past Dana Mode on or restore script names if not ######
    disableVanish = readFileIntoBuffer(originOfLife)

    if enable:
        disableVanish[0xD739:0xD73D] = [0x5F,0x4F,0x46,0x46] #Spells _OFF so it's easy to find in the file, changes the function name so it won't be able to call it from the enemy script
    else:
        disableVanish[0xD739:0xD739] = [0x00,0x00,0x00,0x00] #Restores original script name

    writeBufferIntoFile(originOfLife,disableVanish)

    # Remove Melaiduma vanish slash if Past Dana Mode on or restore script names if not ######
    disableVanishSlash = readFileIntoBuffer(melaiduma)

    if enable:
        disableVanishSlash[0x75E9:0x75ED] = [0x5F,0x4F,0x46,0x46] #Spells _OFF so it's easy to find in the file, changes the function name so it won't be able to call it from the enemy script
    else:
        disableVanishSlash[0x75E9:0x75ED] = [0x00,0x00,0x00,0x00] #Restores original script name

    writeBufferIntoFile(melaiduma,disableVanishSlash)

    # Remove Theos bind attack if Past Dana Mode on or restore script names if not ######
    disableBind = readFileIntoBuffer(theos)

    if enable:
        disableBind[0x4A78:0x4A7C] = [0x5F,0x4F,0x46,0x46] #Spells _OFF so it's easy to find in the file, changes the function name so it won't be able to call it from the enemy script
        disableBind[0x4CF2:0x4CF6] = [0x5F,0x4F,0x46,0x46]
    else:
        disableBind[0x4A78:0x4A7C] = [0x00,0x00,0x00,0x00] #Restores original script name
        disableBind[0x4CF2:0x4CF6] = [0x00,0x00,0x00,0x00]

    writeBufferIntoFile(theos, disableBind)

def makeResourceDropsGuaraneteed():
    resourcePointDropTable = parent_directory + "/text/itempt.tbb"
    makeDropsGuaranteed = readFileIntoBuffer(resourcePointDropTable)
    resourceStrings = ['ICON3D_MT_N1_STONE','ICON3D_MT_N1_WOOD','ICON3D_MT_N1_FLOWER', 'ICON3D_US_MANGO','ICON3D_US_BERRY','ICON3D_US_DRAGONFRUIT']
    viableRewards = {'ICON3D_MT_N1_STONE':['ICON3D_MT_N2_STONE','ICON3D_MT_N3_STONE','ICON3D_MT_N4_STONE','ICON3D_MT_R2_STONE','ICON3D_MT_R4_STONE'],
                     'ICON3D_MT_N1_WOOD': ['ICON3D_MT_N2_WOOD','ICON3D_MT_N3_WOOD','ICON3D_MT_N4_WOOD','ICON3D_MT_R2_WOOD','ICON3D_MT_R4_WOOD'],
                     'ICON3D_MT_N1_FLOWER': ['ICON3D_MT_N2_FLOWER','ICON3D_MT_N3_FLOWER','ICON3D_MT_N4_FLOWER','ICON3D_MT_R1_FLOWER','ICON3D_MT_R3_FLOWER','ICON3D_MT_R5_FLOWER'],
                     'ICON3D_US_MANGO': ['ICON3D_US_MANGO_S'],
                     'ICON3D_US_BERRY': ['ICON3D_US_BERRY_S'],
                     'ICON3D_US_DRAGONFRUIT': ['ICON3D_US_DRAGONFRUIT_S']}
    
    for resourceString in resourceStrings:
        currentPos = 1263
        while makeDropsGuaranteed.find(resourceString.encode('utf-8'), currentPos) != -1:
            bottomTierResourceIndex = makeDropsGuaranteed.find(resourceString.encode('utf-8'), currentPos)
            stringSize = len(resourceString)
            currentPos = currentPos + stringSize
            
            # process higher tier rewards values
            higherTierResourceOffset = makeDropsGuaranteed[bottomTierResourceIndex+stringSize:].find('ICON3D_'.encode('utf-8')) + stringSize
            higherTierResourceIndex = higherTierResourceOffset + bottomTierResourceIndex
            higherTierResourceValue = makeDropsGuaranteed[higherTierResourceIndex:higherTierResourceIndex+stringSize]

            # process rare rewards values
            rareResourceOffset = makeDropsGuaranteed[higherTierResourceIndex+stringSize:].find('ICON3D_'.encode('utf-8')) + stringSize
            rareResourceIndex = rareResourceOffset + higherTierResourceIndex
            rareResourceValue = makeDropsGuaranteed[rareResourceIndex:rareResourceIndex+stringSize]
            
            # write new values and make adjustments for special cases
            if higherTierResourceValue.decode('utf-8') in viableRewards[resourceString]:
                makeDropsGuaranteed[bottomTierResourceIndex:bottomTierResourceIndex+stringSize] = higherTierResourceValue
                
            if rareResourceValue.decode('utf-8') in viableRewards[resourceString]:
                makeDropsGuaranteed[higherTierResourceIndex:higherTierResourceIndex+stringSize] = rareResourceValue
                

    writeBufferIntoFile(resourcePointDropTable,makeDropsGuaranteed)

def newExpMult(parameters):
    statusFileLoc = parent_directory + '/text/en/status.csv'
    defaultExpValues = {'ADOL': {'EXPMIN':100, 'EXPMAX':500000},
                        'LAXIA':{'EXPMIN':95, 'EXPMAX':450000},
                        'SAHAD':{'EXPMIN':105, 'EXPMAX':550000},
                        'HUMMEL':{'EXPMIN':90, 'EXPMAX':420000},
                        'RICOTTA':{'EXPMIN':97, 'EXPMAX':480000},
                        'DANA':{'EXPMIN':102, 'EXPMAX':520000},}
    
    monsterNestExpValues = {'G0001':{'EXPMIN':300, 'EXPMAX':300},
                        'G0002':{'EXPMIN':310, 'EXPMAX':310},
                        'G0003':{'EXPMIN':320, 'EXPMAX':320},
                        'G0004':{'EXPMIN':330, 'EXPMAX':330},
                        'G0005':{'EXPMIN':340, 'EXPMAX':340},
                        'G0006':{'EXPMIN':350, 'EXPMAX':350},
                        'G0007':{'EXPMIN':360, 'EXPMAX':360},
                        'G0008':{'EXPMIN':370, 'EXPMAX':370},
                        'G0009':{'EXPMIN':380, 'EXPMAX':380},}

    with open (statusFileLoc, 'r', encoding='utf-8') as csvFile:
        statusFile = csv.DictReader(csvFile,delimiter='\t',lineterminator='\n',strict=True)
        newStatusFile = []
        fieldNames = []
        for row in statusFile:
            # csv doesn't read in field names until it begins reading rows. 
            # so to gather the field names for later use we need to do it during the first iteration of the loop.
            if len(fieldNames) == 0:
                fieldNames = statusFile.fieldnames
            if row['キャラＩＤ'] in defaultExpValues.keys():
                row['EXPMIN'] = int(defaultExpValues[row['キャラＩＤ']]['EXPMIN'] / (parameters.expMult))
                row['EXPMAX'] = int(defaultExpValues[row['キャラＩＤ']]['EXPMAX'] / (parameters.expMult))
            if row['キャラＩＤ'] in monsterNestExpValues.keys():
                row['EXPMIN'] = int(monsterNestExpValues[row['キャラＩＤ']]['EXPMIN'])
                row['EXPMAX'] = int(monsterNestExpValues[row['キャラＩＤ']]['EXPMAX'])
            newStatusFile.append(row)
        csvFile.close()

        with open (statusFileLoc, 'w', encoding='utf-8') as csvFile:
            writer = csv.DictWriter(csvFile,fieldNames,delimiter='\t',lineterminator='\n',strict=True)
            writer.writeheader()
            writer.writerows(newStatusFile)
            csvFile.close()
    

def readFileIntoBuffer(path):
    with open(path,"rb") as buffer:
        while (curByte := buffer.read()):
            array = curByte

    return bytearray(array)

def writeBufferIntoFile(path,array):
    with open(path,"wb") as buffer:
        buffer.write(array)
        buffer.close()