import shared.classr as classr  

def canAccess(inventory,location,parameters):
    access = classr.access(inventory)
    if location.locRegion == 'White Sand Cape':
        if location.locName == 'Cobalt Crag':
            if location.mapCheckID == 'TBOX03' and access.canMove(20): return True
            elif location.mapCheckID == 'TBOX02' and access.canDoubleJump(): return True
            elif location.mapCheckID == 'TBOX01': return True
            else: return False
        elif location.locName != 'Cobalt Crag': return True
        else: return False
    elif location.locRegion == 'Waterdrop Cave': return True
    elif location.locRegion == 'Calm Inlet': 
        if location.locName ==  'Intercept':
            if location.mapCheckID in ['Stage 2','Stage 3','Stage 5'] and access.memoCheck(1): return True
            elif location.mapCheckID == 'Stage 7' and access.memoCheck(1) and access.hasFlameStones(3): return True
            elif location.mapCheckID == 'Stage 9' and access.memoCheck(3) and access.hasFlameStones(3): return True
            else: return False
        elif location.locName == 'Jewel Trade' and access.hasDina():
            if location.mapCheckID == 'Item 5' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.canSeeDark() and access.canFish(): return True
            elif location.mapCheckID != 'Item 5' and access.hasJewels(23): return True
            else: return False
        elif location.locName == 'Map Completion':
            if location.mapCheckID == 'Percent 10' and (access.canClimb() or access.canMove(8)) and access.hasEuron(): return True
            elif location.mapCheckID == 'Percent 20' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.hasEuron(): return True
            elif location.mapCheckID == 'Percent 30' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.hasEuron() and access.canSwampWalk(): return True
            elif location.mapCheckID == 'Percent 40' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.hasEuron() and access.canSwampWalk() and (access.hasDina() or (access.past1() and access.hasFlameStones(3))) and access.canMove(11) and access.canDefeat('Giasburn'): return True
            elif location.mapCheckID == 'Percent 50' and access.canClimb() and (access.canDoubleJump() or (access.canMove(16) and access.canSwampWalk())) and access.hasEuron() and ((access.hasDina() and access.canDoubleJump() and access.readNote1()) or (access.past1() and access.hasFlameStones(3))) and access.canDefeat('Giasburn'): return True
            elif location.mapCheckID == 'Percent 60' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(16) and access.canSwampWalk() and access.hasEuron() and ((access.hasDina() and access.readNote1) or (access.past1() and access.hasFlameStones(3) and access.past2() and access.past3 and access.hasDana())) and access.canDefeat('Giasburn'): return True
            elif location.mapCheckID == 'Percent 70' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(16) and access.canSwampWalk() and access.hasEuron() and access.hasDina() and access.readNote1 and access.past1() and access.hasFlameStones(3) and access.past2() and access.past3() and ((access.hasDana() and  access.past4()) or (access.past5() and access.canUnderwater())) and access.canDefeat('Giasburn'): return True
            elif location.mapCheckID == 'Percent 80' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(20) and access.canSwampWalk() and access.hasEuron() and access.hasDina() and access.readNote1 and access.past1() and access.hasFlameStones(3) and access.past2() and access.past3() and access.hasDana() and access.past4() and access.past5() and access.canUnderwater() and access.canSeeDark() and access.canDefeat('Giasburn'): return True
            elif location.mapCheckID == 'Percent 90' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(24) and access.canSwampWalk() and access.hasEuron() and access.hasDina() and access.readNote1 and access.past1() and access.hasFlameStones(3) and access.past2() and access.past3() and access.hasDana() and access.past4() and access.past5() and access.canUnderwater() and access.past6() and access.canUndead() and access.canSeeDark() and access.canDefeat('Giasburn'): return True
            elif location.mapCheckID == 'Percent 100': return False
            else: return False
        elif location.locName == 'Discovery Rewards':
            if location.mapCheckID == 'Half' and canDiscover(access,12) and access.canShowDiscoveries(): return True
            elif location.mapCheckID == 'All' and canDiscover(access,24) and access.canShowDiscoveries(): return True
            else: return False
        elif location.locName == 'Fish Trade' and access.canFish(): 
            if location.mapCheckID in ['Fish 4', 'Fish 8', 'Fish 12', 'Fish 16']: return True
            elif location.mapCheckID == 'Fish 20' and (access.canMove(6) or access.canClimb()): return True
            elif location.mapCheckID == 'Fish 24' and (access.canMove(8) or access.canClimb() or (access.canMove(6) and access.canSeeDark())): return True
            else: return False
        elif location.locName == 'Ricotta and Shoebill Reunite' and access.hasRicotta(): return True
        elif location.locName == 'Calm Inlet (Castaway Village Area)':
            if location.mapCheckID in ['Silvia Skill 1','Silvia Skill 1','Silvia'] and access.hasSilvia() and battleLogic(200,access,parameters): return True
            elif location.mapCheckID not in ['Silvia Skill 1','Silvia Skill 1','Silvia']: return True
        else: return False
    elif location.locRegion == 'Nameless Coast':
        if location.locName == 'Shoreline North of Boulder' and (access.canMove(6) or access.canClimb()): return True
        elif location.locName == 'Cliffs North' and (access.canMove(6) or access.canClimb()): return True
        elif location.locName == 'Cliffs South - Treebridge':
            if location.mapCheckID == 'TBOX03' and (access.canClimb() or (access.canMove(6) and access.canDoubleJump())): return True
            elif location.mapCheckID != 'TBOX03': return True
            else: return False
        elif location.locName == 'First Avalodragil Arena': return True
        elif location.locName == 'Forested Area (Gravel Spot)' and (access.canMove(6) or access.canClimb()): return True
        elif location.locName == 'North of Castaway Village (Where Adol Meets Laxia)': return True
        elif location.locName == 'Northwest of Laxia': return True
        elif location.locName == 'Shoreline South of Boulder': return True
        else: return False
    elif location.locRegion == 'Towering Coral Forest' and (access.canMove(6) or access.canClimb()):
        if location.locName == 'Entrance': return True
        elif location.locName == 'Walkways':
            if location.mapCheckID in ['TBOX03','TBOX06'] and (access.canClimb() or access.canDoubleJump()): return True
            elif location.mapCheckID in ['TBOX4','TBOX05']: return True
            else: return False
        elif location.locName == 'Midpoint': return True
        elif location.locName == 'After Mid-Boss':
            if location.mapCheckID == 'Corpse': return True
            elif location.mapCheckID != 'Corpse' and access.canClimb(): return True
            else: return False
        elif location.locName in ['Rainbow Falls','End'] and access.canClimb(): return True
        elif location.locName == 'Boss Arena' and battleLogic(20,access,parameters): 
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Clareon'): return True
            else: return False
        else: return False
    elif location.locRegion == 'Roaring Seashore' and access.canClimb() and access.canDefeat('Clareon'):
        if location.locName == 'Metavolicalis': return True
        elif location.locName == 'Parasequoia' and access.canMove(14) and access.canDefeat('Clareon'): 
            if location.mapCheckID in ['Master Kong Skill Ricotta','Master Kong Ricotta'] and access.hasRicotta() and battleLogic(165,access,parameters): return True
            elif location.mapCheckID not in ['Master Kong Skill Ricotta','Master Kong Ricotta']: return True
            else: return False
        else: return False
    elif location.locRegion == 'Great River Valley' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        if location.locName == 'Cliffs':
            if location.mapCheckID == 'TBOX01' and access.canSwampWalk(): return True
            elif location.mapCheckID == 'TBOX02': return True
            else: return False
        elif location.locName == 'Falls':
            if location.mapCheckID in ['TBOX01','TBOX02'] and access.canSwampWalk(): return True
            elif location.mapCheckID not in ['TBOX01','TBOX02']: return True
            else: return False
        elif location.locName == 'Lookout Tower' and access.hasDina(): return True
        elif location.locName == 'Large Shoreline':
            if location.mapCheckID == 'TBOX02' and access.canMove(10): return True
            elif location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Chimney Rock': return True
        else: return False
    elif location.locRegion == 'Waterfall Grotto' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        if location.mapCheckID == 'Sister Nia Join': return True
        elif location.mapCheckID != 'Sister Nia Join' and access.canSeeDark(): return True
        else: return False
    elif location.locRegion == 'Beast Hills' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        if location.locName == 'Valley (Where Hummel Joins)': return True
        elif location.locName == 'Collapsed Cliff' and access.hasDina():
            if location.mapCheckID == 'TBOX03' and access.canMove(15): return True
            elif location.mapCheckID != 'TBOX03': return True
            else: return False
        else: return False
    elif location.locRegion == 'Eroded Valley' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        if location.locName in ['Entrance','Cave']: return True
        elif location.locName == 'Dark Passage' and access.canSeeDark() and battleLogic(100,access,parameters): return True
        elif location.locName == 'Mid-Boss Arena' and battleLogic(50,access,parameters): return True
        elif location.locName == 'Webbed Walkways' and access.canDefeat('Lonbrigius'):
            if location.mapCheckID == 'TBOX03' and access.canSeeDark(): return True
            elif location.mapCheckID != 'TBOX03': return True
        elif location.locName == 'End'  and access.canSeeDark() and access.canDefeat('Lonbrigius'): return True
        elif location.locName == 'Boss Arena' and battleLogic(60,access,parameters): 
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Gargantula'): return True
            else: return False
        else: return False
    elif location.locRegion == 'Sunrise Beach' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canSeeDark() and access.canDefeat('Gargantula'): 
        if location.mapCheckID in ['Master Kong Skill Sahad','Master Kong Sahad'] and battleLogic(165,access,parameters) and access.hasSahad() and access.canDefeat('Master Kong Ricotta'): return True
        elif location.mapCheckID not in ['Master Kong Skill Sahad','Master Kong Sahad']: return True
    elif location.locRegion == 'Towering Coral Forest (Night)' and (access.canClimb() or access.canMove(6)) and access.canSeeDark():
        if location.locName == 'Walkways':
            if location.mapCheckID == 'TBOX02' and (access.canClimb() or access.canDoubleJump()): return True
            elif location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Mid-Boss Arena': return True
        elif location.locName == 'After Mid-Boss' and access.canClimb(): return True
        elif location.locName == 'Rainbow Falls' and access.canClimb(): return True
        elif location.locName == 'End' and access.canClimb(): return True
        elif location.locName == 'Entrance':
            if location.mapCheckID == 'TBOX03' and access.canClimb(): return True
            elif (location.mapCheckID == 'TBOX01' or location.mapCheckID == 'TBOX02') and access.canDoubleJump(): return True
            else: return False
    elif location.locRegion == 'Weathervane Hills' and access.canMove(11) and access.canClimb(): return True
    elif location.locRegion == 'Headwater Falls' and access.canMove(11) and access.canClimb():
        if location.mapCheckID == 'TBOX01': return True
        elif location.mapCheckID != 'TBOX01' and access.hasDina(): return True
        else: return False
    elif location.locRegion == 'Underground Water Vein' and access.canUnderwater() and access.canMove(11) and access.canClimb(): return True
    elif location.locRegion == 'Longhorn Coast' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.hasDina():
        if location.locName == 'Reja Shore':
            if location.mapCheckID in ['TBOX01','TBOX03'] and access.hasDina(): return True
            elif location.mapCheckID in ['Reja Join','Pirate Treasure']: return True
            else: return False
        elif location.locName == 'Eastern Shore': return True
        else: return False
    elif location.locRegion == 'Schlamm Jungle' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.hasDina():
        if location.locName == 'Entrance':
            if location.mapCheckID == 'TBOX03' and (access.canSwampWalk() or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX02' and access.canClimb(): return True
            elif location.mapCheckID == 'TBOX01': return True
            elif location.mapCheckID == 'Euron Join': return True
            else: return False
        elif location.locName == 'North of Entrance' and access.canClimb(): return True
        elif location.locName == 'Midpoint' and (access.canSwampWalk() or access.canDoubleJump()): return True
        elif location.locName == 'Mid-Boss Arena' and battleLogic(100,access,parameters): return True
        elif location.locName == 'Small Passage' and access.canDefeat('Magamandra'):
            if location.mapCheckID == 'TBOX02' and (access.canSwampWalk() or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX01' and ((access.canSwampWalk() and access.canClimb) or (access.canDoubleJump() and access.canClimb)): return True
            else: return False
        elif location.locName == 'Muddy Passage' and (access.canSwampWalk() or access.canDoubleJump()) and access.canDefeat('Magamandra'):
            if location.mapCheckID == 'TBOX02' and ((access.canSwampWalk() and access.canClimb()) or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX01' and access.canSwampWalk() and access.canClimb(): return True
            else: return False
        elif location.locName == 'End' and access.canSwampWalk() and access.canDefeat('Magamandra'): return True
        elif location.locName == 'Boss Arena' and battleLogic(100,access,parameters): 
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Laspisus'): return True
            else: return False
        else: return False
    elif location.locRegion == 'Odd Rock Coast' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.hasDina() and access.canSwampWalk() and access.canDefeat('Laspisus'): 
        if location.mapCheckID in ['Master Kong Skill Dana','Master Kong Dana'] and battleLogic(175,access,parameters) and access.hasDana() and access.canDefeat('Master Kong Sahad'): return True
        elif location.mapCheckID in ['Kiergaard Weissman','Kiergaard Weissman Skill 1','Kiergaard Weissman Skill 1','Quina Join','Licht Join'] and battleLogic(100,access,parameters): return True
        else: return False
    elif location.locRegion == 'The Primordial Passage' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1(): return True
    elif location.locRegion == 'Mont Gendarme' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1(): 
        if location.locName == 'Mishy Rewards' and battleLogic(100,access,parameters):
            if location.mapCheckID == 'Food 2' and access.canCook(1): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(2): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(3): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(4): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(5): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(6): return True
            else: return False
        elif location.locName == 'Mid-Boss Arena' and battleLogic(100,access,parameters): return True
        elif location.locName in ['Upper Cliffs 1','Upper Cliffs 2'] and access.canDefeat('Avalodragil 2'): return True
        elif location.locName == 'Boss Arena': 
            if location.mapCheckID in ['Giasburn Skill 1','Giasburn Skill 2','Giasburn'] and battleLogic(165,access,parameters): return True
            elif location.mapCheckID in ['Master Kong Skill Laxia','Master Kong Laxia'] and battleLogic(185,access,parameters) and access.hasLaxia() and access.canDefeat('Master Kong Dana'): return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Giasburn'): return True
            else: return False
        elif location.locName not in ['Mid-Boss Arena','Upper Cliffs 1','Upper Cliffs 2','Mishy Rewards','Boss Arena']: return True
        else: return False
    elif location.locRegion == 'Western Foot of Gendarme' and access.canMove(11) and access.canSwampWalk(): return True
    elif location.locRegion == 'Cavern of the Ancient King' and access.canMove(11) and access.canSwampWalk(): return True
    elif location.locRegion == 'Mountain Pinnacle Trail' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.canDefeat('Giasburn'): return True
    elif location.locRegion == 'Titis Primeval Forest' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.canDefeat('Giasburn'):
        if location.locName == 'Near Primordial Den':
            if location.mapCheckID == 'TBOX01' and access.past2(): return True
            elif location.mapCheckID != 'TBOX01': return True
            else: return False
        elif location.locName != 'Near Primordial Den': return True
        else: return False
    elif location.locRegion == 'Pangaia Plains' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.canDefeat('Giasburn'): 
        if location.locName == 'Ancient Tree':
            if location.mapCheckID in ['Master Kong Skill Hummel','Master Kong Hummel'] and battleLogic(200,access,parameters) and access.hasHummel() and access.canDefeat('Master Kong Laxia'): return True
            elif location.mapCheckID not in ['Master Kong Skill Hummel','Master Kong Hummel']: return True
            else: return False
        else: return False
    elif location.locRegion == 'The Ruins of Eternia' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and (access.past2() or (access.past3() and access.hasDana())) and access.canDefeat('Giasburn'):
        if location.locName == 'Eastern Entrance' and access.past3(): return True
        elif location.locName == 'Central District' and access.hasDina(): return True
        elif location.locName == 'Residence':
            if location.mapCheckID == 'TBOX02' and access.past6(): return True
            elif location.mapCheckID == 'TBOX01': return True
            else: return False
        elif location.locName == 'Palace Ruins': return True
        else: return False
    elif location.locRegion == 'Temple of the Great Tree' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.canDefeat('Giasburn'):
        if location.locName == 'Temple Boss Arena':
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Brachion'): return True
            else: return False
        elif location.locName != 'Temple Boss Arena': return True
        else: return False
    elif location.locRegion == 'Mont Gendarme (Night)'and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canSeeDark(): return True
    elif location.locRegion == 'Pangaia Plains (Night)' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.canSeeDark() and access.canDefeat('Giasburn'): return True
    elif location.locRegion == 'Water and Wood Hills' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.hasDina():
        if location.locName == 'Near Silent Tower' and access.canClimb() and access.canDoubleJump(): return True
        elif location.locName == 'Foggy Forest': return True
        elif location.locName == 'Water and Wood Hills - Camp' and access.canMove(12): return True
        else: return False
    elif location.locRegion == 'Silent Tower' and access.canDoubleJump() and access.hasDina() and access.canMove(24):
        if location.locName == 'Second Basement':
            if location.mapCheckID in ['Maphorash','Maphorash Skill 1','Maphorash Skill 2','TBOX04'] and battleLogic(270,access,parameters): return True
            elif location.mapCheckID in ['TBOX01','TBOX02','TBOX03']: return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Maphorash'): return True
            else: return False
        elif location.locName != 'Second Basement': return True
        else: return False
    elif location.locRegion == 'Stone Pillar Wind Cave' and access.canClimb() and access.past1() and access.hasFlameStones(3) and access.canMove(18) and access.canDefeat('Giasburn'):
        if location.mapCheckID == 'TBOX04' and access.canDoubleJump(): return True
        elif location.mapCheckID != 'TBOX04': return True
        else: return False
    elif location.locRegion == 'Towal Highway' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.past3() and access.hasDana() and access.canDefeat('Giasburn'): return True
    elif location.locRegion == 'Baja Tower' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.past3() and access.hasDana() and access.past4() and access.canDefeat('Giasburn'):
        if location.locName == 'Second Floor': return True
        elif location.locName == 'Third Floor':
            if location.mapCheckID == 'TBOX03' and access.canDoubleJump(): return True
            elif location.mapCheckID != 'TBOX03': return True
            else: return False
        elif location.locName == 'Mid-Boss Arena' and battleLogic(180,access,parameters): return True
        elif location.locName == 'Fifth Floor' and access.canDoubleJump(): return True
        elif location.locName == 'Sixth Floor' and access.canDoubleJump(): return True
        elif location.locName == 'Boss Arena' and battleLogic(200,access,parameters): 
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Carveros'): return True
            else: return False
        elif location.locName == 'Top Floor' and access.canDoubleJump() and access.canDefeat('Carveros'): return True
        else: return False
    elif location.locRegion == 'Nostalgia Cape' and (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.hasDina():
        if location.mapCheckID == 'Ed Join' and access.canMove(16): return True
        if location.mapCheckID != 'Ed Join': return True
        else: return False
    elif location.locRegion == 'East Coast Cave' and (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.hasDina(): 
        if location.mapCheckID != 'TBOX02' and battleLogic(100,access,parameters): return True
        elif location.mapCheckID == 'TBOX02': return True
    elif location.locRegion == 'Pirate Ship Eleftheria' and (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.hasDina() and access.readNote1() and battleLogic(100,access,parameters):
        if location.locName == 'Submerged Hold' and access.canUnderwater(): return True
        elif location.locName == 'Hold':
            if location == 'TBOX01' and access.canUnderwater(): return True
            elif location != 'TBOX01': return True
            else: return False
        elif location.locName == 'Accessway': return True
        elif location.locName == 'Crew Quarters': return True
        elif location.locName == 'Deck' and battleLogic(180,access,parameters): 
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Pirate Revenant'): return True
            else: return False
        elif location.locName == 'Stairwell': return True
        else: return False
    elif location.locRegion == 'Balado Monastery' and access.canDefeat('Giasburn'):
        if location.locName == 'Basement' and access.canSeeDark():
            if location.mapCheckID in ['TBOX01','TBOX02','TBOX03'] and access.canClimb() and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and (access.canDoubleJump() or access.canSwampWalk()) and access.canMove(22) and access.canUnderwater(): return True
            elif location.mapCheckID in ['TBOX04','TBOX05'] and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and (access.past2() or (access.past3() and access.hasDana())) and access.past5(): return True
            else: return False
        elif location.locName == 'Entrance' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and (access.past2() or (access.past3() and access.hasDana())) and access.past5():
            if location.mapCheckID in ['TBOX01','TBOX02','TBOX03'] and access.canSeeDark(): return True
            elif location.mapCheckID not in ['TBOX01','TBOX02','TBOX03']: return True
            else: return False
        else: return False
    elif location.locRegion == 'Archeozoic Chasm' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and (access.past2() or (access.past3() and access.hasDana())) and access.past5() and access.canDefeat('Giasburn'):
        if location.locName == 'Entrance': return True
        elif location.locName == 'Cliffs Overlooking Crater':
            if location.mapCheckID == 'TBOX02' and access.canMove(23): return True
            elif location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Whirlpools': return True
        elif location.locName == 'Mid-Boss Arena' and battleLogic(180,access,parameters): return True
        elif location.locName == 'Submerged Cave':
            if location.mapCheckID == 'TBOX01' and access.canDefeat('Coelacantos'): return True
            elif location.mapCheckID != 'TBOX01' and access.canUnderwater(): return True
            else: return False
        elif location.locName == 'Water Vents' and access.canUnderwater(): return True
        elif location.locName == 'Sunken Eternia Ruins West' and access.canUnderwater(): return True
        elif location.locName == 'Sunken Eternia Ruins East' and access.canUnderwater(): return True
        elif location.locName == 'Boss Arena' and access.canUnderwater() and battleLogic(240,access,parameters):
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Oceanus'): return True
            else: return False
        else: return False
    elif location.locRegion == 'Vista Ridge' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.canDefeat('Giasburn'): 
        if location.locName == 'Vista Ridge Upper' and access.canMove(21) and access.canDoubleJump(): return True
        if location.locName == 'Vista Ridge Lower' and access.canMove(14) and access.canSwampWalk() and access.hasDina() and access.hasAdol and access.canDefeat('Master Kong Hummel') and access.canSeeDark() and battleLogic(200,access,parameters): return True
    elif location.locRegion == 'Lodinia Marshland' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.canDefeat('Giasburn'):
        if location.locName == 'Entrance from Vista Ridge':
            if location.mapCheckID == 'TBOX01': return True
            elif location.mapCheckID == 'TBOX02' and (access.canDoubleJump() or access.canSwampWalk()): return True
            elif location.mapCheckID == 'TBOX03' and access.canDoubleJump(): return True
            else: return False
        elif location.locName == 'Near Submerged Cemetery' and access.past6() and (access.canDoubleJump() or access.canSwampWalk()):
            if location.mapCheckID == 'TBOX01' : return True
            elif location.mapCheckID == 'TBOX02' and (access.canSwampWalk() or access.canUnderwater()): return True
            else: return False
        elif location.locName == 'Muddy Lake' and access.canSwampWalk(): return True
        elif location.locName == 'Exit to Valley of Kings'  and (access.canSwampWalk() or (access.canDoubleJump() and access.canUnderwater())): 
            if location.mapCheckID == 'Fermented Sap' and access.canSwampWalk() and access.canDoubleJump(): return True
            elif location.mapCheckID != 'Fermented Sap': return True
            else: return False
        else: return False
    elif location.locRegion == 'Valley of Kings' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and access.canDefeat('Giasburn'):
        if location.locName == 'Valley of Kings - Camp' and access.hasDina(): return True
        elif location.locName == 'Entrance': return True
        elif location.locName == 'Northern Lower Level': return True
        elif location.locName == 'Mid-Boss Arena' and access.canUndead() and battleLogic(210,access,parameters): return True
        elif location.locName == 'Stairway (Statue Doors)' and access.canUndead(): return True
        elif location.locName == 'End' and access.canUndead():
            if location.mapCheckID in ['TBOX01','TBOX02'] and access.canDoubleJump(): return True
            elif location.mapCheckID in ['TBOX03','TBOX04']: return True
            else: return False
        elif location.locName == 'Boss Arena' and access.canUndead() and battleLogic(250,access,parameters):
            if location.mapCheckID != 'Psyches': return True
            elif location.mapCheckID == 'Psyches' and parameters.goal == 'Release the Psyches' and battleLogic(260,access,parameters) and access.canDefeat('Basileus'): return True
            else: return False
        elif location.locName == 'Seren Garden' and access.canUndead() and ((parameters.goal != 'Release the Psyches' and access.canDefeat('Psyche-Ura')) or (parameters.goal == 'Release the Psyches' and access.hasSkyPsyches())): return True
        else: return False
    elif location.locRegion == 'The Submerged Cemetery' and access.canSeeDark() and access.canClimb() and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and (access.canDoubleJump() or access.canSwampWalk()) and access.canMove(22) and access.canUnderwater() and battleLogic(165,access,parameters): return True
    elif location.locRegion == 'Solitude Island' and access.hasBoat(): return True
    elif location.locRegion == 'Eternal Hill'and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and access.past7() and access.canDefeat('Giasburn'): return True
    elif location.locRegion == 'Octus Overlook' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.canDefeat('Giasburn'):
        if location.locName in ['Path of the Frozen Era','Path of the Ocean Era','Path of the Sky Era'] and battleLogic(260,access,parameters): return True
        elif location.locName == 'Path of the Insectoid Era' and battleLogic(260,access,parameters): 
            if location.mapCheckID == 'TBOX02' and access.canDoubleJump(): return True
            elif location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Selection Sphere' and battleLogic(320,access,parameters):
            if parameters.goal == 'Find Crew' and access.canMove(parameters.numGoal): return True
            elif parameters.goal == 'Seiren Escape' and access.hasBoat() and access.hasMistilteinn() and access.hasChart(): return True
            elif parameters.goal == 'Release the Psyches' and access.hasAllPsyches(): return True
            else: return False
        else: return False
    else: return False

def canDiscover(access,requiredDiscoveries):
    discoveryCount = 1 #1 discovery in sphere 0 Cobalt Crag

    if access.canMove(6) or access.canClimb(): #Birdsong Rock
        discoveryCount+=1
    if access.canClimb(): #Rainbow falls and Metavolicalis
        discoveryCount+=2
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canSeeDark(): #Milky White Vein, Indigo Mineral Vein, Beached Remains
        discoveryCount+=3
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())): #Chimney Rock
        discoveryCount+=1
    if access.canMove(11) and access.canClimb(): #Zephyr Hill
        discoveryCount+=1
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.hasDina(): #Beehive
        discoveryCount+=1
    if (access.canDoubleJump() or access.canMove(8)) and access.hasDina() and access.canSwampWalk() and access.canClimb() and access.canDefeat('Magamandra'): #Field of Medicinal Herbs
        discoveryCount+=1
    if access.canMove(11) and access.canSwampWalk(): #Airs Cairn
        discoveryCount+=1
    if access.canMove(14) and access.canClimb(): #Parasequoia
        discoveryCount+=1
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.canDefeat('Giasburn'): #Prismatic Mineral Vein, Ancient Tree
        discoveryCount+=2
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and access.past4() and access.canDefeat('Giasburn'): #Breath Fountain
        discoveryCount+=1
    if access.canClimb() and access.past1() and access.hasFlameStones(3) and access.canDefeat('Giasburn'): #Unicalamites
        discoveryCount+=1
    if (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.hasDina(): #Ship Graveyard, Hidden Pirate's Storehouse
        discoveryCount+=2
    if access.canUnderwater() and access.canMove(11) and access.canClimb(): #Lapis Mineral Vein
        discoveryCount+=1
    if access.canClimb() and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and (access.canDoubleJump() or access.canSwampWalk()) and access.canMove(22) and access.canUnderwater() and access.canSeeDark() and access.canDefeat('Giasburn'): #Soundless Hall
        discoveryCount+=1
    if access.canClimb() and access.canDoubleJump() and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.canSwampWalk() and access.canDefeat('Giasburn'): #Sky Garden
        discoveryCount+=1
    if access.hasBoat(): #Magnacarpa
        discoveryCount+=1
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and access.past7() and access.canDefeat('Giasburn'): #Graves of Ancient Heroes
        discoveryCount+=1

    if discoveryCount >= requiredDiscoveries:
        return True
    return False

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
        elif access.hasFlameStones(7) and (access.canDoubleJump() and access.hasDina() and access.canMove(24) or (access.canSwampWalk() or (access.canDoubleJump() and access.canUnderwater()))) or (access.canUnderwater() and access.canMove(11) and access.canClimb()) or (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3()) or access.hasDana())) and access.canDefeat('Giasburn'):
            weaponStr = 270
        elif access.hasFlameStones(6) and ((access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.hasDina()) or (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and (((access.past2() and access.past3()) or access.hasDana()) or (access.past2() or (access.past3() and access.hasDana())))) and access.canDefeat('Giasburn'): 
            weaponStr = 240
        elif access.hasFlameStones(5) and ((access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.hasDina()) or (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and (((access.past2() and access.past3()) or access.hasDana()) or (access.past2() or (access.past3() and access.hasDana())))) and access.canDefeat('Giasburn'): 
            weaponStr = 210
        elif access.hasFlameStones(4) and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canDefeat('Giasburn'): 
            weaponStr = 180
        elif access.hasFlameStones(3): 
            weaponStr = 150
        elif access.hasFlameStones(2) and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())): 
            weaponStr = 100
        elif access.hasFlameStones(1) and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())): 
            weaponStr = 50
        
        if access.hasFlameStones(7) and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3() and access.past5()) or access.hasDana()) and access.canDefeat('Giasburn'): 
            armorStr = 25
        elif access.hasFlameStones(6) and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3() and access.past5()) or access.hasDana()) and access.canDefeat('Giasburn'): 
            armorStr = 20
        elif access.hasFlameStones(5) and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canDefeat('Giasburn'): 
            armorStr = 16
        elif access.hasFlameStones(4) and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canDefeat('Giasburn'): 
            armorStr = 13
        elif access.hasFlameStones(2) and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and (access.hasFlameStones(3) or access.hasDina()) and access.canDefeat('Giasburn'): 
            armorStr = 10
        elif access.hasFlameStones(1) and access.hasDina(): 
            armorStr = 5
        elif access.hasFlameStones(1) and (access.canMove(6) or access.canClimb() or access.hasDina()): 
            armorStr = 3

        #for armlet's and accesories we scan the world to see what's accessible from checks then compare that to what can be acquired from shop levels then take the highest number
        foundArmStr = access.armletStr()
        if access.hasFlameStones(7) and access.hasEuron() and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3() and access.past5()) or access.hasDana()) and access.canDefeat('Giasburn'): 
            armStr = 30
        elif access.hasFlameStones(6) and access.hasEuron() and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3() and access.past5()) or access.hasDana()) and access.canDefeat('Giasburn'): 
            armStr = 20
        elif access.hasFlameStones(4) and access.hasEuron() and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canDefeat('Giasburn'): 
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
            if access.canMove(6) or access.canClimb() or access.hasDina():
                hopeAndLum.append(20) #Hope Stone
        if access.hasEuron and access.hasFlameStones(2):
            if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump()))  and access.hasDina():
                fenrirAcc.append(5) #Fenrir Talisman
                bladeRings.append(20) #Blade Ring 2
            if ((access.canFish() and access.hasPearls(7)) or (access.hasDina)) and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
                hopeAndLum.append(40) #luminous ring
            if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasDina():
                pyriosAcc.append(5) #Pyrios Talisman
        if access.hasEuron and access.hasFlameStones(4):
            if (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.past3() and access.hasDana()) or ( access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasDina()) and access.canDefeat('Giasburn'):
                bladeRings.append(30) #Blade Ring 3
                otherAcc.append(10) #lightning stone
            if (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana())) or (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasDina()) and access.canDefeat('Giasburn'):
                otherAcc.append(10) #crow stone
            if (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(3) and ((access.past2() and access.past3()) or access.hasDana())) or (access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.hasFlameStones(5) and access.hasDina()) and access.canDefeat('Giasburn'):
                otherAcc.append(10) #snake stone
        if access.hasEuron and access.hasFlameStones(5):
            if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
                dragonAcc.append(10) #dragon pauldron
            if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3()) or access.hasDana()) and (access.past2() or (access.past3() and access.hasDana())) and access.past5() and access.hasDina() and access.canDefeat('Giasburn'):
                fenrirAcc.append(15) #fenrir stone
                pyriosAcc.append(15) #pyrios stone
                dragonAcc.append(20) #dragon stone
                otherAcc.append(10) #nature talisman
        if access.hasEuron and access.hasFlameStones(7):
            if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and ((access.past2() and access.past3()) or access.hasDana()) and access.past6() and access.canDefeat('Giasburn'):
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

        if (weaponStr + armorStr + armStr + accStr) >= requiredStr:
            return True
        else: return False

    else: return True #if battle logic isn't on then we skip everything and return true for access logic




        

    

    
        

    
            
    
    
