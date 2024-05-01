from shared.functions import getCharacterJoinLv 

def getCrewFlags(location):
    flags = ''
    match location.itemName:
        case "Adol":
            flag = """
    SetFlag(SF_ADOL_JOINED, 1)
    SetFlag(SF_ADOL_JOINOK, 1)
    
    GetItem(ICON3D_WP_ADOL_000,1)
    EquipWeapon(ADOL,ICON3D_WP_ADOL_000)
    
    if( FLAG[GF_03MP1201_ALARM_INTERCEPT] && !FLAG[GF_TBOX_DUMMY071])
    {
        GetItem(ICON3D_WP_ADOL_003, 1)		
	    EquipWeapon(ADOL, ICON3D_WP_ADOL_003)
    }
    if( FLAG[GF_TBOX_DUMMY071])
    {
        SetFlag(GF_ADOLWEAPON_BACKUP,(ADOL.CHRWORK[CWK_WEAPON]))
        GetItem(ICON3D_WP_ADOL_008, 1)		
	    EquipWeapon(ADOL, ICON3D_WP_ADOL_008)
    }
    
    JoinParty(PARTY_ADOL)
"""         
            flag = flag + getCharacterJoinLv("ADOL")

        case "Laxia": #vanilla function call on mp1101 script rng:0401
            flag = """
    SetFlag(SF_LAXIA_JOINED, 1)
    SetFlag(SF_LAXIA_JOINOK, 1)
 
    SetDiaryFlag( DF_JOIN_LAXIA, 1 )	
    SetDiaryCharaFlag( DRCHA_LAXIA, DRCHA_FLAG_OPEN, 1 )
    SetDiaryCharaFlag( DRCHA_LAXIA, DRCHA_FLAG_INFO1, 1 ) //Person memo: Additional information release 1 (Dogi)
    SetDiaryCharaFlag( DRCHA_LAXIA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_LAXIA, DRCHA_FLAG_INFO3, 1 )
    GetItem(ICON3D_WP_LAXIA_000, 1)
    EquipWeapon(LAXIA,ICON3D_WP_LAXIA_000)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )
    
    if( FLAG[GF_03MP1201_ALARM_INTERCEPT])
    {
        GetItem(ICON3D_WP_LAXIA_003, 1)		
	    EquipWeapon(LAXIA, ICON3D_WP_LAXIA_003)
    }

    JoinParty(PARTY_LAXIA)
"""
            flag = flag + getCharacterJoinLv("LAXIA")

        case "Captain Barbaros": #vanilla function call on mp1201 script rng:0402
            flag = """
    SetDiaryFlag( DF_JOIN_BARBAROSS, 1 )	//Footprint memo: Reunited with Captain Barbaros.
    JoinNPC(NPC_BARBAROSS, JOIN_NPC_JOIN) // Captain Barbaros joins the interception battle
    SetDiaryCharaFlag( DRCHA_BARBAROSS, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Captain Barbaros)
    SetDiaryCharaFlag( DRCHA_BARBAROSS2, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Captain Barbaros)
    SetDiaryCharaFlag( DRCHA_BARBAROSS, DRCHA_FLAG_INFO1, 1 ) //Person memo: Additional information release 1 (Captain Barbaros)
    SetDiaryCharaFlag( DRCHA_BARBAROSS2, DRCHA_FLAG_INFO1, 1 ) //Character memo: Additional information release 1 (Captain Barbaros)
    SetDiaryCharaFlag( DRCHA_BARBAROSS, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_BARBAROSS2, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_BARBAROSS, DRCHA_FLAG_INFO3, 1 )  
    
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Little Paro": #vanilla function call on mp1201 script rng:0424
            flag = """
    SetDiaryCharaFlag( DRCHA_PARO, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_PARO, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Little Paro) -> (Patch 1.01) Move after name is known
    SetDiaryCharaFlag( DRCHA_PARO, DRCHA_FLAG_INFO2, 1 )
    SetDiaryCharaFlag( DRCHA_PARO, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_PARO, JOIN_NPC_JOIN ) // Little Paro has become a friend
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )
"""
        case "Sahad": #vanilla function call on mp1103 script rng:0404
            flag = """
    SetFlag(SF_SAHAD_JOINED, 1)
    SetFlag(SF_SAHAD_JOINOK, 1)
 
    SetDiaryFlag( DF_JOIN_SAHAD, 1 )		
    SetDiaryCharaFlag( DRCHA_SAHAD, DRCHA_FLAG_OPEN, 1 )
    SetDiaryCharaFlag( DRCHA_SAHAD, DRCHA_FLAG_INFO1, 1 )
    SetDiaryCharaFlag( DRCHA_SAHAD, DRCHA_FLAG_INFO2, 1 )
    SetDiaryCharaFlag( DRCHA_SAHAD, DRCHA_FLAG_INFO3, 1 )
    GetItem(ICON3D_WP_SAHAD_000, 1)
    GetItem(ICON3D_AM_020, 1)
    EquipWeapon(SAHAD,ICON3D_WP_SAHAD_000)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )

    if( FLAG[GF_03MP1201_ALARM_INTERCEPT])
    {
        GetItem(ICON3D_WP_SAHAD_003, 1)		
	    EquipWeapon(SAHAD, ICON3D_WP_SAHAD_003)
    }

    JoinParty(PARTY_SAHAD)
"""
            flag = flag + getCharacterJoinLv("SAHAD")

        case "Dogi": #vanilla function call on mp1201 script rng:0405
            flag = """
    SetDiaryFlag( DF_JOIN_DOGI, 1 ) //Footprint memo: Reunited with Dogi.
    SetDiaryCharaFlag( DRCHA_DOGI, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Dogi)
    SetDiaryCharaFlag( DRCHA_DOGI, DRCHA_FLAG_INFO1, 1 ) //Person memo: Additional information release 1 (Dogi)
    SetDiaryCharaFlag( DRCHA_DOGI, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_DOGI, DRCHA_FLAG_INFO3, 1 )
    JoinNPC(NPC_DOGI, JOIN_NPC_JOIN) // Participate in Dogi interception battle
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Alison": #vanilla function call on mp1201 script rng:0406
            flag = """
    //SetFlag( SF_WARP_DISABLED, 1 ) //Warp disabled
    SetDiaryFlag( DF_JOIN_ALISON, 1 ) //Footprint memo: Rescued Alison.
    SetDiaryCharaFlag( DRCHA_ALISON, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Alison)
    SetDiaryCharaFlag( DRCHA_ALISON, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_ALISON, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_ALISON, DRCHA_FLAG_INFO3, 1 ) //Person memo: Additional information release 3 (Alison)
    SetFlag(GF_02MP1202_OPEN_DRESS,1)
    SetFlag( GF_CAMP_TAILOR_LV, 1 )
    SetFlag( GF_02MP1201_JOIN_ALISON , 1 ) /// Rescued Alison
    SetFlag( GF_NPC_2A_03_JOIN_ALISON , 1)
    //SetFlag( GF_HELP_A26, 1 ) // Tutorial: Rescue the castaways
    // Participate in interception battle
    JoinNPC(NPC_ALISON, JOIN_NPC_JOIN) // Rescued Alison
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Sir Carlan": #vanilla function call on mp1305 script rng:0407
            flag = """
    JoinNPC( NPC_CURRAN, JOIN_NPC_JOIN ) //Rescued Lord Kahran.
    SetDiaryFlag( DF_JOIN_CURRAN, 1 ) //Footprint memo: Rescued Lord Kahran.
    SetDiaryCharaFlag( DRCHA_CURRAN, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_CURRAN, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_CURRAN, DRCHA_FLAG_INFO3, 1 ) 
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Kiergaard": #vanilla function call on mp1305 script rng:0408
            flag = """
    SetFlag( GF_02MP1307_JOIN_KIERGAARD, 1 ) 
    JoinNPC( NPC_KIERGAARD, JOIN_NPC_JOIN ) //Rescued Killgor.
    SetFlag( GF_CAMP_BED_LV, 2 )
    SetDiaryFlag( DF_JOIN_KIERGAARD, 1 ) //Footprint memo: Rescued Killgor.
    SetDiaryCharaFlag( DRCHA_KIERGAARD, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_KIERGAARD, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_KIERGAARD, DRCHA_FLAG_INFO3, 1 )
    WaitPrompt()
    WaitCloseWindow()
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Kathleen": #vanilla function call on mp1201 script rng:0409
            flag = """
    //SetFlag( SF_WARP_DISABLED, 1 ) //Warp disabled
    SetDiaryFlag( DF_JOIN_KATRIN, 1 ) //Footprint memo: Rescued Katrin.
    SetDiaryCharaFlag( DRCHA_KATRIN, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Katrin)
    SetDiaryCharaFlag( DRCHA_KATRIN, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_KATRIN, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_KATRIN, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_KATRIN, JOIN_NPC_JOIN ) // Katrin has joined
    SetFlag( GF_02MP1201_JOIN_KATRIN , 1 )
    
    SetFlag(GF_SMITHY_LV,2) //Blacksmith level setting
    //SetFlag( GF_CAMP_SHIPYARD_LV, 1 ) // Drifting village development settings: Shipyard LV1
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Weapons can now be reforged.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    
    SetDiaryShopFlag(SHOP_ID_WEAPON_A,0) // "Forge (enhanced)"
    SetDiaryShopFlag(SHOP_ID_WEAPON,1) // "Katlin's Weapon Workshop (Enhancement/Evolution)"
    SetDiaryShopFlag(SHOP_ID_ARMOR,1) // "Katlin's Weapon Workshop (Purchase Armor)"

"""
        case "Sister Nia": #vanilla function call on mp7471 script rng:0410
            flag = """
    SetDiaryFlag( DF_JOIN_NIA, 1 ) //Footprint memo: Rescued Sister Nia.
    SetDiaryCharaFlag( DRCHA_NIA, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Sister Nia)
    SetDiaryCharaFlag( DRCHA_NIA, DRCHA_FLAG_INFO1, 1 ) //Person memo: Additional information release 1 (Sister Nia)
    SetDiaryCharaFlag( DRCHA_NIA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_NIA, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_NIA, JOIN_NPC_JOIN ) // Joined with Sister Nia
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Dina": #vanilla function call on mp1119 script rng:0412
            flag = """
    SetFlag( GF_02MP1119_JOIN_DINA , 1 ) // Meet Dina
    SetFlag(GF_NPC_2_11_JOIN_DINA,1)
    SetDiaryFlag( DF_JOIN_DINA, 1 )  //Footprints memo: Dina was rescued.
    SetFlag(GF_TOOLSHOP_LV, 2) //Trade shop level setting
    JoinNPC( NPC_DINA, JOIN_NPC_JOIN ) //Rescued Dina
    SetDiaryShopFlag(SHOP_ID_TRADE_A,0) // "Warehouse"
    SetDiaryShopFlag(SHOP_ID_TRADE,1) // "Dina's Trading Post"
    SetDiaryShopFlag(SHOP_ID_TRADE_SELL,1) // "Trade post/pickup"
    SetDiaryCharaFlag( DRCHA_DINA, DRCHA_FLAG_INFO1, 1 )
    SetDiaryCharaFlag( DRCHA_DINA, DRCHA_FLAG_INFO2, 1 )
    SetDiaryCharaFlag( DRCHA_DINA, DRCHA_FLAG_INFO3, 1 )
    GetItem(ICON3D_US_PESTCIDE,10)
    SetStopFlag(STOPFLAG_TALK)
    GetItemMessageExPlus(ICON3D_US_PESTCIDE,10,ITEMMSG_SE_NORMAL," Obtained.",0,0)
    WaitPrompt()
    WaitCloseWindow()	
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Trades can now be made.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    ResetStopFlag(STOPFLAG_TALK)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Reja": #vanilla function call on mp1114 script rng:0413
            flag = """
    SetFlag( GF_SUBEV_JOIN_REJA, 1 )
    SetDiaryFlag( DF_JOIN_REJA, 1 ) //Footprint memo: Reya was rescued.
    SetDiaryCharaFlag( DRCHA_REJA, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when meeting (layer)
    SetDiaryCharaFlag( DRCHA_REJA, DRCHA_FLAG_INFO1, 1 ) //Person memo: Additional information release 1 (layer)
    SetDiaryCharaFlag( DRCHA_REJA, DRCHA_FLAG_INFO2, 1 )
    SetDiaryCharaFlag( DRCHA_REJA, DRCHA_FLAG_INFO3, 1 )
    SetFlag( GF_CAMP_FARM_LV, 1 ) // Drifting village development settings: Farm LV1
    SetFlag( GF_CAMP_FARMFENCE_LV, 1 ) // Drifting village development settings: Farm fence LV1
    SetFlag( GF_SPEEDRUN_FARM_NASUBI_KC, FLAG[SF_KILLMONSTER_COUNT] )
	SetFlag( GF_SPEEDRUN_FARM_PAPRIKA_KC, FLAG[SF_KILLMONSTER_COUNT] )
	SetFlag( GF_SPEEDRUN_FARM_CABBAGE_KC, FLAG[SF_KILLMONSTER_COUNT] )
	SetFlag( GF_SPEEDRUN_FARM_CORN_KC, FLAG[SF_KILLMONSTER_COUNT] )
	SetFlag( GF_SPEEDRUN_FARM_TOMATO_KC, FLAG[SF_KILLMONSTER_COUNT] )
	SetFlag( GF_SPEEDRUN_FARM_PUMPKIN_KC, FLAG[SF_KILLMONSTER_COUNT] )
	SetFlag( GF_SPEEDRUN_FARM_1ST_KC, FLAG[SF_KILLMONSTER_COUNT] )
    JoinNPC( NPC_REJA, JOIN_NPC_JOIN ) // Joined with Reya
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Euron": #vanilla function call on mp2301 script rng:0414
            flag = """
    SetFlag( GF_02MP2301_JOIN_AARON , 1 )	
    SetDiaryFlag( DF_JOIN_AARON, 1 ) //Footprint memo: Airan has joined the Drifting Village.
    SetDiaryCharaFlag( DRCHA_AARON, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (air run)
    SetDiaryCharaFlag( DRCHA_AARON, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_AARON, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_AARON, DRCHA_FLAG_INFO3, 1 ) 
    JoinNPC( NPC_AARON, JOIN_NPC_JOIN ) //Joined with Airan
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Accessories can now be crafted and the map can be shown.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Licht": #vanilla function call on mp1118 script rng:0415
            flag = """
    SetDiaryFlag( DF_JOIN_LICHT, 1 ) //Footprint memo: Rescued Licht.
    SetDiaryCharaFlag( DRCHA_LICHT, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Licht)
    SetDiaryCharaFlag( DRCHA_LICHT, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_LICHT, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_LICHT, DRCHA_FLAG_INFO3, 1 )
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Medicine can now be brewed.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    SetFlag( GF_CAMP_BED_LV, 2 ) // Drifting village development settings: Bed LV2
    JoinNPC( NPC_LICHT, JOIN_NPC_JOIN ) // Licht has become a friend
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Quina": #vanilla function call on mp1201 script rng:0416
            flag = """
    SetDiaryFlag( DF_JOIN_KUINA, 1 ) //Footprint memo: Kuina was rescued.
    SetDiaryCharaFlag( DRCHA_KUINA, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Kuina)
    SetDiaryCharaFlag( DRCHA_KUINA, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_KUINA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_KUINA, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_KUINA, JOIN_NPC_JOIN ) //Rescued Kuina.
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Ricotta": #vanilla function call on mp4202 script rng:0417
            flag = """
    SetFlag(SF_RICOTTA_JOINED, 1)
    SetFlag(SF_RICOTTA_JOINOK, 1)
    
    GetItem(ICON3D_WP_RICOTTA_000, 1)
    GetItem(ICON3D_AM_022, 1)
    EquipWeapon(RICOTTA,ICON3D_WP_RICOTTA_000)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )

    if( FLAG[GF_03MP1201_ALARM_INTERCEPT])
    {
        GetItem(ICON3D_WP_RICOTTA_001	, 1)
	    EquipWeapon(RICOTTA, ICON3D_WP_RICOTTA_001)
    }
    
    JoinParty(PARTY_RICOTTA)
    SetFlag( GF_QUEST_400, QUEST_START )
    SetDiaryFlag( DF_QS400_START, 1 )
    SetDiaryCharaFlag( DRCHA_RICOTTA, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_RICOTTA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_RICOTTA, DRCHA_FLAG_INFO3, 1 )
"""
            flag = flag + getCharacterJoinLv("RICOTTA")

        case "Austin": #vanilla function call on mp3107 script rng:0418
            flag = """ 
    SetFlag( GF_SUBEV_JOIN_AUSTEN, 1 ) // Joined with Austin
    SetDiaryFlag( DF_JOIN_AUSTEN, 1 ) //Footprint memo: Rescued Austin.
    JoinNPC( NPC_AUSTEN, JOIN_NPC_JOIN ) // Austin has become a friend
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Discoveries can now be shown.",0,0)
    WaitPrompt()
    WaitCloseWindow()
    SetDiaryCharaFlag( DRCHA_AUSTEN, DRCHA_FLAG_OPEN, 1 )
    SetDiaryCharaFlag( DRCHA_AUSTEN2, DRCHA_FLAG_OPEN, 0 )
    SetDiaryCharaFlag( DRCHA_AUSTEN, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_AUSTEN, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_AUSTEN, DRCHA_FLAG_INFO3, 1 )
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Miralda": #vanilla function call on mp2106 script rng:0419
            flag = """
    SetFlag( GF_SUBEV_JOIN_MIRALDA, 1 )
    SetDiaryFlag( DF_JOIN_MIRALDA, 1 ) //Footprint memo: Rescued Miralda.
    JoinNPC( NPC_MIRALDA, JOIN_NPC_JOIN ) // Joined with Miralda
    SetDiaryCharaFlag( DRCHA_MIRALDA, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Miralda)
    SetDiaryCharaFlag( DRCHA_MIRALDA, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_MIRALDA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_MIRALDA, DRCHA_FLAG_INFO3, 1 )
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Thanatos": #vanilla function call on mp1201 script rng:0420
            flag = """

    SetDiaryFlag( DF_JOIN_THANATOS, 1 ) //Footprint memo: Thanatos has joined the Drifting Village.
    SetDiaryCharaFlag( DRCHA_THANATOS, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Thanatos)
    SetDiaryCharaFlag( DRCHA_THANATOS, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_THANATOS, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_THANATOS, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_THANATOS, JOIN_NPC_JOIN ) // Thanatos has become a friend
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Hummel": #vanilla function call on mp1108 script rng:0411
            flag = """
    SetFlag(SF_HUMMEL_JOINED, 1)
    SetFlag(SF_HUMMEL_JOINOK, 1)
 
    GetItem(ICON3D_WP_HUMMEL_000, 1)
    GetItem(ICON3D_AM_021, 1)
    EquipWeapon(HUMMEL,ICON3D_WP_HUMMEL_000)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )
    SetDiaryCharaFlag( DRCHA_HUMMEL, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_HUMMEL, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_HUMMEL, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_HUMMEL, DRCHA_FLAG_INFO3, 1 )
    
    if( FLAG[GF_03MP1201_ALARM_INTERCEPT] || FLAG[GF_TBOX_DUMMY082])
    {
        GetItem(ICON3D_WP_HUMMEL_002	, 1)
	    EquipWeapon(HUMMEL, ICON3D_WP_HUMMEL_002)
    }
    
    JoinParty(PARTY_HUMMEL)
"""
            flag = flag + getCharacterJoinLv("HUMMEL")

        case "Silvia": #vanilla function call on mp6116 script rng:0421
            flag = """
    SetDiaryFlag( DF_JOIN_SILVIA, 1 ) //Footprint memo: Sylvia has joined the Drifting Village.
    SetDiaryCharaFlag( DRCHA_SILVIA, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_SILVIA, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_SILVIA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_SILVIA, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_SILVIA, JOIN_NPC_JOIN ) // Sylvia has become a friend
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Dana": #vanilla function call on mp1210 script rng:0422
            flag = """
    SetFlag(SF_DANA_JOINED, 1)
    SetFlag(SF_DANA_JOINOK, 1)

    SetDiaryFlag( DF_JOIN_DANA, 1 )
    GetItem(ICON3D_WP_DANA_000, 1)
    GetItem(ICON3D_AM_023, 1)
    SetDiaryCharaFlag( DRCHA_DANA2, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_DANA2, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_DANA2, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_DANA2, DRCHA_FLAG_INFO3, 1 )
    EquipWeapon(DANA,ICON3D_WP_DANA_000)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )
    
    JoinParty(PARTY_DANA)
    
    GetItemMessageExPlus(-1,0,ITEMMSG_SE_NORMAL,"Essence doors can be unlocked.",0,0)
    WaitPrompt()
    WaitCloseWindow()
"""
            flag = flag + getCharacterJoinLv("DANA")

        case "Katthew": #vanilla function call on mp6104 script rng:0423
            flag = """
    SetDiaryFlag( DF_JOIN_KASHU, 1 ) //Footprint memo: Rescued Cashu.
    SetDiaryCharaFlag( DRCHA_KASHU, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_KASHU, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_KASHU, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_KASHU, DRCHA_FLAG_INFO3, 1 )
    SetFlag( GF_CAMP_SHIPYARD_LV, 7 )
    JoinNPC( NPC_KASHU, JOIN_NPC_JOIN ) // Joined with Cashu
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Ed": #vanilla function call on mp1201 script rng:0424
            flag = """
    SetDiaryFlag( DF_JOIN_ED, 1 ) //Footprint memo: Rescued Ed.
    SetFlag( GF_CAMP_TAILOR_LV, 2 ) // Drifting village development setting: Tailor LV2
    SetDiaryCharaFlag( DRCHA_ED, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_ED, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_ED, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_ED, DRCHA_FLAG_INFO3, 1 )
    SetDiaryShopFlag(SHOP_ID_DRESS,0) // "Alison's Tailor"
    SetDiaryShopFlag(SHOP_ID_DRESS_E,1) // "Ed & Alison's Tailor"
    JoinNPC( NPC_ED, JOIN_NPC_JOIN ) // Joined with Ed
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )
    SetFlag( GF_QUEST_510, QUEST_SUCCESS ) // [QS510] Hometown flower quest completed
    SetFlag( GF_QS510_FIND_ED, 1 ) //Found Ed on your own (achieved hometown flower)
    SetFlag( GF_SUBEV_JOIN_ED, 1 ) //Rescued Ed
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 1) ) //Quest accomplished [QS510] Hometown Flower Fame Value +1		
    SetDiaryFlag( DF_QS510_END, 1 ) // [QS510]At the same time as finding purple bellweed at Cape Bokkyo
"""
        case "Franz": #vanilla function call on mp4110 script rng:0425
            flag = """
    SetDiaryCharaFlag( DRCHA_FRANZ, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_FRANZ, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_FRANZ, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_FRANZ, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_FRANZ, JOIN_NPC_JOIN ) // Joined with Franz
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Shoebill": #vanilla function call on mp1201 script rng:0426
            flag = """
    //Flag setting/obtaining items
    SetDiaryCharaFlag( DRCHA_RICOTTA, DRCHA_FLAG_INFO2, 1 ) //Person memo: Additional information release 2 (Ricotta)
    JoinNPC( NPC_BALAENICEPS_REX, JOIN_NPC_JOIN ) // Shoebill has joined the party
    JoinNPC( NPC_AUSTEN2, JOIN_NPC_JOIN )
    //Register person memo Register when you talk to Ricotta or see the reunion event with Ricotta
    SetDiaryCharaFlag( DRCHA_BALAENICEPS_REX, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_BALAENICEPS_REX, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_BALAENICEPS_REX, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_BALAENICEPS_REX, DRCHA_FLAG_INFO3, 1 )
    
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Griselda": #vanilla function call on mp6109 script rng:0427
            flag = """
    SetDiaryFlag( DF_JOIN_GRISELDA, 1 ) //Footprint memo: Griselda has joined the Drifting Village.
    SetDiaryCharaFlag( DRCHA_GRISELDA, DRCHA_FLAG_OPEN, 1 ) 
    SetDiaryCharaFlag( DRCHA_GRISELDA, DRCHA_FLAG_INFO1, 1 ) 
    SetDiaryCharaFlag( DRCHA_GRISELDA, DRCHA_FLAG_INFO2, 1 ) 
    SetDiaryCharaFlag( DRCHA_GRISELDA, DRCHA_FLAG_INFO3, 1 )
    JoinNPC( NPC_GRISELDA, JOIN_NPC_JOIN ) // Joined up with Griselda
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 2) )	
"""
        case "Master Kong": #vanilla function call on mp1201 script rng:0428
            flag = """
    JoinNPC( NPC_SKILLMONKY, JOIN_NPC_JOIN ) // Master Kong has become a friend
    JoinNPC( NPC_CURRAN2, JOIN_NPC_JOIN )
    // Switch character memo Master Kong (2) After meeting up with Drifting Village (version with support skill notation)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY, DRCHA_FLAG_OPEN, 0 ) //Person memo: Register when joining (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY2, DRCHA_FLAG_OPEN, 1 ) //Person memo: Register when joining (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY, DRCHA_FLAG_INFO1, 1 ) //Character memo: Additional information release 2 (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY2, DRCHA_FLAG_INFO1, 1 ) //Character memo: Additional information release 2 (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY, DRCHA_FLAG_INFO2, 1 ) //Character memo: Additional information release 2 (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY2, DRCHA_FLAG_INFO2, 1 ) //Character memo: Additional information release 2 (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY, DRCHA_FLAG_INFO3, 1 ) //Character memo: Additional information release 2 (Master Kong)
    SetDiaryCharaFlag( DRCHA_SKILLMONKY2, DRCHA_FLAG_INFO3, 1 ) //Character memo: Additional information release 2 (Master Kong)
    SetFlag( GF_FAME_POINT, (FLAG[GF_FAME_POINT] + 3) )	
"""  
    return flag
    
