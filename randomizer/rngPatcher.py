import csv
import os.path
import shared.classr as classr
from shared.functions import *  
from randomizer.crew import *
from randomizer.shuffle import *
from randomizer.gameStartFunctions import *
from patch.chestPatcher import *
from randomizer.audioShuffle import *
#This is essentially the BnB for how this rando works. This script writes a big .scp file, the game's native scripting files, that we call for all randomized locations (as well as some other important functions for a rando)
#This takes in the game's shuffled list of loctions and then builds the scripts.
#We named our script file rng because we need something short, our script calls from the chests are limited to 8 characters so our standard format for script call is rng:(locID where locID is a 4 digit id).
#Plus rng.scp is a fitting filename for a rando.
patchFile = ''
scpIncludeList = ['#include "inc/mons.h"','#include "inc/def.h"','#include "inc/efx.h"','#include "inc/flag.h"','#include "inc/se.h"',
                  '#include "inc/scr_inc.h"','#include "inc/3dicon.h"','#include "inc/skilldef.h"','#include "inc/vo.h"','#include "inc/temp/rng.h"'] #standard set of header files used in most Ys 8 .scp files
genericMessage = " Obtained."
crewMessage = " Joined the Village."
partyMessage = " Joined the Party."
skillMessage = " has learned skill #2C"
landmarkMessage = ' discovered.'
rngScriptFile = getLocFile('rng','script')


def rngPatcherMain(parameters):
    global patchFile
    patchFile = ''

    if parameters.shuffleBgm:
        randomize_bgmtbl(parameters.seed)

    shuffledLocations = shuffleLocations(parameters) #shuffle and fill functions run from this call

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
            elif location.mapCheckID == 'Psyches':
                patchFile = patchFile + buildPsyches(location,parameters)
            elif 637 <= location.locID <= 660:
                patchFile = patchFile + buildLandmarks(location,script)
    patchFile = patchFile + expMult(parameters)
    patchFile = patchFile + interceptionHandler(parameters)
    patchFile = patchFile + jewelTrade(shuffledLocations)
    patchFile = patchFile + octusGoal(parameters)
    patchFile = patchFile + goal(parameters)
    patchFile = patchFile + endingHandler(parameters)
    with open(rngScriptFile, 'w', encoding = 'Shift-JIS') as fileToPatch: #build the entire rng file from one big string
        fileToPatch.write(patchFile)
        fileToPatch.close()

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
//    GetItem({1},{2})
//    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
//    WaitPrompt()
//    WaitCloseWindow()
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
    skillInfo = getSkillInfo(location.itemName) #retuns tuple: character,skill name,character name
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
        SetFlag(GF_TBOX_DUMMY131, 1) // activate load zone to pinnacle from temple approach
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
            
            SetChrWork(DANA,CWK_SUP_STR,(DANA.CHRWORK[CWK_SUP_STR] + 41))
            SetChrWork(RICOTTA,CWK_SUP_STR,(RICOTTA.CHRWORK[CWK_SUP_STR] + 33))
            SetChrWork(HUMMEL,CWK_SUP_STR,(HUMMEL.CHRWORK[CWK_SUP_STR] - 18))
            GetItem(ICON3D_WP_HUMMEL_000, 1)
            GetItem(ICON3D_AM_021, 1)
            EquipWeapon(HUMMEL,ICON3D_WP_HUMMEL_000)
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

            SetChrWork(DANA,CWK_SUP_STR,(DANA.CHRWORK[CWK_SUP_STR] + 34))
            SetChrWork(RICOTTA,CWK_SUP_STR,(RICOTTA.CHRWORK[CWK_SUP_STR] - 55))
            GetItem(ICON3D_WP_RICOTTA_000, 1)
            GetItem(ICON3D_AM_022, 1)
            EquipWeapon(RICOTTA,ICON3D_WP_RICOTTA_000)
        }}
        else if (!FLAG[GF_TBOX_DUMMY082])
        {{
            SetFlag(GF_SHOP_RANK_3_05,1)
            SetFlag(GF_SHOP_RANK_4_01,1)
            //The flag here is the trigger for speaking with Kathleen about the orichalcum and having new weapons made.
            //That event then trips the flag for being able to kill enemies flagged as Saurians.
            SetFlag(GF_03MP7401_GET_MATERIAL, 1)
            //Hummel has no shop upgarde to get him this weapon tier and therefore cannot upgrade to it. So we'll give it to him when we hit this level so Hummel isn't stuck with a tier 2 weapon all game.
            GetItem(ICON3D_WP_HUMMEL_002,1)
            EquipWeapon(HUMMEL, ICON3D_WP_HUMMEL_002)
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

            SetChrWork(DANA,CWK_SUP_STR,(DANA.CHRWORK[CWK_SUP_STR] + 47))
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

            SetChrWork(DANA,CWK_SUP_STR,(DANA.CHRWORK[CWK_SUP_STR] - 130))
            GetItem(ICON3D_AM_023, 1)
            if( !(FLAG[GF_TBOX_DUMMY108] && !FLAG[GF_TBOX_DUMMY109]) )
            {{
                EquipWeapon(DANA,ICON3D_WP_DANA_000)
                GetItem(ICON3D_WP_DANA_000,1)
            }}
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
    
    elif parameters.goal == 'Seiren Escape':
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
    if(ALLITEMWORK[ICON3D_972] >= {0} && !FLAG[GF_06MP6409_OPEN_GATE]) //ICON3D_972:junk item used for tracking
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
    if(ALLITEMWORK[ICON3D_SHIP_PLAN] && ALLITEMWORK[ICON3D_SEIREN_CHART] && ALLITEMWORK[ICON3D_WP_ADOL_008])
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
    if(ALLITEMWORK[ICON3D_972] >= {0}) //ICON3D_972:junk item used for tracking
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

#This sorts out our final boss settings.
#First we figure out what phases we're doing then we run through our script that's called to start the final boss and what's used to call the ending cutscenes.
#if we're only doing theos then the theos start script calls theos and the ending script calls the ending cutscene.
#if we're doing both then the ending cutscene script instead calls origin.
#if we're only doing origin then the theos start script calls the origin boss fight.
#for Past Dana we only load the Io fight
def endingHandler(parameters):

    if parameters.charMode == 'Past Dana':
        ioFightLoad = """
    function "finalBoss"
    {
        LoadArg("map/mp6569m/mp6569m.arg")
	    EventCue("mp6569m:EV_RetryBoss")
    }
    """
        return ioFightLoad
    
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

    return theosStartScript + ending1

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

#we're going to build our scripts for every location where psches could appear. If the boss isn't there then we build a function that does nothing. 
#The hooks will work like any other: rng + locID
#GF_TBOX_DUMMY112 is our flag for release the psyches so these won't get called outside this game mode.
#Therefore we don't need to worry about these not being built outside that flag being on.
#The calls will be an EventCue which could be a little awkward in larger environments when it triggers but this is the best way to make these work logically.
#The random item given, ICON3D_972, is being used to track how many wardens have been fought. It doesn't show up in inventory and the game still tracks it, which isn't true for all unused junk items, so it can be an effective hidden counter.
#I give it when the fight loads because it's easier to plug it in here rather than after every fight and the player is locked into the fight until they've won anyway.
#I'm hijacking this to setup a unique version of this for Past Dana so she'll have bosses that make use of her gimmicks. Still figuring out how I want to handle some of this but this is a good starting place for testing. 
def buildPsyches(location, parameters):
    scriptName = buildLocScripts(location.locID,False)
    callPrompt = ''
    promptFight = ''

    if location.itemName == 'Psyches of the Sky Era\Braziers Fight(DANA)':
        if parameters.charMode == 'Past Dana':
            callPrompt = 'CallFunc("rng:brazierFight")'
            promptFight = brazierFight()
        else:
            callPrompt = 'CallFunc("rng:uraFight")'
            promptFight = uraFight(location.locID)
    elif location.itemName == 'Psyches of the Insectoid Era\Stone Fight(DANA)':
        if parameters.charMode == 'Past Dana':
            callPrompt = 'CallFunc("rng:stoneFight")'
            promptFight = stoneFight()
        else:
            callPrompt = 'CallFunc("rng:nestorFight")'
            promptFight = nestorFight(location.locID)
    elif location.itemName == 'Psyches of the Frozen Era\Clairvoyance Fight(DANA)':
        if parameters.charMode == 'Past Dana':
            callPrompt = 'CallFunc("rng:clairvoyanceFight")'
            promptFight = clairvoyanceFight()
        else:
            callPrompt = 'CallFunc("rng:minosFight")'
            promptFight = minosFight(location.locID)
    elif location.itemName == 'Psyches of the Ocean Era\Frost Fight(DANA)':
        if parameters.charMode == 'Past Dana':
            callPrompt = 'CallFunc("rng:frostFight")'
            promptFight = frostFight()
        else:
            callPrompt = 'CallFunc("rng:hydraFight")'
            promptFight = hydraFight(location.locID)
            
    elif location.itemName == 'Empty Psyches\Magma Fight(DANA)' and parameters.charMode == "Past Dana":
        callPrompt = 'CallFunc("rng:magmaFight")'
        promptFight = magmaFight()
    else:
        callPrompt = """
        SetStopFlag(STOPFLAG_TALK)
        Message("No presence felt.")
        WaitPrompt()
        WaitCloseWindow()
        ResetStopFlag(STOPFLAG_TALK)
        """
    psycheFunction = """
    function "{0}"
    {{
        if(!FLAG[SF_BOSS_BATTLE] && !FLAG[GF_TBOX_DUMMY127])
        {{
            WaitFade()
            Wait(20)
            {1}
        }}
    }}
    {2}
    """
    return psycheFunction.format(scriptName,callPrompt,promptFight)

def brazierFight():
    script = """
    function "brazierFight"
    {
        if(!FLAG[GF_SUBEV_PAST_02_BOSS])
        {
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            Message("The guardian of the Chamber of Braziers is near.")
            WaitPrompt()
            WaitCloseWindow()
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                SetFlag(SF_PAST_MODE, 1)
                LoadArg("map/mp6519m/mp6519m.arg")
                EventCue("mp6519m:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    return script

def stoneFight():
    script = """
    function "stoneFight"
    {
        if(!FLAG[GF_SUBEV_PAST_BOSS_B2])
        {
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            Message("The guardian of the Chamber of Stone is near.")
            WaitPrompt()
            WaitCloseWindow()
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                SetFlag(SF_PAST_MODE, 1)
                LoadArg("map/mp6529m/mp6529m.arg")
                EventCue("mp6529m:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    return script

def clairvoyanceFight():
    script = """
    function "clairvoyanceFight"
    {
        if(!FLAG[GF_SUBEV_PAST_BOSS_B3])
        {
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            Message("The guardian of the Chamber of Clairvoyance is near.")
            WaitPrompt()
            WaitCloseWindow()
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                SetFlag(SF_PAST_MODE, 1)
                LoadArg("map/mp6539m/mp6539m.arg")
                EventCue("mp6539m:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    return script

def frostFight():
    script = """
    function "frostFight"
    {
        if(!FLAG[GF_SUBEV_PAST_BOSS_B4])
        {
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            Message("The guardian of the Chamber of Frost is near.")
            WaitPrompt()
            WaitCloseWindow()
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                SetFlag(SF_PAST_MODE, 1)
                LoadArg("map/mp6549m/mp6549m.arg")
                EventCue("mp6549m:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    return script

def magmaFight():
    script = """
    function "magmaFight"
    {
        if(!FLAG[GF_SUBEV_PAST_BOSS_B5])
        {
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            Message("The guardian of the Chamber of Magma is near.")
            WaitPrompt()
            WaitCloseWindow()
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                SetFlag(SF_PAST_MODE, 1)
                LoadArg("map/mp6559m/mp6559m.arg")
                EventCue("mp6559m:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    return script

def hydraFight(locationID):
    script = """
    function "hydraFight"
    {
        if(!FLAG[GF_06MP6305_TALK_HYDRA])
        {
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            Message("The presence of the Ocean Warden can be felt.")
            WaitPrompt()
            WaitCloseWindow()
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                LoadArg("map/mp6305b/mp6305b.arg")
                EventCue("mp6305b:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    if locationID not in [617,618,619,620,621]:
        script = script + """
    function "warden1Scaling"
    {
        SetLevel("B112", 60)
    }
"""
    else:
        script = script + """
    function "warden1Scaling"
    {
    }
"""
    return script

def minosFight(locationID):
    script = """
    function "minosFight"
    {
        if(!FLAG[GF_06MP6306_TALK_MINOS])
        {
            Message("The presence of the Frozen Warden can be felt.")
            WaitPrompt()
            WaitCloseWindow()
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                LoadArg("map/mp6306b/mp6306b.arg")
                EventCue("mp6306b:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    if locationID not in [617,618,619,620,621]:
        script = script + """
    function "warden2Scaling"
    {
        SetLevel("B110", 60)
    }
"""
    else:
        script = script + """
    function "warden2Scaling"
    {
    }
"""
    return script

def nestorFight(locationID):
    script = """
    function "nestorFight"
    {
        if(!FLAG[GF_06MP6307_TALK_NESTOR])
        {
            Message("The presence of the Insect Warden can be felt.")
            WaitPrompt()
            WaitCloseWindow()
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                LoadArg("map/mp6307b/mp6307b.arg")
                EventCue("mp6307b:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    if locationID not in [617,618,619,620,621]:
        script = script + """
    function "warden3Scaling"
    {
        SetLevel("B111", 60)
    }
"""
    else:
        script = script + """
    function "warden3Scaling"
    {
    }
"""
    return script

def uraFight(locationID):
    script = """
    function "uraFight"
    {
        if(!FLAG[GF_06MP6308_TALK_SARAI])
        {
            Message("The presence of the Sky Warden can be felt.")
            WaitPrompt()
            WaitCloseWindow()
            SetStopFlag(STOPFLAG_SIMPLEEVENT2)
            SetFlag( TF_MENU_SELECT, 0 )
            YesNoMenu(TF_MENU_SELECT,"#7CFight?",1)
            
            //──────────────────────
            //　⇒支援要請を出す
            if( FLAG[TF_MENU_SELECT] )
            {
                SetEnvSEPlayState(-1, 0)
                FadeOut(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                
                SetFlag( TF_MENU_SELECT, 1 )	
            }
            //	⇒やめる
            else
            {
                
                SetFlag( TF_MENU_SELECT, 0 )
            }
            //──────────────────────

            if( FLAG[TF_MENU_SELECT] == 0 )
            {
                CrossFade(FADE_CROSS)
                SetStopFlag(STOPFLAG_NOCHARACLIP)
                
                ResetPartyPos()
                ResetFollowPoint()
                
                RestoreCamera(0,0)
                ResetCameraObserver(0)
                ResetCameraZPlane()
                Wait(FADE_CROSS)
                
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
            else
            {
                SetFlag(GF_TBOX_DUMMY127,1)
                GetItem(ICON3D_972,1)
                LoadArg("map/mp6308b/mp6308b.arg")
                EventCue("mp6308b:EV_RetryBoss")
                //FadeIn(FADE_BLACK,FADE_NORMAL)
                WaitFade()
                ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
            }
        }
        else
        {
            SetStopFlag(STOPFLAG_TALK)
            Message("No presence felt.")
            WaitPrompt()
            WaitCloseWindow()
            ResetStopFlag(STOPFLAG_TALK)
        }
	}
"""
    if locationID not in [617,618,619,620,621]:
        script = script + """
    function "warden4Scaling"
    {
        SetLevel("B008", 60)
    }
"""
    else:
        script = script + """
    function "warden4Scaling"
    {
    }
"""

    return script

def buildLandmarks(location,script):
    scriptName = buildLocScripts(location.locID, False)
    itemIcon = -1
    itemQuantity = 1
    itemSE = 'ITEMMSG_SE_BETTER'
    message = "#2C" + location.itemName + "#4C" + landmarkMessage

    landmarkFlags = ['GF_LOCATION01','GF_LOCATION02','GF_LOCATION03','GF_LOCATION04','GF_LOCATION05','GF_LOCATION08','GF_LOCATION09',\
     'GF_LOCATION10','GF_LOCATION11','GF_LOCATION13','GF_LOCATION16','GF_LOCATION17','GF_LOCATION19','GF_LOCATION21',\
     'GF_LOCATION22','GF_LOCATION23','GF_LOCATION24','GF_LOCATION25','GF_LOCATION27','GF_LOCATION28','GF_LOCATION32',\
     'GF_LOCATION33','GF_LOCATION34','GF_LOCATION18']
    landmarkMarkers = [
        'SetMapMarker(SMI_LOCATION ,PAGE_F001, MARKER_EV_LC_MP1112, 191.56f, -1038.36f, 19.90f, 191.56f, -1038.36f,LOCATION_MP1112,MN_F_SOUTHWEST_PLANE_MP1112,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F005, MARKER_EV_LC_MP1132, 248.87f, -1574.29f, 6.64f, 248.87f, -1574.29f,LOCATION_MP1132, MN_F_MP1132,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP1301, MARKER_EV_LC_MP1304, -168.19f, -30.17f, 1.17f , -168.19f, -30.17f,LOCATION_MP1304,MN_D_MP1304,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F008, MARKER_EV_LC_MP1117, -904.35f, -537.19f, 6.24f, -904.35f, -537.19f,LOCATION_MP1117,MN_F_MP1117,1)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F008, MARKER_EV_LC_MP1135, -724.75f, -824.40f, 151.63f,-724.75f, -824.40f,LOCATION_MP1135,MN_F_MP1135,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F002, MARKER_EV_LC_MP3104, 296.16f,-641.87f,93.75f, 296.16f,-641.87f,LOCATION_MP3104,MN_F_MP3104,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP4301, MARKER_EV_LC_MP4303, -95.07f,-305.72f,7.17f, -95.07f,-305.72f,LOCATION_MP4303,MN_D_EROSIONVALLEY_MP4303,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F010, MARKER_EV_LC_MP1119, 842.68f,792.22f,-2.67f, 842.68f,792.22f,LOCATION_MP1119,MN_F_MP1119,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP230x, MARKER_EV_LC_MP2306, 300.59f,-2.19f,12.86f, 300.59f,-2.19f,LOCATION_MP2306,MN_D_MP2306,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F014, MARKER_EV_LC_MP3107, -431.89f,-340.84f,243.95f, -431.89f,-340.84f,LOCATION_MP3107,MN_F_MP3107,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F006, MARKER_EV_LC_MP3102, -238.71f, -1189.07f, 171.47f, -238.71f, -1189.07f,LOCATION_MP3102,MN_F_MP3102,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP746x, MARKER_EV_LC_MP7462, 63.881f , 105.550f , 8.446f, 63.881f , 105.550f,LOCATION_MP7462,MN_D_MP7462,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F012, MARKER_EV_LC_MP1114, 627.60f, -727.38f, 26.55f, 627.60f, -727.38f,LOCATION_MP1114,MN_F_MP1114,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F004, MARKER_EV_LC_MP1116, 881.70f, -1372.22f, -0.92f, 881.70f, -1372.22f,LOCATION_MP1116,MN_F_MP1116,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP741x, MARKER_EV_LC_MP7411, -119.33f, -89.28f, 21.75f, -119.33f, -89.28f,LOCATION_MP7411,MN_D_MP7411,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F013, MARKER_EV_LC_MP1122, 530.35f, -1178.29f, 2.62f, 530.35f, -1178.29f,LOCATION_MP1122,MN_F_MP1122,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F031, MARKER_EV_LC_MP7102, -57.11f, 388.66f, -28.86f, -57.11f, 388.66f,LOCATION_MP7102,MN_F_MP7102,3)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F033, MARKER_EV_LC_MP5102, 185.18f, 739.42f, 116.63f, 185.18f, 739.42f,LOCATION_MP5102,MN_F_MP5102,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F034, MARKER_EV_LC_MP6116, 43.27f, 1324.20f, 52.69f, 43.27f, 1324.20f,LOCATION_MP6116,MN_F_MP6116,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F034, MARKER_EV_LC_MP6112, -11.73f, 1062.84f, 49.82f, -11.73f, 1062.84f,LOCATION_MP6112,MN_F_MP6112,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F037, MARKER_EV_LC_MP6114, -986.765f, 789.094f, 105.952f, -986.765f, 789.094f,LOCATION_MP6114,MN_F_MP6114,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP748x, MARKER_EV_LC_MP7481, 78.00f, 32.01f, -29.00f, 78.00f, 32.01f,LOCATION_MP7481,MN_D_MP7481,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_F038, MARKER_EV_LC_MP6109, -796.36f, 1322.28f, 66.29f, -796.36f, 1322.28f,LOCATION_MP6109,MN_F_MP6109,0)',
        'SetMapMarker(SMI_LOCATION ,PAGE_MP747x, MARKER_EV_LC_MP7471, -40.94f,88.52f,2.60f, -40.94f,88.52f,LOCATION_MP7471,MN_D_MP7471,0)'
    ]
    landmarkFlag = 'SetFlag(' + landmarkFlags[(location.locID - 637)] +  ', 1)' #landmark flags are in the order they appear in the location file and landmarks start at locID 637
    landmarkMarker = landmarkMarkers[(location.locID - 637)]

    if location.event:
        getLandmarkFunction = """
function "{0}"
{{
    
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()
    {5}
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
    {5}
    {6}
    {7}
    ResetStopFlag(STOPFLAG_TALK)
}}
"""   
    return getLandmarkFunction.format(scriptName,itemIcon,itemQuantity,itemSE,message,landmarkFlag,landmarkMarker,script)


#this function runs once per map load. It's heavy handed but works to increase the exp of every enemy in the game.
#there's a second similar formula we use for a growth rate, it's called per "major" boss defeat, which we do by just checking the flags that are set after each "major" boss and calling again.
#this creates a compounding exp growth curve which should play well with this game's overall exp curve and help make sure levels don't come too quickly in "early game" while remaining relatively fast in "late game".
#the idea is to flatten the overall exp curve in a way that makes sure grinding is never cumbersome in the rando while playthroughs remain fast but retain difficulty.
def expMult(parameters):
    scripExpMult = """
function "expMult"
{{
    if(FLAG[SF_LOADMAP] || FLAG[GF_TBOX_DUMMY127])
    {{
        SetChrWorkGroup(B000,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B001,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B002,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B003,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B004,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B005,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B006,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B007,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B008,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B009,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B010,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B011,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B012,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B013,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B020,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B021,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B022,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B023,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B024,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B025,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B030,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B100,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B101,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B102,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B103,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B104,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B105,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B106,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B110,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B111,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B112,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B150,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B151,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B152,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B153,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B154,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B155,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B161,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B162,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B163,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B164,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B165,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(B170,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0001,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0002,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0003,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0004,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0005,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0006,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0007,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0008,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(G0009,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0100,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0101,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0102,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0103,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0104,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0105,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0106,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0107,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0108,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0109,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0110,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0111,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0112,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0113,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0120,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0121,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0122,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0123,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0124,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0140,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0141,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0142,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0143,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0144,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0145,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0146,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0147,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0148,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0149,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0150,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0151,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0200,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0201,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0202,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0203,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0220,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0221,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0222,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0223,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0224,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0225,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0226,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0240,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0241,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0300,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0301,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0302,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0303,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0340,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0341,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0400,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0401,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0402,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0403,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0440,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0441,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0442,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0500,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0501,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0502,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0503,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0504,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0600,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0601,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0602,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0603,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0604,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0605,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0620,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0621,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0622,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0623,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0640,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0641,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0642,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0643,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0644,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0660,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0661,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0662,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0663,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0664,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0680,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0700,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0701,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0800,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0801,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0805,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0806,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0810,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0811,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0815,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0816,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0830,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0831,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0840,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0841,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0850,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0851,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0860,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0861,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0870,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0871,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0881,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0882,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0883,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0884,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0885,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0886,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0887,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0888,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0889,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0890,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0900,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0901,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0902,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0903,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0910,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0911,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0915,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0916,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0920,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0925,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0926,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0930,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0931,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0935,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0936,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0940,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0941,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0942,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0945,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M0960,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1000,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1001,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1003,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1004,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1005,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1007,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1009,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1010,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1011,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1012,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1013,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1014,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1015,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1020,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1021,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1022,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1030,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1031,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1040,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1041,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1042,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1099,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1100,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1101,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1102,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1103,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1104,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1105,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1200,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1201,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1202,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1203,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1300,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1301,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1400,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1401,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1402,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1403,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1404,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1405,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1406,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1407,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1408,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1409,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1600,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1601,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1602,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1603,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1604,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1605,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1610,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1611,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1612,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M1613,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M2100,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M2101,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M2102,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M2103,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M9917,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M9918,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M9919,CWK_EXPMUL, {0}f)
        SetChrWorkGroup(M9920,CWK_EXPMUL, {0}f)

        SetFlag(GF_TBOX_DUMMY114,0)
		SetFlag(GF_TBOX_DUMMY115,0)
		SetFlag(GF_TBOX_DUMMY116,0)
		SetFlag(GF_TBOX_DUMMY117,0)
		SetFlag(GF_TBOX_DUMMY118,0)
		SetFlag(GF_TBOX_DUMMY119,0)
		SetFlag(GF_TBOX_DUMMY120,0)
		SetFlag(GF_TBOX_DUMMY121,0)
		SetFlag(GF_TBOX_DUMMY122,0)
		SetFlag(GF_TBOX_DUMMY123,0)
		SetFlag(GF_TBOX_DUMMY124,0)
		SetFlag(GF_TBOX_DUMMY125,0)
		SetFlag(GF_TBOX_DUMMY126,0)
        CallFunc("rng:bossCheck")
    }}
}}

function "bossCheck"
{{
	
    if(FLAG[GF_01MP1103_JOIN_SAHAD] && !FLAG[GF_TBOX_DUMMY114])
    {{
        SetFlag(GF_TBOX_DUMMY114,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_02MP1308_KILL_CHAMELEON] && !FLAG[GF_TBOX_DUMMY115])
    {{
        SetFlag(GF_TBOX_DUMMY115,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_TBOX_DUMMY074] && !FLAG[GF_TBOX_DUMMY116])
    {{
        SetFlag(GF_TBOX_DUMMY116,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_02MP2308_KILL_HIPPO] && !FLAG[GF_TBOX_DUMMY117])
    {{
        SetFlag(GF_TBOX_DUMMY117,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_02MP1103_KILL_KIERGAARD] && !FLAG[GF_TBOX_DUMMY118])
    {{
        SetFlag(GF_TBOX_DUMMY118,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_03MP4341_KILL_ANCIENT] && !FLAG[GF_TBOX_DUMMY119])
    {{
        SetFlag(GF_TBOX_DUMMY119,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_04MP6410_KILL_GUARDIAN] && !FLAG[GF_TBOX_DUMMY120])
    {{
        SetFlag(GF_TBOX_DUMMY120,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_05MP6329_KILL_BAHABOSS] && !FLAG[GF_TBOX_DUMMY121])
    {{
        SetFlag(GF_TBOX_DUMMY121,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_05MP0405_READ_REED] && !FLAG[GF_TBOX_DUMMY122])
    {{
        SetFlag(GF_TBOX_DUMMY122,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_TBOX_DUMMY078] && !FLAG[GF_TBOX_DUMMY123])
    {{
        SetFlag(GF_TBOX_DUMMY123,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_TBOX_DUMMY080] && !FLAG[GF_TBOX_DUMMY124])
    {{
        SetFlag(GF_TBOX_DUMMY124,1)
        CallFunc("rng:expGrowth")
    }}
    if((FLAG[GF_06MP6305_TALK_HYDRA] || FLAG[GF_06MP6306_TALK_MINOS] || FLAG[GF_06MP6307_TALK_NESTOR] || FLAG[GF_06MP6308_TALK_SARAI]) && !FLAG[GF_TBOX_DUMMY125])
    {{
        SetFlag(GF_TBOX_DUMMY125,1)
        CallFunc("rng:expGrowth")
    }}
    if(FLAG[GF_SUBEV_06_6413_KILL_BOSS] && !FLAG[GF_TBOX_DUMMY126])
    {{
        SetFlag(GF_TBOX_DUMMY126,1)
        CallFunc("rng:expGrowth")
    }}
}}

function "expGrowth"
{{
    SetChrWorkGroup(B000,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B001,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B002,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B003,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B004,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B005,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B006,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B007,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B008,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B009,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B010,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B011,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B012,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B013,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B020,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B021,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B022,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B023,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B024,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B025,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B030,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B100,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B101,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B102,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B103,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B104,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B105,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B106,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B110,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B111,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B112,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B150,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B151,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B152,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B153,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B154,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B155,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B161,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B162,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B163,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B164,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B165,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(B170,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0001,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0002,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0003,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0004,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0005,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0006,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0007,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0008,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(G0009,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0100,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0101,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0102,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0103,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0104,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0105,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0106,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0107,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0108,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0109,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0110,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0111,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0112,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0113,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0120,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0121,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0122,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0123,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0124,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0140,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0141,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0142,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0143,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0144,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0145,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0146,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0147,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0148,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0149,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0150,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0151,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0200,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0201,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0202,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0203,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0220,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0221,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0222,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0223,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0224,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0225,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0226,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0240,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0241,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0300,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0301,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0302,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0303,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0340,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0341,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0400,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0401,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0402,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0403,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0440,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0441,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0442,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0500,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0501,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0502,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0503,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0504,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0600,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0601,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0602,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0603,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0604,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0605,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0620,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0621,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0622,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0623,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0640,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0641,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0642,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0643,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0644,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0660,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0661,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0662,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0663,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0664,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0680,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0700,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0701,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0800,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0801,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0805,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0806,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0810,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0811,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0815,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0816,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0830,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0831,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0840,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0841,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0850,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0851,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0860,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0861,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0870,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0871,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0881,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0882,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0883,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0884,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0885,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0886,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0887,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0888,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0889,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0890,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0900,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0901,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0902,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0903,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0910,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0911,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0915,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0916,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0920,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0925,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0926,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0930,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0931,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0935,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0936,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0940,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0941,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0942,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0945,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M0960,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1000,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1001,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1003,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1004,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1005,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1007,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1009,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1010,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1011,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1012,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1013,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1014,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1015,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1020,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1021,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1022,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1030,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1031,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1040,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1041,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1042,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1099,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1100,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1101,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1102,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1103,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1104,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1105,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1200,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1201,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1202,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1203,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1300,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1301,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1400,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1401,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1402,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1403,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1404,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1405,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1406,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1407,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1408,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1409,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1600,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1601,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1602,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1603,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1604,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1605,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1610,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1611,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1612,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M1613,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M2100,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M2101,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M2102,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M2103,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M9917,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M9918,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M9919,CWK_EXPMUL, {1}f)
    SetChrWorkGroup(M9920,CWK_EXPMUL, {1}f)
    CallFunc("rng:bossCheck")
    
}}
""" 
    return scripExpMult.format(parameters.expMult,parameters.expGrowth)








