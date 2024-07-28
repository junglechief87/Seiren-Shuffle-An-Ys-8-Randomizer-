import os.path
import csv
import shared.classr as classr
from shared.functions import *

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
    ys8 = getExecutable()

    with open(ys8,"rb") as buffer:
        while (curByte := buffer.read()):
            exeBytes = curByte

    exeBytes = bytearray(exeBytes)
    # remove exp level scaling
    exeBytes[0x29B61C:0x29B61E] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B64F:0x29B651] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B632:0x29B634] = [0x29,0xC9] #convert opcode sub ecx, ebp to sub ecx, ecx
    exeBytes[0x29B665:0x29B667] = [0x29,0xC0] #convert opcode sub eax, ebp to sub eax, eax
 
    with open(ys8,"wb") as buffer:
        buffer.write(exeBytes)
        buffer.close()
    
    
