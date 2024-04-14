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

