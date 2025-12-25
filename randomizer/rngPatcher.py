import csv
import os.path
import shared.classr as classr
import random
from shared.functions import *  
from randomizer.crew import *
from randomizer.shuffle import *
from randomizer.gameStartFunctions import *
from patch.chestPatcher import *
from randomizer.audioShuffle import *
from patch.miscPatches import pastDanaFixes, randomizeOctoBosses, newExpMult
from randomizer.buildEntrances import *

#This is essentially the BnB for how this rando works. This script writes a big .scp file, the game's native scripting files, that we call for all randomized locations (as well as some other important functions for a rando)
#This takes in the game's shuffled list of loctions and then builds the scripts.
#We named our script file rng because we need something short, our script calls from the chests are limited to 8 characters so our standard format for script call is rng:(locID where locID is a 4 digit id).
#Plus rng.scp is a fitting filename for a rando.
patchFile = ''
scpIncludeList = ['#include "inc/mons.h"','#include "inc/def.h"','#include "inc/efx.h"','#include "inc/flag.h"','#include "inc/se.h"',
                  '#include "inc/scr_inc.h"','#include "inc/3dicon.h"','#include "inc/skilldef.h"','#include "inc/vo.h"','#include "inc/temp/rng.h"'] #standard set of header files used in most Ys 8 .scp files
genericMessage = " Obtained."
crewMessage = " joined the Village."
partyMessage = " joined the Party."
skillMessage = " has learned skill #2C"
landmarkMessage = ' discovered.'
rngScriptFile = getLocFile('rng','script')

def rngPatcherMain(parameters):
    global patchFile
    global spoilerLog
    patchFile = ''
    spoilerLog = open("Ys_8_" + str(parameters.seed) + ".txt", "a")

    if parameters.charMode == 'Past Dana':
        global partyMessage 
        partyMessage = " joined the Village."
        pastDanaFixes(True)  
    else:
        pastDanaFixes(False)

    if parameters.shuffleBgm:
        randomize_bgmtbl(parameters.seed)
    else:
        restore_original_bgm()
    
    shuffledLocations, playthrough, playthroughAllProgression = shuffleLocations(parameters) #shuffle and fill functions run from this call

    for inc in scpIncludeList:
        patchFile = patchFile + inc + '\n'
    
    duplicateChests = [47,48,49,179]
    for location in shuffledLocations:
        if location.locID not in duplicateChests: #no need to build out functions for the same location twice, these chests share flags with the not dawn version
            #cleanup the placeholders the game had for chests without scripts
            if location.script != "--------":
                script = ('EventCue("' + location.script + '")')
            else:
                script = ""
                
            if location.locID == 429: #location ID 429 opening cutscene
                patchFile = patchFile + buildStartParameters(location,parameters) 
                patchFile = patchFile + manageEarlyGameParty(location)
                patchFile = patchFile + soloStartingCharacterEvent(location) 

            if location.itemID == 778:#flame stone: moving this here as we're now mixing items and crew into the shop upgrade chain and it makes the most sense to have the upgrade function do any calling of necessary item/crew scripts
                patchFile = patchFile + shopUpgrades(location, script)
            elif location.item: 
                patchFile = patchFile + genericItemMessage(location,script,parameters)      
            elif location.crew:
                patchFile = patchFile + buildCrewLocation(location,script)
            elif location.skill:
                patchFile = patchFile + buildSkillLocation(location,script)
            elif location.landmark:
                patchFile = patchFile + buildLandmarks(location,script)

    bossScalingScript, finalNonGoalBossLevel, bossLevelsDictByRegion = bossScaling(playthroughAllProgression,parameters)
    patchFile = patchFile + bossScalingScript

    if parameters.goal == 'Release the Psyches':
        patchFile = patchFile + buildPsyches(shuffledLocations,parameters,bossLevelsDictByRegion,finalNonGoalBossLevel)
    if parameters.formerSanctuaryCrypt:
        patchFile = patchFile + buildFSCWarp()

    patchFile = patchFile + interceptionHandler(parameters)
    patchFile = patchFile + jewelTrade(shuffledLocations)
    patchFile = patchFile + octusGoal(parameters)
    if parameters.openOctusPaths:
        patchFile = patchFile + octoBosses(parameters, finalNonGoalBossLevel)
    else:
        #this is to restore the original values
        randomizeOctoBosses(parameters)
    patchFile = patchFile + goal(parameters)
    patchFile = patchFile + endingHandler(parameters,finalNonGoalBossLevel)
    if parameters.entranceShuffle:
        patchFile = patchFile + buildEntrances()
    with open(rngScriptFile, 'w', encoding = 'Shift-JIS') as fileToPatch: #build the entire rng file from one big string
        fileToPatch.write(patchFile)
        fileToPatch.close()

    expMult(parameters)
    
    spoilerLog.flush()
    spoilerLog.close()

#function used for all non-person item function generation
def genericItemMessage(location,vanillaScript,parameters):    
    scriptName = buildLocScripts(location.locID,False)
    itemIcon = getIcon(location.itemID)
    itemQuantity = location.quantity
    #'Maiden Journal','Blue Seal of Whirling Water','Green Seal of Roaring Stone','Golden Seal of Piercing Light','Treasure Chest Key','Frozen Flower','Shrine Maiden Amulate'
    danaPastEventsItems = [698,700,701,702,796,699,727]
    script = ""

    #if the item is progression let's do the jingle
    if location.progression:
        itemSE = 'ITEMMSG_SE_JINGLE'
    else:
        itemSE = 'ITEMMSG_SE_NORMAL'

    #unique item functions that will need additional scripting when the item is recieved
    if location.itemID == 739: #glow stone
        script = script + makeGlowStoneUseful()
    elif location.itemID in danaPastEventsItems:
        script = script + danaPastEvents(location.itemID)
    elif location.itemID == 9: #mistilteinn
        script = script + sopEvent(parameters)
        #this solution for unique message on the progressive weapons is a little heavy handed but it should resolves all issues I had with them
        if parameters.progressiveSuperWeapons:
            if location.event:   
                getItemFunction =  """
function "{0}"
{{
    GetItem(ICON3D_WP_ADOL_009,1) //rusty sword is the best representation of broken weapon I can think of
    GetItemMessageExPlus(-1,1,{1},"#2CBroken Mistilteinn#0C Obtained.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {2}
}}
"""  
            else:
                fillChest(location,146,location.quantity)

                getItemFunction =  """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    {2}
    ResetStopFlag(STOPFLAG_TALK)
}}
""" 
            return getItemFunction.format(scriptName,itemSE,script)
        
    elif location.itemID == 13: #Spirit Ring Celesdia
        script = script + spiritRingEvent(parameters)
        if parameters.progressiveSuperWeapons:
            if location.event:   
                getItemFunction =  """
function "{0}"
{{
    GetItem(ICON3D_WP_ADOL_009,1) //rusty sword is the best representation of broken weapon I can think of
    GetItemMessageExPlus(-1,1,{1},"#2CBroken Spirit Ring#4C Obtained.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {2}
}}
"""  
            else:
                fillChest(location,147,location.quantity)
                getItemFunction =  """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    {2}
    ResetStopFlag(STOPFLAG_TALK)
}}
""" 
            return getItemFunction.format(scriptName,itemSE,script)
    elif location.itemID == 770: #logbook from east coast cave
        script = script + pirateShipDocks()
    elif location.itemID in [760,761,762,763]: #T memos
        script = script + interceptUnlock()
    elif location.itemID == 629: #fishing rod
        startingBait = """
    GetItem(ICON3D_FISHBAIT_WORM,30)
    """
        script = script + startingBait
    elif location.itemID == 779: #ship blueprints
        buildBoat = """
    SetFlag(GF_SUBEV_06_1111_LOOK_BOAT,1)
    """
        script = script + buildBoat
    elif location.itemID in [569,570,571,572,573,574,575,576,577,578,579] and parameters.extraIngredients: #item IDs for recipes
        script = script + recipeIngredients(location.itemID)
    
    if location.itemID in [750,751,752,753,754,755,760,761,762,763] and parameters.memoHints:
        script = script + memoHints(location.itemID)
        
    message = genericMessage
    script =  script + vanillaScript #append the original chest scripts to the end of the function

     #if the location is not inside an event we want to freeze the player while they receive the item. This prevents some awkwardness, it's strictly for polish.
     #setting the talk flags and then unsetting them during events can break many events though, so we don't want to do it there. Many events already have these flags set at their starts and ends.
    if location.event:   
        getItemFunction =  """
function "{0}"
{{
    GetItem({1},{2})
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {5}
}}
"""  
    else:
        fillChest(location,location.itemID,location.quantity)
        getItemFunction =  """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    {5}
   ResetStopFlag(STOPFLAG_TALK)
}}
"""   
    if location.itemID == 218:
        #Adding the other 2 medals to the slash medal check
        script =  script + """
    GetItem(ICON3D_AC_068,1)
    GetItem(ICON3D_AC_069,1)
            """ 
    if location.itemID == 206: #Jade pendant
        if parameters.formerSanctuaryCrypt:
            script = script + """
    SetFlag(SF_SYS_CLEARED, 1)
    SetFlag(GF_SUBEV_PAST_07_CLEAR, 1)
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The path to the Sanctuary has opened.",0,0)
    WaitPrompt()
    WaitCloseWindow()
                """

    return getItemFunction.format(scriptName,itemIcon,itemQuantity,itemSE,message,script)

#function used for all people function generations
def buildCrewLocation(location,script):
    scriptName = buildLocScripts(location.locID,False)
    itemIcon = -1
    itemID = 0
    itemQuantity = 1
    itemSE = 'ITEMMSG_SE_BETTER' #Placeholder item jingles in chests
    
    if location.event:
        itemSE = 'ITEMMSG_SE_JINGLE' 

    if location.party:
        message = "#2C" + location.itemName + "#4C" + partyMessage
        itemID = 145
    elif location.crew:
        message = "#2C" + location.itemName + "#4C" + crewMessage
        itemID = 143
        
    crewFlags = getCrewFlags(location.itemName)

     #if the location is not inside an event we want to freeze the player while they receive the item. This prevents some awkwardness, it's strictly for polish.
     #setting the talk flags and then unsetting them during events can break many events though, so we don't want to do it there. Many events already have these flags set at their starts and ends.    
    if location.event:
        getCrewFunction = """
function "{0}"
{{
    
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {5}
    {6}
}}
"""
    else: 
        fillChest(location,143,1)
        getCrewFunction = """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {5}
    {6}
    ResetStopFlag(STOPFLAG_TALK)
}}
"""   
    return getCrewFunction.format(scriptName,itemIcon,itemQuantity,itemSE,message,crewFlags,script)

#now skills are in the rando and they need a third special handler for their locations
def buildSkillLocation(location,script):
    scriptName = buildLocScripts(location.locID,False)
    itemIcon = -1
    itemQuantity = 1
    itemSE = 'ITEMMSG_SE_NORMAL'
    skillInfo = getSkillInfo(location.itemName) #returns tuple: character,skill name,character name
    characterName = skillInfo[2]
    message = "#4C" + characterName + skillMessage + skillInfo[1] + "#4C."
    character = skillInfo[0]

    if location.locRegion == 'startingSkill': #for starting skills just go ahead and give the skill, don't bombard the player with messages each time they get a character.
        getSkillFunction = """
function "{0}"
{{
    GetSkill({6},{7},1)
}}
"""
    elif location.event:
        getSkillFunction = """
function "{0}"
{{

    GetSkill({6},{7},1)
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {5}
}}
"""
    else: 
         fillChest(location,144,1)
         getSkillFunction = """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    
    GetSkill({6},{7},1)
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()  
    {5}
    ResetStopFlag(STOPFLAG_TALK)
}}
"""  
    return getSkillFunction.format(scriptName,itemIcon,itemQuantity,itemSE,message,script,character,location.itemName)

def recipeIngredients(itemID):
    if itemID == 569: #omlet
        ingredients = """
        GetItem(ICON3D_FD_LAND_EGG,2)
        GetItem(ICON3D_FD_MUSHROOM,2)
        GetItem(ICON3D_FD_SEA_SHELLFISH,2)
        """
        return ingredients
    elif itemID == 570: #ratatouille
        ingredients = """
        GetItem(ICON3D_FD_LAND_HONEY,2)
        GetItem(ICON3D_FD_MEAT_01,2)
        GetItem(ICON3D_FD_VG_EGGPLANT,2)
        """
        return ingredients
    elif itemID == 571: #meuniere
        ingredients = """
        GetItem(ICON3D_FD_WHEAT,2)
        GetItem(ICON3D_FD_MEAT_02,2)
        GetItem(ICON3D_FD_MUSHROOM,2)
        GetItem(ICON3D_FD_VG_PAPRIKA,2)
        """
        return ingredients
    elif itemID == 572: #quiche
        ingredients = """
        GetItem(ICON3D_FD_WHEAT,2)
        GetItem(ICON3D_FD_LAND_EGG,2)
        GetItem(ICON3D_FD_MEAT_02,2)
        GetItem(ICON3D_FD_SEA_SHELLFISH,2)
        """
        return ingredients
    elif itemID == 573: #cabbage
        ingredients = """
        GetItem(ICON3D_FD_SEA_SALT,2)
        GetItem(ICON3D_FD_LAND_HONEY,2)
        GetItem(ICON3D_FD_MEAT_01,2)
        GetItem(ICON3D_FD_VG_CABBAGE,2)
        """
        return ingredients
    elif itemID == 574: #mushroom-wrapped meat
        ingredients = """
        GetItem(ICON3D_FD_SEA_SALT,2)
        GetItem(ICON3D_FD_MUSHROOM,4)
        GetItem(ICON3D_FD_MEAT_03,2)
        GetItem(ICON3D_FD_VG_CORN,2)
        """
        return ingredients
    elif itemID == 575: #fish fry
        ingredients = """
        GetItem(ICON3D_FD_WHEAT,2)
        GetItem(ICON3D_FD_LAND_EGG,2)
        GetItem(ICON3D_FD_MEAT_02,4)
        GetItem(ICON3D_FD_VG_TOMATO,2)
        """
        return ingredients
    elif itemID == 576: #pirate platter
        ingredients = """
        GetItem(ICON3D_FD_SEA_SHELLFISH,2)
        GetItem(ICON3D_FD_MEAT_01,2)
        GetItem(ICON3D_FD_MEAT_03,4)
        GetItem(ICON3D_FD_VG_PUMPKIN,2)
        """
        return ingredients
    elif itemID == 577: #coleslaw
        ingredients = """
        GetItem(ICON3D_FD_SEA_SALT,2)
        GetItem(ICON3D_FD_LAND_HONEY,2)
        GetItem(ICON3D_FD_VG_CABBAGE,4)
        GetItem(ICON3D_FD_VG_CORN,4)
        """
        return ingredients
    elif itemID == 578: #Bolognese
        ingredients = """
        GetItem(ICON3D_FD_WHEAT,2)
        GetItem(ICON3D_FD_MEAT_03,2)
        GetItem(ICON3D_FD_VG_EGGPLANT,4)
        GetItem(ICON3D_FD_VG_TOMATO,4)
        """
        return ingredients
    elif itemID == 579: #pumpkin pie
        ingredients = """
        GetItem(ICON3D_FD_LAND_HONEY,2)
        GetItem(ICON3D_FD_WHEAT,2)
        GetItem(ICON3D_FD_VG_PAPRIKA,4)
        GetItem(ICON3D_FD_VG_PUMPKIN,4)
        """
        return ingredients

def memoHints(itemID):
    match itemID:
        case 750:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_P_01,1)\n"
        case 751:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_P_02,1)\n"
        case 752:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_P_03,1)\n"
        case 753:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_P_04,1)\n"
        case 754:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_P_05,1)\n"
        case 755:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_P_06,1)\n"
        case 760:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_T_01,1)\n"
        case 761:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_T_02,1)\n"
        case 762:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_T_03,1)\n"
        case 763:
            return "\n\t\tSetFlag(GF_SUBEV_GET_MEMO_T_04,1)\n"
    
#The glow stone will now trigger this script from the chest that has it. This unlocks night explorations.
def makeGlowStoneUseful():
    script = """
    // Flag setting/item collection
    SetFlag(GF_OPEN_PANGAIA_T2,1) //Pangaia Great Plains night map released
    //SetFlag( GF_QUEST_613, QUEST_START ) // [QS613]
    //SetDiaryFlag( DF_QS613_START, 1 ) // [QS613]
    // Flag setting/item collection
    SetFlag(GF_OPEN_GENSD_T2,1) //Gendarme night map released
    //SetFlag( GF_QUEST_505, QUEST_START ) // [QS505] Saw the start event for gathering moonlight grass (Drifting Village/Night D)
    //SetDiaryFlag( DF_QS505_START, 1 ) // [QS505]I heard from Licht.
    //Flag setting/item collection
    SetFlag(GF_OPEN_CORAL_T2,1) //Coral Forest night map released
    //SetFlag( GF_QUEST_232, QUEST_START ) // [QS232] Watched the Dark Night Mystery (Drifting Village/Night D) starting event
    //SetDiaryFlag( DF_QS232_START, 1 ) // [QS232]I heard from Dogi.
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Night Explorations can now be undertaken.",0,0)
    WaitPrompt()
    WaitCloseWindow()
"""
    return script

#These items will trigger these flags for Dana's past events.
#Dana's past events are pretty linear and don't make for great rando content, there are probably interesting things that could be done with sanctuary crypt but it's massive and pretty linear with vanilla behavior.
#So we're instead taking items from her past, most of them key items, and making them items that will auto complete all specific Dana past events that affect the present. 
#There are 7 Dana past events where she is able to do things that affect the present, so there are 7 key items here.
def danaPastEvents(pastItem):
    if pastItem == 698: #'Maiden Journal'
        script = """
    if(!FLAG[GF_03MP1101_LEAVE_CAMP] ) //primordial passage access
    {
        SetFlag(GF_TBOX_DUMMY131, 1) // activate load zone to pinnacle from temple approach, moved to primordial passage post entrance shuffle
        SetFlag(GF_03MP1101_LEAVE_CAMP,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The path up The Mountain is open.",0,0)
        WaitPrompt()
        WaitCloseWindow()

    }
    """
    elif pastItem == 700: #'Blue Seal of Whirling Water'
        script = """
    if(!FLAG[GF_04MP5101_OUT_CAMP]) //ruins of eternia access
    {
        SetFlag( GF_04MP5101_OUT_CAMP, 1 )
        SetFlag(GF_04MP6401M_GO_MP6101M,1)
        SetFlag( GF_04MP6101_MAKE_CAMP, 1 )
        SetFlag( GF_04MP6101_CRYSTAL_FLASH, 1 )
        SetFlag(GF_SUBEV_PAST_01_GIMMICK_A,1) // Past Part I: Achieved [Past Gimmick : Waterway Repair]
        SetFlag(GF_SUBEV_PAST_01_GIMMICK_C,1) // Past episode I: Viewed [Past gimmick: Reflection in modern version]
        SetFlag(GF_SUBEV_PAST_01_LP_1ST,1) // Past Part I: [LP: Bookshelf in Dana's Room] First time
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The streets of the Forgotten City can be walked.",0,0)
        WaitPrompt()
        WaitCloseWindow()

    }
    """
    elif pastItem == 701: #'Green Seal of Roaring Stone'
        script = """
    if(!FLAG[GF_04MP6201_DIS_OBSTACLE]) //temple of the great tree access
    {
        SetFlag(GF_04MP6201_DIS_OBSTACLE,1)
        SetFlag(GF_SUBEV_PAST_02_GIMMICK_A, 1) // Past Part II: Watched the event [Past Gimmick : Listen to the story of the key]
        SetFlag(GF_SUBEV_PAST_02_GIMMICK_B, 1)// Past Part II: [Past Gimmick : Listen to the story about the key] Opened the door
        SetFlag(GF_SUBEV_PAST_02_FIRECNT_A, 1)// Past Part II: [Past Quest E: Examine the light on the statue] Light the three candlesticks
        SetFlag(GF_SUBEV_PAST_02_FIRECNT_B, 1)// Past Part II: [Past Quest E: Examine the light on the statue] Light the three candlesticks
        SetFlag(GF_SUBEV_PAST_02_FIRECNT_C, 1)// Past Part II: [Past Quest E: Examine the light on the statue] Light the three candlesticks
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The path to The Maiden awaits.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    """
    elif pastItem == 702: #'Golden Seal of Piercing Light'
        script = """
    if(!FLAG[GF_05MP6201M_GOTO_BAHA]) //baja tower access
    {
        SetFlag(GF_05MP6201M_GOTO_BAHA,1)
        SetFlag(GF_SUBEV_PAST_03_GIMMICK_L,1) // Watched Past Edition III: [Past Gimmick : Helping Animals]
        SetFlag(GF_SUBEV_PAST_03_GIMMICK_A, 2) // Past Edition III: Achieved [Past Gimmick: Helping animals] (substitute 2)
        SetFlag(GF_SUBEV_PAST_03_GIMMICK_B, 1) // Viewed past edition III: [Past gimmick : Reflection in modern edition]
        SetFlag(GF_GET_GRATICA,	1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The Leaning Tower can now be scaled.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    """
    elif pastItem == 699: #'Frozen Flower'
        script = """
    if(!FLAG[GF_05MP6204_APPEAR_CASTLE]) //chasm access
    {
        SetFlag(GF_05MP6204_APPEAR_CASTLE,1)
        SetFlag(GF_SUBEV_PAST_04_GIMMICK_L, 1)// Watched Past Chapter IV: [Past Gimmick : Repairing the Great Monastery Door]
        SetFlag(GF_SUBEV_PAST_04_GIMMICK, 2)// Past Part IV: Achieved [Past Gimmick : Repairing the door of the Great Monastery] (substitute 2)
        SetFlag(GF_OPEN_FLOOR_02,1) //I saw a prediction that the second floor would open.
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The Palace emerges from the depths.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    """
    elif pastItem == 796: #'Treasure Chest Key'
        script = """
    if(!FLAG[GF_05MP6105_GOTO_VALLAY]) //lodinia marsh back half access
    {
        SetFlag(GF_05MP6105_GOTO_VALLAY,1)
        SetFlag(GF_OPEN_FLOOR_03,1) //I saw a prediction that the third floor would open.
        SetFlag(GF_GET_LUMINOUS,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The way through Lodinia Marsh is cleared.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    """
    elif pastItem == 727: #'Shrine Maiden Amulate'
        script = """
    if(!FLAG[GF_SUBEV_PAST_06_GIMMICK_A]) //hill of eternity
    {
        SetFlag(GF_SUBEV_PAST_06_GIMMICK_A,1) // Watched Past Edition VI: [Past Gimmick : Discovered Poisonous Swamp]
        SetFlag(GF_SUBEV_PAST_06_GIMMICK_B,1)// Past Chapter VI: Moved the meteor fragment with [Past Gimmick : Purification of Poisonous Swamp]
        SetFlag(GF_SUBEV_PAST_06_GIMMICK_C,1) // Watched past edition VI: [Past gimmick : Reflection in modern edition]
        SetFlag(GF_OPEN_FLOOR_04, 1) //I saw a prediction that the 4th floor would open.
        SetFlag(GF_OPEN_FLOOR_05, 1) //I saw a prediction that the 5th floor would open.
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Hill of Eternity can now be accessed.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }  									
    """
    return script

#Sword of Psyches event. Adol gets Mistletein(probably mispelled that)
#we make sure the weapon is equipped here when it is received, if progressive super weapons we just set the flag for haivng received it so Kathleen will know the upgrade can happen at shop rank max 
def sopEvent(parameters):
    if parameters.progressiveSuperWeapons:
        script = """
    SetFlag(GF_TBOX_DUMMY071,1)
    """
    else:
        script = """
	SetFlag(GF_ADOLWEAPON_BACKUP,(ADOL.CHRWORK[CWK_WEAPON]))
	GetItem(ICON3D_WP_ADOL_008,1)
	EquipWeapon(ADOL,ICON3D_WP_ADOL_008)
	SetFlag(GF_TBOX_DUMMY071,1)
	"""
    return script

#dana spirit ring
def spiritRingEvent(parameters):
    if parameters.progressiveSuperWeapons:
        script = """
    SetFlag(GF_TBOX_DUMMY108,1)
    """
    else:
        script = """
	GetItem(ICON3D_WP_DANA_005,1)
	EquipWeapon(DANA,ICON3D_WP_DANA_005)
	SetFlag(GF_TBOX_DUMMY108,1)
	"""
    return script

#This makes shop upgrades progressive and is also what makes the flame stones actually do something.
#In vanilla all they did was act as a signpost for flags that were already set. 
#Kathleen has also been added the the to the shop upgrade chain as the first step. This is to help with combat balancing. 
#The idea being that weapons are the most important factor for combat balancing so making sure that Kathleen is found first before the reforge chains are unlocked will help with the game flow.
#Also to improve character balance in the rando late joining characters come without weapons equipped and are supplemented with stat bonuses equal to what stats that would be expected of a weapon at that tier for that character.
#Character with no weapon animate with their default weapons still, with the exception of Adol who starts with his tier 1 weapon anyway.
def shopUpgrades(location, vanillaScript = ''):
    stopFlag = ''
    stopFlagEnd = ''
    itemSE = 'ITEMMSG_SE_JINGLE' #Jingle during events
    scriptName = buildLocScripts(location.locID,False)

    if not location.event:
        fillChest(location,139,1)
        stopFlag = 'SetStopFlag(STOPFLAG_TALK)'
        stopFlagEnd = 'ResetStopFlag(STOPFLAG_TALK)'
        itemSE = 'ITEMMSG_SE_BETTER' #Placeholder item jingles in chests

    script = """
    function "{5}"
    {{
        {3}
        if (!FLAG[GF_02MP1201_JOIN_KATRIN])
        {{
            GetItemMessageExPlus(-1,1,{6},"#2CKathleen#4C {1}",0,0)
            WaitPrompt()
            WaitCloseWindow()        
            {0}
        }}
        else if (!FLAG[GF_TBOX_DUMMY081])
        {{
            SetFlag(GF_SHOP_RANK_3_02,1)
            SetFlag(GF_02MP4309_KILL_SPIDER,1)
            SetFlag(GF_QS201_SHOP_ADD,1)
            SetFlag(GF_TBOX_DUMMY081,1)
            GetItem(ICON3D_FIRESTONE,1)
            GetItemMessageExPlus(ICON3D_FIRESTONE,1,{6},"{2}",0,0)
            WaitPrompt()
            WaitCloseWindow()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 2.",0,0)
            WaitPrompt()
            WaitCloseWindow()  
        }}
        else if (!FLAG[GF_TBOX_DUMMY082])
        {{
            SetFlag(GF_SHOP_RANK_3_05,1)
            SetFlag(GF_SHOP_RANK_4_01,1)
            //The flag here is the trigger for speaking with Kathleen about the orichalcum and having new weapons made.
            //That event then trips the flag for being able to kill enemies flagged as Saurians.
            SetFlag(GF_03MP7401_GET_MATERIAL, 1)
            SetFlag(GF_TBOX_DUMMY082,1)
            GetItem(ICON3D_HIIROKANE,1)
            GetItemMessageExPlus(ICON3D_HIIROKANE,1,{6},"{2}",0,0)
            WaitPrompt()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Turn this into Kathleen.",0,0)
            WaitPrompt()
            WaitCloseWindow()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 3.",0,0)
            WaitPrompt()
            WaitCloseWindow()
        }}
        else if (!FLAG[GF_TBOX_DUMMY083])
        {{
            SetFlag(GF_SHOP_RANK_5_02,1)
            SetFlag(GF_TBOX_DUMMY083,1)
            GetItem(ICON3D_FIRESTONE,1)
            GetItemMessageExPlus(ICON3D_FIRESTONE,1,{6},"{2}",0,0)
            WaitPrompt()
            WaitCloseWindow()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 4.",0,0)
            WaitPrompt()
            WaitCloseWindow()
        }}
        else if (!FLAG[GF_TBOX_DUMMY084])
        {{
            SetFlag(GF_SHOP_RANK_5_04,1)
            SetFlag(GF_QS222_SHOP_ADD,1)
            SetFlag(GF_QS310_GET_ITEM,1)
            SetFlag(GF_QS310_GET_ITEM2,1)
            SetFlag(GF_QS310_GET_ITEM3,1)
            SetFlag(GF_TBOX_DUMMY084,1)
            GetItem(ICON3D_FIRESTONE,1)
            GetItemMessageExPlus(ICON3D_FIRESTONE,1,{6},"{2}",0,0)
            WaitPrompt()
            WaitCloseWindow()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 5.",0,0)
            WaitPrompt()
            WaitCloseWindow()
        }}
        else if (!FLAG[GF_TBOX_DUMMY085])
        {{
            SetFlag(GF_SHOP_RANK_5_07,1)
            SetFlag(GF_TBOX_DUMMY085,1)
            GetItem(ICON3D_FIRESTONE,1)
            GetItemMessageExPlus(ICON3D_FIRESTONE,1,{6},"{2}",0,0)
            WaitPrompt()
            WaitCloseWindow()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 6.",0,0)
            WaitPrompt()
            WaitCloseWindow()
        }}
        else if (!FLAG[GF_TBOX_DUMMY086])
        {{
            SetFlag(GF_SHOP_RANK_6_01,1)
            SetFlag(GF_05MP6349_KILL_BOSS,1)
            SetFlag(GF_QS600_SHOP_ADD,1)
            SetFlag(GF_TBOX_DUMMY086,1)
            SetFlag(GF_NPC_6_03_AFTER_INTERCEPT12,1)
            SetFlag(GF_06MP1201_GOTO_GEND,1)
            GetItem(ICON3D_FIRESTONE,1)
            GetItemMessageExPlus(ICON3D_FIRESTONE,1,{6},"{2}",0,0)
            WaitPrompt()
            WaitCloseWindow()
            GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank MAX.",0,0)
            WaitPrompt()
            WaitCloseWindow()
        }}
        else
        {{
            GetItem(ICON3D_MT_N4_STONE,5)
            GetItemMessageExPlus(ICON3D_MT_N4_STONE,5,ITEMMSG_SE_NORMAL," Obtained.",0,0)
            WaitPrompt()
            WaitCloseWindow()
        }}
        {4}
        {7}
    }}
    """

    return script.format(getCrewFlags("Kathleen"),crewMessage,genericMessage,stopFlag,stopFlagEnd,scriptName, itemSE, vanillaScript)

#setting for when the great tree of origins entrance opens
def octusGoal(parameters):
    if parameters.goal == 'Find Crew':
        octusAccess ="""
function "openTree"
{{
    if(WORK[WK_NPCNUM] >= {0} && !FLAG[GF_06MP6409_OPEN_GATE])
    {{
        SetFlag(GF_06MP6409_OPEN_GATE, 1)
        CallFunc("mp6409:init")
    }}
}}
"""
        return octusAccess.format(str(parameters.numOctus))
    
    elif parameters.goal in ['Seiren Escape','Untouchable']:
        octusAccess ="""
function "openTree"
{
    SetFlag(GF_06MP6409_OPEN_GATE, 1)
    CallFunc("mp6409:init")
}
"""
        return octusAccess
    
    elif parameters.goal == 'Release the Psyches':
        octusAccess ="""
function "openTree"
{{
    if(ALLITEMWORK[ICON3D_971] >= {0} && !FLAG[GF_06MP6409_OPEN_GATE]) //ICON3D_971:junk item used for tracking
    {{
        SetFlag(GF_06MP6409_OPEN_GATE, 1)
        CallFunc("mp6409:init")
    }}
}}
"""
    return octusAccess.format(str(parameters.numOctus))
    
#Our goals for entering the selection sphere
def goal(parameters):
    if parameters.goal == 'Find Crew':
        selectionSphereAccess ="""
function "goal"
{{
    if(WORK[WK_NPCNUM] >= {0})
    {{
        // filler
    }}
    else 
    {{
        SetChrWork("LP_warpin_mp6310b", CWK_CHECKOFF, 1)
        SetChrPos("b020",-100000.00f,0.00f,0.00f)
    }}
}}
"""
        return selectionSphereAccess.format(str(parameters.numGoal))
    
    elif parameters.goal == 'Seiren Escape':
        selectionSphereAccess ="""
function "goal"
{
    if(ALLITEMWORK[ICON3D_SHIP_PLAN] && ALLITEMWORK[ICON3D_SEIREN_CHART] && FLAG[GF_TBOX_DUMMY071])
    {
        // filler
    }
    else 
    {
        SetChrWork("LP_warpin_mp6310b", CWK_CHECKOFF, 1)
        SetChrPos("b020",-100000.00f,0.00f,0.00f)
    }
}
"""
        return selectionSphereAccess
        
    elif parameters.goal == 'Release the Psyches':
        selectionSphereAccess ="""
function "goal"
{{
    if(ALLITEMWORK[ICON3D_971] >= {0}) //ICON3D_971:junk item used for tracking
    {{
        // filler
    }}
    else 
    {{
        SetChrWork("LP_warpin_mp6310b", CWK_CHECKOFF, 1)
        SetChrPos("b020",-100000.00f,0.00f,0.00f)
    }}
}}
"""
    
        return selectionSphereAccess.format(str(parameters.numGoal))

    elif parameters.goal == 'Untouchable':
        selectionSphereAccess ="""
function "goal"
{
    if(FLAG[GF_SUBEV_UNTOUCHABLE])
    {
        // filler
    }
    else 
    {
        SetChrWork("LP_warpin_mp6310b", CWK_CHECKOFF, 1)
        SetChrPos("b020",-100000.00f,0.00f,0.00f)
    }
}
"""
    return selectionSphereAccess

def octoBosses(parameters, finalNonGoalBossLevel):
    random.seed(parameters.seed)
    octoBossAliases = ['"ev_mons01"','"ev_mons02"','"ev_mons03"','"ev_mons04"','"ev_mons05"','"ev_mons06"','"ev_mons07"','"ev_mons08"','"ev_mons09"','"ev_mons10"']
    HPmod = round(finalNonGoalBossLevel/80,2)
    EXPMod = round((140)/finalNonGoalBossLevel,1)
    script = '\tfunction "setOctoBossLevels"\n\t{\n'
    for boss in octoBossAliases:
        bossLevel = random.randrange(65,75)
        script = script + '\t\tSetLevel(' + boss + ', ' + str(bossLevel) + ')\n'
        script = script + '\t\tSetChrWork(' + boss + ', CWK_MAXHP, (' + boss.replace('"','') + '.CHRWORK[CWK_MAXHP] * '+ str(HPmod) +'))\n'
        script = script + '\t\tSetChrWork(' + boss + ', CWK_HP, (' + boss.replace('"','') + '.CHRWORK[CWK_MAXHP]))\n'
        script = script + '\t\tSetChrWorkGroup(' + boss + ', CWK_EXPMUL, ' + str(EXPMod) + 'f)\n'
    script = script + '\t}\n'

    randomizeOctoBosses(parameters)

    return script
#This sorts out our final boss settings.
#First we figure out what phases we're doing then we run through our script that's called to start the final boss and what's used to call the ending cutscenes.
#if we're only doing theos then the theos start script calls theos and the ending script calls the ending cutscene.
#if we're doing both then the ending cutscene script instead calls origin.
#if we're only doing origin then the theos start script calls the origin boss fight.
#for Past Dana we only load the Io fight
def endingHandler(parameters, finalNonGoalBossLevel):
    finalBossLevel = finalNonGoalBossLevel + 2

    if parameters.charMode != 'Past Dana':
        finalBossLevel = finalBossLevel + 2
    if parameters.goal == 'Untouchable':
        finalBossLevel = 80
    if parameters.goal == 'release the psyches':
        finalBossLevel = finalBossLevel + 2*parameters.numGoal

    
    if parameters.finalBoss == 'Both':
        spoilerLog.write('\nFinal Boss Level: ' + parameters.finalBoss + ' ' + str(finalBossLevel) + ',' + str(finalBossLevel + 1) + '\n')
    elif parameters.finalBoss == 'Origin of Life':
        spoilerLog.write('\nFinal Boss Level: ' + parameters.finalBoss + ' ' + str(finalBossLevel + 1) + '\n')
    else:
        spoilerLog.write('\nFinal Boss Level: ' + parameters.finalBoss + ' ' + str(finalBossLevel) + '\n')

    finalBossLevelScript = """
    function "finalBossLevel"
    {{
        SetChrWorkGroup(B020, CWK_LV, {0})
        SetChrWorkGroup(B021, CWK_LV, {0})
        SetChrWorkGroup(B021IVY, CWK_LV, {0})
        SetChrWorkGroup(B022, CWK_LV, {0})
        SetChrWorkGroup(B023, CWK_LV, {0})
        SetChrWorkGroup(B024, CWK_LV, {0})
        SetChrWorkGroup(B025, CWK_LV, {0})
        SetChrWorkGroup(B009, CWK_LV, {1})
        SetChrWorkGroup(B010, CWK_LV, {1})
        SetChrWorkGroup(B030, CWK_LV, {0})
    }}
    """
    finalBossLevelScript = finalBossLevelScript.format(str(finalBossLevel), str(finalBossLevel + 1))

    if parameters.charMode == 'Past Dana':
        ioFightLoad = """
    function "finalBoss"
    {
        LoadArg("map/mp6569m/c.arg")
	    EventCue("mp6569m:EV_RetryBoss")
    }
    """
        return ioFightLoad + finalBossLevelScript
    
    if parameters.theosPhase == 'First':
        theosPhase = ''
    elif parameters.theosPhase == 'Second':
        theosPhase = 'SetFlag(GF_MP6310B_ENDROGRAM_STEP,1)'
    elif parameters.theosPhase == 'Final':
        theosPhase = 'SetFlag(GF_MP6310B_ENDROGRAM_STEP,2)'
    
    if parameters.originPhase == 'First':
        originPhase = ''
    elif parameters.originPhase == 'Final':
        originPhase = 'SetFlag(GF_MP8323_2NDBATTLE,1)'

    if parameters.carePackage == 'Generous':
        package = """
        GetItem(ICON3D_US_BERRY_S,9)
        GetItem(ICON3D_US_COCONUT_S,9)
        GetItem(ICON3D_US_MANGO_S,9)
        GetItem(ICON3D_US_DRAGONFRUIT_S,9)
        GetItem(ICON3D_USFD_FOOD15,9)
        GetItem(ICON3D_USFD_FOOD03,9)
        GetItem(ICON3D_US_RESSURECT_02,9)
        GetItem(ICON3D_US_EXTRA_02,2)
        """
    elif parameters.carePackage == 'Lite':
        package = """
        GetItem(ICON3D_US_BERRY_S,5)
        GetItem(ICON3D_US_COCONUT_S,5)
        GetItem(ICON3D_US_MANGO_S,5)
        GetItem(ICON3D_US_DRAGONFRUIT_S,5)
        GetItem(ICON3D_USFD_FOOD15,1)
        GetItem(ICON3D_US_RESSURECT_02,1)
        GetItem(ICON3D_US_EXTRA_02,1)
        """
    elif parameters.carePackage == 'None':
        package = ""
        

    if parameters.finalBoss == 'Theos de Endogram' or parameters.finalBoss == 'Both':
        theosStartScript = """
    function "finalBoss"
    {{
        {0}
        LoadArg("map/mp6310b/mp6310b.arg")
	    EventCue("mp6310b:EV_M06S240")
    }}
    """
        theosStartScript = theosStartScript.format(theosPhase)
    elif parameters.finalBoss == 'Origin of Life':
        theosStartScript = """
    function "finalBoss"
    {{
        {0}
        LoadArg("map/mp8323/mp8323.arg")
		EventCue("mp8323:init")
    }}
    """
        theosStartScript = theosStartScript.format(originPhase)

    if parameters.finalBoss == 'Theos de Endogram' or parameters.finalBoss == 'Origin of Life':
        ending1 = """
    function "ending"
    {
        LoadArg("map/mp0021/mp0021.arg")
        EventCue("mp0021:EV_M07S130")
    }
    
    function "ending2"
    {
        LoadArg("map/mp0021/mp0021.arg")
        EventCue("mp0021:EV_M07S130")
    }
    """
    elif parameters.finalBoss == 'Both':
        ending1 = """
    function "ending"
    {{
        {0}
        {1}
        LoadArg("map/mp8323/mp8323.arg")
		EventCue("mp8323:init")
    }}

    function "ending2"
    {{
        LoadArg("map/mp0021/mp0021.arg")
        EventCue("mp0021:EV_M07S130")
    }}
    """
        ending1 = ending1.format(originPhase,package)

    return theosStartScript + ending1 + finalBossLevelScript

#This flag was original tripped by the chest event from the chest on the Docks of East Coast Cave. Now it has been moved to the note that was originally in that chest.
def pirateShipDocks():
    script = """

    SetFlag(GF_05MP7411_READ_NOTE1, 1)
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The gangway has been dropped.",0,0)
    WaitPrompt()
    WaitCloseWindow()

"""
    return script

#this builds out all our intercept rewards, it's called every time we return from an intercept in castaway village by checking the flags for last stage rank and stage clear
def interceptionHandler(parameters):
    interceptionRewards = getIntRewards()

    script = """
function "newInterceptControl"
{
	SetWork(WK_ITC_BASE_LV, 9)
	SetWork(WK_ITC_DECOY_NUM, 8)
	SetWork(WK_ITC_DECOY_LV, 5)
	SetWork(WK_ITC_DECOY_OPT, 1)
	SetWork(WK_ITC_BARRICADE_NUM, 4)
	SetWork(WK_ITC_BARRICADE_LV, 5)
	SetWork(WK_ITC_BARRICADE_OPT, 1)
	SetWork(WK_ITC_CATAPULT_NUM, 1)
	SetWork(WK_ITC_CATAPULT_LV, 5)
	SetWork(WK_ITC_CATAPULT_OPT, 1)
	SetWork(WK_ITC_GONG_NUM, 1)
	SetWork(WK_ITC_GONG_LV, 3)
	SetWork(WK_ITC_GONG_OPT, 1)

    if (FLAG[GF_INTERCEPT_LASTRESULT] == 1)
    {

"""
    for stage in interceptionRewards:
        stageCheck = """
        if (FLAG[GF_INTERCEPT_LASTSTAGEID] == {0})
        {{
            SetStopFlag(STOPFLAG_TALK)

"""
        script = script + stageCheck.format(stage.stage)

        if parameters.intRewards:
            totalReward = 0
            for index,reward in enumerate(stage.rewards):
                if index % 2 == 0 or index == 0:
                    item = reward
                else:
                    itemNum = reward

                totalReward+=1
                if totalReward == 2:
                    rewardGet = """

                GetItem({0},{1})
                GetItemMessageExPlus({0},{1},ITEMMSG_SE_NORMAL,"{2}",0,0)
                WaitPrompt()
                WaitCloseWindow()

                """
                    script = script + rewardGet.format(item,itemNum,genericMessage)
                    totalReward = 0

        if stage.stage == 'INTERCEPT_STAGE02':
            dogiReward = """
            SetFlag(GF_TBOX_DUMMY089,1)
            """
        elif stage.stage == 'INTERCEPT_STAGE03':
            dogiReward = """
            SetFlag(GF_TBOX_DUMMY090,1)"""
        elif stage.stage == 'INTERCEPT_STAGE05':
            dogiReward = """
            SetFlag(GF_TBOX_DUMMY091,1)
            """
        elif stage.stage == 'INTERCEPT_STAGE07':
            dogiReward = """
            SetFlag(GF_TBOX_DUMMY092,1)
            """
        elif stage.stage == 'INTERCEPT_STAGE09':
            dogiReward = """
            SetFlag(GF_TBOX_DUMMY093,1)
            """
        else:
            dogiReward = ''

        stageFooter = """
            ResetStopFlag(STOPFLAG_TALK)
        }"""  
        
        script = script + dogiReward + stageFooter

    scriptFooter = """
        SetFlag(GF_INTERCEPT_LASTRESULT, 0)
	    SetFlag(GF_INTERCEPT_LASTSTAGEID, INTERCEPT_STAGE_NONE)
	    CallFunc("mp1201:init") 
    }
}  
"""
    script = script + scriptFooter

    return script

def jewelTrade(locations):
    dinasItems = [None] * 10
    for location in locations:
        if location.locName == "Jewel Trade":
            dinasItems[location.locID - 461] = copyLocationToNewLoc(location) #dina's location IDs for the rando start at ID 461 so this gets us the exact array index we need to have them in order inside the array
    
    #we have to do a little extra work for skills because of the divergent way I handled skills in the locaiton file
    for item in dinasItems: 
        if item.skill:
            skillInfo = getSkillInfo(item.itemName)
            item.itemName = skillInfo[2] + " Skill -" + skillInfo[1]
    
    script = """
function "newTradeHandler"
{{
        
    if(ALLITEMWORK[ICON3D_MT_R4_GOLD] > 0 && !FLAG[GF_TBOX_DUMMY095])
    {{
        MenuAdd(10, "#2C Prismatic Jewel x 1 #0C for #2C {0}#0C .")
    }}
    else
    {{
        MenuAdd(11, "Prismatic Jewel x 1 for {0}.")
    }}
    if(ALLITEMWORK[ICON3D_MT_R4_GOLD] > 0 && !FLAG[GF_TBOX_DUMMY096])
	{{
        MenuAdd(20, "#2C Prismatic Jewel x 1 #0C for #2C {1}#0C .")
	}}
	else
	{{
        MenuAdd(21, "Prismatic Jewel x 1 for {1}.")
	}}

	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 2 && !FLAG[GF_TBOX_DUMMY097])
	{{
		MenuAdd(110, "#2C Prismatic Jewel x 2 #0C for #2C {2}#0C .")
	}}
	else
	{{
		MenuAdd(111, "Prismatic Jewel x 2 for {2}.")
	}}
	
	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 10 && !FLAG[GF_TBOX_DUMMY098])
	{{
		MenuAdd(30, "#2C Prismatic Jewel x 10 #0C for #2C {3}#0C .")
	}}
	else
	{{
		MenuAdd(31, "Prismatic Jewel x 10 for {3}.")
	}}
	
	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 25 && !FLAG[GF_TBOX_DUMMY099])
    {{
		MenuAdd(40, "#2C Prismatic Jewel x 25 #0C for #2C {4}#0C .")
	}}
	else
	{{
		MenuAdd(41, "Prismatic Jewel x 25 for {4}.")
	}}

	//--------------------------------------------------------------------------------------

	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 1 && !FLAG[GF_OLDITEM_TRADE_01])	
    {{
		MenuAdd(50, "#2C Prismatic Jewel x 1 #0C for #2C {5}#0C .")
	}}
	else
	{{
		MenuAdd(51, "Prismatic Jewel x 1 for {5}.")
	}}

	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 1 && !FLAG[GF_OLDITEM_TRADE_02])	
    {{
		MenuAdd(60, "#2C Prismatic Jewel x 1 #0C for #2C {6}#0C .")
	}}
	else
	{{
		MenuAdd(61, "Prismatic Jewel x 1 for {6}.")
	}}
	
	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 2 && !FLAG[GF_OLDITEM_TRADE_03])	
    {{
		MenuAdd(70, "#2C Prismatic Jewel x 2 #0C for #2C {7}#0C .")
	}}
	else
	{{
		MenuAdd(71, "Prismatic Jewel x 2 for {7}.")
	}}

	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 2 && !FLAG[GF_OLDITEM_TRADE_04])	
    {{
		MenuAdd(80, "#2C Prismatic Jewel x 2 #0C for #2C {8}#0C .")
	}}
	else
	{{
		MenuAdd(81, "Prismatic Jewel x 2 for {8}.")
	}}		

	if(ALLITEMWORK[ICON3D_MT_R4_GOLD] >= 3 && !FLAG[GF_OLDITEM_TRADE_05])	
    {{
		MenuAdd(90, "#2C Prismatic Jewel x 3 #0C for #2C {9}#0C .")
	}}
	else
	{{
		MenuAdd(91, "Prismatic Jewel x 3 for {9}.")
	}}

}}
"""
    item1 = dinasItems[0].itemName + ' x ' + str(dinasItems[0].quantity)
    item2 = dinasItems[1].itemName + ' x ' + str(dinasItems[1].quantity)
    item3 = dinasItems[2].itemName + ' x ' + str(dinasItems[2].quantity)
    item4 = dinasItems[3].itemName + ' x ' + str(dinasItems[3].quantity)
    item5 = dinasItems[4].itemName + ' x ' + str(dinasItems[4].quantity)
    item6 = dinasItems[5].itemName + ' x ' + str(dinasItems[5].quantity)
    item7 = dinasItems[6].itemName + ' x ' + str(dinasItems[6].quantity)
    item8 = dinasItems[7].itemName + ' x ' + str(dinasItems[7].quantity)
    item9 = dinasItems[8].itemName + ' x ' + str(dinasItems[8].quantity)
    item10 = dinasItems[9].itemName + ' x ' + str(dinasItems[9].quantity)
    return script.format(item1,item2,item3,item4,item5,item6,item7,item8,item9,item10)

#the order intercepts unlock for finding T's Memos
def interceptUnlock():
    script = """
    if( !FLAG[GF_TBOX_DUMMY100])
    {
        Intercept(INTERCEPT_STAGE01,1)
        Intercept(INTERCEPT_STAGE02,1)
        Intercept(INTERCEPT_STAGE03,1)
        Intercept(INTERCEPT_STAGE04,1)
        Intercept(INTERCEPT_STAGE05,1)
        Intercept(INTERCEPT_STAGE06,1)
        Intercept(INTERCEPT_STAGE07,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Intercept list updated.",0,0)
        WaitPrompt()
        WaitCloseWindow()
        SetFlag(GF_TBOX_DUMMY100,1)
    }
    else if( !FLAG[GF_TBOX_DUMMY101])
    {
        SetFlag(GF_TBOX_DUMMY094,1)
        Intercept(INTERCEPT_STAGE31,1)
        SetFlag(GF_QS303_QUESTCLEAR,1)
        Intercept(INTERCEPT_STAGE32,1)
        Intercept(INTERCEPT_STAGE33,1)
        Intercept(INTERCEPT_STAGE34,1)
        Intercept(INTERCEPT_STAGE35,1)
        Intercept(INTERCEPT_STAGE36,1)
        Intercept(INTERCEPT_STAGE37,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Intercept list updated.",0,0)
        WaitPrompt()
        WaitCloseWindow()
        SetFlag(GF_TBOX_DUMMY101,1)
    }
    else if( !FLAG[GF_TBOX_DUMMY102])
    {
        Intercept(INTERCEPT_STAGE08,1)
        Intercept(INTERCEPT_STAGE09,1)
        Intercept(INTERCEPT_STAGE11,1)
        Intercept(INTERCEPT_STAGE12,1)
        Intercept(INTERCEPT_STAGE38,1)
        Intercept(INTERCEPT_STAGE39,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Intercept list updated.",0,0)
        WaitPrompt()
        WaitCloseWindow()
        SetFlag(GF_TBOX_DUMMY102,1)
    }
    else if ( !FLAG[GF_TBOX_DUMMY103])
    {
	    Intercept(INTERCEPT_STAGE21,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Intercept list complete.",0,0)
        WaitPrompt()
        WaitCloseWindow()
        SetFlag(GF_TBOX_DUMMY103,1)
    }
"""
    return script

#GF_TBOX_DUMMY112 is our flag for release the psyches so these won't get called outside this game mode.
#New version of this script hacks the checkpoint in Castaway Village and uses the boss flags for activation of the custom shop
#The boss menu is essentially a custom shop, it uses Dina's jewel trade menu as a base, there are two version of it depending on game mode
def buildPsyches(shuffledLocations, parameters, bossLevelsDictByRegion, finalNonGoalBossLevel):
    #region: boss flag for region
    bossFlagDict = {'Silent Tower': 'FLAG[GF_SUBEV_06_6413_KILL_BOSS]',
                    'Octus Overlook': 'FLAG[GF_TBOX_DUMMY161]',
                    'Valley of Kings': 'FLAG[GF_TBOX_DUMMY080]',
                    'Archeozoic Chasm': 'FLAG[GF_TBOX_DUMMY078]',
                    'Pirate Ship Eleftheria': 'FLAG[GF_05MP0405_READ_REED]',
                    'Baja Tower': 'FLAG[GF_05MP6329_KILL_BAHABOSS]',
                    'Temple of the Great Tree': 'FLAG[GF_04MP6410_KILL_GUARDIAN]',
                    'Mont Gendarme': 'FLAG[GF_03MP4341_KILL_ANCIENT]',
                    'Schlamm Jungle': 'FLAG[GF_02MP2308_KILL_HIPPO]',
                    'Eroded Valley': 'FLAG[GF_TBOX_DUMMY074]',
                    'Towering Coral Forest': 'FLAG[GF_02MP1308_KILL_CHAMELEON]',
                    'Former Sanctuary Crypt - Final Floor': 'FLAG[GF_SUBEV_UNTOUCHABLE]'}
    #Boss name: load boss map script, boss event, boss map id, boss character id
    bossCue = {'Hydra': ['LoadArg("map/mp6305b/mp6305b.arg")', 'EventCue("mp6305b:EV_RetryBoss")', 'MN_D_MP6305b', 'B112'],
               'Minos': ['LoadArg("map/mp6306b/mp6306b.arg")', 'EventCue("mp6306b:EV_RetryBoss")', 'MN_D_MP6306b', 'B110'],
               'Nestor': ['LoadArg("map/mp6307b/mp6307b.arg")', 'EventCue("mp6307b:EV_RetryBoss")', 'MN_D_MP6307b', 'B111'],
               'Ura': ['LoadArg("map/mp6308b/mp6308b.arg")', 'EventCue("mp6308b:EV_RetryBoss")', 'MN_D_MP6308b', 'B008'],
               'Le-Erythros': ['LoadArg("map/mp6409b/mp6409b.arg")', 'EventCue("mp6409b:EV_RetryBoss")', 'MN_D_MP6409B', 'B012'],
               'Grazios': ['LoadArg("map/mp6519m/mp6519m.arg")', 'EventCue("mp6519m:EV_RetryBoss")', 'MN_D_MP6519M','B161'],
               'Nebritia': ['LoadArg("map/mp6529m/mp6529m.arg")', 'EventCue("mp6529m:EV_RetryBoss")', 'MN_D_MP6529M','B162'],
               'Argura': ['LoadArg("map/mp6539m/mp6539m.arg")', 'EventCue("mp6539m:EV_RetryBoss")', 'MN_D_MP6539M', 'B163'],
               'Crusos': ['LoadArg("map/mp6549m/mp6549m.arg")', 'EventCue("mp6549m:EV_RetryBoss")', 'MN_D_MP6549M', 'B011'],
               'Blasphima': ['LoadArg("map/mp6559m/mp6559m.arg")', 'EventCue("mp6559m:EV_RetryBoss")', 'MN_D_MP6559M', 'B164'],
               'Le-Kyanos': ['LoadArg("map/mp6204m/mp6204m.arg")', 'EventCue("mp6204m:EV_Boss_Jump")', 'MN_F_MP6204M', 'B165'],
               'Melaiduma': ['LoadArg("map/mp6569/mp6569.arg")', 'EventCue("mp6569:EV_RetryBoss")', 'MN_D_MP6569', 'B170']
        }
    

    if parameters.charMode == 'Past Dana':
        bossPool = ['Grazios','Nebritia','Argura','Crusos','Blasphima','Le-Kyanos']
    else:
        bossPool = ['Hydra','Minos','Nestor','Ura','Le-Erythros']
    
    if not parameters.formerSanctuaryCrypt:
        bossPool.append('Melaiduma')
        
    random.shuffle(bossPool)

    for location in shuffledLocations:
        if location.itemName == 'Psyches of the Sky Era\Braziers Fight(DANA)':
            bossFight1 = bossFlagDict[location.locRegion]
            bossLoc1 = location.locRegion
        if location.itemName == 'Psyches of the Insectoid Era\Stone Fight(DANA)':
            bossFight2 = bossFlagDict[location.locRegion]
            bossLoc2 = location.locRegion
        if location.itemName == 'Psyches of the Frozen Era\Clairvoyance Fight(DANA)':
            bossFight3 = bossFlagDict[location.locRegion]
            bossLoc3 = location.locRegion
        if location.itemName == 'Psyches of the Ocean Era\Frost Fight(DANA)':
            bossFight4 = bossFlagDict[location.locRegion]
            bossLoc4 = location.locRegion
        if location.itemName == 'Empty Psyches\Magma Fight(DANA)':
            bossFight5 = bossFlagDict[location.locRegion]
            bossLoc5 = location.locRegion

    wardenScaling = """
        SetChrWork("b012", CWK_MAXHP, (b012.CHRWORK[CWK_MAXHP] * 3.0f))
        SetChrWork("b012", CWK_HP, (b012.CHRWORK[CWK_MAXHP]))
"""

    for boss in bossLevelsDictByRegion:
        print(boss + ': ' + str(bossLevelsDictByRegion[boss]))

    danaWardenIncrease = 5
    danaModerateWardenIncrease = 2
    normalWardenIncrease = 10
    moderateWardenIncrease = 5

    if parameters.charMode == 'Past Dana':
        
        try:
            warden1Level = bossLevelsDictByRegion[bossLoc1] + danaWardenIncrease
        except:
            warden1Level = finalNonGoalBossLevel + danaModerateWardenIncrease
        try:
            warden2Level = bossLevelsDictByRegion[bossLoc2] + danaWardenIncrease
        except:
            warden2Level = finalNonGoalBossLevel + danaModerateWardenIncrease
        try:
            warden3Level = bossLevelsDictByRegion[bossLoc3] + danaWardenIncrease
        except:
            warden3Level = finalNonGoalBossLevel + danaModerateWardenIncrease
        try:
            warden4Level = bossLevelsDictByRegion[bossLoc4] + danaWardenIncrease
        except:
            warden4Level = finalNonGoalBossLevel + danaModerateWardenIncrease
        try:
            warden5Level = bossLevelsDictByRegion[bossLoc5] + danaWardenIncrease
        except:
            warden5Level = finalNonGoalBossLevel + danaModerateWardenIncrease
    else:
        

        try:
            warden1Level = bossLevelsDictByRegion[bossLoc1] + normalWardenIncrease
        except:
            warden1Level = finalNonGoalBossLevel + moderateWardenIncrease
        try:
            warden2Level = bossLevelsDictByRegion[bossLoc2] + normalWardenIncrease
        except:
            warden2Level = finalNonGoalBossLevel + moderateWardenIncrease
        try:
            warden3Level = bossLevelsDictByRegion[bossLoc3] + normalWardenIncrease
        except:
            warden3Level = finalNonGoalBossLevel + moderateWardenIncrease
        try:
            warden4Level = bossLevelsDictByRegion[bossLoc4] + normalWardenIncrease
        except:
            warden4Level = finalNonGoalBossLevel + moderateWardenIncrease

    spoilerLog.write('\nPsyches Boss Assignments:\n')
    spoilerLog.write('\tPsyches of the Sky Era\Braziers Fight(DANA) Region: ' + bossLoc1 + " Warden:" + bossPool[0] + " Level:" + str(warden1Level) + '\n')
    spoilerLog.write('\tPsyches of the Insectoid Era\Stone Fight(DANA) Region: ' + bossLoc2 + " Warden:" + bossPool[1] + " Level:" + str(warden2Level) + '\n')
    spoilerLog.write('\tPsyches of the Frozen Era\Clairvoyance Fight(DANA) Region: ' + bossLoc3 + " Warden:" + bossPool[2] + " Level:" + str(warden3Level) + '\n')
    spoilerLog.write('\tPsyches of the Ocean Era\Frost Fight(DANA) Region: ' + bossLoc4 + " Warden:" + bossPool[3] + " Level:" + str(warden4Level) + '\n')
    if parameters.charMode == 'Past Dana':
        spoilerLog.write('\tEmpty Psyches\Magma Fight(DANA) Region: ' + bossLoc5 + " Warden:" + bossPool[4] + " Level:" + str(warden5Level) + '\n')

    wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(' + bossCue[bossPool[0]][3] + ', CWK_LV, ' + str(warden1Level) + ')\n'
    if bossPool[0] == 'Ura': wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(B008BIT, CWK_LV, ' + str(warden1Level) + ')\n'

    wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(' + bossCue[bossPool[1]][3] + ', CWK_LV, ' + str(warden2Level) + ')\n'
    if bossPool[1] == 'Ura': wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(B008BIT, CWK_LV, ' + str(warden2Level) + ')\n'
    
    wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(' + bossCue[bossPool[2]][3] + ', CWK_LV, ' + str(warden3Level) + ')\n'
    if bossPool[2] == 'Ura': wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(B008BIT, CWK_LV, ' + str(warden3Level) + ')\n'

    wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(' + bossCue[bossPool[3]][3] + ', CWK_LV, ' + str(warden4Level) + ')\n'
    if bossPool[3] == 'Ura': wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(B008BIT, CWK_LV, ' + str(warden4Level) + ')\n'

    if parameters.charMode == 'Past Dana':
        wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(' + bossCue[bossPool[4]][3] + ', CWK_LV, ' + str(warden5Level) + ')\n'
        if bossPool[4] == 'Ura': wardenScaling = wardenScaling + '\t\tSetChrWorkGroup(B008BIT, CWK_LV, ' + str(warden5Level) + ')\n'

    ### Past Dana Mode Bosses
    if parameters.charMode == 'Past Dana':
        bossCheckpoint = """
    function "bossCheckpoint"
    {{
        SetStopFlag(STOPFLAG_TALK)
        
        SetFlag(TF_MENU_SELECT2, 0)
        MenuReset()
        MenuType(MENUTYPE_POPUP)
        
        //--------------------------------------------------------------------------------------

        if({0} && !FLAG[GF_SUBEV_PAST_02_BOSS])
        {{
            MenuAdd(10, "#2C{5}: Chamber of Braziers Guardian ({10})")	
        }}
        else if(!{0} || FLAG[GF_SUBEV_PAST_02_BOSS])
        {{
            MenuAdd(11, "{5}: Chamber of Braziers Guardian({10})")	
        }}

        if({1} && !FLAG[GF_SUBEV_PAST_BOSS_B2])	
        {{
            MenuAdd(20, "#2C{6}: Chamber of Stone Guardian({11})")	
        }}
        else if(!{1} || FLAG[GF_SUBEV_PAST_BOSS_B2])
        {{
            MenuAdd(21, "{6}: Chamber of Stone Guardian({11})")	
        }}
        
        if({2} && !FLAG[GF_SUBEV_PAST_BOSS_B3])	
        {{
            MenuAdd(30, "#2C{7}: Chamber of Clairvoyance Guardian({12})")	
        }}
        else if(!{2} || FLAG[GF_SUBEV_PAST_BOSS_B3])
        {{
            MenuAdd(31, "{7}: Chamber of Clairvoyance Guardian({12})")	
        }}

        if({3} && !FLAG[GF_SUBEV_PAST_BOSS_B4])	
        {{
            MenuAdd(40, "#2C{8}: Chamber of Frost Guardian({13})")	
        }}
        else if(!{3} || FLAG[GF_SUBEV_PAST_BOSS_B4])
        {{
            MenuAdd(41, "{8}: Chamber of Frost Guardian({13})")	
        }}		

        if({4} && !FLAG[GF_SUBEV_PAST_BOSS_B5])	
        {{
            MenuAdd(50, "#2C{9}: Chamber of Magma Guardian({14})")	
        }}
        else if(!{4} || FLAG[GF_SUBEV_PAST_BOSS_B5])
        {{
            MenuAdd(51, "{9}: Chamber of Magma Guardian({14})")	
        }}			
        //--------------------------------------------------------------------------------------
        

        MenuEnable( 11, 0)
        MenuEnable( 21, 0)
        MenuEnable( 31, 0)
        MenuEnable( 41, 0)
        MenuEnable( 51, 0)

        MenuOpen( TF_MENU_SELECT2 , 283 , ADOLMENU_PPOSY , -2 , -2 , 10 , 1)
        WaitMenu(0)
        CloseMessage(6,0)
        WaitCloseMessage(6)
        MenuClose(10, 0)
        
        if(FLAG[TF_MENU_SELECT2] == 10)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            SetFlag(SF_PAST_MODE, 1)
            {15}
            {16}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()
        }}
        else if(FLAG[TF_MENU_SELECT2] == 20)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            SetFlag(SF_PAST_MODE, 1)
            {17}
            {18}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()
        }}
        else if(FLAG[TF_MENU_SELECT2] == 30)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            SetFlag(SF_PAST_MODE, 1)
            {19}
            {20}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()
        }}
        else if(FLAG[TF_MENU_SELECT2] == 40)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            SetFlag(SF_PAST_MODE, 1)
            {21}
            {22}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade() 
        }}
        else if(FLAG[TF_MENU_SELECT2] == 50)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            SetFlag(SF_PAST_MODE, 1)
            {23}
            {24}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()
        }}
        ResetStopFlag(STOPFLAG_TALK)
    
    }}

    function "wardenScaling"
    {{
        {26} 
    }}
    
    {25}

"""
        bossReturn = """
        function "bossReturn"
        {{
            SetFlag( SF_BOSS_BATTLE, 0 )
            if(WORK[WK_MAPNAMENO] == {0})
            {{
                SetFlag(GF_SUBEV_PAST_02_BOSS,1)
                LoadArg("map/mp1201/mp1201.arg")
		        EventCue("mp1201:EV_M01S080_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {1})
            {{
                SetFlag(GF_SUBEV_PAST_BOSS_B2,1)
                LoadArg("map/mp1201/mp1201.arg")
		        EventCue("mp1201:EV_M01S080_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {2})
            {{
                SetFlag(GF_SUBEV_PAST_BOSS_B3,1)
                LoadArg("map/mp1201/mp1201.arg")
		        EventCue("mp1201:EV_M01S080_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {3})
            {{
                SetFlag(GF_SUBEV_PAST_BOSS_B4,1)
                LoadArg("map/mp1201/mp1201.arg")
		        EventCue("mp1201:EV_M01S080_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {4})
            {{
                SetFlag(GF_SUBEV_PAST_BOSS_B5,1)
                LoadArg("map/mp1201/mp1201.arg")
		        EventCue("mp1201:EV_M01S080_ED")
            }}
                
        }}
"""
        bossReturn = bossReturn.format(bossCue[bossPool[0]][2], bossCue[bossPool[1]][2], bossCue[bossPool[2]][2], bossCue[bossPool[3]][2], bossCue[bossPool[4]][2])

        return bossCheckpoint.format(bossFight1,bossFight2,bossFight3,bossFight4,bossFight5,
                                     bossLoc1,bossLoc2,bossLoc3,bossLoc4,bossLoc5,
                                     bossPool[0],bossPool[1],bossPool[2],bossPool[3],bossPool[4],
                                     bossCue[bossPool[0]][0],bossCue[bossPool[0]][1],bossCue[bossPool[1]][0],bossCue[bossPool[1]][1],
                                     bossCue[bossPool[2]][0],bossCue[bossPool[2]][1],bossCue[bossPool[3]][0],bossCue[bossPool[3]][1],
                                     bossCue[bossPool[4]][0],bossCue[bossPool[4]][1],
                                     bossReturn,wardenScaling)
    
    #### Standard Mode

    bossCheckpoint = """
    function "bossCheckpoint"
    {{
        SetStopFlag(STOPFLAG_TALK)
        
        SetFlag(TF_MENU_SELECT2, 0)
        MenuReset()
        MenuType(MENUTYPE_POPUP)
        
        //--------------------------------------------------------------------------------------

        if({0} && !FLAG[GF_06MP6305_TALK_HYDRA])
        {{
            MenuAdd(10, "#2C{4}: Ocean Warden({9})")	
        }}
        else if(!{0} || FLAG[GF_06MP6305_TALK_HYDRA])
        {{
            MenuAdd(11, "{4}: Ocean Warden({9})")	
        }}

        if({1} && !FLAG[GF_06MP6306_TALK_MINOS])	
        {{
            MenuAdd(20, "#2C{5}: Frost Warden({10})")	
        }}
        else if(!{1} || FLAG[GF_06MP6306_TALK_MINOS])
        {{
            MenuAdd(21, "{5}: Frost Warden({10})")	
        }}
        
        if({2} && !FLAG[GF_06MP6307_TALK_NESTOR])	
        {{
            MenuAdd(30, "#2C{6}: Insect Warden({11})")	
        }}
        else if(!{2} || FLAG[GF_06MP6307_TALK_NESTOR])
        {{
            MenuAdd(31, "{6}: Insect Warden({11})")	
        }}

        if({3} && !FLAG[GF_06MP6308_TALK_SARAI])	
        {{
            MenuAdd(40, "#2C{7}: Sky Warden({12})")	
        }}
        else if(!{3} || FLAG[GF_06MP6308_TALK_SARAI])
        {{
            MenuAdd(41, "{7}: Sky Warden({12})")	
        }}			
        //--------------------------------------------------------------------------------------
        

        MenuEnable( 11, 0)
        MenuEnable( 21, 0)
        MenuEnable( 31, 0)
        MenuEnable( 41, 0)

        MenuOpen( TF_MENU_SELECT2 , 283 , ADOLMENU_PPOSY , -2 , -2 , 10 , 1)
        WaitMenu(0)
        CloseMessage(6,0)
        WaitCloseMessage(6)
        MenuClose(10, 0)
        
        if(FLAG[TF_MENU_SELECT2] == 10)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            {13}
            {14}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()
        }}
        else if(FLAG[TF_MENU_SELECT2] == 20)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            {15}
            {16}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()
        }}
        else if(FLAG[TF_MENU_SELECT2] == 30)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            {17}
            {18}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()  
        }}
        else if(FLAG[TF_MENU_SELECT2] == 40)
        {{
            MenuClose(10, 0)
            SetFlag(GF_TBOX_DUMMY127,1)
            GetItem(ICON3D_971,1)
            {19}
            {20}
            //FadeIn(FADE_BLACK,FADE_NORMAL)
            WaitFade()  
        }}
        ResetStopFlag(STOPFLAG_TALK)
    
    }}
    
    function "wardenScaling"
    {{
        {8} 
    }}

    {21}
"""
    bossReturn = """
        function "bossReturn"
        {{
            SetFlag( SF_BOSS_BATTLE, 0 )
            if(WORK[WK_MAPNAMENO] == {0})
            {{
                LoadArg("map/mp6305/mp6305.arg")
                EventCue("mp6305:EV_M06S143_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {1})
            {{
                LoadArg("map/mp6306/mp6306.arg")
                EventCue("mp6306:EV_M06S163_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {2})
            {{
                LoadArg("map/mp6307/mp6307.arg")
                EventCue("mp6307:EV_M06S183_ED")
            }}
            else if(WORK[WK_MAPNAMENO] == {3})
            {{
                LoadArg("map/mp6308/mp6308.arg")
                EventCue("mp6308:EV_M06S203_ED")
            }}  
        }}
"""
    bossReturn = bossReturn.format(bossCue[bossPool[0]][2], bossCue[bossPool[1]][2], bossCue[bossPool[2]][2], bossCue[bossPool[3]][2])

    return bossCheckpoint.format(bossFight1,bossFight2,bossFight3,bossFight4,
                                     bossLoc1,bossLoc2,bossLoc3,bossLoc4,wardenScaling,
                                     bossPool[0],bossPool[1],bossPool[2],bossPool[3],
                                     bossCue[bossPool[0]][0],bossCue[bossPool[0]][1],bossCue[bossPool[1]][0],bossCue[bossPool[1]][1],
                                     bossCue[bossPool[2]][0],bossCue[bossPool[2]][1],bossCue[bossPool[3]][0],bossCue[bossPool[3]][1],
                                     bossReturn)

def bossScaling(playthroughAllProgression,parameters):
    bossLevels = [7,5,13,14,20,23,26,28,29,32,35,40,43,45,48,51,53,58,60,60,80]
    bossIDs = {'Byfteriza': 'M0111',
               'Avalodragil': 'B150',
               'Serpentus': 'B100',
               'Clareon': 'B000',
               'Lonbrigius': 'B101B',
               'Gargantula': 'B001',
               'Magamandra': 'B102',
               'Laspisus': 'B002',
               'Kiergaard Weissman': 'B152',
               'Avalodragil 2': 'B154',
               'Giasburn': 'B003',
               'Brachion': 'B006',
               'Exmetal': 'B104',
               'Carveros': 'B004',
               'Pirate Revenant': 'B103',
               'Coelacantos': 'B106',
               'Oceanus': 'B007',
               'Doxa Griel': 'B105',
               'Basileus': 'B005',
               'Mephorash': 'B153',
               'Silvia': 'B155',}
    remainingBosses = []
    finalBossLevels = []
    bossLevelsDictByRegion = {}

    if not parameters.goal == 'Untouchable': # Make sure Melaiduma's level and ID are in the pool if he's not the goal
        bossLevels.append(99) 
        bossIDs['Melaiduma'] = 'B170' 

    if not parameters.goal == 'Release the Psyches': # Make sure the Psyches' levels and IDs are in the pool if they aren't the goal
        bossLevels.extend([67,70,73,75])
        bossIDs['Psyche-Hydra'] = 'B112'
        bossIDs['Psyche-Minos'] = 'B110'
        bossIDs['Psyche-Nestor'] = 'B111'
        bossIDs['Psyche-Ura'] = 'B008'

    # build out a list of IDs for us to track what bosses aren't in the pool
    for boss in bossIDs.keys():
            remainingBosses.append(bossIDs.get(boss))

    random.seed(parameters.seed)
    spoilerLog.write(f'\n'
                     f'Boss Levels:\n')   
    # process bosses that are accessible before the goal in the seed and assign them levels in ascending order as the playthrough should have them in order
    for boss in playthroughAllProgression.bosses:
        if boss.mapCheckID in bossIDs.keys():
            bossID = bossIDs.get(boss.mapCheckID)
            bossLevel = bossLevels.pop(0)
            finalNonGoalBossLevel = random.randrange(bossLevel-2,bossLevel+2)
            finalBossLevels.append([remainingBosses.pop(remainingBosses.index(bossID)),random.randrange(bossLevel-2,bossLevel+2)])
            spoilerLog.write(f'\tBoss: {boss.mapCheckID} - Level {finalBossLevels[-1][1]}\n')

            if boss.mapCheckID in ['Clareon','Gargantula','Laspisus','Giasburn','Brachion','Carveros','Pirate Revenant','Oceanus','Basileus','Mephorash']:  #only bosses with psyches flags 
                bossLevelsDictByRegion[boss.locRegion] = finalBossLevels[-1][1] #storing this for use with psyches
        elif boss.mapCheckID == 'Gilkyra Encounter':
            finalBossLevels.append(['M0902', max(random.randrange(bossLevel-4,bossLevel+4), 5)])
    
    # bosses post goal have their levels shuffled from among the remaining levels in the boss level pool
    random.shuffle(bossLevels)
    for bossID in remainingBosses:
        bossLevel = bossLevels.pop(0)
        finalBossLevels.append([bossID,random.randrange(bossLevel-2,bossLevel+2)])
        bossName = [name for name, id in bossIDs.items() if id == bossID][0]
        spoilerLog.write(f'\tBoss: {bossName} - Level {finalBossLevels[-1][1]}\n')

    fscBosses = ''
    script = '\tfunction "bossScaling"\n\t{\n'
    for boss in finalBossLevels:
        script = script + '\t\tSetChrWorkGroup(' + boss[0] + ', CWK_LV, ' + str(boss[1]) + ')\n'
        #handling special cases for bosses with forms or minions
        if boss[0] == 'B005':
            script = script + '\t\tSetChrWorkGroup(M0644, CWK_LV, ' + str(boss[1]) + ')\n'
            script = script + '\t\tSetChrWorkGroup(M0643, CWK_LV, ' + str(boss[1]-1) + ')\n' #if you can beat these enemies you can reach basileus so scale them too
        if boss[0] == 'B101B':
            script = script + '\t\tSetChrWorkGroup(B101, CWK_LV, ' + str(boss[1]) + ')\n'
        if boss[0] == 'B170': # set FSC bosses relative to Melaiduma if Melaiduma is scaled
            fscBosses = (f'\n\tfunction "fscBosses"\n'
                         f'\t{{\n'
                         f'\t\tSetChrWorkGroup(B103,	CWK_LV,	' + str(max(1,boss[1]-10)) + ')\n'
                         f'\t\tSetChrWorkGroup(B006,	CWK_LV,	' + str(max(1,boss[1]-12)) + ')\n'
                         f'\t\tSetChrWorkGroup(B001,	CWK_LV,	' + str(max(1,boss[1]-14)) + ')\n'
                         f'\t\tSetChrWorkGroup(B105,	CWK_LV,	' + str(max(1,boss[1]-16)) + ')\n'
                         f'\t\tSetChrWorkGroup(B161,	CWK_LV,	' + str(max(1,boss[1]-18)) + ')\n'
                         f'\t}}\n')
                        
    script = script + '\t}'

    return script + fscBosses, finalNonGoalBossLevel, bossLevelsDictByRegion

def buildFSCWarp():
    function = ''
    function = function + """
function "FSC_warp"
{
    SetStopFlag(STOPFLAG_TALK)
    SetFlag(TF_MENU_SELECT2, 0)
    MenuReset()
    MenuType(MENUTYPE_POPUP)

    if(FLAG[GF_TBOX_DUMMY156])
    {
        MenuAdd(10, "1F - Chamber of Braziers, Ent")	
    }
    else if(!FLAG[GF_TBOX_DUMMY156])
    {
        MenuAdd(11, "1F - Chamber of Braziers, Ent")	
    }


    if(FLAG[GF_TBOX_DUMMY157])
    {
        MenuAdd(20, "2F - Chamber of Stone, Ent")	
    }
    else if(!FLAG[GF_TBOX_DUMMY157])
    {
        MenuAdd(21, "2F - Chamber of Stone, Ent")	
    }

    if(FLAG[GF_TBOX_DUMMY158])
    {
        MenuAdd(30, "3F - Chamber of Clairvoyance, Ent")	
    }
    else if(!FLAG[GF_TBOX_DUMMY158])
    {
        MenuAdd(31, "3F - Chamber of Clairvoyance, Ent")	
    }

    if(FLAG[GF_TBOX_DUMMY159])
    {
        MenuAdd(40, "4F - Chamber of Frost, Ent")	
    }
    else if(!FLAG[GF_TBOX_DUMMY159])
    {
        MenuAdd(41, "4F - Chamber of Frost, Ent")	
    }

    if(FLAG[GF_TBOX_DUMMY160])
    {
        MenuAdd(50, "5F - Chamber of Magma, Ent")	
    }
    else if(!FLAG[GF_TBOX_DUMMY160])
    {
        MenuAdd(51, "5F - Chamber of Magma, Ent")	
    }

    MenuEnable( 11, 0)
    MenuEnable( 21, 0)
    MenuEnable( 31, 0)
    MenuEnable( 41, 0)
    MenuEnable( 51, 0)
    MenuOpen( TF_MENU_SELECT2 , 283 , ADOLMENU_PPOSY , -2 , -2 , 10 , 1)
    WaitMenu(0)
    CloseMessage(6,0)
    WaitCloseMessage(6)
    MenuClose(10, 0)
    
    if(FLAG[TF_MENU_SELECT2] == 10)
    {
        MenuClose(10, 0)
        LoadArg("map/mp6511/mp6511.arg")
        EventCue("mp6511:init")
        WaitFade()
    }
    else if(FLAG[TF_MENU_SELECT2] == 20)
    {
        MenuClose(20, 0)
        LoadArg("map/mp6521/mp6521.arg")
        EventCue("mp6521:init")
        WaitFade()
    }
    else if(FLAG[TF_MENU_SELECT2] == 30)
    {
        MenuClose(30, 0)
        LoadArg("map/mp6531/mp6531.arg")
        EventCue("mp6531:init")
        WaitFade()
    }
    else if(FLAG[TF_MENU_SELECT2] == 40)
    {
        MenuClose(40, 0)
        LoadArg("map/mp6541/mp6541.arg")
        EventCue("mp6541:init")
        WaitFade()
    }
            else if(FLAG[TF_MENU_SELECT2] == 50)
    {
        MenuClose(50, 0)
        LoadArg("map/mp6551/mp6551.arg")
        EventCue("mp6551:init")
        WaitFade()
    }
    ResetStopFlag(STOPFLAG_TALK)
}
"""
    return function
        
def buildLandmarks(location,script):
    scriptName = buildLocScripts(location.locID, False)
    itemIcon = -1
    itemQuantity = 1
    itemSE = 'ITEMMSG_SE_BETTER'
    message = "#2C" + location.itemName + "#4C" + landmarkMessage

    landmarks = {
        'Birdsong Rock':            {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F001, MARKER_EV_LC_MP1112, 191.56f, -1038.36f, 19.90f, 191.56f, -1038.36f,LOCATION_MP1112,MN_F_SOUTHWEST_PLANE_MP1112,0)',
                                    'flag': 'GF_LOCATION01'},
        'Cobalt Crag':              {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F005, MARKER_EV_LC_MP1132, 248.87f, -1574.29f, 6.64f, 248.87f, -1574.29f,LOCATION_MP1132, MN_F_MP1132,0)',
                                    'flag': 'GF_LOCATION02'},
        'Rainbow Falls':            {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP1301, MARKER_EV_LC_MP1304, -168.19f, -30.17f, 1.17f , -168.19f, -30.17f,LOCATION_MP1304,MN_D_MP1304,0)',
                                    'flag': 'GF_LOCATION03'},
        'Metavolicalis':            {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F008, MARKER_EV_LC_MP1117, -904.35f, -537.19f, 6.24f, -904.35f, -537.19f,LOCATION_MP1117,MN_F_MP1117,1)',
                                    'flag': 'GF_LOCATION04'},
        'Parasequoia':              {'marker':  'SetMapMarker(SMI_LOCATION ,PAGE_F008, MARKER_EV_LC_MP1135, -724.75f, -824.40f, 151.63f,-724.75f, -824.40f,LOCATION_MP1135,MN_F_MP1135,0)',
                                    'flag': 'GF_LOCATION05'},
        'Chimney Rock':             {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F002, MARKER_EV_LC_MP3104, 296.16f,-641.87f,93.75f, 296.16f,-641.87f,LOCATION_MP3104,MN_F_MP3104,0)',
                                    'flag': 'GF_LOCATION08'},
        'Indigo Mineral Vein':      {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP4301, MARKER_EV_LC_MP4303, -95.07f,-305.72f,7.17f, -95.07f,-305.72f,LOCATION_MP4303,MN_D_EROSIONVALLEY_MP4303,0)',
                                    'flag': 'GF_LOCATION09'},
        'Beached Remains':          {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F010, MARKER_EV_LC_MP1119, 842.68f,792.22f,-2.67f, 842.68f,792.22f,LOCATION_MP1119,MN_F_MP1119,0)',
                                    'flag': 'GF_LOCATION10'},
        'Field of Medicinal Herbs': {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP230x, MARKER_EV_LC_MP2306, 300.59f,-2.19f,12.86f, 300.59f,-2.19f,LOCATION_MP2306,MN_D_MP2306,0)',
                                    'flag': 'GF_LOCATION11'},
        'Airs Cairn':               {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F014, MARKER_EV_LC_MP3107, -431.89f,-340.84f,243.95f, -431.89f,-340.84f,LOCATION_MP3107,MN_F_MP3107,0)',
                                    'flag': 'GF_LOCATION13'},
        'Zephyr Hill':              {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F006, MARKER_EV_LC_MP3102, -238.71f, -1189.07f, 171.47f, -238.71f, -1189.07f,LOCATION_MP3102,MN_F_MP3102,0)',
                                    'flag': 'GF_LOCATION16'},
        'Lapis Mineral Vein':       {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP746x, MARKER_EV_LC_MP7462, 63.881f , 105.550f , 8.446f, 63.881f , 105.550f,LOCATION_MP7462,MN_D_MP7462,0)',
                                    'flag': 'GF_LOCATION17'},
        'Beehive':                  {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F012, MARKER_EV_LC_MP1114, 627.60f, -727.38f, 26.55f, 627.60f, -727.38f,LOCATION_MP1114,MN_F_MP1114,0)',
                                    'flag': 'GF_LOCATION19'},
        'Ship Graveyard':           {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F004, MARKER_EV_LC_MP1116, 881.70f, -1372.22f, -0.92f, 881.70f, -1372.22f,LOCATION_MP1116,MN_F_MP1116,0)',
                                    'flag': 'GF_LOCATION21'},
        'Hidden Pirate Storehouse': {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP741x, MARKER_EV_LC_MP7411, -119.33f, -89.28f, 21.75f, -119.33f, -89.28f,LOCATION_MP7411,MN_D_MP7411,0)',
                                    'flag': 'GF_LOCATION22'},
        'Magna Carpa':              {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F013, MARKER_EV_LC_MP1122, 530.35f, -1178.29f, 2.62f, 530.35f, -1178.29f,LOCATION_MP1122,MN_F_MP1122,0)',
                                    'flag': 'GF_LOCATION23'},
        'Prismatic Mineral Vein':   {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F031, MARKER_EV_LC_MP7102, -57.11f, 388.66f, -28.86f, -57.11f, 388.66f,LOCATION_MP7102,MN_F_MP7102,3)',
                                    'flag': 'GF_LOCATION24'},
        'Unicalamites':             {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F033, MARKER_EV_LC_MP5102, 185.18f, 739.42f, 116.63f, 185.18f, 739.42f,LOCATION_MP5102,MN_F_MP5102,0)',
                                    'flag': 'GF_LOCATION25'},
        'Breath Fountain':          {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F034, MARKER_EV_LC_MP6116, 43.27f, 1324.20f, 52.69f, 43.27f, 1324.20f,LOCATION_MP6116,MN_F_MP6116,0)',
                                    'flag': 'GF_LOCATION27'},
        'Ancient Tree':             {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F034, MARKER_EV_LC_MP6112, -11.73f, 1062.84f, 49.82f, -11.73f, 1062.84f,LOCATION_MP6112,MN_F_MP6112,0)',
                                    'flag': 'GF_LOCATION28'},
        'Sky Garden':               {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F037, MARKER_EV_LC_MP6114, -986.765f, 789.094f, 105.952f, -986.765f, 789.094f,LOCATION_MP6114,MN_F_MP6114,0)',
                                    'flag': 'GF_LOCATION32'},
        'Soundless Hall':           {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP748x, MARKER_EV_LC_MP7481, 78.00f, 32.01f, -29.00f, 78.00f, 32.01f,LOCATION_MP7481,MN_D_MP7481,0)',
                                    'flag': 'GF_LOCATION33'},
        'Graves of Ancient Heroes': {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_F038, MARKER_EV_LC_MP6109, -796.36f, 1322.28f, 66.29f, -796.36f, 1322.28f,LOCATION_MP6109,MN_F_MP6109,0)',
                                    'flag': 'GF_LOCATION34'},
        'Milky White Vein':         {'marker': 'SetMapMarker(SMI_LOCATION ,PAGE_MP747x, MARKER_EV_LC_MP7471, -40.94f,88.52f,2.60f, -40.94f,88.52f,LOCATION_MP7471,MN_D_MP7471,0)',
                                    'flag': 'GF_LOCATION18'},   
    }
    
    if location.event:
        getLandmarkFunction = """
function "{0}"
{{
    
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    SetFlag({5},1)
    {6}
    {7}
}}
"""
    else: 
        fillChest(location,148,1)
        getLandmarkFunction = """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    SetFlag({5},1)
    {6}
    {7}
    ResetStopFlag(STOPFLAG_TALK)
}}
"""   
    return getLandmarkFunction.format(scriptName,itemIcon,itemQuantity,itemSE,message,landmarks[location.itemName]['flag'],landmarks[location.itemName]['marker'],script)


# we're doing away with this old method and simplifying everything. Max exp is a character stat in this game and the status file contains an editable version of it.
# so instead of the old method we're going to call a function to divide the character's max exp by our multiplier.
# this achives the same effect as a global exp multiplier in a far cleaner way than our old method.
# there is no growth rate anymore because honestly a lot of what it was going for is achieved through boss level scaling better
def expMult(parameters):
    newExpMult(parameters)








