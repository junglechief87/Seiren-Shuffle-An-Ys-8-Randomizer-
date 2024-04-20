import csv
import os.path
import shared.classr as classr
from shared.functions import *  
from randomizer.crew import *
from randomizer.shuffle import *
from randomizer.gameStartFunctions import *

#This is essentially the BnB for how this rando works. This script writes a big .scp file, the game's native scripting files, that we call for all randomized locations (as well as some other important functions for a rando)
#This takes in the game's shuffled list of loctions and then builds the scripts.
#We named our script file rng because we need something short, our script calls from the chests are limited to 8 characters so our standard format for script call is rng:(locID where locID is a 4 digit id).
#Plus rng.scp is a fitting filename for a rando.
patchFile = ''
scpIncludeList = ['#include "inc/mons.h"','#include "inc/def.h"','#include "inc/efx.h"','#include "inc/flag.h"','#include "inc/se.h"',
                  '#include "inc/scr_inc.h"','#include "inc/3dicon.h"','#include "inc/skilldef.h"','#include "inc/vo.h"'] #standard set of header files used in most Ys 8 .scp files
genericMessage = " Obtained."
crewMessage = " Joined the Village."
partyMessage = " Joined the Party."
rngScriptFile = getLocFile('rng','script')


def rngPatcherMain(parameters):
    global patchFile
    numBigLuckyBox = parameters.bigLuckyBox
    numLuckyBox = parameters.mediumLuckyBox
    numSmallLuckyBox = parameters.smallLuckyBox
    
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
                patchFile = patchFile + buildStartParameters(location) 
                patchFile = patchFile + manageEarlyGameParty(location)
                patchFile = patchFile + soloStartingCharacterEvent(location) 

            if location.item: 
                patchFile = patchFile + genericItemMessage(location,script,parameters)
                  
            elif location.crew:
                patchFile = patchFile + buildCrewLocation(location,script)

    patchFile = patchFile + interceptionHandler(parameters)
    patchFile = patchFile + jewelTrade(shuffledLocations)
    patchFile = patchFile + goal(parameters)
    patchFile = patchFile + endingHandler(parameters)

    with open(rngScriptFile, 'w', encoding = 'Shift-JIS') as fileToPatch:
        fileToPatch.write(patchFile)
        fileToPatch.close()

def genericItemMessage(location,script,parameters):    
    scriptName = buildLocScripts(location.locID,False)
    itemIcon = getIcon(location.itemID)
    itemQuantity = location.quantity
    #'Maiden Journal','Blue Seal of Whirling Water','Green Seal of Roaring Stone','Golden Seal of Piercing Light','Treasure Chest Key','Frozen Flower','Shrine Maiden Amulate'
    danaPastEventsItems = [698,700,701,702,796,699,727]
    
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
    elif location.itemID == 775: #oricalcum
        script = script + oriOre()
        script = script + shopUpgrades()
    elif location.itemID == 9: #mistlltein (probably mispelled that)
        script = script + sopEvent()
    elif location.itemID == 778:#flame stone
        script = script + shopUpgrades()
    elif location.itemID == 770: #logbook from east coast cave
        script = script + pirateShipDocks()
    elif location.itemID == 760 or location.itemID == 761 or location.itemID == 762 or location.itemID == 763: #T memos
        script = script + interceptUnlock()
    elif location.itemID == 629: #fishing rod
        startingBait = """
    GetItem(ICON3D_FISHBAIT_WORM,10)
    """
        script = script + startingBait

    if not location.progression and not location.event and location.item and location.locRegion.find('Sanctuary Crypt') == -1:
        if parameters.bigLuckyBox > 0:
            script = script + luckyBox('bigLuckyBox')
            parameters.getLuckyChecks('big',parameters.bigLuckyBox-1)
        elif parameters.mediumLuckyBox > 0:
            script = script + luckyBox('luckyBox')
            parameters.getLuckyChecks('med',parameters.mediumLuckyBox-1)
        elif parameters.smallLuckyBox > 0:
            script = script + luckyBox('smallLuckyBox')
            parameters.getLuckyChecks('small',parameters.smallLuckyBox-1)
        
    message = genericMessage

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
        getItemFunction =  """
function "{0}"
{{
    SetStopFlag(STOPFLAG_TALK)
    GetItem({1},{2})
    GetItemMessageExPlus({1},{2},{3},"{4}",0,0)
    WaitPrompt()
    WaitCloseWindow()

    {5}

    ResetStopFlag(STOPFLAG_TALK)
}}
"""          
    return getItemFunction.format(scriptName,itemIcon,itemQuantity,itemSE,message,script)

def buildCrewLocation(location,script):
    scriptName = buildLocScripts(location.locID,False)
    itemIcon = -1
    itemQuantity = 1
    itemSE = 'ITEMMSG_SE_BETTER'
    
    if location.party:
        message = location.itemName + partyMessage
    elif location.crew:
        message = location.itemName + crewMessage
        
    crewFlags = getCrewFlags(location)

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

#This is the orichalcum, the flag here is the trigger for speaking with Kathleen about the orichalcum and having new weapons made.
#That event then trips the flag for being able to kill enemies flagged as Saurians.
def oriOre():
    script = """
        SetFlag(GF_03MP7401_GET_MATERIAL, 1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Turn this into Kathleen.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    """
    return script

#Sword of Psyches event. Adol gets Mistletein(probably mispelled that)
def sopEvent():
    script = """
	SetFlag(GF_ADOLWEAPON_BACKUP,(ADOL.CHRWORK[CWK_WEAPON]))
	GetItem(ICON3D_WP_ADOL_008,1)
	EquipWeapon(ADOL,ICON3D_WP_ADOL_008)
	SetFlag(GF_TBOX_DUMMY071,1)
	"""
    return script

#This makes shop upgrades progressive and is also what makes the flame stones actually do something.
#In vanilla all they did was act as a signpost for flags that were already set. 
def shopUpgrades():
    script = """
    if (!FLAG[GF_TBOX_DUMMY081])
    {
        SetFlag(GF_SHOP_RANK_3_02,1)
        SetFlag(GF_02MP4309_KILL_SPIDER,1)
        SetFlag(GF_QS201_SHOP_ADD,1)
        SetFlag(GF_TBOX_DUMMY081,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 2.",0,0)
        WaitPrompt()
        WaitCloseWindow()
        
    }
    else if (!FLAG[GF_TBOX_DUMMY082])
    {
        SetFlag(GF_SHOP_RANK_3_05,1)
        SetFlag(GF_SHOP_RANK_4_01,1)
        //Hummel has no shop upgarde to get him this weapon tier and therefore cannot upgrade to it. So we'll give it to him when we hit this level so Hummel isn't stuck with a  tier 2 weapon all game.
        GetItem(ICON3D_WP_HUMMEL_002,1)
	    EquipWeapon(HUMMEL, ICON3D_WP_HUMMEL_002)
        SetFlag(GF_TBOX_DUMMY082,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 3.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    else if (!FLAG[GF_TBOX_DUMMY083])
    {
        SetFlag(GF_SHOP_RANK_5_02,1)
        SetFlag(GF_TBOX_DUMMY083,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 4.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    else if (!FLAG[GF_TBOX_DUMMY084])
    {
        SetFlag(GF_SHOP_RANK_5_04,1)
        SetFlag(GF_QS222_SHOP_ADD,1)
        SetFlag(GF_QS310_GET_ITEM,1)
        SetFlag(GF_QS310_GET_ITEM2,1)
        SetFlag(GF_QS310_GET_ITEM3,1)
        SetFlag(GF_TBOX_DUMMY084,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 5.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    else if (!FLAG[GF_TBOX_DUMMY085])
    {
        SetFlag(GF_SHOP_RANK_5_07,1)
        SetFlag(GF_TBOX_DUMMY085,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank 6.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    else if (!FLAG[GF_TBOX_DUMMY086])
    {
        SetFlag(GF_SHOP_RANK_6_01,1)
        SetFlag(GF_05MP6349_KILL_BOSS,1)
        SetFlag(GF_QS600_SHOP_ADD,1)
        SetFlag(GF_TBOX_DUMMY086,1)
        SetFlag(GF_NPC_6_03_AFTER_INTERCEPT12,1)
        SetFlag(GF_06MP1201_GOTO_GEND,1)
        GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Shops have been upgraded: Rank MAX.",0,0)
        WaitPrompt()
        WaitCloseWindow()
    }
    """

    return script

#We make some chests lucky, they will give stacks of exp boosting items.
def luckyBox(boxType):
    if boxType == 'bigLuckyBox':
        script = """

    GetItem(ICON3D_US_ADD_LEVEL,3)
    GetItemMessageExPlus(ICON3D_US_ADD_LEVEL,3,ITEMMSG_SE_BETTER," LUCKY!!!",0,0)
    WaitPrompt()
    WaitCloseWindow()	

"""
    elif boxType == 'luckyBox':
        script = """

    GetItem(ICON3D_US_ADD_EXP_03,3)
    GetItemMessageExPlus(ICON3D_US_ADD_EXP_03,3,ITEMMSG_SE_BETTER," LUCKY!!",0,0)
    WaitPrompt()
    WaitCloseWindow()	

"""
    elif boxType == 'smallLuckyBox':
        script = """

    GetItem(ICON3D_US_ADD_EXP_02,5)
    GetItemMessageExPlus(ICON3D_US_ADD_EXP_02,5,ITEMMSG_SE_BETTER," LUCKY!",0,0)
    WaitPrompt()
    WaitCloseWindow()	

"""

    return script

def goal(parameters):
    if parameters.goal == 'Find Crew':
        selectionSphereAccess ="""
function "goal"
{{
    if(WORK[WK_NPCNUM] >= {0} && !FLAG[GF_06MP6301_GOTO_BOSSROOM])
    {{
        SetFlag( GF_06MP6301_OPEN_STAIRS , 1 )
	    SetFlag( GF_06MP6301_GOTO_BOSSROOM , 1 )
    }}
}}
"""
    return selectionSphereAccess.format(str(parameters.numGoal))

def endingHandler(parameters):
    script = """
function "ending"
{
    LoadArg("map/mp0021/mp0021.arg")
    EventCue("mp0021:EV_M07S130")
}
"""

    return script

#This flag was original tripped by the chest event from the chest on the Docks of East Coast Cave. Now it has been moved to the note that was originally in that chest.
def pirateShipDocks():
    script = """

    SetFlag(GF_05MP7411_READ_NOTE1, 1)
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"The gangway has been dropped.",0,0)
    WaitPrompt()
    WaitCloseWindow()

"""
    return script

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

            









