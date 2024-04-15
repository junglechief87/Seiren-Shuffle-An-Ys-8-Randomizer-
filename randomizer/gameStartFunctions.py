from randomizer.crew import *

#This functions was getting too big with so many flags so I split it into it's own file
#I also included the stuff for the starting character functions because they seemed logical to group together
def buildStartParameters(location):
    startingCharacter = getCrewFlags(location) 
    startParams = """
function "startParameters"
{{
    SetFlag(SF_ADOL_JOINOK, 0)
    SetFlag(SF_ADOL_JOINED, 0)
    {0}
    CallFunc("rng:earlyGameParty")
    SetLevel(ADOL,1)
    SetLevel(LAXIA,1)
    SetLevel(SAHAD,1)
    SetLevel(RICOTTA,1)
    SetLevel(HUMMEL,1)
    SetLevel(DANA,1)
    SetFlag( GF_SUBEV_1107_CHECKED_BRIDGE , 1 )  //Checked broken bridge
    SetFlag( GF_03MP1107_REPAIR_ROPE , 1 )      //Had conversation with Ricotta about bridge
    //preset system flags for convenience 
    SetFlag(SF_CAMP_CANT_FORMATION,0)           // Formation menu prohibited
    SetFlag(SF_CAMP_CANT_MEMORYMENU,0)             // Disable memory menu
    SetFlag(SF_CAMP_CANT_DIARY,0)             // Adventure diary menu prohibited
    SetFlag(SF_CAMP_CANT_MAP,0)             // Map menu prohibited. If you stand on it while the map is open, it will not close.
    SetFlag(SF_CAMP_CANT_EQUIP,0)            // Equipment menu prohibited
    SetFlag(SF_CAMP_CANT_SKILL,0)
    SetFlag( SF_CANUSE_MAPWARP, 1 )
    SetFlag(SF_CANTUSE_MAP, 0)
    SetFlag(SF_CANTUSE_SKILL ,0)
    SetFlag(SF_CAN_EXSKILL, 1)
    //set a ton of story progress flags to try and make events more open, hopefully doesn't break anything, will need lots of testing
    SetFlag(GF_00MP0011_GO_CAPTAINROOM, 1)	// Head to the captain's room
    SetFlag(GF_00MP0012_START_PATROL, 1)	// start patrolling
    SetFlag(GF_00MP0012_GO_CAPTAINROOM2, 1)	// Head to the captain's room (second time)
    SetFlag(GF_00MP0016_HEAR_SCREAM, 1)		// I hear a scream
    SetFlag(GF_00MP0011b_DIVE_OCEAN, 1)		// jump into the sea
    SetFlag(GF_00MP1102_TALK_LAXIA,	1)	// Talked to Laxia
    SetFlag(GF_00MP1102_TALK_SAHAD,	1)	// Talked to Sahad
    SetFlag(GF_00MP1102_TALK_HUMMEL, 1)		// Talked to Hummel
    SetFlag(GF_00MP1102_TALK_DOGI, 1)		// Talked to Dogi
    SetFlag(GF_01MP1110_DRIFT,1)
    SetFlag(GF_01MP1110_GET_SWORD, 1)
    SetFlag(GF_01MP7301_GET_SKILL,1)
    SetFlag(GF_01MP7301_SET_SKILL,1)
    SetFlag(GF_01MP1110_BATTLE_WIN,1)
    SetFlag(GF_01MP1102_DRINK_WATER, 1)
    SetFlag(GF_01MP1201_IN_BASE, 1)
    SetFlag(GF_01MP1201_TALK_LAXIA, 1)
    SetFlag(GF_01MP1201_GET_DRIFT, 1)
    SetFlag(GF_01MP1202_IN_MP1202,1)
    SetFlag(GF_01MP1201_LOOK_MAN,1)
    SetFlag(GF_01MP7302_GET_ITEM, 1)
    SetFlag(GF_01MP7302_GET_ARMOR, 1)
    SetFlag(GF_01MP7302_GET_SWORD, 1)
    //SetFlag(GF_01MP1101_DRAW_MAP,1)
    SetFlag(GF_02MP1201_TALK_DOGISAHAD,	1)
	SetFlag(GF_02MP1203_START_FISHING,1)	
	SetFlag(GF_02MP1203_GET_FISH,1)	
    SetFlag(GF_02MP1201_TEST_SMITH, 1)
    SetFlag(GF_02MP1201_TEST_TRADE, 1)
    SetFlag(GF_02MP1201_TEST_DRUG, 1)
	SetFlag(GF_02MP1201_TAKE_BREAKFAST,	1)	
	SetFlag(GF_02MP1201_INFO_QUEST,1)			
	SetFlag(GF_GALL_EVIMG_01,1)			
	SetFlag(GF_GALL_EVIMG_02,1)		
	SetFlag(GF_GALL_EVIMG_03,1)	
    SetFlag(GF_02MP1110_REMOVE_OBSTACLE, 1)     // removed initial tree, lets the player see numbers required to move obstacles and makes sphere 0 more dynamic 
    //set flags fro arriving at the shoreline for great river valley
    SetFlag(GF_02MP1120_MEET_HUMMEL,1)
    SetFlag(GF_02MP1121_MAKE_CAMP,1)
    SetFlag( GF_02MP1201_TEST_RENSEI , 1 ) // Enables weapon enhancement, still requires kathleen
    SetFlag(GF_02MP1201_BEFORE_INTERCEPT,1) // Preparations for interception battle have begun.
    SetFlag(GF_02MP1201_START_INTERCEPT,1) // Started interception battle
    SetFlag(GF_02MP1201_AFTER_INTERCEPT,1) // The first interception battle is over.
    SetFlag(GF_02MP23xx_OCCUR_INTERCEPT3,1) // Interception 3 has occurred
    SetFlag(GF_02MP23xx_AFTER_INTERCEPT3,1) // Interception battle 3 has ended
    SetFlag(GF_03MP3109M_MOVE_CANYON,1) //Dana Edition Head to the Great Canyon
                                        //Dana Part 1: Declare the start of the tree-planting festival
                                        // Dana Edition Proceed deep into the valley
                                        //Dana Part 1: Start the tree-planting ceremony
    //SetFlag(GF_03MP1101_LEAVE_CAMP,1)  //Spawns tree that leads to primordial passage
    SetFlag(GF_03MP4202_LOOK_LODGE,1)
    SetFlag(GF_03MP4202_LOOK_NOTE,1)
    SetFlag(GF_03MP4202_LOOK_FLOWER,1)
    SetFlag(GF_03MP4202_LOOK_BOOK,1)
    SetFlag(GF_03MP4202_TALK_LODGE,1)  //skip events at cabin on the initial way up gendarme
    SetFlag(GF_03MP433x_OCCUR_INTERCEPT5,1) // Interception battle 5 has occurred
    SetFlag(GF_03MP433x_AFTER_INTERCEPT5,1) // Intercept Battle 5 has ended
    SetFlag(GF_04MP5101_OCCUR_INTERCEPT7,1) // Intercept battle 7 has occurred
    SetFlag(GF_04MP5101_AFTER_INTERCEPT7,1) // Intercept Battle 7 has ended
    //Stop all the chasing of Thanatos
    SetFlag(GF_04MP6203_RUN_CENTER,1)
    SetFlag(GF_04MP6203_LOOK_BUILD,1)
    SetFlag(GF_04MP6203_IN_BUILD,1)
    SetFlag(GF_04MP6203_RUN_AWAY,1)
    SetFlag(GF_04MP6203_SEE_BUILD,1)
    SetFlag(GF_04MP6201_RUN_WEST,1)
    SetFlag(GF_04MP6201_LOOK_PAGOIDA,1)
    SetFlag(GF_04MP6203_RUN_CENTER,1)
    SetFlag(GF_04MP6202_SEE_FIGURE,1)
    SetFlag(GF_04MP6202_IN_EAST,1)
    SetFlag(GF_04MP6203_LOOK_BUILD,1)
    SetFlag(GF_04MP6214_GOTO_2F,1)
    SetFlag(GF_04MP6201_LOOK_PAGOIDA,1)
    SetFlag(GF_04MP6211_LOOK_STATUE,1)
    SetFlag(GF_04MP6211_RUN_PAGOIDA,1)
    SetFlag(GF_NPC_4_02_SEE_THANATOS,1)
    SetFlag(GF_04MP6204_IN_PAGOIDA,1)
    SetFlag(GF_04MP6201_TALK_THANATOS,1)
    //There are zero checks in temple of the great tree and the "puzzel" is simple to let's hurry the player along and open the doors for them.
    SetFlag(GF_MP6401_SWITCH_01R,1)
    SetFlag(GF_MP6401_SWITCH_01L,1)
    //SetFlag(GF_05MP1213_INTERCEPT_DANA,1) //Dana participates in the interception battle 2
    //SetFlag(GF_SUBEV_ST_6201_DOOR_OPEN,1)  //Door to Towal Highway is open if it can be reached, leaving this in as Dana can be a non-linear progression item for this
    //Towal entry cutscenes
    SetFlag(GF_05MP6204_SEE_RUIN,1)
    SetFlag(GF_05MP6201_IN_EAST,1)
    SetFlag(GF_05MP6203_SEE_BAHA,1)
    SetFlag(GF_05MP6115_SEE_HOLLOW,1)
    SetFlag(GF_05MP6110_OUT_CAMP,1)
    //Cutscenes before palace
    SetFlag(GF_05MP6204_FIND_CRYSTAL,1)
    SetFlag(GF_05MP6202_GOTO_SKYWAY,1)
    SetFlag(GF_05MP1201_OCCUR_INTERCEPT9,1) // Intercept battle 9 has occurred
    SetFlag(GF_05MP1201_AFTER_INTERCEPT9,1) // Intercept battle 9 has ended
    //Valley of Kings
    SetFlag(GF_05MP4105_PASS_TEM, 1)
    SetFlag(GF_05MP6108_MALK_CAMP,1)
    SetFlag(GF_SUBEV_ST_DOOR_1STTALK,1)
    SetFlag(GF_06MP6409_OCCUR_INTERCEPT12,1) // Interception 12 has occurred
    SetFlag(GF_06MP6409_AFTER_INTERCEPT12,1) // Interception Battle 12 has ended
    GetItem(ICON3D_MAP,1) //start with the map for faster exploration
    SetFlag(GF_06MP6409_OPEN_GATE, 1) //Set the great tree of origins to be open if it can be reached, this will probably be a setting at some point.
    //Remove all tutorials from the game
    SetFlag(    GF_HELP_A01,1 )
    SetFlag(	GF_HELP_A02,			1 )
    SetFlag(	GF_HELP_A03,			1 )
    SetFlag(	GF_HELP_A04,			1 )
    SetFlag(	GF_HELP_A05,			1 )
    SetFlag(	GF_HELP_A06,			1 )
    SetFlag(	GF_HELP_A07,			1 )
    SetFlag(	GF_HELP_A08,			1 )
    SetFlag(	GF_HELP_A09,			1 )
    SetFlag(	GF_HELP_A10,			1 )
    SetFlag(	GF_HELP_A11,			1 )
    SetFlag(	GF_HELP_A12,			1 )
    SetFlag(	GF_HELP_A13,			1 )
    SetFlag(	GF_HELP_A14,			1 )
    SetFlag(	GF_HELP_A15,			1 )
    SetFlag(	GF_HELP_A16,			1 )
    SetFlag(	GF_HELP_A17,			1 )
    SetFlag(	GF_HELP_A18,			1 )
    SetFlag(	GF_HELP_A19,			1 )
    SetFlag(	GF_HELP_A20,			1 )
    SetFlag(	GF_HELP_A21,			1 )
    SetFlag(	GF_HELP_A22,			1 )
    SetFlag(	GF_HELP_A23,			1 )
    SetFlag(	GF_HELP_A24,			1 )
    SetFlag(	GF_HELP_A25,			1 )
    SetFlag(	GF_HELP_A26,			1 )
    SetFlag(	GF_HELP_A27,			1 )
    SetFlag(	GF_HELP_A28,			1 )
    SetFlag(	GF_HELP_A29,			1 )
    SetFlag(	GF_HELP_A30,			1 )
    SetFlag(	GF_HELP_A31,			1 )
    SetFlag(	GF_HELP_A32,			1 )
    SetFlag(	GF_HELP_A33,			1 )
    SetFlag(	GF_HELP_A34,			1 )
    SetFlag(	GF_HELP_A35,			1 )
    SetFlag(	GF_HELP_A36,			1 )
    SetFlag(	GF_HELP_A37,			1 )
    SetFlag(	GF_HELP_A38,			1 )
    SetFlag(	GF_HELP_A39,			1 )
    SetFlag(	GF_HELP_A40,			1 )
    SetFlag(	GF_HELP_A41,			1 )
    SetFlag(	GF_HELP_A42,			1 )
    SetFlag(	GF_HELP_A43,			1 )
    SetFlag(	GF_HELP_A44,			1 )
    SetFlag(	GF_HELP_A45,			1 )
    SetFlag(	GF_HELP_B01,			1 )
    SetFlag(	GF_HELP_B02,			1 )
    SetFlag(	GF_HELP_B03,			1 )
    SetFlag(	GF_HELP_B04,			1 )
    SetFlag(	GF_HELP_B05,			1 )
    SetFlag(	GF_HELP_B06,			1 )
    SetFlag(	GF_HELP_B07,			1 )
    SetFlag(	GF_HELP_B08,			1 )
    SetFlag(	GF_HELP_B09,			1 )
    SetFlag(	GF_HELP_B10,			1 )
    SetFlag(	GF_HELP_B11,			1 )
    SetFlag(	GF_HELP_B12,			1 )
    SetFlag(	GF_HELP_B13,			1 )
    SetFlag(	GF_HELP_B13_B,			1 )
    SetFlag(	GF_HELP_B14,			1 )
    SetFlag(	GF_HELP_B15,			1 )
    SetFlag(	GF_HELP_B16,			1 )
    SetFlag(	GF_HELP_B17,			1 )
    SetFlag(	GF_HELP_B18,			1 )
    SetFlag(	GF_HELP_B19,			1 )
    SetFlag(	GF_HELP_B20,			1 )
    SetFlag(	GF_HELP_A46,			1 )
    SetFlag(	GF_HELP_A47,			1 )
    SetFlag(	GF_HELP_A48,			1 )
    SetFlag(	GF_HELP_A49,			1 )
    SetFlag(	GF_HELP_A50,			1 )
    SetFlag(	GF_HELP_A51,			1 )
    SetFlag(	GF_HELP_A52,			1 )
    SetFlag(	GF_HELP_A53,			1 )
    SetFlag(	GF_HELP_A54,			1 )
    SetFlag(	GF_HELP_A55,			1 )
    SetFlag(	GF_HELP_A56,			1 )
    SetFlag(	GF_HELP_A57,			1 )
    SetFlag(	GF_HELP_B21,			1 )
    SetFlag(	GF_HELP_B22,			1 )
    SetFlag(	GF_HELP_B23,			1 )
    SetFlag(	GF_HELP_B24,			1 )
    SetFlag(	GF_HELP_B25,			1 )
    SetFlag(	GF_HELP_B26,			1 )
    SetFlag(	GF_HELP_B27,			1 )
    SetFlag(	GF_HELP_B28,			1 )
    SetFlag(	GF_HELP_B29,			1 )
    SetFlag(	GF_HELP_B30,			1 )
    SetFlag(	GF_HELP_B31,			1 )
    SetFlag(	GF_HELP_A58,			1 )
    SetFlag(	GF_HELP_A59,			1 )
    SetFlag(	GF_HELP_A44_B,	1 )
    //Let's set every mission flag for a cleaner more stable looking diary and interface
    SetFlag(SF_MISSIONNO,MS_00_01)					
    SetFlag(SF_MISSIONNO,	MS_00_02)					
    SetFlag(SF_MISSIONNO,	MS_00_03)					
    SetFlag(SF_MISSIONNO,	MS_00_04)					
    SetFlag(SF_MISSIONNO,	MS_01_01)					
    SetFlag(SF_MISSIONNO,	MS_01_02)					
    SetFlag(SF_MISSIONNO,	MS_01_03)					
    SetFlag(SF_MISSIONNO,	MS_01_04)					
    SetFlag(SF_MISSIONNO,	MS_01_05)					
    SetFlag(SF_MISSIONNO,	MS_01_06)					
    SetFlag(SF_MISSIONNO,	MS_01_07)					
    SetFlag(SF_MISSIONNO,	MS_01_08)					
    SetFlag(SF_MISSIONNO,	MS_01_09)					
    SetFlag(SF_MISSIONNO,	MS_02_01)					
    SetFlag(SF_MISSIONNO,	MS_02_02)
    SetFlag(SF_MISSIONNO,	MS_02_02B)					
    SetFlag(SF_MISSIONNO,	MS_02_03)					
    SetFlag(SF_MISSIONNO,	MS_02_04)					
    SetFlag(SF_MISSIONNO,	MS_02_05)					
    SetFlag(SF_MISSIONNO,	MS_02_06)					
    SetFlag(SF_MISSIONNO,	MS_02_07)					
    SetFlag(SF_MISSIONNO,	MS_02_08)					
    SetFlag(SF_MISSIONNO,	MS_02_09)					
    SetFlag(SF_MISSIONNO,	MS_02_10)					
    SetFlag(SF_MISSIONNO,	MS_02_11)					
    SetFlag(SF_MISSIONNO,	MS_02_12)					
    SetFlag(SF_MISSIONNO,	MS_02_13)					
    SetFlag(SF_MISSIONNO,	MS_02_14)					
    SetFlag(SF_MISSIONNO,	MS_02_15)					
    SetFlag(SF_MISSIONNO,	MS_02_16)					
    SetFlag(SF_MISSIONNO,	MS_02_17)					
    SetFlag(SF_MISSIONNO,	MS_02_18)					
    SetFlag(SF_MISSIONNO,	MS_02_19)					
    SetFlag(SF_MISSIONNO,	MS_02_20)					
    SetFlag(SF_MISSIONNO,	MS_02_21)					
    SetFlag(SF_MISSIONNO,	MS_02_22)					
    SetFlag(SF_MISSIONNO,	MS_02_23)					
    SetFlag(SF_MISSIONNO,	MS_03_01)					
    SetFlag(SF_MISSIONNO,	MS_03_02)					
    SetFlag(SF_MISSIONNO,	MS_03_03)					
    SetFlag(SF_MISSIONNO,	MS_03_04)					
    SetFlag(SF_MISSIONNO,	MS_03_05)					
    SetFlag(SF_MISSIONNO,	MS_03_06)					
    SetFlag(SF_MISSIONNO,	MS_03_07)					
    SetFlag(SF_MISSIONNO,	MS_03_08)
    SetFlag(SF_MISSIONNO,	MS_03_08B)
    SetFlag(SF_MISSIONNO,	MS_03_08C)					
    SetFlag(SF_MISSIONNO,	MS_03_09)					
    SetFlag(SF_MISSIONNO,	MS_03_10)					
    SetFlag(SF_MISSIONNO,	MS_04_01)					
    SetFlag(SF_MISSIONNO,	MS_04_02)					
    SetFlag(SF_MISSIONNO,	MS_04_03)					
    SetFlag(SF_MISSIONNO,	MS_04_04)					
    SetFlag(SF_MISSIONNO,	MS_04_05)					
    SetFlag(SF_MISSIONNO,	MS_04_06)					
    SetFlag(SF_MISSIONNO,	MS_04_07)					
    SetFlag(SF_MISSIONNO,	MS_04_08)					
    SetFlag(SF_MISSIONNO,	MS_04_09)					
    SetFlag(SF_MISSIONNO,	MS_05_01)					
    SetFlag(SF_MISSIONNO,	MS_05_02)					
    SetFlag(SF_MISSIONNO,	MS_05_03)
    SetFlag(SF_MISSIONNO,	MS_05_03B)					
    SetFlag(SF_MISSIONNO,	MS_05_04)					
    SetFlag(SF_MISSIONNO,	MS_05_05)					
    SetFlag(SF_MISSIONNO,	MS_05_06)					
    SetFlag(SF_MISSIONNO,	MS_05_07)					
    SetFlag(SF_MISSIONNO,	MS_05_08)					
    SetFlag(SF_MISSIONNO,	MS_05_09)					
    SetFlag(SF_MISSIONNO,	MS_05_10)					
    SetFlag(SF_MISSIONNO,	MS_05_11)					
    SetFlag(SF_MISSIONNO,	MS_05_12)					
    SetFlag(SF_MISSIONNO,	MS_05_13)					
    SetFlag(SF_MISSIONNO,	MS_06_01)					
    SetFlag(SF_MISSIONNO,	MS_06_02)					
    SetFlag(SF_MISSIONNO,	MS_06_03)					
    SetFlag(SF_MISSIONNO,	MS_06_04)					
    SetFlag(SF_MISSIONNO,	MS_06_05)					
    SetFlag(SF_MISSIONNO,	MS_06_06)					
    SetFlag(SF_MISSIONNO,	MS_06_07)					
    SetFlag(SF_MISSIONNO,	MS_06_08)					
    SetFlag(SF_MISSIONNO,	MS_06_09)					
    SetFlag(SF_MISSIONNO,	MS_07_01)
    SetFlag(SF_MISSIONNO,	MS_07_01B)
    SetFlag(SF_MISSIONNO,	MS_07_01C)					
    SetFlag(SF_MISSIONNO,	MS_07_02)					
    SetFlag(SF_MISSIONNO,	MS_07_03)					
    SetFlag(SF_MISSIONNO,	MS_07_04)										
    SetFlag(SF_MISSIONNO,	MS_08_D1A)					
    SetFlag(SF_MISSIONNO,	MS_08_D1B)					
    SetFlag(SF_MISSIONNO,	MS_08_D1C)					
    SetFlag(SF_MISSIONNO,	MS_08_D3)					
    SetFlag(SF_MISSIONNO,	MS_08_D3B)					
    SetFlag(SF_MISSIONNO,	MS_08_01)					
    SetFlag(SF_MISSIONNO,	MS_08_01B)					
    SetFlag(SF_MISSIONNO,	MS_08_01C)					
    SetFlag(SF_MISSIONNO,	MS_08_02)					
    SetFlag(SF_MISSIONNO,	MS_08_02B)					
    SetFlag(SF_MISSIONNO,	MS_08_02C)					
    SetFlag(SF_MISSIONNO,	MS_08_02D)					
    SetFlag(SF_MISSIONNO,	MS_08_02E)					
    SetFlag(SF_MISSIONNO,	MS_08_02F)					
    SetFlag(SF_MISSIONNO,	MS_08_03)					
    SetFlag(SF_MISSIONNO,	MS_08_03B)					
    SetFlag(SF_MISSIONNO,	MS_08_03C)					
    SetFlag(SF_MISSIONNO,	MS_08_04)					
    SetFlag(SF_MISSIONNO,	MS_08_042)					
    SetFlag(SF_MISSIONNO,	MS_08_05)					
    SetFlag(SF_MISSIONNO,	MS_08_06)					
    SetFlag(SF_MISSIONNO,	MS_08_06B)					
    SetFlag(SF_MISSIONNO,	MS_08_06C)					
    SetFlag(SF_MISSIONNO,	MS_08_06D)					
    SetFlag(SF_MISSIONNO,	MS_08_07)					
    SetFlag(SF_MISSIONNO,	MS_08_07B)					
    SetFlag(SF_MISSIONNO,	MS_08_07C)					
    SetFlag(SF_MISSIONNO,	MS_08_07D)					
    SetFlag(GF_TBOX_DUMMY060,1) //enables first avolodragil fight from the start, this flag is replacing meeting barbaros
    SetFlag(GF_TBOX_DUMMY067,1) //Make ghostship available if it can be reached.
    SetFlag(GF_NPC_0_01_GO_CAPTAINROOM		, 1)
    SetFlag(	GF_NPC_0_02_START_PATROL		, 1)
    SetFlag(	GF_NPC_0_03_ATTACK_SHIP			, 1)
    SetFlag(	GF_NPC_1_01_IN_BASE				, 1)
    SetFlag(	GF_NPC_6_04_GET_MISTILTEINN		, 1)
    SetFlag( GF_CAMP_VILLAGE_LV, 7 )     //Same thing for the village build.
    //Set the captains quest to done, since he'll never be in the village.
    SetFlag(GF_QUEST_200, QUEST_END)
    SetFlag(GF_QUEST_201, QUEST_END)
    SetFlag(GF_QUEST_210, QUEST_END)
    SetFlag(GF_QUEST_220, QUEST_END)
    SetFlag(GF_QUEST_222, QUEST_END)
    SetFlag(GF_QUEST_223, QUEST_END)
    SetFlag(GF_QUEST_230, QUEST_END)
    SetFlag(GF_QUEST_231, QUEST_END)
    SetFlag(GF_QUEST_300, QUEST_END)
    SetFlag(GF_QUEST_310, QUEST_END)
    SetFlag(GF_QUEST_301, QUEST_END)
    SetFlag(GF_QUEST_302, QUEST_END)
    SetFlag(GF_QUEST_310, QUEST_END)
    SetFlag(GF_QUEST_311, QUEST_END)
    SetFlag(GF_QUEST_401, QUEST_END)
    SetFlag(GF_QUEST_402, QUEST_END)
    SetFlag(GF_QUEST_500, QUEST_END)
    SetFlag(GF_QUEST_501, QUEST_END)
    SetFlag(GF_QUEST_502, QUEST_END)
    SetFlag(GF_QUEST_503, QUEST_END)
    SetFlag(GF_QUEST_520, QUEST_END)
    SetFlag(GF_QUEST_522, QUEST_END)
    SetFlag(GF_QUEST_530, QUEST_END)
    SetFlag(GF_QUEST_600, QUEST_END)
    SetFlag(GF_QUEST_601, QUEST_END)
    SetFlag(GF_QUEST_602, QUEST_END)
    SetFlag(GF_QUEST_610, QUEST_END)
    SetFlag(GF_QUEST_611, QUEST_END)
    SetFlag(GF_QUEST_612, QUEST_END)
    SetFlag(GF_QUEST_613, QUEST_END)
    SetFlag(GF_SUBEV_JOIN_CURRAN2,1)
    EquipCostume(ADOL, ICON3D_COS_ADOL_01, EQC_MAIN, EQC_MODE_EVDEFAULT)
    EquipCostume(ADOL, -1, EQC_MAIN, EQC_MODE_EQUIP)
    EquipCostume(ADOL, -1, EQC_MAIN, EQC_MODE_EVFORCE)	
    LoadArg("map/mp1201/mp1201.arg")
    EventCue("mp1201:EV_M01S070_ED")
}}
"""
    return startParams.format(startingCharacter)

def manageEarlyGameParty(location):
    match location.itemName:
        case 'Adol':
            party = "(PARTY_ADOL , -1 , -1)"
        case 'Laxia':
            party = "(PARTY_LAXIA , -1 , -1)"
        case 'Sahad':
            party = "(PARTY_SAHAD , -1 , -1)"
        case 'Hummel':
            party = "(PARTY_HUMMEL , -1 , -1)"
        case 'Ricotta':
            party = "(PARTY_RICOTTA , -1 , -1)"
        case 'Dana':
            party = "(PARTY_DANA , -1 , -1)"

    startParams = """
function "earlyGameParty"
{{
    SetPartyMember{0}
}}
"""
    return startParams.format(party)

def soloStartingCharacterEvent(location):
    match location.itemName:
        case 'Adol':
            flags = """
    SetFlag(SF_ADOL_JOINOK, 1)
    SetFlag(SF_LAXIA_JOINOK, 0)
    SetFlag(SF_SAHAD_JOINOK, 0)
    SetFlag(SF_HUMMEL_JOINOK, 0)
    SetFlag(SF_RICOTTA_JOINOK, 0)
    SetFlag(SF_DANA_JOINOK, 0)
"""
        case 'Laxia':
            flags = """
    SetFlag(SF_ADOL_JOINOK, 0)
    SetFlag(SF_LAXIA_JOINOK, 1)
    SetFlag(SF_SAHAD_JOINOK, 0)
    SetFlag(SF_HUMMEL_JOINOK, 0)
    SetFlag(SF_RICOTTA_JOINOK, 0)
    SetFlag(SF_DANA_JOINOK, 0)
"""
        case 'Sahad':
            flags = """
    SetFlag(SF_ADOL_JOINOK, 0)
    SetFlag(SF_LAXIA_JOINOK, 0)
    SetFlag(SF_SAHAD_JOINOK, 1)
    SetFlag(SF_HUMMEL_JOINOK, 0)
    SetFlag(SF_RICOTTA_JOINOK, 0)
    SetFlag(SF_DANA_JOINOK, 0)
"""
        case 'Hummel':
            flags = """
    SetFlag(SF_ADOL_JOINOK, 0)
    SetFlag(SF_LAXIA_JOINOK, 0)
    SetFlag(SF_SAHAD_JOINOK, 0)
    SetFlag(SF_HUMMEL_JOINOK, 1)
    SetFlag(SF_RICOTTA_JOINOK, 0)
    SetFlag(SF_DANA_JOINOK, 0)
"""
        case 'Ricotta':
            flags = """
    SetFlag(SF_ADOL_JOINOK, 0)
    SetFlag(SF_LAXIA_JOINOK, 0)
    SetFlag(SF_SAHAD_JOINOK, 0)
    SetFlag(SF_HUMMEL_JOINOK, 0)
    SetFlag(SF_RICOTTA_JOINOK, 1)
    SetFlag(SF_DANA_JOINOK, 0)
"""
        case 'Dana':
            flags = """
    SetFlag(SF_ADOL_JOINOK, 0)
    SetFlag(SF_LAXIA_JOINOK, 0)
    SetFlag(SF_SAHAD_JOINOK, 0)
    SetFlag(SF_HUMMEL_JOINOK, 0)
    SetFlag(SF_RICOTTA_JOINOK, 0)
    SetFlag(SF_DANA_JOINOK, 1)
"""
    partyFlags = """
function "soloEvent"
{{
{0}
}}
"""
    return partyFlags.format(flags)
