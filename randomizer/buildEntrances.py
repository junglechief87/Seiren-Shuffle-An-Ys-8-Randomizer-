try:
	from randomizer.spoiler import shuffledEntranceList
except ImportError:
	from randomizer.spoiler import mock_entrances as shuffledEntranceList  # Use a mock object as a fallback

entranceList ={
        'Archeozoic Chasm Dungeon': {'load': 'map/mp6361/mp6361.arg', 'entry_event': 'rng:6361_entry'},
        'Baja Tower Dungeon': {'load': 'map/mp6321/mp6321.arg', 'entry_event': 'rng:6321_entry'},
        'Beast Hills - Camp North': {'load': 'map/mp4102/mp4102.arg', 'entry_event': 'rng:4102_entry'},
        'Beast Hills - Camp South': {'load': 'map/mp2103/mp2103.arg', 'entry_event': 'rng:2103_entry'},
        'Calm Inlet - Castaway Village Area': {'load': 'map/mp1201/mp1201.arg', 'entry_event': 'rng:1201_entry'},
        'East Coast Cave Dungeon': {'load': 'map/mp7411/mp7411.arg', 'entry_event': 'rng:7411_entry'},
        'Eroded Valley Dungeon Back': {'load': 'map/mp4309/mp4309.arg', 'entry_event': 'rng:4309_entry'},
        'Eroded Valley Dungeon Front': {'load': 'map/mp4301/mp4301.arg', 'entry_event': 'rng:4301_entry'},
        'Mont Gendarme Dungeon Back': {'load': 'map/mp4107/mp4107.arg', 'entry_event': 'rng:4107_entry'},
        'Mont Gendarme Dungeon Front': {'load': 'map/mp4331/mp4331.arg', 'entry_event': 'rng:4331_entry'},
        'Mountain Pinnacle Trail - Top': {'load': 'map/mp4103/mp4103.arg', 'entry_event': 'rng:4103_entry'},
        'Nameless Coast - Camp': {'load': 'map/mp1105/mp1105.arg', 'entry_event': 'rng:1105_entry'},
        'Nostalgia Cape - Nostalgia Cape': {'load': 'map/mp1116/mp1116.arg', 'entry_event': 'rng:1116_entry'},
        'Octus Dungeon': {'load': 'map/mp6301/mp6301.arg', 'entry_event': 'rng:6301_entry'},
        'Odd Rock Coast - Odd Rock Coast': {'load': 'map/mp1118/mp1118.arg', 'entry_event': 'rng:1118_entry'},
        'Primordial Passage - Camp': {'load': 'map/mp3105/mp3105.arg', 'entry_event': 'rng:3105_entry'},
        'Roaring Seashore - Metavolicalis': {'load': 'map/mp1117/mp1117.arg', 'entry_event': 'rng:1117_entry'},
        'Schlamm Jungle Dungeon Back': {'load': 'map/mp2308/mp2308.arg', 'entry_event': 'rng:2308_entry'},
        'Schlamm Jungle Dungeon Front': {'load': 'map/mp2301/mp2301.arg', 'entry_event': 'rng:2301_entry'},
        'Sunrise Beach - Sunrise Beach': {'load': 'map/mp1119/mp1119.arg', 'entry_event': 'rng:1119_entry'},
        'Temple of the Great Tree - Great Tree Garden': {'load': 'map/mp6409/mp6409.arg', 'entry_event': 'rng:6409_entry'},
        'The Ruins of Eternia - Palace Ruins': {'load': 'map/mp6204/mp6204.arg', 'entry_event': 'rng:6204_entry'},
        'Towal Highway - Camp': {'load': 'map/mp6110/mp6110.arg', 'entry_event': 'rng:6110_entry'},
        'Towering Coral Forest Dungeon Back': {'load': 'map/mp1308/mp1308.arg', 'entry_event': 'rng:1308_entry'},
        'Towering Coral Forest Dungeon Front': {'load': 'map/mp1301/mp1301.arg', 'entry_event': 'rng:1301_entry'},
        'Valley of Kings - Camp': {'load': 'map/mp6108/mp6108.arg', 'entry_event': 'rng:6108_entry'},
        'Valley of Kings Dungeon': {'load': 'map/mp6341/mp6341.arg', 'entry_event': 'rng:6341_entry'},
        'Waterdrop Cave Dungeon': {'load': 'map/mp7301/mp7301.arg', 'entry_event': 'rng:7301_entry'},
    }

def getEntrance(region, check):
	for entrance in shuffledEntranceList:
		if entrance.locRegion == region and entrance.mapCheckID == check:
			ent = entranceList.get(entrance.itemName)
			try: 
				if ent:
					return ent['load'], ent['entry_event']
			except Exception as e:
				print(f"Error retrieving entrance data for {entrance.mapCheckID}: {e}")

def buildEntrances():
	print('buildEntrances')
	entranceScript ="""
	function "dungeonEntrances"
	{{
		if(FLAG[SF_LASTENTRY_NO] >= 0)
		{{
			SetWork( WK_BGM , BGM_Nothing )
		}}

    	if(FLAG[GF_TBOX_DUMMY114])
		{{
			//Exits
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_EROSIONVALLEY_MP4301) //entrance from Beast Hills - Eroded Valley Front Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)
			}}""".format(getEntrance('Beast Hills', 'Eroded Valley Front Entrance')[0], getEntrance('Beast Hills', 'Eroded Valley Front Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_SOUTHWEST_PLANE_MP1105) //entrance from Towering Coral Forest - Exit to Nameless Coast
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)
			}}""".format(getEntrance('Towering Coral Forest', 'Exit to Nameless Coast')[0], getEntrance('Towering Coral Forest', 'Exit to Nameless Coast')[1])
    
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 2 && WORK[WK_MAPNAMENO] == MN_D_MP1301) //entrance from Nameless Coast - Towering Coral Forest Front Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Nameless Coast', 'Towering Coral Forest Front Entrance')[0], getEntrance('Nameless Coast', 'Towering Coral Forest Front Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_F_MP1118) //entrance from Schlamm Jungle - Exit to Odd Rock Coast
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Schlamm Jungle', 'Exit to Odd Rock Coast')[0], getEntrance('Schlamm Jungle', 'Exit to Odd Rock Coast')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_D_MP1308) //entrance from Roaring Seashore - Towering Coral Forest Back Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Roaring Seashore', 'Towering Coral Forest Back Entrance')[0], getEntrance('Roaring Seashore', 'Towering Coral Forest Back Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_F_MP1117) //entrance from Towering Coral Forest - Exit to Roaring Seashore
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Towering Coral Forest', 'Exit to Roaring Seashore')[0], getEntrance('Towering Coral Forest', 'Exit to Roaring Seashore')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP2103) //entrance from Schlamm Jungle - Exit to Beast Hills South
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Schlamm Jungle', 'Exit to Beast Hills South')[0], getEntrance('Schlamm Jungle', 'Exit to Beast Hills South')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_MP2301) //entrance from Beast Hills - Schlamm Jungle Front Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Beast Hills', 'Schlamm Jungle Front Entrance')[0], getEntrance('Beast Hills', 'Schlamm Jungle Front Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_D_MP2308) //entrance from Odd Rock Coast - Schlamm Jungle Back Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Odd Rock Coast', 'Schlamm Jungle Back Entrance')[0], getEntrance('Odd Rock Coast', 'Schlamm Jungle Back Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 5 && WORK[WK_MAPNAMENO] == MN_T_VILLAGE_MP1201) //entrance from Waterdrop Cave - Exit to Calm Inlet
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Waterdrop Cave', 'Exit to Calm Inlet')[0], getEntrance('Waterdrop Cave', 'Exit to Calm Inlet')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_CELLAR_MP7301) //entrance from Calm Inlet - Waterdrop Cave Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Calm Inlet', 'Waterdrop Cave Entrance')[0], getEntrance('Calm Inlet', 'Waterdrop Cave Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP4102) //entrance from Eroded Valley - Exit to Beast Hills North
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Eroded Valley', 'Exit to Beast Hills North')[0], getEntrance('Eroded Valley', 'Exit to Beast Hills North')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_D_EROSIONVALLEY_MP4309) //entrance from Sunrise Beach - Eroded Valley Back Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Sunrise Beach', 'Eroded Valley Back Entrance')[0], getEntrance('Sunrise Beach', 'Eroded Valley Back Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_F_MP1119) //entrance from Eroded Valley - Exit to Sunrise Beach
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Eroded Valley', 'Exit to Sunrise Beach')[0], getEntrance('Eroded Valley', 'Exit to Sunrise Beach')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_MP7411) //entrance from Nostalgia Cape - East Coast Cave Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Nostalgia Cape', 'East Coast Cave Entrance')[0], getEntrance('Nostalgia Cape', 'East Coast Cave Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 2 && WORK[WK_MAPNAMENO] == MN_F_MP1116) //entrance from East Coast Cave - Exit to Nostalgia Cape
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('East Coast Cave', 'Exit to Nostalgia Cape')[0], getEntrance('East Coast Cave', 'Exit to Nostalgia Cape')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP3105) //entrance from Mont Gendarme - Exit to Primordial Passage
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Mont Gendarme', 'Exit to Primordial Passage')[0], getEntrance('Mont Gendarme', 'Exit to Primordial Passage')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_MP4331) //entrance from The Primordial Passage - Mont Gendarme Front Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('The Primordial Passage', 'Mont Gendarme Front Entrance')[0], getEntrance('The Primordial Passage', 'Mont Gendarme Front Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP4107) //entrance from Mountain Pinnacle Trail - Mont Gendarme Back Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Mountain Pinnacle Trail', 'Mont Gendarme Back Entrance')[0], getEntrance('Mountain Pinnacle Trail', 'Mont Gendarme Back Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_F_MP4103) //entrance from Mont Gendarme - Exit to Mountain Pinnacle Trail
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Mont Gendarme', 'Exit to Mountain Pinnacle Trail')[0], getEntrance('Mont Gendarme', 'Exit to Mountain Pinnacle Trail')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP6110) //entrance from Baja Tower - Exit to Towal Highway
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Baja Tower', 'Exit to Towal Highway')[0], getEntrance('Baja Tower', 'Exit to Towal Highway')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_MP6321) //entrance from Towal Highway - Baja Tower Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Towal Highway', 'Baja Tower Entrance')[0], getEntrance('Towal Highway', 'Baja Tower Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP6204) //entrance from Archeozoic Chasm - Exit to The Ruins of Eternia
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Archeozoic Chasm', 'Exit to The Ruins of Eternia')[0], getEntrance('Archeozoic Chasm', 'Exit to The Ruins of Eternia')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 2 && WORK[WK_MAPNAMENO] == MN_D_MP6361) //entrance from The Ruins of Eternia - Archeozoic Chasm Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('The Ruins of Eternia', 'Archeozoic Chasm Entrance')[0], getEntrance('The Ruins of Eternia', 'Archeozoic Chasm Entrance')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 1 && WORK[WK_MAPNAMENO] == MN_F_MP6108) //entrance from Valley of Kings - Exit to Valley of Kings - Camp
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Valley of Kings', 'Exit to Valley of Kings - Camp')[0], getEntrance('Valley of Kings', 'Exit to Valley of Kings - Camp')[1])
	
	entranceScript = entranceScript + """
			if(FLAG[SF_LASTENTRY_NO] == 0 && WORK[WK_MAPNAMENO] == MN_D_MP6341) //entrance from Lodinia Marshland - Valley of Kings Entrance
			{{
				SetFlag(SF_LASTENTRY_NO, -2)
				CallFunc("rng:warpmask")
				LoadArg("{0}")
				EventCue("{1}",1)	
			}}""".format(getEntrance('Lodinia Marshland', 'Valley of Kings Entrance')[0], getEntrance('Lodinia Marshland', 'Valley of Kings Entrance')[1])
    
	entranceScript = entranceScript + """
		}
	}
	"""
	
	entranceScript = entranceScript + """
	function "disablePrimordialPassage"
	{{
		if (!FLAG[GF_TBOX_DUMMY131])
		{{
			SetStopFlag(STOPFLAG_SIMPLEEVENT2)
			TalkPopup("UNDEF",0,3,STOPPER_PPOSX,STOPPER_PPOSY,0)
			{{
				"#7CA Mysterious Presence Stops Your Progress."
			}}
			WaitPrompt()
			WaitCloseWindow()
			ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
			LoadArg("{0}")
			EventCue("{1}",1)
		}}
	}}

	function "disableRuinsOfEterniaPalace"
	{{
		if (!FLAG[GF_05MP6204_APPEAR_CASTLE])
		{{
			SetStopFlag(STOPFLAG_SIMPLEEVENT2)
			TalkPopup("UNDEF",0,3,STOPPER_PPOSX,STOPPER_PPOSY,0)
			{{
				"#7CA Mysterious Presence Stops Your Progress."
			}}
			WaitPrompt()
			WaitCloseWindow()
			ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
			LoadArg("{2}")
			EventCue("{3}",1)
		}}
	}}
	""".format(getEntrance('The Primordial Passage', 'Mont Gendarme Front Entrance')[0], getEntrance('The Primordial Passage', 'Mont Gendarme Front Entrance')[1],\
			getEntrance('The Ruins of Eternia', 'Archeozoic Chasm Entrance')[0], getEntrance('The Ruins of Eternia', 'Archeozoic Chasm Entrance')[1])

	entranceScript = entranceScript + """

	function "Entry_warpout_mp6409_replace" //entrance from Temple of the Great Tree - Octus Entrance
	{{
		SetWork( WK_BGM , BGM_Nothing )
		SetFlag(SF_LASTENTRY_NO, -2)
		CallFunc("rng:warpmask")
		LoadArg("{0}")
		EventCue("{1}",1)
	}}""".format(getEntrance('Temple of the Great Tree', 'Octus Entrance')[0], getEntrance('Temple of the Great Tree', 'Octus Entrance')[1])

	entranceScript = entranceScript + """

	function "Entry_warpout_mp6301_replace" //entrance from Octus Overlook - Exit to Temple of the Great Tree
	{{
		SetWork( WK_BGM , BGM_Nothing )
		SetFlag(SF_LASTENTRY_NO, -2)
		CallFunc("rng:warpmask")
		LoadArg("{0}")
		EventCue("{1}",1)
	}}""".format(getEntrance('Octus Overlook', 'Exit to Temple of the Great Tree')[0], getEntrance('Octus Overlook', 'Exit to Temple of the Great Tree')[1])

	entranceScript = entranceScript + """

	function "4301_entry"
	{
		VisualName("visual/mapname/mn_4301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4301:init")
		SetChrPos("LEADER",-243.63f,-267.33f,3.28f)
		Turn("LEADER",-148.36f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -30.000f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1105_entry"
	{
		VisualName("visual/mapname/mn_1110.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4301:init")
		SetChrPos("LEADER", -249.92f, -829.87f, 39.28f)
		Turn("LEADER", -30.0f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 230.15f, 0)					// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1301_entry"
	{
		VisualName("visual/mapname/mn_1301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）

		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp1301:init")
		SetChrPos("LEADER",20.28f , -265.74f , -16.40f  )
		Turn("LEADER", 180.0f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 0.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1118_entry"
	{
		VisualName("visual/mapname/mn_1118.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp1118:init")
		SetChrPos("LEADER", 1055.09f, 340.37f, 10.13f)
		Turn("LEADER", -136.53f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 315.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1308_entry"
	{
		VisualName("visual/mapname/mn_1301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp1308:init")
		SetChrPos("LEADER",-65.26f,288.08f,0.71f)
		Turn("LEADER", -80.0f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 230.15f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1117_entry"
	{
		VisualName("visual/mapname/mn_1117.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )			// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp1117:init")
		SetChrPos("LEADER", -790.50f, -462.97f, 8.05f )
		Turn("LEADER", 90.0f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -230.15f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "2103_entry"
	{
		VisualName("visual/mapname/mn_1108.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp2103:init")
		SetChrPos("LEADER",805.73f,-347.07f,26.58f)
		Turn("LEADER", 70.0f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -230.15f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "2301_entry"
	{
		VisualName("visual/mapname/mn_2301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp2301:init")
		SetChrPos("LEADER",-18.11f, -20.72f, 0.93f)
		Turn("LEADER",-119.99f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 300.15f, 0)					// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
		if( !FLAG[GF_TBOX_DUMMY066]){			// エアランと合流していない
			//SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
			SetFlag(GF_02MP2302_LOOK_MAN,1)  //get rid of scene later in dungeon
			EventCue("mp2301:EV_M02S390_ED")
		}
	}
				
	function "2308_entry"
	{
		VisualName("visual/mapname/mn_2301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp2308:init")
		SetChrPos("LEADER",452.0f,392.0f,0.00f)
		Turn("LEADER",45.00f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -230.15f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1201_entry"
	{
		VisualName("visual/mapname/mn_1201.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetFlag(GF_MP1202_NOW,1)
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp1201:init")
		SetChrPos("LEADER",-5.90f, -1390.17f, 11.57f)
		Turn("LEADER",-133.50f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 310.15f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "7301_entry"
	{
		VisualName("visual/mapname/mn_7301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp7301:init")
		SetChrPos("LEADER",-2.60f,0.17f,-0.20f)
		Turn("LEADER",-270.50f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 90.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "4102_entry"
	{
		VisualName("visual/mapname/mn_1108.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4102:init")
		SetChrPos("LEADER",545.0f,20.15f,96.64f)
		Turn("LEADER",70.23f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 120.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "4309_entry"
	{
		VisualName("visual/mapname/mn_4301.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4309:init")
		SetChrPos("LEADER",189.82f,439.57f,-85.21f)
		Turn("LEADER",55.31f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 120.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1119_entry"
	{
		VisualName("visual/mapname/mn_1119.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp1119:init")
		SetChrPos("LEADER", 846.28f, 608.73f, 12.98f)
		Turn("LEADER", -145.38f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -30.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "7411_entry"
	{
		VisualName("visual/mapname/mn_7411.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp7411:init")
		SetChrPos("LEADER", 87.93f, -163.0f, 40.1f )
		Turn("LEADER" ,110.53f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 65.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "1116_entry"
	{
		VisualName("visual/mapname/mn_1116.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp7411:init")
		SetChrPos("LEADER", 1048.96f, -1152.60f, 7.77f )
		Turn("LEADER" ,-92.0f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -90.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "3105_entry"
	{
		if (!FLAG[GF_TBOX_DUMMY131])
		{
			CallFunc("rng:disablePrimordialPassage")
		}
		else
		{
			VisualName("visual/mapname/mn_3109.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
			SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
			SetStopFlag(STOPFLAG_EVENT)
			RestoreEventState()
			ReleaseEventPartyChr()
			ResetMapParam(-1)
			CallFunc("mp3105:init")
			SetChrPos("LEADER",82.75f,-204.67f,222.3f)
			Turn("LEADER",-24.87f,360.0f)
			ResetPartyPos()
			ResetFollowPoint()
			RotateCamera(0, -160.0f, 0)				// 角度
			CallFunc("system:camera_reset")
			ResetStopFlag(STOPFLAG_EVENT)
			FadeIn(FADE_BLACK, FADE_FAST)
		}
	}

	function "4331_entry"
	{
		VisualName("visual/mapname/mn_4331.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4331:init")
		SetChrPos("LEADER", -21.24f, -134.64f, 310.70f)
		Turn("LEADER", -168.00f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -20.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "4107_entry"
	{
		VisualName("visual/mapname/mn_4331.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4107:init")
		SetChrPos("LEADER",290.73f,13.11f,771.47f)
		Turn("LEADER",287.03f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -110.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "4103_entry"
	{
		VisualName("visual/mapname/mn_4103.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp4103:init")
		SetChrPos( "LEADER", 161.44f, 205.64f, 769.51f )
		Turn("LEADER",57.03f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 120.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "6110_entry"
	{
		VisualName("visual/mapname/mn_6103.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp6110:init")
		SetChrPos("LEADER",-62.18f,1445.56f,104.68f)
		Turn("LEADER",40.37f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 140.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}


	function "6321_entry"
	{
		VisualName("visual/mapname/mn_6321.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp6321:init")
		SetChrPos("LEADER", -118.43f, -0.20f, -8.00f)
		Turn("LEADER", -90.00f, 360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, -90.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "6204_entry"
	{
		if (!FLAG[GF_05MP6204_APPEAR_CASTLE])
		{
			CallFunc("rng:disableRuinsOfEterniaPalace")
		}
		else
		{
			VisualName("visual/mapname/mn_6201.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
			SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
			SetStopFlag(STOPFLAG_EVENT)
			RestoreEventState()
			ReleaseEventPartyChr()
			ResetMapParam(-1)
			CallFunc("mp6204:init")
			SetChrPos("LEADER",-567.57f,1256.93f,23.0f)
			Turn("LEADER",-30.65f,360.0f)
			ResetPartyPos()
			ResetFollowPoint()
			RotateCamera(0, 200.0f, 0)				// 角度
			CallFunc("system:camera_reset")
			ResetStopFlag(STOPFLAG_EVENT)
			FadeIn(FADE_BLACK, FADE_FAST)
		}
	}

	function "6361_entry"
	{
		VisualName("visual/mapname/mn_6361.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp6361:init")
		SetChrPos("LEADER",-0.12f,-395.71f,144.0f)
		Turn("LEADER",180.0f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 0.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "6108_entry"
	{
		VisualName("visual/mapname/mn_6108.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp6108:init")
		SetChrPos("LEADER",-138.2f,0.07f,0.35f)
		Turn("LEADER",83.20f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 90.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "6341_entry"
	{
		VisualName("visual/mapname/mn_6341.itp",VN_NAMEMAP2,-1,-1,VN_MAPNAME_TIME)//浸食谷
		SetFlag( TF_MAPNAME_SHOWN, 1 )				// 地名表示した（テンポラリ）
		SetStopFlag(STOPFLAG_EVENT)
		RestoreEventState()
		ReleaseEventPartyChr()
		ResetMapParam(-1)
		CallFunc("mp6341:init")
		SetChrPos("LEADER",-93.97f,0.0f,0.0f)
		Turn("LEADER",270.0f,360.0f)
		ResetPartyPos()
		ResetFollowPoint()
		RotateCamera(0, 270.0f, 0)				// 角度
		CallFunc("system:camera_reset")
		ResetStopFlag(STOPFLAG_EVENT)
		FadeIn(FADE_BLACK, FADE_FAST)
	}

	function "6301_entry"
	{
		EventCue("mp6301:Entry_warpout_mp6409")
	}

	function "6409_entry"
	{
		EventCue("mp6409:Entry_warpout_mp6301")
	}

	function "warpmask"
	{
		FadeOut(FADE_BLACK,0)
		SetStopFlag(STOPFLAG_SIMPLEEVENT2)
		ResetStopFlag(STOPFLAG_NOCHARACLIP)
		Wait(10)
		SetFlag( SF_NOUSE_MTDSE, 1 )
		SetStopFlag(STOPFLAG_NOCHARACLIP)
		ResetStopFlag(STOPFLAG_SIMPLEEVENT2)
		SetStopFlag(STOPFLAG_EVENT)
		SetFlag( SF_NOUSE_MTDSE, 0 )
	}
    """

	return entranceScript