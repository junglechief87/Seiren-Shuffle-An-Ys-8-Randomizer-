from shared.functions import * 
from randomizer.accessLogic import *

class location:
  def __init__(self,locID,mapID,locRegion,locName,mapCheckID,event,itemID,itemName,quantity,progression,nice,party,crew,item,script,skill):
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
    self.skill = skill

  def printSpoiler(self):
    print("\t" + self.locRegion + '-' + self.locName + '(' + self.mapCheckID + '): ' + self.itemName + '(' + str(self.itemID) + ')x' + str(self.quantity))

  def writeSpoiler(self,file):
    if self.skill:
      skillName = getSkillInfo(self.itemName)
      file.write("\t" + self.locRegion + '-' + self.locName + '(' + self.mapCheckID + '): ' + skillName[2] + ':' + skillName[1] + '\n')
    elif self.quantity == 1:
      file.write("\t" + self.locRegion + '-' + self.locName + '(' + self.mapCheckID + '): ' + self.itemName + '\n')
    else:
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
    self.skill = location.skill

class access:
  def __init__(self, inventoryObjects, parameters):
    self.inventoryObjects = inventoryObjects
    self.parameters = parameters

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
    #This needs to be checked since Past Dana mode has the player starting with 2 additional characters, Dana's two other forms are counted by the game as castaways.
    if self.parameters.charMode == 'Past Dana':
      requiredCrew -= 2

    #since Kathleen is now progressive with the flame stones she needs to be counted as the first flame stone here.
    for item in self.inventoryObjects:
      if item.itemID == 778: #flame stones
        count+=1
        break
    
    for item in self.inventoryObjects:
      if item.crew and item.itemName != 'Little Paro' and item.itemID != 778: #I used the curran2 and austen2 NPC allocated space to make kong and shoebill count towards village totals, there wasn't another free one for paro but paro is a small bird anyway so it's logical he doesn't count for moving obstacles
        count+=1

    if count >= requiredCrew:
      return True
    else:
      return False

  def hasDina(self):
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
      if item.itemID == 796: #Treasure Chest Key
        return True
    return False
      
  def past7(self):
    for item in self.inventoryObjects:
      if item.itemID == 727: #Shrine Maiden Amulate
        return True
    return False

  def hasDana(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Dana':
        return True
    return False
  
  def hasRicotta(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Ricotta':
        return True
    return False
  
  def hasAdol(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Adol':
        return True
    return False
  
  def hasHummel(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Hummel':
        return True
    return False
  
  def hasSahad(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Sahad':
        return True
    return False
  
  def hasLaxia(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Laxia':
        return True
    return False
  
  def partySize(self, requiredSize):
    count = 0
    for item in self.inventoryObjects:
      if item.itemName in ['Laxia','Sahad','Hummel','Adol','Ricotta','Dana']:
        count+=1

    if count >= requiredSize:
      return True
    else:
      return False

  def canShowDiscoveries(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Austin':
        return True
    return False
  
  def hasEuron(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Euron':
        return True
    return False
  
  def hasSilvia(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Silvia':
        return True
    return False
  
  def hasFlameStones(self,requiredAmount):
    count = 0
    for item in self.inventoryObjects:
      if item.itemID == 778: #flame stones
        count+=1

    if count >= requiredAmount:
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
  
  def hasSpiritRing(self):
    for item in self.inventoryObjects: 
      if item.itemID == 13: #Spirit Ring Celesdia
        return True
    return False
  
  def hasChart(self):
    for item in self.inventoryObjects:
      if item.itemID == 795: #seiren chart
        return True
    return False
  
  def hasJadePendant(self):
    for item in self.inventoryObjects:
      if item.itemID == 206: #Jade Pendant
        return True
    return False
  
  def armletStr(self):
    #check for the two armlets that are in the shuffle not bound by shops, if you hit on the warrior wrist set strength to 20 but keep searching, if you hit on battle armlet kill the search since it's the most powerful anyway.
    strength = 0
    for item in self.inventoryObjects:
      if item.itemID == 271: #warrior wrist
        strength = 20
      if item.itemID == 720: #battle armlet
        strength = 30
        break
    return strength
  
  def accessoryStr(self):
    strength = 0
    accStrList = []
    #we have to loop through the inventory multiple times to find the strongest of each group of items that can't be equipped together.
    ringStr = 0
    for item in self.inventoryObjects:
      if item.itemID == 155 and ringStr < 10: #Blade Ring
        ringStr = 10
      elif item.itemID == 156: #Blade Ring 2
        ringStr = 20
      elif item.itemID == 157: #Blade Ring 3,  Break on blade ring 3 it's the most powerful that can be found.
        ringStr = 30
        break
    
    ancientStr = 0
    for item in self.inventoryObjects:
      if item.itemID in [548,209]: #Stone of Anitquity or Ocean Hogeki, these are the most powerful so we're done if we find them.
        ancientStr = 40 
        break
      elif item.itemID == 727: #maiden amulate
        for item in self.inventoryObjects:
          if item.itemName in ['Laxia','Dana','Ricotta']: #need to confirm a female party member so the player can equip it
            ancientStr = 15
            break
    
    pyriosStr = 0
    for item in self.inventoryObjects:
      if item.itemID == 171: #pyrios charm
        pyriosStr = 5
      elif item.itemID == 172: #pyrios stone
        pyriosStr = 15
        break
    
    for item in self.inventoryObjects:
      if item.itemID == 542: #hope stone
        accStrList.append(20)
      elif item.itemID == 169: #fenrir charm
        accStrList.append(5)
    
    accStrList.append(ringStr)
    accStrList.append(ancientStr)
    accStrList.append(pyriosStr)

    accStrList.sort(reverse=True)
    strength = accStrList[0] + accStrList[1]
    return strength
  
  def hasAlison(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Alison':
        return True
    return False
  
  def hasPearls(self,requiredPearls):
    count = 0
    for item in self.inventoryObjects:
      if item.itemID == 436: #Large Pearls
        count+=item.quantity
        
    if count >= requiredPearls:
      return True
    return False
   
  def canDefeat(self,boss):
    boss = boss + ' Defeated'
    for item in self.inventoryObjects:
      if item.itemName == boss:
        return True
    return False
  
  def hasSkyPsyches(self):
    for item in self.inventoryObjects:
      if item.itemName == 'Psyches of the Sky Era':
        return True
    return False
  
  def hasPsyches(self,goalCount):
    count = 0
    for item in self.inventoryObjects:
      if item.itemName in ['Psyches of the Sky Era','Psyches of the Insectoid Era','Psyches of the Frozen Era','Psyches of the Ocean Era']:
        count+=1
        
    if count >= goalCount:
      return True
    return False

  def hasEssenceKeyStone(self, requiredEssenceKeyStone):
    count = 0
    for item in self.inventoryObjects:
      if item.itemID == 703: #Essence key stone
        count += 1
    
    if count >= requiredEssenceKeyStone:
      return True
    return False
  
  def hasEssenceKeyStone(self, requiredEssenceKeyStone):
    count = 0
    for item in self.inventoryObjects:
      if item.itemID == 703: #Essence key stone
        count += 1
    
    if count >= requiredEssenceKeyStone:
      return True
    return False
  
class guiInput:
  def __init__(self):
    self.seed = None
    self.goal = None
    self.numGoal = None
    self.numOctus = None
    self.charMode = None
    self.shuffleParty = None
    self.shuffleCrew = None
    self.shuffleSkills = None
    self.jewelTrades = None
    self.fishTrades = None
    self.discoveries = None
    self.mapCompletion = None
    self.foodTrades = None
    self.dogiRewards = None
    self.mkRewards = None
    self.silvia = None
    self.maphorash = None
    self.formerSanctuaryCrypt = None
    self.intRewards = None
    self.expMult = None
    self.expGrowth = None
    self.battleLogic = None
    self.progressiveSuperWeapons = None
    self.openOctusPaths = None
    self.extraFlameStones = None
    self.extraIngredients = None
    self.finalBoss = None
    self.theosPhase = None
    self.originPhase = None
    self.carePackage = None
    self.shuffleBgm = None
    self.essenceKeySanity = None
    self.hint = None
  
  def getSeed(seed):
    guiInput.seed = int(seed)

  def getGoal(option,num,numOctus,charMode):
    guiInput.goal = option
    guiInput.numGoal = int(num)
    guiInput.numOctus = int(numOctus)
    guiInput.charMode = charMode
    
  def getShuffleLocations(party,crew,skills):
    guiInput.shuffleParty = party
    guiInput.shuffleCrew = crew
    guiInput.shuffleSkills = skills
  
  def getProgressionMods(jewels,fish,disc,map,food,dogiRewards,mkRewards,silvia,maphorash):
    guiInput.jewelTrades = jewels
    guiInput.fishTrades = fish
    guiInput.discoveries = disc
    guiInput.mapCompletion = map
    guiInput.foodTrades = food
    guiInput.dogiRewards = dogiRewards
    guiInput.mkRewards = mkRewards
    guiInput.silvia = silvia
    guiInput.maphorash = maphorash

  def getOtherToggles(intRewards,battleLogic,superWeapons,openPaths,extraFlameStones,extraIngredients):
    guiInput.intRewards = intRewards
    guiInput.battleLogic = battleLogic
    guiInput.progressiveSuperWeapons = superWeapons
    guiInput.openOctusPaths = openPaths
    guiInput.extraFlameStones = extraFlameStones
    guiInput.extraIngredients = extraIngredients

  def getExpMult(expMult,expGrowth):
    guiInput.expMult = expMult
    expGrowth = expGrowth/100 + 1 #converting to growth rate percent(eg. if set to 5 convert to 1.05)
    guiInput.expGrowth = expGrowth

  def getFinalBoss(finalBoss,theosPhase,originPhase,carePackage):
    guiInput.finalBoss = finalBoss
    guiInput.theosPhase = theosPhase
    guiInput.originPhase = originPhase
    guiInput.carePackage = carePackage
  
  def getShuffleBgm(shuffleBgm):
    guiInput.shuffleBgm = shuffleBgm

  def getEssenceKeySanity(essenceKeySanity):
    guiInput.essenceKeySanity = essenceKeySanity
  
  def getFormerSanctuaryCrypt(formerSanctuaryCrypt):
    guiInput.formerSanctuaryCrypt = formerSanctuaryCrypt
  
  def getHint(hint):
    guiInput.hint = hint
    
class interceptReward:
  def __init__(self,stage,rewards):
    self.stage = stage
    self.rewards = rewards




