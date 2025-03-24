import os.path
import csv
import sys
import shared.classr as classr
from shared.functions import *

YS8 = getExecutable()
parent_directory = os.path.join(os.path.dirname(sys.executable))

#right now this is only to get rid of some logically problematic beehives but could do more later
def miscFixes():
    deleteHives = ['mons47','mons48','mons49']
    locFile = getLocFile('mp1302t2','map')
    print("Swatting flies: " + locFile)
    monsIDOffset = 26
    monsFlagsOffset = 68
    monsScriptOffset = 92
    
    with open(locFile,"rb") as buffer:
        while (curByte := buffer.read()):
            fileBytes = curByte
                
    for hive in deleteHives:
        hiveLoc = fileBytes.find(hive.encode('utf-8'))
        fileBytes = bytearray(fileBytes)
        fileBytes = writeStringToBytes(fileBytes,hiveLoc + monsIDOffset,'M0225')
        fileBytes = writeStringToBytes(fileBytes,hiveLoc + monsFlagsOffset,'---------P-------')
        fileBytes = writeStringToBytes(fileBytes,hiveLoc + monsScriptOffset,'m0225:m0225')
    
    with open(locFile,"wb") as buffer:
            buffer.write(fileBytes)
            buffer.close()
    
    #executable patches
    exeBytes = readFileIntoBuffer(YS8)

    # remove exp level scaling
    exeBytes[0x29B61C:0x29B61E] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B64F:0x29B651] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B632:0x29B634] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B665:0x29B667] = [0x29,0xC0] #convert opcode sub eax, ebp to sub eax, eax
    
    writeBufferIntoFile(YS8,exeBytes)

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
        disableVanish[0xD739:0xD73D] = [0x00,0x00,0x00,0x00] #Restores original script name

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

def readFileIntoBuffer(path):
    with open(path,"rb") as buffer:
        while (curByte := buffer.read()):
            array = curByte

    return bytearray(array)

def writeBufferIntoFile(path,array):
    with open(path,"wb") as buffer:
        buffer.write(array)
        buffer.close()
    
    return
    
    
