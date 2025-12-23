import os.path
import csv
import shared.classr as classr
import sys
encode = "utf-8"
sourceScript = "rng"
current_directory = os.path.dirname(__file__)
#The top versoin is used for running the randomizer from source, the bottom version of the loop is for the executable compile, comment and uncomment accordingly.
#parent_directory = os.path.join(os.path.dirname(__file__),os.pardir)
parent_directory = os.path.join(os.path.dirname(sys.executable))

_cache = None  # Global variable for lazy loading
    
def getLocations():
    with open(current_directory + "/database/location.csv",encoding = encode) as locDB:
        
        locRows = csv.DictReader(locDB)
        locations = []
        for row in locRows:
            locID = int(row['locID'])
            mapID = row['mapID']
            locRegion = row['locRegion']
            locName = row['locName']
            mapCheckID = row['mapCheckID']
            event = bool(int(row['event']))
            itemID = int(row['itemID'])
            itemName = row['itemName']
            quantity = int(row['quantity'])
            progression = bool(int(row['progression']))
            nice = bool(int(row['nice']))
            party = bool(int(row['party']))
            crew = bool(int(row['crew']))
            item = bool(int(row['item']))
            script = row['script']
            skill = bool(int(row['skill']))
            landmark = bool(int(row['landmark']))
            entrance = bool(int(row['entrance']))
            exit = bool(int(row['exit']))
     
            locationObject = classr.location(locID,mapID,locRegion,locName,mapCheckID,event,itemID,itemName,quantity,progression,nice,party,crew,item,script,skill,landmark,entrance,exit)
            locations.append(locationObject)
            
    locDB.close()
    return locations

#def getItems:

def getIcon(itemID):
    with open(current_directory + "/database/itemTable.csv",encoding = encode) as itemDB:
        itemRows = csv.DictReader(itemDB) 
        for itemRow in itemRows:
            if int(itemRow['ID']) == itemID:
                icon = itemRow['3DIcon']
                itemDB.close
                return icon

def getSkillInfo(itemName):
    with open(current_directory + "/database/skillTable.csv",encoding = encode) as skillDB:
        skillRows = csv.DictReader(skillDB) 
        for skillRow in skillRows:
            if skillRow['skillID'] == itemName:
                character = skillRow['character']
                skillName = skillRow['skillName']
                skillDB.close
                if character == 'PARTY_ADOL':
                    characterName = 'Adol'  
                elif character == 'PARTY_LAXIA':
                    characterName = 'Laxia'  
                elif character == 'PARTY_SAHAD':
                    characterName = 'Sahad'  
                elif character == 'PARTY_HUMMEL':
                    characterName = 'Hummel'  
                elif character == 'PARTY_RICOTTA':
                    characterName = 'Ricotta'  
                elif character == 'PARTY_DANA':
                    characterName = 'Dana'  

                return character,skillName,characterName
            
def getLocFile(mapID, fileType):
    cache = load_cache()  # Loads cache only on first call
    if (mapID, fileType) in cache:
        return cache[(mapID, fileType)]

    #The top versoin of the loop is used for running the randomizer from source, the bottom version of the loop is for the executable compile, comment and uncomment accordingly.
    if fileType == 'script':
        #for root, dirs, files in os.walk(os.path.join(os.path.dirname(__file__),os.pardir) + "/script/"):
        for root, dirs, files in os.walk(os.path.join(os.path.dirname(sys.executable)) + "/script/"):
            for file in files:
                if file.endswith('.scp') and file.find(mapID) >= 0:
                    return os.path.join(root, file)
                
    elif fileType == 'map':
        #for root, dirs, files in os.walk(os.path.join(os.path.dirname(__file__),os.pardir) + "/map/"):
        for root, dirs, files in os.walk(os.path.join(os.path.dirname(sys.executable)) + "/map/"):
            for file in files:
                if file.endswith('.arb') and file.find(mapID) >= 0:
                    return os.path.join(root, file)
    else:
        raise Exception('Must specify either script or map for file retrieval or specify correct mapID')

def getExecutable():
    return os.path.join(parent_directory, "ys8.exe")

def buildLocScripts(locID, source):

    #only build on set of scripts for river valley long shoreline, chests for dawn version share flags
    if locID == 47:
        locID = 44
    elif locID == 48:
        locID = 45
    elif locID == 49:
        locID = 46
        
    if source:
        scriptCall = sourceScript + ':' + str(locID).zfill(4)
    else:
        scriptCall = str(locID).zfill(4)
    return scriptCall

def writeStringToBytes(byteArray,offset,bytesToWrite):
    bytesToWrite = bytesToWrite.encode('utf-8')
    curOffset = offset
    
    for byte in bytesToWrite:
        byteArray[curOffset] = byte
        curOffset+=1

    return byteArray

def combineShuffledLocAndItem(shuffledLocation,inventory):
    locID = shuffledLocation.locID
    mapID = shuffledLocation.mapID
    locRegion = shuffledLocation.locRegion
    locName = shuffledLocation.locName
    mapCheckID = shuffledLocation.mapCheckID
    event = shuffledLocation.event
    itemID = inventory.itemID
    itemName = inventory.itemName
    quantity = inventory.quantity
    progression = inventory.progression
    nice = inventory.nice
    party = inventory.party
    crew = inventory.crew
    item = inventory.item
    script = shuffledLocation.script
    skill = inventory.skill
    landmark = inventory.landmark
    entrance = inventory.entrance
    exit = inventory.exit

    return classr.location(locID,mapID,locRegion,locName,mapCheckID,event,itemID,itemName,quantity,progression,nice,party,crew,item,script,skill,landmark,entrance,exit)

def copyLocationToNewLoc(location):
    locID = location.locID
    mapID = location.mapID
    locRegion = location.locRegion
    locName = location.locName
    mapCheckID = location.mapCheckID
    event = location.event
    itemID = location.itemID
    itemName = location.itemName
    quantity = location.quantity
    progression = location.progression
    nice = location.nice
    party = location.party
    crew = location.crew
    item = location.item
    script = location.script
    skill = location.skill
    landmark = location.landmark
    entrance = location.entrance
    exit = location.exit

    return classr.location(locID,mapID,locRegion,locName,mapCheckID,event,itemID,itemName,quantity,progression,nice,party,crew,item,script,skill,landmark,entrance,exit)

def getIntRewards():
    with open(current_directory + "/database/interceptionRewards.csv",encoding = encode) as rewardDB:
        
        rewardRows = csv.DictReader(rewardDB)
        intRewards = []

        for row in rewardRows:
            stage = row['stage']

            rewards = []
            for index,col in enumerate(row):
                if row[col] == '' or row[col] == None:
                    break
                elif index == 0:
                    pass
                else: 
                    rewards.append(row[col])

            stageReward = classr.interceptReward(stage,rewards)
            intRewards.append(stageReward)
            
    rewardDB.close()
    return intRewards

def getCharacterJoinLv(character):
    lvScript = ''
    for lv in range(1,100):
        if lv == 1:
            lvScript = lvScript + "\tif(LEADER.CHRWORK[CWK_LV] ==" + str(lv) + "){SetLevel(" + character + "," + str(lv) + ")} \n"
        elif lv == 99:
            lvScript = lvScript + "\telse{SetLevel(" + character + "," + str(lv) + ")} \n"
        else:
            lvScript = lvScript + "\telse if(LEADER.CHRWORK[CWK_LV] ==" + str(lv) + "){SetLevel(" + character + "," + str(lv) + ")} \n"

    return lvScript


def load_cache():
    """
    Reads cache.txt and converts it into a dictionary.
    This is used to improve time efficiency of findLocFile
    """
    global _cache
    if _cache is None:  # Load only if it's not already loaded
        _cache = {}  # Initialize empty dictionary
        path = './shared/database/locFileCache.txt'
        if os.path.exists(path):
            with open(path, "r", encoding="utf-8") as f:
                for line in f:
                    parts = line.split(",")
                    map_id = parts[0].strip()
                    file_type = parts[1].strip()
                    file_path = parts[2].strip()
                    _cache[(map_id, file_type)] = file_path  # Convert "(mapID, fileType)" back to tuple
    return _cache