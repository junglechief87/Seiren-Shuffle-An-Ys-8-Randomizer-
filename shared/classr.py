from shared.functions import * 
from randomizer.accessLogic import *

class location:
  def __init__(self,locID,mapID,locRegion,locName,mapCheckID,event,itemID,itemName,quantity,progression,nice,party,crew,item,script):
    self.locID = locID
    self.mapID = mapID
    self.locRegion = locRegion
    self.locName = locName
    self.mapCheckID = mapCheckID
    self.event = event
    self.itemID = itemID
    self.itemName = itemName
    self.quantity = quantity
    self.progression = progression
    self.nice = nice
    self.party = party
    self.crew = crew
    self.item = item
    self.script = script

  def printSpoiler(self):
    print("\t" + self.locRegion + '-' + self.locName + '(' + self.mapCheckID + '): ' + self.itemName + '(' + str(self.itemID) + ')x' + str(self.quantity))

  def writeSpoiler(self,file):
    file.write("\t" + self.locRegion + '-' + self.locName + '(' + self.mapCheckID + '): ' + self.itemName + ' x ' + str(self.quantity) + '\n')

class shuffledLocation(location):
  def __init__(self,location):
    self.locID = location.locID
    self.mapID = location.mapID
    self.locRegion = location.locRegion
    self.locName = location.locName
    self.mapCheckID = location.mapCheckID
    self.event = location.event
    self.script = location.script
     
class inventory(location):
  def __init__(self,location):
    self.itemID = location.itemID
    self.itemName = location.itemName
    self.quantity = location.quantity
    self.progression = location.progression
    self.nice = location.nice
    self.party = location.party
    self.crew = location.crew
    self.item = location.item

class goal:
  def __init__(self, goal, numGoal):
    self.goal = goal
    self.numGoal = numGoal
    
class access(goal):
  def __init__(self, inventoryObjects, goal):
    self.inventoryObjects = inventoryObjects
    self.goal = goal.goal
    self.numGoal = goal.numGoal
    
  def canDoubleJump(self):
    for item in self.inventoryObjects:
      if item.itemID == 741: #archeopteryx wings
        return True
    return False
  
  def canClimb(self):
    for item in self.inventoryObjects:
      if item.itemID == 737: #Grip Gloves
        return True
    return False

  def canSwampWalk(self):
    for item in self.inventoryObjects:
      if item.itemID == 740: #float shoes
        return True
    return False

  def canUndead(self):
    for item in self.inventoryObjects:
      if item.itemID == 742: #Purifying bell
        return True
    return False

  def canUnderwater(self):
    for item in self.inventoryObjects:
      if item.itemID == 738: #hermit's scale
        return True
    return False

  def canMove(self,requiredCrew):
    count = 0
    for item in self.inventoryObjects:
      if item.crew and item.itemName != 'Little Paro': #I used the curran2 and austen2 NPC allocated space to make kong and shoebill count towards village totals, there wasn't another free one for paro but paro is a small bird anyway so it's logical he doesn't count for moving obstacles
        count+=1

    if count >= requiredCrew:
      return True
    else:
      return False

  def canInsect(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Dina':
        return True
    return False

  def canSeeDark(self):
    for item in self.inventoryObjects:
      if item.itemID == 739: #glow stone
        return True
    return False

  def past1(self):
    for item in self.inventoryObjects:
      if item.itemID == 698: #maiden journal
        return True
    return False

  def past2(self):
    for item in self.inventoryObjects:
      if item.itemID == 700: #Blue Seal of Whirling Water
        return True
    return False

  def past3(self):
    for item in self.inventoryObjects:
      if item.itemID == 701: #Green Seal of Roaring Stone
        return True
    return False

  def past4(self):
    for item in self.inventoryObjects:
      if item.itemID == 702: #Golden Seal of Piercing Light
        return True
    return False

  def past5(self):
    for item in self.inventoryObjects:
      if item.itemID == 699: #Frozen Flower
        return True
    return False
      
  def past6(self):
    for item in self.inventoryObjects:
      if item.itemID == 769: #Treasure Chest Key
        return True
    return False
      
  def past7(self):
    for item in self.inventoryObjects:
      if item.itemID == 727: #Shrine Maiden Amulate
        return True
    return False

  def dana(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Dana':
        return True
    return False
  
  def ricotta(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Ricotta':
        return True
    return False
  
  def canShowDiscoveries(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Austin':
        return True
    return False

  def canSmith(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Kathleen':
        return True
    return False
  
  def canShowMap(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Euron':
        return True
    return False
  
  def canAncient(self):
    for item in self.inventoryObjects:
      if item.itemID == 775: #Orichalcum Ore
        return True
    return False

  def fullParty(self):
    count = 0
    for item in self.inventoryObjects:
      if item.party:
        count+=1

    if count >= 6:
      return True
    else:
      return False
    
  def memoCheck(self,requiredMemo):
    count = 0
    for item in self.inventoryObjects:
      if item.itemID == 760 or item.itemID == 761 or item.itemID == 762 or item.itemID == 763: #T memos
        count+=1
    
    if count >= requiredMemo:
        return True
    return False
  
  def canCook(self,requiredRecipes):
    count = 1 #player starts the game with fish soup
    for item in self.inventoryObjects:
      if item.itemID in [569,570,571,572,573,574,575,576,577,578,579]: #Recipe books
        count+=1
    
    if count >= requiredRecipes:
        return True
    return False

  def hasJewels(self,requiredJewels):
    count = 0
    for item in self.inventoryObjects:
      if item.itemID == 476: #Prismatic Jewels
        count+=item.quantity
        
    if count >= requiredJewels:
      return True
    return False
  
  def canFish(self):
    for item in self.inventoryObjects:
      if item.itemID == 629: #Fishing Rod
        return True
    return False

  def goalCheck(self):
    if self.goal == 'Find Crew':
      return self.canMove(self.numGoal)
    
    if self.goal == 'Seiren Escape' and self.hasBoat() and self.hasChart() and self.hasMistilteinn():
      return True

  def readNote1(self):
    for item in self.inventoryObjects:
      if item.itemID == 770: #logbook from east coast cave
        return True
    return False
  
  def mapIncrease(self):
    for item in self.inventoryObjects:
      if item.itemID == 745: #eagle eye orb
        return True
      return False
  
  def hasBoat(self):
    for item in self.inventoryObjects:
      if item.itemID == 779: #ship blueprints
        return True
      return False
    
  def hasMistilteinn(self):
    for item in self.inventoryObjects:
      if item.itemID == 9: #Mistilteinn
        return True
      return False
    
  def hasChart(self):
    for item in self.inventoryObjects:
      if item.itemID == 795: #seiren chart
        return True
      return False
    
class guiInput:
  def __init__(self):
     self.seed = None
     self.smallLuckyBox = None
     self.mediumLuckyBox = None
     self.bigLuckyBox = None
     self.goal = None
     self.numGoal = None
     self.shuffleCrew = None
     self.shuffleItems = None
     self.shuffleParty = None
     self.jewelTrades = None
     self.fishTrades = None
     self.discoveries = None
     self.mapCompletion = None
     self.foodTrades = None
     self.dogiRewards = None
     self.intRewards = None
  
  def getSeed(seed):
    guiInput.seed = seed

  def getLuckyChecks(checkType, num):
    if checkType == 'small':
      guiInput.smallLuckyBox = int(num)
    elif checkType == 'med':
      guiInput.mediumLuckyBox = int(num)
    elif checkType == 'big':
      guiInput.bigLuckyBox = int(num)

  def getGoal(option, num):
    guiInput.goal = option
    guiInput.numGoal = int(num)
  
  def getShuffleLocations(item,party,crew):
    guiInput.shuffleItems = item
    guiInput.shuffleParty = party
    guiInput.shuffleCrew = crew
  
  def getProgressionMods(jewels,fish,disc,map,food,dogiRewards):
    guiInput.jewelTrades = jewels
    guiInput.fishTrades = fish
    guiInput.discoveries = disc
    guiInput.mapCompletion = map
    guiInput.foodTrades = food
    guiInput.dogiRewards = dogiRewards

  def getIntRewards(intRewards):
    guiInput.intRewards = intRewards

class interceptReward:
  def __init__(self,stage,rewards):
    self.stage = stage
    self.rewards = rewards




