import shared.classr as classr  

def alwaysFalse(*args):
    #this exists because in some places I was calling lambda: False with arguments
    #as the default value for some calls
    return False

def onlyNorthCoastAccess(access):
        return (
        access.canMove(6) or access.canClimb() or 
        access.hasAnyDiscovery(['Birdsong Rock','Rainbow Falls']) or 
        access.canDefeat('Clareon')
        )

def coastNorthSideAccess(access,parameters):
    return onlyNorthCoastAccess(access) or southSideOpen(access, parameters)
        
def southSideOpen(access, parameters):
    # technically Great river valley open
    def isSouthSideRoute():
        return (
            (onlyNorthCoastAccess(access) and (access.canMove(8) or access.canDoubleJump())) or
            access.hasDiscovery('Chimney Rock') or
            (((access.hasAnyDiscovery(['Milky White Vein','Indigo Mineral Vein']) or access.canDefeat('Gargantula'))) and access.canSeeDark()) or
            (access.hasDiscovery('Field of Medicinal Herbs') and access.canDefeat('Magamandra')) or
            (access.hasAnyDiscovery(['Beehive','Ship Graveyard','Hidden Pirate Storehouse']) and access.hasDina()) or
            (access.hasDiscovery('Airs Cairn') and access.canMove(11))
        )
    
    def isNorthSideRoute():
        return access.canDefeat('Giasburn') and access.past1()
    
    return isSouthSideRoute() or isNorthSideRoute()

def canAccessNorthSide(access, parameters):
    return  (access.canDefeat('Giasburn') or 
             parameters.northSideOpen or 
             access.hasAnyDiscovery(['Unicalamites','Breath Fountain','Ancient Tree','Prismatic Mineral Vein']) or 
             ((lodiniaToVista(access) and access.canDoubleJump()) and ((access.hasDana()) or (access.past3() and access.past2())))
        )

def eterniaOpen(access,parameters):
    return ((canAccessNorthSide(access, parameters) and access.past2()) or (access.past3() and lodiniaToVista(access) and access.canDoubleJump()))

def templeOfGreatTreeOpen(access):
    return ( (access.past2() and access.past3()) or access.hasDana() )

def FormerSanctuaryCryptOpen(access, parameters):
    return (
        eterniaOpen(access,parameters) and 
        access.hasDina() and
        access.canSeeDark() and 
        access.hasJadePendant() and 
        battleLogic(390, access, parameters)
    )

def canAccess(inventory, location, parameters):
    access = classr.access(inventory, parameters)

    regionChecks = {
        'White Sand Cape': checkWhiteSandCape,
        'Waterdrop Cave': checkWaterDropCave,
        'Calm Inlet': checkCalmInlet,
        'Nameless Coast': checkNamelessCoast,
        'Towering Coral Forest': checkToweringCoralForest,
        'Roaring Seashore': checkRoaringSeashore,
        'Great River Valley': checkGreatRiverValley,
        'Waterfall Grotto': checkWaterfallGrotto,
        'Beast Hills': checkBeastHills,
        'Eroded Valley': checkErodedValley,
        'Sunrise Beach': checkSunriseBeach,
        'Towering Coral Forest (Night)': checkToweringCoralForestNight,
        'Weathervane Hills': checkWeathervaneHills,
        'Headwater Falls': checkHeadwaterFalls,
        'Underground Water Vein': checkUndergroundWaterVein,
        'Longhorn Coast': checkLonghornCoast,
        'Schlamm Jungle': checkSchlammJungle,
        'Odd Rock Coast': checkOddRockCoast,
        'The Primordial Passage': checkPrimordialPassage,
        'Mont Gendarme': checkMontGendarme,
        'Western Foot of Gendarme': checkWesternFootOfGendarme,
        'Cavern of the Ancient King': checkCavernOfTheAncientKing,
        'Mountain Pinnacle Trail': checkMountainPinnacleTrail,
        'Titis Primeval Forest': checkTitisPrimevalForest,
        'Pangaia Plains': checkPangaiaPlains,
        'The Ruins of Eternia': checkRuinsOfEternia,
        'Temple of the Great Tree': checkTempleOfGreatTree,
        'Mont Gendarme (Night)': checkMontGendarmeNight,
        'Pangaia Plains (Night)': checkPangaiaPlainsNight,
        'Water and Wood Hills': checkWaterAndWoodHills,
        'Silent Tower': checkSilentTower,
        'Stone Pillar Wind Cave':checkStonePillarWindCave,
        'Towal Highway': checkTowalHighway,
        'Baja Tower': checkBajaTower,
        'Nostalgia Cape': checkNostalgiaCape,
        'East Coast Cave': checkEastCoastCave,
        'Pirate Ship Eleftheria': checkPirateShipEleftheria,
        'Bolado Monastery': checkBoladoMonastery,
        'Archeozoic Chasm': checkArcheozoicChasm,
        'Vista Ridge': checkVistaRidge,
        'Lodinia Marshland': checkLodiniaMarshland,
        'Valley of Kings': checkValleyOfKings,
        'The Submerged Cemetery': checkSubmergedCemetery,
        'Solitude Island': checkSolitudeIsland,
        'Eternal Hill': checkEternalHill,
        'Octus Overlook': checkOctusOverlook,
        'Former Sanctuary Crypt - B1': checkFSC_B1,
        'Former Sanctuary Crypt - B2': checkFSC_B2,
        'Former Sanctuary Crypt - B3': checkFSC_B3,
        'Former Sanctuary Crypt - B4': checkFSC_B4,
        'Former Sanctuary Crypt - B5': checkFSC_B5,
        'Former Sanctuary Crypt - B6': checkFSC_B6,
        'Former Sanctuary Crypt - Final Floor': checkFSC_Final,
    }

    return regionChecks.get(location.locRegion, alwaysFalse)(location, access, parameters)

def checkFSC_Final(location, access, parameters):
    if not (
        FormerSanctuaryCryptOpen(access, parameters) and 
        access.canDoubleJump() and
        access.hasEssenceKeyStone(6) and 
        access.canUndead() and
        access.canSwampWalk() and 
        battleLogic(425,access,parameters) # 450 is not possible yet?
    ):
        return False

    if location.mapCheckID == "Melaiduma": #Getting the access.canDefeat("melaiduma")
        return True

    location_checks = {
        'Boss Arena': lambda: (
            access.canDefeat('Melaiduma') and 
            (parameters.goal == 'Release the Psyches' if location.mapCheckID == 'Psyches' else True)
        ),
    }

    return location_checks.get(location.locName, lambda: False)()
def checkFSC_B6(location, access, parameters):
    return (
        FormerSanctuaryCryptOpen(access, parameters) and 
        access.canDoubleJump() and
        access.hasEssenceKeyStone(6) and 
        access.canUndead() and
        access.canSwampWalk()
    )

def checkFSC_B5(location, access, parameters):
    if not (FormerSanctuaryCryptOpen(access, parameters) and 
        access.canDoubleJump() and
        access.hasEssenceKeyStone(6) and 
        access.canUndead() and
        access.canSwampWalk()
    ):
        return False
    
    location_checks = {
        'Entrance': lambda: 
            (
                (location.mapCheckID in ['TBOX01', 'TBOX02'] and 
                 access.hasEssenceKeyStone(9)) or 
                (location.mapCheckID not in ['TBOX01', 'TBOX02'])
            ),
        'Western Hall': lambda: 
            (
                (location.mapCheckID == 'TBOX02' and 
                access.hasEssenceKeyStone(9)) or
                (location.mapCheckID != 'TBOX02')
            ),
    }
    return location_checks.get(location.locName, lambda: False)()

def checkFSC_B4(location, access, parameters):
    if not (FormerSanctuaryCryptOpen(access, parameters) and 
            access.canDoubleJump() and
            access.hasEssenceKeyStone(3) and 
            access.canUndead() and
            access.canSwampWalk()
            ):
        return False
    
    location_checks = {
        'Entrance': lambda: (
            location.mapCheckID != 'TBOX02' or access.canUnderwater()
        ),
        'Frozen Statue Room': lambda: (
            access.hasEssenceKeyStone(6) and 
            (location.mapCheckID not in ['TBOX01', 'TBOX04'] or access.canUnderwater())
        ),
        'Boss Arena': lambda: access.hasEssenceKeyStone(6),
    }
    return location_checks.get(location.locName, lambda: False)()

def checkFSC_B3(location, access, parameters):
    if not (FormerSanctuaryCryptOpen(access, parameters) and 
            access.canDoubleJump() and
            access.hasEssenceKeyStone(3) and 
            access.canUndead() and
            access.canSwampWalk()
            ):
        return False

    location_checks = {
        'Entrance': lambda: (
            (location.mapCheckID not in ['TBOX05', 'TBOX06']) or
            (location.mapCheckID in ['TBOX05', 'TBOX06'] and
            access.hasEssenceKeyStone(9) ) 
        ),
        'Floating Block Puzzle': lambda: True,
        'Boss Arena': lambda: True,
    }
    return location_checks.get(location.locName, lambda: False)()

def checkFSC_B2(location, access, parameters):
    if not (FormerSanctuaryCryptOpen(access, parameters) and 
            access.canDoubleJump() and
            access.hasEssenceKeyStone(1)
            ):
        return False
    
    location_checks = {
        'Entrance': lambda: True,
        'Stone and Rock Block Puzzle': lambda: access.hasEssenceKeyStone(3),
        'Boss Arena': lambda: access.hasEssenceKeyStone(3) and access.canUndead(),
    }
    return location_checks.get(location.locName, lambda: False)()

def checkFSC_B1(location, access, parameters):
    if not FormerSanctuaryCryptOpen(access, parameters):
        return False
    
    location_checks = {
        'Entrance': lambda: location.mapCheckID in ['TBOX01', 'TBOX03'] or (location.mapCheckID == 'TBOX02' and access.canDoubleJump()),
        'First Brazier': lambda: access.hasEssenceKeyStone(1),
        'Boss Arena': lambda: access.hasEssenceKeyStone(1),
        'North Brazier Room': lambda:  access.hasEssenceKeyStone(9),
    }
    return location_checks.get(location.locName, lambda: False)()

def octusAccess(access,parameters):
    return (battleLogic(340, access, parameters) and (
            (parameters.goal == 'Find Crew' and access.canMove(parameters.numOctus)) or
            (parameters.goal in ['Seiren Escape','Untouchable']) or
            (parameters.goal == 'Release the Psyches' and access.hasPsyches(parameters.numOctus))))

def checkOctusOverlook(location, access, parameters):
    if not (access.canDefeat('Octus Enterance')):
        return False
    
    location_checks = {
        'Path of the Frozen Era': lambda: True,
        'Path of the Ocean Era': lambda: True,
        'Path of the Sky Era': lambda: True,
        'Path of the Insectoid Era': lambda: location.mapCheckID != 'TBOX02' or access.canDoubleJump(),
        'Selection Sphere': lambda: battleLogic(390, access, parameters) and (
            (location.mapCheckID == 'Goal' and (
                (parameters.goal == 'Find Crew' and access.canMove(parameters.numGoal)) or
                (parameters.goal == 'Seiren Escape' and access.hasBoat() and access.hasMistilteinn() and access.hasChart()) or
                (parameters.goal == 'Release the Psyches' and access.hasPsyches(parameters.numGoal))  or
                (parameters.goal == 'Untouchable' and access.canDefeat('Melaiduma'))
            )) or (location.mapCheckID != 'Goal')
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkEternalHill(location, access, parameters):
    return (
        canAccessNorthSide(access, parameters) and 
        templeOfGreatTreeOpen(access) and
        access.past6() and 
        (access.canSwampWalk() or access.canUnderwater()) and 
        access.past7()
    ) or access.hasDiscovery('Graves of Ancient Heroes')

def checkSolitudeIsland(location, access, parameters):
    return access.hasBoat() or access.hasDiscovery('Magna Carpa')

def checkSubmergedCemetery(location, access, parameters):
    if not (((access.canDoubleJump() or access.canSwampWalk()) and 
        access.canMove(22) and access.canSeeDark() and access.canUnderwater() and ((
        canAccessNorthSide(access, parameters) and
        templeOfGreatTreeOpen(access) and
        access.past6()) or ((
        access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or (access.hasDiscovery('Sky Garden'))))) or 
        access.hasDiscovery('Soundless Hall')):
        return False 
    
    location_checks = {
        'The Submerged Cemetery': lambda: (location.mapCheckID in ['TBOX01','Landmark'] or (access.canUnderwater() and access.canSeeDark()))
    }

    return location_checks.get(location.locName, lambda: False)()

def checkValleyOfKings(location, access, parameters):
    if not (
        ((access.canSwampWalk() or access.canUnderwater()) and ((
            canAccessNorthSide(access, parameters) and 
            templeOfGreatTreeOpen(access) and
            access.past6() and 
            access.canClimb()) or (
            (access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or access.hasDiscovery('Sky Garden')))) or (
        access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark() and access.canMove(22))
        ):
        return False

    location_checks = {
        'Valley of Kings - Camp': lambda: access.hasDina(),
        'Entrance': lambda: True,
        'Northern Lower Level': lambda: True,
        'Mid-Boss Arena': lambda: access.canUndead() and battleLogic(270, access, parameters),
        'Stairway (Statue Doors)': lambda: access.canUndead(),
        'End': lambda: (
            access.canUndead() and 
            ((location.mapCheckID in ['TBOX01', 'TBOX02'] and access.canDoubleJump()) or 
            location.mapCheckID in ['TBOX03', 'TBOX04'])
        ),
        'Boss Arena': lambda: (
            battleLogic(330, access, parameters) and access.canUndead() and 
            (location.mapCheckID != 'Psyches' or 
            (parameters.goal == 'Release the Psyches' and battleLogic(340, access, parameters) and access.canDefeat('Basileus')))
        ),
        'Seren Garden': lambda: (
            access.canDefeat('Basileus') and (
                (parameters.goal != 'Release the Psyches' and access.canDefeat('Psyche-Ura')) or 
                (parameters.goal == 'Release the Psyches' and access.hasSkyPsyches())
            )
        ),
    }

    return location_checks.get(location.locName, lambda: False)()

def checkLodiniaMarshland(location, access, parameters):
    if (access.hasDiscovery('Graves of Ancient Heroes') and access.past7() and 
        checkLodiniaMarshlandFromEternalHill(location, access)):
        return True
    
    if (access.hasDiscovery('Sky Garden') and checkLodiniaMarshlandFromSkyGarden(location, access)):
        return True
    
    if (access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark() and access.canMove(22) and 
        checkLodiniaMarshlandFromCemetery(location, access)):
        return True
    
    if not (canAccessNorthSide(access, parameters) and templeOfGreatTreeOpen(access)):
        return False

    location_checks = {
        'Entrance from Vista Ridge': lambda: (
            location.mapCheckID == 'TBOX01' or 
            (location.mapCheckID in ['TBOX02', 'TBOX03'] and (access.canDoubleJump() or access.canSwampWalk()))
        ),
        'Near Submerged Cemetery': lambda: (
            access.past6() and access.canClimb() and 
            (access.canDoubleJump() or access.canSwampWalk() or access.canUnderwater()) and 
            (location.mapCheckID == 'TBOX01' or 
            (location.mapCheckID == 'TBOX02' and access.canSwampWalk()))
        ),
        'Muddy Lake': lambda: access.canSwampWalk(),
        'Exit to Valley of Kings': lambda: (
            access.past6() and access.canClimb() and 
            (access.canSwampWalk() or access.canUnderwater()) and 
            (
                (location.mapCheckID in ['Fermented Sap','Landmark'] and access.canSwampWalk() and access.canDoubleJump()) or 
                (location.mapCheckID not in ['Fermented Sap','Landmark'])
            )
        ),
    }

    return location_checks.get(location.locName, lambda: False)()

def checkLodiniaMarshlandFromEternalHill(location, access):
    location_checks = {
        'Entrance from Vista Ridge': lambda: (
            access.past6() and (access.canSwampWalk() or access.canUnderwater()) 
        ),
        'Near Submerged Cemetery': lambda: (
            (access.canUnderwater() or access.canSwampWalk())
        ),
        'Muddy Lake': lambda: access.canSwampWalk() and access.past6(),
        'Exit to Valley of Kings': lambda: (
            (access.canSwampWalk() or access.canUnderwater()) and 
            (
                (location.mapCheckID in ['Fermented Sap','Landmark'] and 
                 access.canSwampWalk() and access.canDoubleJump() and access.canClimb()) or 
                (location.mapCheckID not in ['Fermented Sap','Landmark'])
            )
        ),
    }
    return location_checks.get(location.locName, lambda: False)()

def checkLodiniaMarshlandFromSkyGarden(location, access):
    location_checks = {
        'Entrance from Vista Ridge': lambda: (
            access.past6() and (access.canSwampWalk() or access.canUnderwater())
        ),
        'Near Submerged Cemetery': lambda: (access.canUnderwater() or access.canSwampWalk()),
        'Muddy Lake': lambda: access.past6() and access.canSwampWalk(),
        'Exit to Valley of Kings': lambda: (
            (access.canSwampWalk() or access.canUnderwater()) or (location.mapCheckID in ['Fermented Sap','Landmark'])
        ),
    }
    return location_checks.get(location.locName, lambda: False)()

def checkLodiniaMarshlandFromCemetery(location, access):
    location_checks = {
        'Entrance from Vista Ridge': lambda: access.past6(),
        'Near Submerged Cemetery': lambda: True,
        'Muddy Lake': lambda: access.past6() and access.canSwampWalk(),
        'Exit to Valley of Kings': lambda: (
            (access.canSwampWalk() or access.canUnderwater()) and 
            (
                (location.mapCheckID in ['Fermented Sap','Landmark'] and 
                 access.canSwampWalk() and access.canDoubleJump() and access.canClimb()) or 
                (location.mapCheckID not in ['Fermented Sap','Landmark'])
            )
        ),
    }
    return location_checks.get(location.locName, lambda: False)()

def lodiniaToVista(access):
    return (access.past6() and  (
        ((access.canSwampWalk() or access.canUnderwater()) and ((
        access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or (access.hasDiscovery('Sky Garden')))) or (
        access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark() and access.canMove(22))))
   
     
def checkVistaRidge(location, access, parameters):
    if not ((canAccessNorthSide(access, parameters) and templeOfGreatTreeOpen(access)) or lodiniaToVista(access)):
        return False

    location_checks = {
        'Vista Ridge Upper': lambda: access.canMove(21) and access.canDoubleJump() and access.canClimb(),
        'Vista Ridge Lower': lambda: (
            access.canDefeat('Master Kong Hummel') and 
            battleLogic(240, access, parameters) and
            access.hasAdol()
            ),
    }

    return location_checks.get(location.locName, lambda: False)()

def checkArcheozoicChasm(location, access, parameters):
    if not (eterniaOpen(access,parameters) and access.past5()):
        return False

    location_checks = {
        'Entrance': lambda: True,
        'Cliffs Overlooking Crater': lambda: (
            (location.mapCheckID == 'TBOX02' and access.canMove(23)) or
            location.mapCheckID != 'TBOX02'
        ),
        'Whirlpools': lambda: True,
        'Mid-Boss Arena': lambda: battleLogic(250, access, parameters),
        'Submerged Cave': lambda: ( 
        (
        location.mapCheckID == 'TBOX01' and 
        access.canDefeat('Coelacantos')
        ) or 
        access.canUnderwater()
        ),
        'Water Vents': lambda: access.canUnderwater(),
        'Sunken Eternia Ruins West': lambda: access.canUnderwater(),
        'Sunken Eternia Ruins East': lambda: access.canUnderwater(),
        'Boss Arena': lambda: (
            (location.mapCheckID != 'Psyches' and 
            battleLogic(320, access, parameters) and 
            access.canUnderwater()) or 
            (parameters.goal == 'Release the Psyches' and battleLogic(340, access, parameters) and access.canDefeat('Oceanus'))
        ),
    }

    return location_checks.get(location.locName, lambda: False)()

def checkBoladoMonastery(location, access, parameters):
    #accessing the basement chests from submerged cemetery when not coming from eternia
    if (((access.canMove(22) and ((access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or 
        (access.hasDiscovery('Sky Garden') and (access.canUnderwater() or access.canSwampWalk())))) or 
        (access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark())) 
        and monasteryBackhalfChests(location)):
        return True
    
    if not (eterniaOpen(access,parameters) and access.past5()):
        return False

    location_checks = {
        'Basement': lambda: (
            access.canSeeDark() and 
            (
                (
                location.mapCheckID in ['TBOX01', 'TBOX02', 'TBOX03'] and 
                templeOfGreatTreeOpen(access) and 
                access.past6() and 
                (access.canDoubleJump() or access.canSwampWalk()) and 
                access.canMove(22) and 
                access.canUnderwater()
                ) or 
                (
                location.mapCheckID in ['TBOX04', 'TBOX05']
                )
            )
        ),
        'Entrance': lambda: (
            (
            location.mapCheckID in ['TBOX01', 'TBOX02', 'TBOX03'] and 
            access.canSeeDark()
            ) or 
            (
            location.mapCheckID in ['TBOX04', 'TBOX05']
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def monasteryBackhalfChests(location):
    location_checks = {
        'Basement': lambda: (
            location.mapCheckID in (['TBOX01', 'TBOX02', 'TBOX03'])
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkPirateShipEleftheria(location, access, parameters):
    if not (
            access.canDoubleJump() and 
            access.readNote1() and 
            access.canDefeat('Gilkyra Encounter')
    ):
        return False

    location_checks = {
        'Submerged Hold': lambda: access.canUnderwater(),
        'Hold': lambda: ( 
            (location.mapCheckID == 'TBOX01' and access.canUnderwater()) or
            (location.mapCheckID != 'TBOX01')
            ),
        'Accessway': lambda: True,
        'Crew Quarters': lambda: True,
        'Deck': lambda: (
            battleLogic(260, access, parameters) and 
            ((location.mapCheckID != 'Psyches') or 
            (parameters.goal == 'Release the Psyches' and battleLogic(340, access, parameters) and access.canDefeat('Pirate Revenant')))
        ),
        'Stairwell': lambda: True,
    }

    return location_checks.get(location.locName, lambda: False)()

def checkEastCoastCave(location, access, parameters):
    if not ((southSideOpen(access, parameters) and access.hasDina() and access.canDoubleJump()) or 
            access.hasAnyDiscovery(['Ship Graveyard','Hidden Pirate Storehouse'])  or 
            (access.hasDiscovery('Beehive') and access.canDoubleJump())):
        return False

    location_checks = {
        'East Coast Cave': lambda: 
        (
            (location.mapCheckID in ['TBOX01', 'TBOX03'] and access.canDoubleJump() and access.canDefeat('Gilkyra Encounter')) or 
            (location.mapCheckID == 'Gilkyra Encounter' and battleLogic(170, access, parameters)) or
            (location.mapCheckID in ['TBOX02','Landmark'])
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkNostalgiaCape(location, access, parameters):
    if not ((southSideOpen(access, parameters) and access.hasDina() and access.canDoubleJump()) or 
            access.hasAnyDiscovery(['Ship Graveyard','Hidden Pirate Storehouse']) or 
            (access.hasDiscovery('Beehive') and access.canDoubleJump())):
        return False

    location_checks = {
        'Nostalgia Cape': lambda: (
            (location.mapCheckID == 'Ed Join' and access.canMove(16)) or
            (location.mapCheckID in ['TBOX01', 'Driftage','Landmark'])
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkBajaTower(location, access, parameters):
    if not  (
        eterniaOpen(access,parameters) and
        access.past4() and 
        access.hasDana() and
        access.canClimb() #Adding this because of northSideOpen
    ):
        return False

    location_checks = {
        'Second Floor': lambda: True,
        'Third Floor': lambda: location.mapCheckID != 'TBOX03' or access.canDoubleJump(),
        'Mid-Boss Arena': lambda: battleLogic(230, access, parameters),
        'Fifth Floor': lambda: access.canDoubleJump(),
        'Sixth Floor': lambda: access.canDoubleJump(),
        'Boss Arena': lambda: (
            battleLogic(280, access, parameters) and access.canDoubleJump() and 
            (location.mapCheckID != 'Psyches' or (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(340, access, parameters) and access.canDefeat('Carveros')))
        ),
        'Top Floor': lambda: access.canDefeat('Carveros')
    }

    return location_checks.get(location.locName, lambda: False)()

def checkTowalHighway(location, access, parameters):
    if not (
        eterniaOpen(access,parameters) and 
        access.hasDana()
        ):
        return False
    
    if location.mapCheckID == 'Katthew Join' and not access.canClimb():
        # with northSideOpen, its possible to not have grip gloves on north side now
        return False

    return True

def checkStonePillarWindCave(location, access, parameters):
    if not (canAccessNorthSide(access, parameters) and access.canMove(18)):
        return False

    if location.mapCheckID == 'TBOX01':
        return True
    elif location.mapCheckID in ['TBOX02','TBOX03','TBOX05'] and access.canClimb():
        return True
    elif location.mapCheckID == 'TBOX04' and access.canDoubleJump() and access.canClimb():
        return True

def checkSilentTower(location, access, parameters):
    if not (access.canDoubleJump() and (access.hasDina() or access.hasAnyDiscovery(['Beehive','Ship Graveyard','Hidden Pirate Storehouse'])) and access.canMove(24)):
        return False

    location_checks = {
        'Second Basement': lambda: (
            (
            location.mapCheckID in ['Maphorash', 'Maphorash Skill', 'TBOX04'] and 
            battleLogic(380, access, parameters)
            ) or
            location.mapCheckID in ['TBOX01', 'TBOX02', 'TBOX03'] or
            (
            location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
            battleLogic(340, access, parameters) and 
            access.canDefeat('Maphorash')
            )
        ),
        'First Basement': lambda: True
    }

    return location_checks.get(location.locName, lambda: False)()

def checkWaterAndWoodHills(location, access, parameters):
    if not ((access.hasDina() and southSideOpen(access, parameters)) or access.hasAnyDiscovery(['Beehive','Ship Graveyard','Hidden Pirate Storehouse'])):
        return False

    location_checks = {
        'Near Silent Tower': lambda: access.canClimb() and access.canDoubleJump(),
        'Foggy Forest': lambda: True,
        'Water and Wood Hills - Camp': lambda: access.canMove(12)
    }

    return location_checks.get(location.locName, lambda: False)()

def checkPangaiaPlainsNight(location, access, parameters):
    return canAccessNorthSide(access, parameters) and access.canSeeDark()

def checkMontGendarmeNight(location, access, parameters):
    def isSouthSideRoute():
        return (
            access.canClimb()
            and southSideOpen(access, parameters)
            and access.past1()
        )

    def isNorthSideRoute():
        return (
            access.canDefeat('Giasburn') and 
            isValidCheckIfNorth(location, access)
        )

    def isValidCheckIfNorth(location, access):
        return (
            location.locName not in ['Boss Arena','Upper Cliffs 2','Upper Cliffs 1','Mid-Boss Arena',
                                     'Cliffside Midpoint','Outside Cabin','Northern Lower Cliffside Trail'] 
                                     # This was added because there's a potential softlock when dropping into the Northern Lower Cliffside Trail without grip glvoes.
                                     # The player is unable to return without them, therefore we will require them. 
                                     # An event has been added to the entrance of this map to prevent the player from doing this without the gloves.
            or access.canClimb()
        )

    return (
        access.canSeeDark() and
        (isSouthSideRoute() or isNorthSideRoute())
    )

def checkTempleOfGreatTree(location, access, parameters):
    if not ((canAccessNorthSide(access, parameters) and 
            templeOfGreatTreeOpen(access)) or (lodiniaToVista(access) and access.canDoubleJump())):
        return False

    location_checks = {
        "Dana's Room": lambda: True,
        'Temple Boss Arena': lambda: (
            (
            location.mapCheckID == 'Psyches' and 
            battleLogic(340, access, parameters) and 
            access.canDefeat('Brachion')
            ) or 
            (
            location.mapCheckID != 'Psyches' and 
            battleLogic(230,access,parameters)
            )
        ),
        'Great Tree Garden': lambda: (access.canDefeat('Brachion') and 
                                     ((location.mapCheckID != 'Octus Enterance') or (
                                      location.mapCheckID == 'Octus Enterance' and octusAccess(access,parameters)))),
    }

    return location_checks.get(location.locName, lambda: False)()

def checkRuinsOfEternia(location, access, parameters):
    if not (eterniaOpen(access,parameters)):
        return False

    location_checks = {
        'Eastern Entrance': lambda: access.past3(),
        'Central District': lambda: access.hasDina(),
        'Residence': lambda: (
            location.mapCheckID == 'TBOX02' and access.past6()
        ) or location.mapCheckID == 'TBOX01',
        'Palace Ruins': lambda: True,
        'Central Stupa': lambda: True
    }

    return location_checks.get(location.locName, lambda: False)()

def checkPangaiaPlains(location, access, parameters):
    if not canAccessNorthSide(access, parameters):
        return False

    if location.mapCheckID in ['Master Kong Skill Hummel', 'Master Kong Hummel']:
        return (
            battleLogic(220, access, parameters) and
            access.hasHummel() and
            access.canDefeat('Master Kong Laxia')
        )
    
    return True

def checkTitisPrimevalForest(location, access, parameters):
    if not canAccessNorthSide(access, parameters):
        return False
    
    location_checks = {
        'Exit to Pangaia Plains': lambda: True,
        'Near Primordial Den': lambda: (
            (location.mapCheckID == 'TBOX01' and access.past2()) or
            (location.mapCheckID != 'TBOX01')
        ),
        'Entrance from Temple Approach': lambda: True,
    }
    
    return location_checks.get(location.locName, lambda: False)()
    
def checkMountainPinnacleTrail(location, access, parameters):
    return (canAccessNorthSide(access, parameters) and access.past1()) or access.hasDiscovery('Prismatic Mineral Vein')

def checkCavernOfTheAncientKing(location, access, parameters):
    return (access.canMove(11) and access.canSwampWalk()) or access.hasDiscovery('Airs Cairn')

def checkWesternFootOfGendarme(location, access, parameters):
    return (access.canMove(11) and access.canSwampWalk()) or access.hasDiscovery('Airs Cairn')

def mishyRewards(location,access):
    food_checks = {
            'Food 2': lambda: access.canCook(1),
            'Food 4': lambda: access.canCook(2),
            'Food 6': lambda: access.canCook(3),
            'Food 8': lambda: access.canCook(4),
            'Food 10': lambda: access.canCook(5),
            'Food 12': lambda: access.canCook(6)
        }
    
    return food_checks.get(location.mapCheckID, lambda: False)()

def checkMontGendarmeWhenNorthSideOpen(location, access, parameters):
    if location.mapCheckID in ['Giasburn Skill 1', 'Giasburn Skill 2', 'Giasburn']: 
        return battleLogic(230, access, parameters) and access.hasFlameStones(3)
    
    if not access.canDefeat('Giasburn'):
        return False
    
    # If you come from northside, you can already defeat giasburn => can defeat avalodragil 2
    location_checks = {
        'Entrance': lambda: True,
        'Southern Lower Cliffside Trail': lambda: True,
        'Northern Lower Cliffside Trail': lambda: True,
        'Outside Cabin': lambda: True,
        'Cliffside Midpoint': lambda: True,
        'Mid-Boss Arena': lambda: True,
        'Upper Cliffs 1': lambda: True,
        'Upper Cliffs 2': lambda: True,
        'Boss Arena': lambda: (
            (location.mapCheckID in ['Master Kong Skill Laxia', 'Master Kong Laxia'] and 
             access.hasLaxia() and 
             access.canDefeat('Master Kong Dana')
            ) or
            (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
             battleLogic(340, access, parameters))
            ),
        'Mishy Rewards': lambda: mishyRewards(location,access) # Moved here because it was making the logic think food was required for gendarme access
    }

    return location_checks.get(location.locName, lambda: False)()
    

def checkMontGendarme(location, access, parameters):
    if ((access.hasDiscovery('Prismatic Mineral Vein') or (canAccessNorthSide(access,parameters) and access.past1())) and 
        checkMontGendarmeWhenNorthSideOpen(location, access, parameters)):
        return True

    if not (southSideOpen(access, parameters) and access.past1() and access.canClimb()):
        return False

    location_checks = {
        'Entrance': lambda: True,
        'Southern Lower Cliffside Trail': lambda: True,
        'Northern Lower Cliffside Trail': lambda: True,
        'Outside Cabin': lambda: True,
        'Cliffside Midpoint': lambda: True,
        'Mid-Boss Arena': lambda: battleLogic(140, access, parameters),
        'Upper Cliffs 1': lambda: access.canDefeat('Avalodragil 2'),
        'Upper Cliffs 2': lambda: access.canDefeat('Avalodragil 2'),
        'Boss Arena': lambda: (
            (location.mapCheckID in ['Giasburn Skill 1', 'Giasburn Skill 2', 'Giasburn'] and 
             battleLogic(230, access, parameters) and access.hasFlameStones(3)) or
            (location.mapCheckID in ['Master Kong Skill Laxia', 'Master Kong Laxia'] and 
             access.hasLaxia() and 
             access.canDefeat('Master Kong Dana') and 
             access.canDefeat('Giasburn')) or
            (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
             battleLogic(340, access, parameters) and access.canDefeat('Giasburn'))
             ),
        'Mishy Rewards': lambda: access.canDefeat('Avalodragil 2') and mishyRewards(location,access)
    }

    return location_checks.get(location.locName, lambda: False)()

def checkPrimordialPassage(location, access, parameters):
    def isSouthSideRoute():
        return (
            southSideOpen(access, parameters) and 
            access.past1() and 
            access.canClimb()
        )
    
    def isNorthSideRoute():
        return (
            access.canDefeat('Giasburn') and 
            access.past1()
        )
    
    return isSouthSideRoute() or isNorthSideRoute()

def checkOddRockCoast(location, access, parameters):
    if not (access.canDefeat('Laspisus')):
        return False

    return (
        (location.mapCheckID in ['Master Kong Skill Dana', 'Master Kong Dana'] and battleLogic(200, access, parameters) 
        and access.hasDana() 
        and access.canDefeat('Master Kong Sahad')) or
        (location.mapCheckID not in ['Master Kong Skill Dana', 'Master Kong Dana'] 
        and battleLogic(120, access, parameters))
    )

def checkSchlammJungle(location, access, parameters):
    if access.hasDiscovery('Field of Medicinal Herbs') and schlammJungleFromField(location, access, parameters):
        return True
    
    if not (southSideOpen(access, parameters) and access.hasDina()):
        return False

    location_checks = {
        'Entrance': lambda: (
            (location.mapCheckID == 'TBOX03' and (access.canSwampWalk() or access.canDoubleJump())) or
            (location.mapCheckID == 'TBOX02' and access.canClimb()) or
            (location.mapCheckID in ['TBOX01', 'Euron Join'])
        ),
        'North of Entrance': lambda: access.canClimb(),
        'Midpoint': lambda: access.canSwampWalk() or access.canDoubleJump(),
        'Mid-Boss Arena': lambda: battleLogic(100, access, parameters),
        'Small Passage': lambda: (
            access.canDefeat('Magamandra') and (
                (location.mapCheckID == 'TBOX02' and (access.canSwampWalk() or access.canDoubleJump())) or
                (location.mapCheckID == 'TBOX01' and (
                    (access.canSwampWalk() and access.canClimb()) or
                    (access.canDoubleJump() and access.canClimb())
                ))
            )
        ),
        'Muddy Passage': lambda: (
            access.canDefeat('Magamandra') and (access.canSwampWalk() or access.canDoubleJump()) and (
                (location.mapCheckID == 'TBOX02' and ((access.canSwampWalk() and access.canClimb()) or access.canDoubleJump())) or
                (location.mapCheckID == 'TBOX01' and access.canSwampWalk() and access.canClimb())
            )
        ),
        'End': lambda: access.canSwampWalk() and access.canDefeat('Magamandra'),
        'Boss Arena': lambda: (
            battleLogic(100, access, parameters) and access.canDefeat('Magamandra') and access.canSwampWalk() and (
                (location.mapCheckID != 'Psyches') or
                (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and
                 battleLogic(340, access, parameters) and access.canDefeat('Laspisus'))
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def schlammJungleFromField(location, access, parameters):
    location_checks = {
        'Entrance': lambda: (
            (location.mapCheckID == 'TBOX03' and (access.canSwampWalk() or access.canDoubleJump()) and access.canDefeat('Magamandra')) or
            (location.mapCheckID == 'TBOX02' and access.canClimb() and access.canDefeat('Magamandra')) or
            (location.mapCheckID in ['TBOX01', 'Euron Join'] and access.canDefeat('Magamandra'))
        ),
        'North of Entrance': lambda: (access.canClimb() and access.canDefeat('Magamandra')),
        'Midpoint': lambda: ((access.canSwampWalk() or access.canDoubleJump()) and access.canDefeat('Magamandra')),
        'Mid-Boss Arena': lambda: (battleLogic(100, access, parameters) and access.hasDina()),
        'Small Passage': lambda: (
            access.hasDina() and 
                (location.mapCheckID == 'TBOX02' or
                (location.mapCheckID == 'TBOX01' and access.canClimb()))),
        'Muddy Passage': lambda: (
                (location.mapCheckID == 'TBOX02' and ((access.canSwampWalk() and access.canClimb()) or access.canDoubleJump())) or
                (location.mapCheckID == 'TBOX01')
        ),
        'End': lambda: access.canSwampWalk() and access.hasDina(),
        'Boss Arena': lambda: (
            battleLogic(100, access, parameters) and access.hasDina() and access.canSwampWalk() and (
                (location.mapCheckID != 'Psyches') or
                (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and
                 battleLogic(340, access, parameters) and access.canDefeat('Laspisus'))
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkLonghornCoast(location, access, parameters):
    if not ((southSideOpen(access, parameters) and access.hasDina()) or access.hasAnyDiscovery(['Beehive','Ship Graveyard','Hidden Pirate Storehouse'])):
        return False

    location_checks = {
        'Reja Shore': lambda: (
            (location.mapCheckID in ['TBOX03','Pirate Treasure','Landmark'] and access.hasDina()) or
            (location.mapCheckID not in ['TBOX03','Pirate Treasure','Landmark']) or 
            access.hasDiscovery('Beehive')
        ),
        'Eastern Shore': lambda: True
    }

    return location_checks.get(location.locName, lambda: False)()

def checkUndergroundWaterVein(location, access, parameters):
    if not ((access.canUnderwater() and ((access.canMove(11) and access.canClimb()) or access.hasDiscovery('Zephyr Hill'))) 
            or access.hasDiscovery('Lapis Mineral Vein')):
        return False
    
    location_checks = {
        'Lapis Mineral Vein': lambda: True,
        'Submerged Area': lambda: (
            (location.mapCheckID in ['TBOX01','TBOX02'] and access.canUnderwater()) or
            (location.mapCheckID == 'Driftage' and access.canUnderwater() and access.canClimb()) or
            (location.mapCheckID not in ['TBOX01','TBOX02','Driftage'])
        ),
    }
    return location_checks.get(location.locName, lambda: False)()

def checkToweringCoralForestNight(location, access, parameters):
    if not (coastNorthSideAccess(access, parameters) and access.canSeeDark()):
        return False

    location_checks = {
        'Walkways': lambda: (
            location.mapCheckID == 'TBOX02' and (access.canClimb() or access.canDoubleJump())
        ) or (location.mapCheckID != 'TBOX02'),
        'Mid-Boss Arena': lambda: True,
        'After Mid-Boss': lambda: access.canClimb(),
        'Rainbow Falls': lambda: access.canClimb(),
        'End': lambda: access.canClimb(),
        'Entrance': lambda: (
            (location.mapCheckID == 'TBOX03' and access.canClimb()) or
            (location.mapCheckID in ['TBOX01', 'TBOX02'] and access.canDoubleJump())
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkWeathervaneHills(location, access, parameters):
    return (access.canMove(11) and access.canClimb()) or (access.hasDiscovery('Zephyr Hill')) or (access.hasDiscovery('Lapis Mineral Vein') and access.canUnderwater())

def checkHeadwaterFalls(location, access, parameters):
    if not ((access.canMove(11) and access.canClimb()) or (access.hasDiscovery('Zephyr Hill')) or (access.hasDiscovery('Lapis Mineral Vein') and access.canUnderwater())):
        return False

    return (
        (location.mapCheckID == 'TBOX01' and access.canClimb()) or
        (location.mapCheckID != 'TBOX01' and access.hasDina())
    )

def checkSunriseBeach(location, access, parameters):
    if not (access.canDefeat('Gargantula') or access.hasDiscovery('Beached Remains')):
        return False
    
    location_checks = {
        'Sunrise Beach': lambda: (location.mapCheckID in ['Master Kong Skill Sahad','Master Kong Sahad'] 
                                  and battleLogic(200, access, parameters) and access.hasSahad() and access.canDefeat('Master Kong Ricotta')) or
                                  location.mapCheckID not in ['Master Kong Skill Sahad','Master Kong Sahad'] 
    }

    return location_checks.get(location.locName, lambda: False)()

def checkErodedValley(location, access, parameters):
    if not (southSideOpen(access, parameters)):
        return False

    location_checks = {
        'Entrance': lambda: True,
        'Cave': lambda: True,
        'Dark Passage': lambda: access.canSeeDark() and battleLogic(155, access, parameters),
        'Mid-Boss Arena': lambda: battleLogic(60, access, parameters),
        'Webbed Walkways': lambda: (access.canDefeat('Lonbrigius') or access.canDefeat('Gargantula')) and (
            (location.mapCheckID == 'TBOX03' and access.canSeeDark()) or 
            (location.mapCheckID != 'TBOX03')
        ),
        'End': lambda: access.canSeeDark() and (access.canDefeat('Lonbrigius') or access.canDefeat('Gargantula')),
        'Boss Arena': lambda: (
            battleLogic(75, access, parameters) and 
            access.canSeeDark() and 
            (access.canDefeat('Lonbrigius') or access.hasDiscovery('Beached Remains')) and (
                (location.mapCheckID != 'Psyches') or
                (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
                 battleLogic(340, access, parameters) and 
                 access.canDefeat('Gargantula')
                )
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkBeastHills(location, access, parameters):
    if not (southSideOpen(access, parameters)):
        return False

    location_checks = {
        'Valley (Where Hummel Joins)': lambda: True,
        'Collapsed Cliff': lambda: (
            (access.hasDina() or access.hasAnyDiscovery(['Beehive','Ship Graveyard','Hidden Pirate Storehouse'])) and (
                (location.mapCheckID == 'TBOX03' and access.canMove(15)) or
                (location.mapCheckID != 'TBOX03')
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()
    
def checkWaterfallGrotto(location, access, parameters):
    if not (southSideOpen(access, parameters)):
        return False
    
    return (
        location.mapCheckID == 'Sister Nia Join' or
        (location.mapCheckID == 'Landmark' and access.hasDiscovery('Milky White Vein')) or 
        (location.mapCheckID != 'Sister Nia Join' 
             and access.canSeeDark())
    )

def checkGreatRiverValley(location, access, parameters):
    if not (
        southSideOpen(access, parameters)
    ):
        return False

    location_checks = {
        'Cliffs': lambda: (
            (location.mapCheckID == 'TBOX01' and access.canSwampWalk()) or
            (location.mapCheckID == 'TBOX02') or 
            (access.hasDiscovery('Airs Cairn') and access.canMove(11))
        ),
        'Falls': lambda: (
            (location.mapCheckID in ['TBOX01', 'TBOX02'] and access.canSwampWalk()) or
            (location.mapCheckID not in ['TBOX01', 'TBOX02'])
        ),
        'Lookout Tower': lambda: access.hasDina(),
        'Large Shoreline': lambda: (
            (location.mapCheckID == 'TBOX02' and access.canMove(10)) or
            (location.mapCheckID != 'TBOX02')
        ),
        'Chimney Rock': lambda: True,
    }

    return location_checks.get(location.locName, lambda: False)()

def checkRoaringSeashore(location, access, parameters):
    if not (access.canDefeat('Clareon') or access.hasDiscovery('Metavolicalis') or (access.canMove(14) and access.hasDiscovery('Parasequoia'))):
        return False

    location_checks = {
        'Metavolicalis': lambda: True,
        'Parasequoia': lambda: (
            (access.canMove(14) or access.hasDiscovery('Parasequoia')) and (
                (location.mapCheckID in ['Master Kong Skill Ricotta', 'Master Kong Ricotta'] and
                 access.hasRicotta() and battleLogic(220, access, parameters)) or
                (location.mapCheckID not in ['Master Kong Skill Ricotta', 'Master Kong Ricotta'])
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def checkToweringCoralForest(location, access, parameters):
    if access.hasDiscovery('Rainbow Falls') and coralForestFromRainbowFalls(location, access, parameters):
        return True

    if (access.hasDiscovery('Metavolicalis') or (access.canMove(14) and access.hasDiscovery('Parasequoia'))) and coralForestFromRoaringSeashore(location, access, parameters):
        return True

    if not (coastNorthSideAccess(access, parameters)):
        return False

    location_checks = {
        'Entrance': lambda: True,
        'Walkways': lambda: (
            (location.mapCheckID in ['TBOX03', 'TBOX06'] and (access.canClimb() or access.canDoubleJump())) or
            (location.mapCheckID in ['TBOX04', 'TBOX05'])
        ),
        'Midpoint': lambda: True,
        'After Mid-Boss': lambda: (
            location.mapCheckID == 'Corpse' or (location.mapCheckID != 'Corpse' and access.canClimb())
        ),
        'Rainbow Falls': lambda: access.canClimb(),
        'End': lambda: access.canClimb(),
        'Boss Arena': lambda: (
            battleLogic(30, access, parameters) and access.canClimb() and (
                location.mapCheckID != 'Psyches' or 
                (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
                 battleLogic(340, access, parameters) and access.canDefeat('Clareon'))
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def coralForestFromRainbowFalls(location, access, parameters):

    location_checks = {
        'Entrance': lambda: True,
        'Walkways': lambda: (
            (location.mapCheckID in ['TBOX03', 'TBOX06'] and (access.canClimb() or access.canDoubleJump())) or
            (location.mapCheckID in ['TBOX04', 'TBOX05'])
        ),
        'Midpoint': lambda: True,
        'After Mid-Boss': lambda: True,
        'Rainbow Falls': lambda: (
            location.mapCheckID == ['TBOX01','Landmark'] or access.canClimb()
            ),
        'End': lambda: access.canClimb(),
        'Boss Arena': lambda: (
            battleLogic(30, access, parameters) and access.canClimb() and (
                location.mapCheckID != 'Psyches' or 
                (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
                 battleLogic(340, access, parameters) and access.canDefeat('Clareon'))
            )
        )
    }

    return location_checks.get(location.locName, lambda: False)()

def coralForestFromRoaringSeashore(location, access, parameters):
    if location.mapCheckID in ['Clareon Skill 1', 'Clareon Skill 2', 'Clareon']: 
        return battleLogic(30, access, parameters)
    
    if not access.canDefeat('Clareon'):
        return False
    
    location_checks = {
        'Entrance': lambda: True,
        'Walkways': lambda: (
            (location.mapCheckID == 'TBOX03' and (access.canClimb() or access.canDoubleJump())) or
            (location.mapCheckID != 'TBOX03')
        ),
        'Midpoint': lambda: True,
        'After Mid-Boss': lambda: (
            location.mapCheckID == 'Corpse' or (location.mapCheckID != 'Corpse' and access.canClimb())
        ),
        'Rainbow Falls': lambda: (
            (location.mapCheckID in ['TBOX02','TBOX05']) or
            (location.mapCheckID == 'TBOX04' and access.canDoubleJump()) or
            access.canClimb()
            ),
        'End': lambda: True,
        'Boss Arena': lambda: (
                (location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and 
                 battleLogic(340, access, parameters))
            )
    }
    return location_checks.get(location.locName, lambda: False)()

def checkNamelessCoast(location, access, parameters):
    location_checks = {
        'Shoreline North of Boulder': lambda: coastNorthSideAccess(access, parameters),
        'Cliffs North': lambda: southSideOpen(access, parameters),
        'Cliffs South - Treebridge': lambda: (
            (location.mapCheckID == 'TBOX03' and (access.canClimb() or (coastNorthSideAccess(access, parameters) and access.canDoubleJump()))) or 
            (location.mapCheckID != 'TBOX03')
        ),
        'First Avalodragil Arena': lambda: True,
        'Forested Area (Gravel Spot)': lambda: coastNorthSideAccess(access, parameters),
        'North of Castaway Village (Where Adol Meets Laxia)': lambda: True,
        'Northwest of Laxia': lambda: True,
        'Shoreline South of Boulder': lambda: True,
    }

    return location_checks.get(location.locName, lambda: False)()

def checkCalmInlet(location, access, parameters):
    location_checks = {
        'Intercept': checkIntercept,
        'Jewel Trade': checkJewelTrade,
        'Map Completion': checkMapCompletion,
        'Discovery Rewards': checkDiscoveryRewards,
        'Fish Trade': checkFishTrade,
        'Ricotta and Shoebill Reunite': checkRicotta,
        'Calm Inlet (Castaway Village Area)': checkCastawayVillage,
    }

    return location_checks.get(location.locName, alwaysFalse)(location, access, parameters)

def checkIntercept(location, access, parameters):
    stage_logic = {
        'Stage 2': lambda: access.memoCheck(1) and battleLogic(30, access, parameters),
        'Stage 3': lambda: access.memoCheck(1) and battleLogic(75, access, parameters),
        'Stage 5': lambda: access.memoCheck(1) and battleLogic(120, access, parameters),
        'Stage 7': lambda: access.memoCheck(1) and access.hasFlameStones(3),
        'Stage 9': lambda: access.memoCheck(3) and access.hasFlameStones(3) and battleLogic(200, access, parameters),
    }

    return stage_logic.get(location.mapCheckID, lambda: False)()

def checkJewelTrade(location, access, parameters):
    if not access.hasDina():
        return False

    if location.mapCheckID == 'Item 5':
        return (
            canAccessNorthSide(access, parameters) and
            access.canSeeDark() and 
            access.canFish()
        )
    else:
        return access.hasJewels(23)

def checkMapCompletion(location, access, parameters):

    if not access.hasEuron():
        return False

    completionLogic = {
        'Percent 10': lambda: (
            access.mapCompletion(13)
        ),
        'Percent 20': lambda: (
            access.mapCompletion(23)
        ),
        'Percent 30': lambda: (
            access.mapCompletion(33)
        ),
        'Percent 40': lambda: (
            access.mapCompletion(43)
        ),
        'Percent 50': lambda: (
            access.mapCompletion(53)
        ),
        'Percent 60': lambda: (
            access.mapCompletion(63) and 
            access.mapIncrease() 
        ),
        'Percent 70': lambda: (
            access.mapCompletion(73) and 
            access.mapIncrease() 
        ),
        'Percent 80': lambda: (
            access.mapCompletion(83) and 
            access.mapIncrease() 
        ),
        'Percent 90': lambda: (
            access.mapCompletion(93) and 
            access.mapIncrease() 
        ),
        'Percent 100': lambda: False,
    }
    return completionLogic.get(location.mapCheckID, lambda: False)()

def checkDiscoveryRewards(location, access, parameters):
    if not access.canShowDiscoveries():
        return False
    if location.mapCheckID == 'Half':
        return access.discoveryCount(12)
    elif location.mapCheckID == 'All':
        return access.discoveryCount(24)
    else:
        return False

def checkFishTrade(location, access, parameters):
    if not access.canFish():
        return False
    if location.mapCheckID in ['Fish 4', 'Fish 8', 'Fish 12', 'Fish 16']:
        return True
    elif location.mapCheckID == 'Fish 20':
        return coastNorthSideAccess(access, parameters)
    elif location.mapCheckID == 'Fish 24':
        return southSideOpen(access, parameters)
    return False

def checkRicotta(location, access, parameters):
    return access.hasRicotta()

def checkCastawayVillage(location, access, parameters):
    if location.mapCheckID in ['Silvia Skill 1', 'Silvia Skill 2', 'Silvia']:
        return access.hasSilvia() and battleLogic(260, access, parameters)
    else:
        return True

def checkWaterDropCave(location, access, parameters):
    return True

def checkWhiteSandCape(location, access, parameters):
    location_checks = {
        'Cobalt Crag': lambda: (
            location.mapCheckID == 'TBOX03' and access.canMove(20) or
            location.mapCheckID == 'TBOX02' and access.canDoubleJump() or
            location.mapCheckID not in ['TBOX03' or 'TBOX02']
        ),
        'North of Starting Shore': lambda: True,
        "Alison's Shore": lambda: True,
        'Coral Shore': lambda: True
    }

    return location_checks.get(location.locName, lambda: False)()

def battleLogic(requiredStr,access,parameters):
    #if battle logic isn't turned on we just skip this entire calculation and return true. 
    #battle logic is based entirely off current strength. 
    if parameters.battleLogic:
        weaponStr = 0
        armorStr = 0
        armStr = 0
        accStr = 0

        #weapon strength is based on rounded averages of accessible weapons at their base levels.
        #some basic checks will be made to make sure materials can be farmed as well
        if parameters.progressiveSuperWeapons and access.hasFlameStones(7) and ((access.hasMistilteinn() and access.hasAdol()) or (access.hasSpiritRing() and access.hasDana())):
            weaponStr = 290
        elif not parameters.progressiveSuperWeapons and ((access.hasMistilteinn() and access.hasAdol()) or (access.hasSpiritRing() and access.hasDana())):
            weaponStr = 290
        elif access.hasFlameStones(7) and materialAccess('Dragon Crest Stone',access,parameters):
            weaponStr = 270
        elif access.hasFlameStones(6) and (materialAccess('Essence Stone',access,parameters) or 
                                           materialAccess('Dragon Crest Stone',access,parameters)): 
            weaponStr = 240
        elif access.hasFlameStones(5) and (materialAccess('Essence Stone',access,parameters) or 
                                           materialAccess('Dragon Crest Stone',access,parameters)): 
            weaponStr = 210
        elif access.hasFlameStones(4) and (materialAccess('Essence Stone',access,parameters) or 
                                           materialAccess('Dragon Crest Stone',access,parameters) or
                                           materialAccess('Tectite Ore',access,parameters)): 
            weaponStr = 180
        elif access.hasFlameStones(3): 
            weaponStr = 150
        elif access.hasFlameStones(2) and (materialAccess('Essence Stone',access,parameters) or 
                                           materialAccess('Dragon Crest Stone',access,parameters) or
                                           materialAccess('Tectite Ore',access,parameters) or
                                           materialAccess('Iron Ore',access,parameters)): 
            weaponStr = 100
        elif access.hasFlameStones(1) and (materialAccess('Essence Stone',access,parameters) or 
                                           materialAccess('Dragon Crest Stone',access,parameters) or
                                           materialAccess('Tectite Ore',access,parameters) or
                                           materialAccess('Iron Ore',access,parameters)): 
            weaponStr = 50
        
        if access.hasFlameStones(7) and materialAccess('Underworld Parts',access,parameters): 
            armorStr = 25
        elif access.hasFlameStones(6) and ((materialAccess('Underworld Parts',access,parameters) and access.hasDina()) or (
                                           materialAccess('Ancient Bone',access,parameters) and
                                           materialAccess('Ancient Hide',access,parameters) and
                                           materialAccess('Saurian Scale',access,parameters))): 
            armorStr = 20
        elif access.hasFlameStones(5) and ((materialAccess('Underworld Parts',access,parameters) and access.hasDina()) or (
                                           materialAccess('Ancient Bone',access,parameters) and
                                           materialAccess('Ancient Hide',access,parameters) and
                                           materialAccess('Saurian Scale',access,parameters))): 
            armorStr = 16
        elif access.hasFlameStones(4) and ((materialAccess('Underworld Parts',access,parameters) and access.hasDina()) or (
                                           materialAccess('Ancient Bone',access,parameters) and
                                           materialAccess('Ancient Hide',access,parameters) and
                                           materialAccess('Saurian Scale',access,parameters) and access.hasDina()) or (
                                           materialAccess('Beast Parts',access,parameters))): 
            armorStr = 13
        elif access.hasFlameStones(2) and ((materialAccess('Underworld Parts',access,parameters) and access.hasDina()) or (
                                           materialAccess('Ancient Bone',access,parameters) and
                                           materialAccess('Ancient Hide',access,parameters) and
                                           materialAccess('Saurian Scale',access,parameters) and access.hasDina()) or (
                                           materialAccess('Beast Parts',access,parameters))): 
            armorStr = 10
        elif access.hasFlameStones(1) and (((materialAccess('Underworld Parts',access,parameters) and access.hasDina()) or (
                                           materialAccess('Ancient Bone',access,parameters) and
                                           materialAccess('Ancient Hide',access,parameters) and
                                           materialAccess('Saurian Scale',access,parameters) and access.hasDina()) or (
                                           materialAccess('Beast Parts',access,parameters) and access.hasDina())) or 
                                           access.hasDina()): 
            armorStr = 6
        elif access.hasFlameStones(1) and (((materialAccess('Underworld Parts',access,parameters) and access.hasDina()) or (
                                           materialAccess('Ancient Bone',access,parameters) and
                                           materialAccess('Ancient Hide',access,parameters) and
                                           materialAccess('Saurian Scale',access,parameters) and access.hasDina()) or (
                                           materialAccess('Beast Parts',access,parameters) and access.hasDina())) or 
                                           access.hasDina()): 
            armorStr = 3

        #for armlet's and accesories we scan the world to see what's accessible from checks then compare that to what can be acquired from shop levels then take the highest number
        foundArmStr = access.armletStr()
        if access.hasFlameStones(7) and access.hasEuron() and materialAccess('Beast Parts',access,parameters): 
            armStr = 30
        elif access.hasFlameStones(6) and access.hasEuron() and materialAccess('Saurian Scale',access,parameters) and materialAccess('Ancient Hide',access,parameters):
            armStr = 20
        elif access.hasFlameStones(4) and access.hasEuron() and materialAccess('Dragon Crest Stone',access,parameters) and materialAccess('Essence Stone',access,parameters): 
            armStr = 10

        if armStr < foundArmStr:
            armStr = foundArmStr

        
        foundAccStr = access.accessoryStr()
        bladeRings = [0]
        pyriosAcc = [0]
        fenrirAcc = [0]
        hopeAndLum = [0]
        dragonAcc = [0]
        otherAcc = [0]
    
        #shop logic for accessories to see what can be found and farmed for. This is a little imperfect as we aren't combining what is found with the shop values 
        #but it should be a close enough approximation to what the player could pump their strength to with accessories.
        if access.hasAlison and not access.hasEuron:
            bladeRings.append(10) #Blade Ring
            if coastNorthSideAccess(access, parameters) or access.hasDina():
                hopeAndLum.append(20) #Hope Stone
        if access.hasEuron and access.hasFlameStones(2):
            if materialAccess('Razor Feather',access,parameters) and southSideOpen(access, parameters):
                fenrirAcc.append(5) #Fenrir Talisman
            if southSideOpen(access, parameters):
                bladeRings.append(20) #Blade Ring 2
            if ((access.canFish() and access.hasPearls(7)) or (access.hasDina)) and (southSideOpen(access, parameters)):
                hopeAndLum.append(40) #luminous ring
            if materialAccess('Accursed Shell',access,parameters) and southSideOpen(access, parameters):
                pyriosAcc.append(5) #Pyrios Talisman
        if access.hasEuron and access.hasFlameStones(4):
            if materialAccess('Thunder Claw',access,parameters) and materialAccess('Tectite Ore',access,parameters):
                otherAcc.append(10) #lightning stone
            if materialAccess('Thunder Claw',access,parameters) and materialAccess('Beast Parts',access,parameters):
                bladeRings.append(30) #Blade Ring 3
            if materialAccess('Essence Stone',access,parameters) and materialAccess('Tectite Ore',access,parameters):
                otherAcc.append(10) #crow stone
            if materialAccess('Tectite Ore',access,parameters) and materialAccess('Ancient Lumber',access,parameters):
                otherAcc.append(10) #snake stone
        if access.hasEuron and access.hasFlameStones(5):
            if southSideOpen(access, parameters):
                dragonAcc.append(10) #dragon pauldron
            if materialAccess('Essence Stone',access,parameters):
                dragonAcc.append(20) #dragon stone
            if materialAccess('Essence Stone',access,parameters) and materialAccess('Dragon Crest Stone',access,parameters):
                fenrirAcc.append(15) #fenrir stone
                pyriosAcc.append(15) #pyrios stone
                otherAcc.append(10) #nature talisman
        if access.hasEuron and access.hasFlameStones(7):
            if materialAccess('Dragon Crest Stone',access,parameters) and materialAccess('Ancient Hide',access,parameters):
                bladeRings.append(40) #Blade Ring 4
        
        #sort all of the lists of accessories that can't be equipped together highest strength to lowest. We'll then combine them taking only the highest from each list except the other category which doesn't have any conflicts.
        bladeRings.sort(reverse=True)
        pyriosAcc.sort(reverse=True)
        fenrirAcc.sort(reverse=True)
        hopeAndLum.sort(reverse=True)
        dragonAcc.sort(reverse=True)
        
        #other becomes our base since it lacks conflicts. We'll then sort it and add the top two number together.
        otherAcc.append(bladeRings[0])
        otherAcc.append(pyriosAcc[0])
        otherAcc.append(fenrirAcc[0])
        otherAcc.append(hopeAndLum[0])
        otherAcc.append(dragonAcc[0])
        otherAcc.sort(reverse=True)

        accStr = otherAcc[0] + otherAcc[1]

        if accStr < foundAccStr:
            accStr = foundAccStr

        if requiredStr >= 150:
            if (weaponStr + armorStr + armStr + accStr) >= requiredStr and access.partySize(2):
                return True
            else: return False
        else:
            if (weaponStr + armorStr + armStr + accStr) >= requiredStr:
                return True
            else: return False

    else: return True #if battle logic isn't on then we skip everything and return true for access logic

def materialAccess(material,access,parameters):
    match material:
        case 'Dragon Crest Stone': #Used for Acidic Liquid and Sunlight Fang too
            return (
            #Silent Tower Access
            (access.canDoubleJump() and access.canMove(24) and 
                (access.hasDina() or access.hasAnyDiscovery(['Beehive','Ship Graveyard','Hidden Pirate Storehouse']))) or 
            #Valley of Kings Access
            (((access.canSwampWalk() or access.canUnderwater()) and ((
                canAccessNorthSide(access, parameters) and 
                templeOfGreatTreeOpen(access) and
                access.past6() and 
                access.canClimb()) or (
                (access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or access.hasDiscovery('Sky Garden')))) or (
            access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark() and access.canMove(22))
            ) or 
            #Octus Access
            access.canDefeat('Octus Enterance') or 
            #Lapis Mineral Vein Access
            (access.canUnderwater() and ((access.canMove(11) and access.canClimb()) or access.hasDiscovery('Zephyr Hill'))) 
            or access.hasDiscovery('Lapis Mineral Vein'))
        case 'Essence Stone': #blue feather and dandale horn are also used on this as it's the same requirements
            #Access to Vista Ridge from Eternia or access to all of Lodinia
            return ((canAccessNorthSide(access, parameters) and templeOfGreatTreeOpen(access)) or (lodiniaToVista(access) and access.canDoubleJump()))
        case 'Tectite Ore':
            #Access to north side and Mountain Pinnacle Trail
            return (access.hasDiscovery('Prismatic Mineral Vein') or (canAccessNorthSide(access,parameters) and access.past1()))
        case 'Iron Ore':
            return (coastNorthSideAccess(access,parameters) or access.hasAnyDiscovery(['Milky White Vein','Indigo Mineral Vein']))
        case 'Underworld Parts':
            #Octus Access
            return access.canDefeat('Octus Enterance')
        case 'Ancient Bone':
            #Valley of Kings Access
            return ((((access.canSwampWalk() or access.canUnderwater()) and ((
                canAccessNorthSide(access, parameters) and 
                templeOfGreatTreeOpen(access) and
                access.past6() and 
                access.canClimb()) or (
                (access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or access.hasDiscovery('Sky Garden')))) or (
            access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark() and access.canMove(22))
            ) or (
            #Eleftheria Access
            (southSideOpen(access, parameters) and access.hasDina()) or 
                access.hasAnyDiscovery(['Ship Graveyard','Hidden Pirate Storehouse','Beehive'])) and 
            access.canDoubleJump() and 
            access.readNote1() and 
            access.canDefeat('Gilkyra Encounter') or (
            #Chasm Access
            eterniaOpen(access,parameters) and access.past5())
            )
        case 'Ancient Hide':
            #Temple of the Great Tree Access
            return (((canAccessNorthSide(access, parameters) and templeOfGreatTreeOpen(access)) or 
                     (lodiniaToVista(access) and access.canDoubleJump())) or (
            #Eleftheria Access
            (southSideOpen(access, parameters) and access.hasDina()) or 
                access.hasAnyDiscovery(['Ship Graveyard','Hidden Pirate Storehouse','Beehive'])) and 
            access.canDoubleJump() and 
            access.readNote1() and 
            access.canDefeat('Gilkyra Encounter') or (
            #Chasm Access
            eterniaOpen(access,parameters) and access.past5())
            )
        case 'Saurian Scale':
            return canAccessNorthSide(access,parameters)
        case 'Beast Parts':
            return (canAccessNorthSide(access, parameters) and access.past1()) or access.hasDiscovery('Prismatic Mineral Vein')
        case 'Accursed Shell':
            return (southSideOpen(access, parameters) and access.past1() and access.canClimb()) or canAccessNorthSide(access,parameters)
        case 'Razor Feather':
            return access.canDefeat('Gargantula') or access.canDefeat('Lonbrigius')
        case 'Thunder Claw':
            #Towal Highway Access
            return ((eterniaOpen(access,parameters) and access.hasDana()) or (
            #Valley of Kings Access 
            ((access.canSwampWalk() or access.canUnderwater()) and ((
                canAccessNorthSide(access, parameters) and 
                templeOfGreatTreeOpen(access) and
                access.past6() and 
                access.canClimb()) or (
                (access.hasDiscovery('Graves of Ancient Heroes') and access.past7()) or access.hasDiscovery('Sky Garden')))) or (
            access.hasDiscovery('Soundless Hall') and access.canUnderwater() and access.canSeeDark() and access.canMove(22))
            ))
        case 'Ancient Lumber':
            #Temple of the Great Tree Access
            return (((canAccessNorthSide(access, parameters) and templeOfGreatTreeOpen(access)) or 
                     (lodiniaToVista(access) and access.canDoubleJump())) or (
            #Chasm Access
            eterniaOpen(access,parameters) and access.past5()))
        



        

    

    
        

    
            
    
    
