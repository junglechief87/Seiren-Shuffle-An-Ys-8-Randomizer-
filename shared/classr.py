from shared.functions import * 
from randomizer.accessLogic import *

class location:
  def __init__(self,locID,mapID,locRegion,locName,mapCheckID,event,itemID,itemName,quantity,progression,nice,party,crew,item,script,skill,landmark):
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
    self.landmark = landmark

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
    self.landmark = location.landmark

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
    if self.parameters.charMode == 'Past Dana':
      return True
    
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
    if boss != 'Octus Enterance':
      boss = boss + ' Defeated'
    else:
      boss = 'Octus Entered'

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

    if self.parameters.charMode == 'Past Dana':
      for item in self.inventoryObjects:
        if item.itemName in ['Psyches of the Sky Era\Braziers Fight(DANA)','Psyches of the Insectoid Era\Stone Fight(DANA)',\
                                      'Psyches of the Frozen Era\Clairvoyance Fight(DANA)','Psyches of the Ocean Era\Frost Fight(DANA)','Empty Psyches\Magma Fight(DANA)']:
          count+=1
    else:
      for item in self.inventoryObjects:
        if item.itemName in ['Psyches of the Sky Era\Braziers Fight(DANA)','Psyches of the Insectoid Era\Stone Fight(DANA)',\
                                      'Psyches of the Frozen Era\Clairvoyance Fight(DANA)','Psyches of the Ocean Era\Frost Fight(DANA)']:
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
  
  def hasDiscovery(self,discovery):
    for item in self.inventoryObjects:
      if item.itemName == discovery:
        return True
    return False
  
  def hasAnyDiscovery(self,discoveries):
    for item in self.inventoryObjects:
      if item.itemName in discoveries:
        return True
    return False
  
  def discoveryCount(self,requiredDiscoveries):
    count = 0
    for item in self.inventoryObjects:
      if item.itemName in ['Birdsong Rock','Cobalt Crag','Rainbow Falls','Metavolicalis','Parasequoia','Chimney Rock','Indigo Mineral Vein',\
                           'Beached Remains','Field of Medicinal Herbs','Airs Cairn','Zephyr Hill','Lapis Mineral Vein','Beehive','Ship Graveyard',\
                            'Hidden Pirate Storehouse','Magna Carpa','Prismatic Mineral Vein','Unicalamites','Breath Fountain','Ancient Tree','Sky Garden',\
                              'Soundless Hall','Graves of Ancient Heroes','Milky White Vein']:
        count+=1

    if count >= requiredDiscoveries:
      return True
    else:
      return False

  def mapCompletion(self,requiredCompletion):
    #making a list of specific items that contribute towards actual map completion
    mapComplesionItems = ['Maphorash Defeated','Basileus Defeated','Doxa Griel Defeated','Oceanus Defeated',\
                          'Coelacantos Defeated','Pirate Revenant Defeated','Carveros Defeated','Exmetal Defeated','Brachion Defeated','Giasburn Defeated',\
                          'Avalodragil 2 Defeated','Kiergaard Weissman Defeated','Laspisus Defeated','Magamandra Defeated','Gargantula Defeated','Octus Entered'\
                          'Lonbrigius Defeated','Clareon Defeated','Serpentus Defeated','Avalodragil Defeated','Byfteriza Defeated','Birdsong Rock','Cobalt Crag',\
                          'Rainbow Falls','Metavolicalis','Parasequoia','Chimney Rock','Indigo Mineral Vein','Beached Remains','Field of Medicinal Herbs','Airs Cairn',\
                          'Zephyr Hill','Lapis Mineral Vein','Beehive','Ship Graveyard','Hidden Pirate Storehouse','Magna Carpa','Prismatic Mineral Vein',\
                          'Unicalamites','Breath Fountain','Ancient Tree','Sky Garden','Soundless Hall','Graves of Ancient Heroes','Milky White Vein','Gilkyra Encounter']
    
    count = 0
    if self.canMove(6):
      count += 1
    if self.canMove(8):
      count += 1
    if self.canMove(10):
      count += 1
    if self.canMove(11):
      count += 1
    if self.canMove(12):
      count += 1
    if self.canMove(14):
      count += 1
    if self.canMove(15):
      count += 1
    if self.canMove(16):
      count += 1
    if self.canMove(18):
      count += 1
    if self.canMove(20):
      count += 1
    if self.canMove(21):
      count += 1
    if self.canMove(22):
      count += 1
    if self.canMove(23):
      count += 1
    if self.canMove(24):
      count += 1

    for item in mapComplesionItems:
      if item in self.inventoryObjects:
        count += 1
    
    if ((count/(len(mapComplesionItems)+14)) * 100) > requiredCompletion:
      return True
    else:
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
    self.northSideOpen = None
    self.finalBoss = None
    self.theosPhase = None
    self.originPhase = None
    self.carePackage = None
    self.shuffleBgm = None
    self.essenceKeySanity = None
    self.discoverySanity = None
    self.hint = None
    self.adventuringGearHints = None
    self.castawayHints = None
    self.foolishHints = None
    self.partyPool = None
    self.infinityMode = None
    
  def getSeed(self, seed):
    self.seed = int(seed)

  def getGoal(self, option,num,numOctus,charMode):
    self.goal = option
    self.numGoal = int(num)
    self.numOctus = int(numOctus)
    self.charMode = charMode
    
  def getShuffleLocations(self, party,crew,skills,discoverySanity):
    self.shuffleParty = party
    self.shuffleCrew = crew
    self.shuffleSkills = skills
    self.discoverySanity = discoverySanity
  
  def getProgressionMods(self, jewels,fish,disc,map,food,dogiRewards,mkRewards,silvia,maphorash):
    self.jewelTrades = jewels
    self.fishTrades = fish
    self.discoveries = disc
    self.mapCompletion = map
    self.foodTrades = food
    self.dogiRewards = dogiRewards
    self.mkRewards = mkRewards
    self.silvia = silvia
    self.maphorash = maphorash

  def getOtherToggles(self, intRewards,battleLogic,superWeapons,openPaths,extraFlameStones,extraIngredients, northSideOpen, infinityMode):
    self.intRewards = intRewards
    self.battleLogic = battleLogic
    self.progressiveSuperWeapons = superWeapons
    self.openOctusPaths = openPaths
    self.extraFlameStones = extraFlameStones
    self.extraIngredients = extraIngredients
    self.northSideOpen = northSideOpen
    self.infinityMode = infinityMode

  def getExpMult(self, expMult,expGrowth):
    self.expMult = expMult
    expGrowth = expGrowth/100 + 1 #converting to growth rate percent(eg. if set to 5 convert to 1.05)
    self.expGrowth = expGrowth

  def getFinalBoss(self, finalBoss,theosPhase,originPhase,carePackage):
    self.finalBoss = finalBoss
    self.theosPhase = theosPhase
    self.originPhase = originPhase
    self.carePackage = carePackage

  def getMiscSettings(self, shuffleBgm, essenceKeySanity, formerSanctuaryCrypt, hint, adventuringGearHints, castawayHints, foolishHints, 
                      startAdol, startLaxia, startSahad, startHummel, startRicotta, startDana):
    self.shuffleBgm = shuffleBgm
    self.essenceKeySanity = essenceKeySanity
    self.formerSanctuaryCrypt = formerSanctuaryCrypt
    self.hint = hint
    self.adventuringGearHints = adventuringGearHints
    self.castawayHints = castawayHints
    self.foolishHints = foolishHints
    
    self.partyPool = []
    if startAdol: self.partyPool.append('Adol')
    if startLaxia: self.partyPool.append('Laxia')
    if startSahad: self.partyPool.append('Sahad')
    if startHummel: self.partyPool.append('Hummel')
    if startRicotta: self.partyPool.append('Ricotta')
    if startDana: self.partyPool.append('Dana')
    
class interceptReward:
  def __init__(self,stage,rewards):
    self.stage = stage
    self.rewards = rewards




