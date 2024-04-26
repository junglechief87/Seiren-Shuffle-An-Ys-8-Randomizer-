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
            if (location.mapCheckID == 'Stage 2' or location.mapCheckID == 'Stage 3' or location.mapCheckID == 'Stage 5') and access.memoCheck(1): return True
            elif location.mapCheckID == 'Stage 7' and access.memoCheck(1) and access.canAncient() and access.canSmith(): return True
            elif location.mapCheckID == 'Stage 9' and access.memoCheck(3) and access.canAncient() and access.canSmith(): return True
            else: return False
        elif location.locName == 'Jewel Trade' and access.canInsect():
            if location.mapCheckID == 'Item 5' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and access.canSeeDark() and access.canFish(): return True
            elif location.mapCheckID != 'Item 5' and access.hasJewels(23): return True
            else: return False
        elif location.locName == 'Map Completion':
            if location.mapCheckID == 'Percent 10' and (access.canClimb() or access.canMove(6)) and access.canShowMap(): return True
            elif location.mapCheckID == 'Percent 20' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.canShowMap(): return True
            elif location.mapCheckID == 'Percent 30' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.canShowMap() and access.canSwampWalk(): return True
            elif location.mapCheckID == 'Percent 40' and (access.canClimb() or access.canMove(6)) and (access.canMove(8) or access.canDoubleJump()) and access.canShowMap() and access.canSwampWalk() and (access.canInsect() or (access.past1() and access.canAncient() and access.canSmith())): return True
            elif location.mapCheckID == 'Percent 50' and access.canClimb() and (access.canDoubleJump() or (access.canMove(16) and access.canSwampWalk())) and access.canShowMap() and ((access.canInsect() and access.canDoubleJump() and access.readNote1()) or (access.past1() and access.canAncient() and access.canSmith())): return True
            elif location.mapCheckID == 'Percent 60' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(16) and access.canSwampWalk() and access.canShowMap() and ((access.canInsect() and access.readNote1) or (access.past1() and access.canAncient() and access.canSmith() and access.past2() and access.past3 and access.Dana())): return True
            elif location.mapCheckID == 'Percent 70' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(16) and access.canSwampWalk() and access.canShowMap() and access.canInsect() and access.readNote1 and access.past1() and access.canAncient() and access.canSmith() and access.past2() and access.past3() and ((access.dana() and  access.past4()) or (access.past5() and access.canUnderwater())): return True
            elif location.mapCheckID == 'Percent 80' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(20) and access.canSwampWalk() and access.canShowMap() and access.canInsect() and access.readNote1 and access.past1() and access.canAncient() and access.canSmith() and access.past2() and access.past3() and access.dana() and access.past4() and access.past5() and access.canUnderwater() and access.canSeeDark(): return True
            elif location.mapCheckID == 'Percent 90' and access.mapIncrease() and access.canClimb() and access.canDoubleJump() and access.canMove(24) and access.canSwampWalk() and access.canShowMap() and access.canInsect() and access.readNote1 and access.past1() and access.canAncient() and access.canSmith() and access.past2() and access.past3() and access.dana() and access.past4() and access.past5() and access.canUnderwater() and access.past6() and access.canUndead() and access.canSeeDark(): return True
            elif location.mapCheckID == 'Percent 100': return False
            else: return False
        elif location.locName == 'Discovery Rewards':
            if location.mapCheckID == 'Half' and canDiscover(access,12) and access.canShowDiscoveries(): return True
            elif location.mapCheckID == 'All' and canDiscover(access,24) and access.canShowDiscoveries(): return False
            else: return False
        elif location.locName == 'Fish Trade' and access.canFish(): return True
        elif location.locName == 'Ricotta and Shoebill Reunite' and access.ricotta(): return True
        elif location.locName not in ['Fish Trade','Map Completion','Jewel Trade','Intercept','Discovery Rewards','Ricotta Bonus']: return True
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
        if location.locName == 'Walkways':
            if (location.mapCheckID == 'TBOX03' or location.mapCheckID == 'TBOX06') and (access.canClimb() or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX04' or location.mapCheckID == 'TBOX05': return True
            else: return False
        elif location.locName == 'Entrance': return True
        elif location.locName == 'Midpoint': return True
        elif (location.locName == 'Rainbow Falls' or location.locName == 'End') and access.canClimb(): return True
        elif location.locName == 'After Mid-Boss':
            if location.mapCheckID == 'Corpse': return True
            elif location.mapCheckID != 'Corpse' and access.canClimb(): return True
            else: return False
    elif location.locRegion == 'Roaring Seashore' and access.canClimb():
        if location.locName == 'Metavolicalis': return True
        elif location.locName == 'Parasequoia' and access.canMove(14): return True
        else: return False
    elif location.locRegion == 'Great River Valley' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        if location.locName == 'Cliffs':
            if location.mapCheckID == 'TBOX01' and access.canSwampWalk(): return True
            elif location.mapCheckID == 'TBOX02': return True
            else: return False
        elif location.locName == 'Falls':
            if (location.mapCheckID == 'TBOX01' or location.mapCheckID == 'TBOX02') and access.canSwampWalk(): return True
            elif location.mapCheckID != 'TBOX01' or location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Lookout Tower' and access.canInsect(): return True
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
        elif location.locName == 'Collapsed Cliff' and access.canInsect():
            if location.mapCheckID == 'TBOX03' and access.canMove(15): return True
            elif location.mapCheckID != 'TBOX03': return True
            else: return False
        else: return False
    elif location.locRegion == 'Eroded Valley' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        if (location.locName == 'Dark Passage' or location.locName == 'End') and access.canSeeDark(): return True
        elif location.locName == 'Webbed Walkways':
            if location.mapCheckID == 'TBOX03' and access.canSeeDark(): return True
            elif location.mapCheckID != 'TBOX03': return True
        elif location.locName not in ['Dark Passage','Webbed Walkways','End']: return True
        else: return False
    elif location.locRegion == 'Sunrise Beach' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())): return True
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
        elif location.mapCheckID != 'TBOX01' and access.canInsect(): return True
        else: return False
    elif location.locRegion == 'Underground Water Vein' and access.canUnderwater() and access.canMove(11) and access.canClimb(): return True
    elif location.locRegion == 'Longhorn Coast' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canInsect():
        if location.locName == 'Reja Shore':
            if (location.mapCheckID == 'TBOX01' or location.mapCheckID == 'TBOX03') and access.canInsect(): return True
            elif location.mapCheckID == 'Reja Join' or location.mapCheckID == 'Pirate Treasure': return True
            else: return False
        elif location.locName == 'Eastern Shore': return True
        else: return False
    elif location.locRegion == 'Schlamm Jungle' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canInsect():
        if location.locName == 'Entrance':
            if location.mapCheckID == 'TBOX03' and (access.canSwampWalk() or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX02' and access.canClimb(): return True
            elif location.mapCheckID == 'TBOX01': return True
            elif location.mapCheckID == 'Euron Join': return True
            else: return False
        elif location.locName == 'North of Entrance' and access.canClimb(): return True
        elif location.locName == 'Midpoint' and (access.canSwampWalk() or access.canDoubleJump()): return True
        elif location.locName == 'Mid-Boss Arena': return True
        elif location.locName == 'Small Passage':
            if location.mapCheckID == 'TBOX02' and (access.canSwampWalk() or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX01' and ((access.canSwampWalk() and access.canClimb) or (access.canDoubleJump() and access.canClimb)): return True
            else: return False
        elif location.locName == 'Muddy Passage' and (access.canSwampWalk() or access.canDoubleJump()):
            if location.mapCheckID == 'TBOX02' and ((access.canSwampWalk() and access.canClimb()) or access.canDoubleJump()): return True
            elif location.mapCheckID == 'TBOX01' and access.canSwampWalk() and  access.canClimb(): return True
            else: return False
        elif location.locName == 'End' and access.canSwampWalk(): return True
        else: return False
    elif location.locRegion == 'Odd Rock Coast' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canInsect() and access.canSwampWalk(): return True
    elif location.locRegion == 'The Primordial Passage' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1(): return True
    elif location.locRegion == 'Mont Gendarme' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1(): 
        if location.locName == 'Mishy Rewards':
            if location.mapCheckID == 'Food 2' and access.canCook(1): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(2): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(3): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(4): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(5): return True
            elif location.mapCheckID == 'Food 4' and access.canCook(6): return True
            else: return False
        elif location.locName != 'Mishy Rewards': return True
        else: return False
    elif location.locRegion == 'Western Foot of Gendarme' and access.canMove(11) and access.canSwampWalk(): return True
    elif location.locRegion == 'Cavern of the Ancient King' and access.canMove(11) and access.canSwampWalk(): return True
    elif location.locRegion == 'Mountain Pinnacle Trail' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith(): return True
    elif location.locRegion == 'Titis Primeval Forest' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith():
        if location.locName == 'Near Primordial Den':
            if location.mapCheckID == 'TBOX01' and access.past2(): return True
            elif location.mapCheckID != 'TBOX01': return True
            else: return False
        elif location.locName != 'Near Primordial Den': return True
        else: return False
    elif location.locRegion == 'Pangaia Plains' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith(): return True
    elif location.locRegion == 'The Ruins of Eternia' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and (access.past2() or (access.past3() and access.dana())):
        if location.locName == 'Eastern Entrance' and access.past3(): return True
        elif location.locName == 'Central District' and access.canInsect(): return True
        elif location.locName == 'Residence':
            if location.mapCheckID == 'TBOX02' and access.past6(): return True
            elif location.mapCheckID == 'TBOX01': return True
            else: return False
        elif location.locName == 'Palace Ruins': return True
        else: return False
    elif location.locRegion == 'Temple of the Great Tree' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()): return True
    elif location.locRegion == 'Mont Gendarme (Night)'and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canSeeDark(): return True
    elif location.locRegion == 'Pangaia Plains (Night)' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and access.canSeeDark(): return True
    elif location.locRegion == 'Water and Wood Hills' and (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canInsect():
        if location.locName == 'Near Silent Tower' and access.canClimb() and access.canDoubleJump(): return True
        elif location.locName == 'Foggy Forest': return True
        elif location.locName == 'Water and Wood Hills - Camp' and access.canMove(12): return True
        else: return False
    elif location.locRegion == 'Silent Tower' and access.canDoubleJump() and access.canInsect() and access.canMove(24): return True
    elif location.locRegion == 'Stone Pillar Wind Cave' and access.canClimb() and access.past1() and access.canAncient() and access.canSmith() and access.canMove(18):
        if location.mapCheckID == 'TBOX04' and access.canDoubleJump(): return True
        elif location.mapCheckID != 'TBOX04': return True
        else: return False
    elif location.locRegion == 'Towal Highway' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and access.past3() and access.dana(): return True
    elif location.locRegion == 'Baja Tower' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and access.past3() and access.dana() and access.past4():
        if location.locName == 'Second Floor': return True
        elif location.locName == 'Third Floor':
            if location.mapCheckID == 'TBOX03' and access.canDoubleJump(): return True
            elif location.mapCheckID != 'TBOX03': return True
            else: return False
        elif location.locName == 'Mid-Boss Arena': return True
        elif location.locName == 'Fifth Floor' and access.canDoubleJump(): return True
        elif location.locName == 'Sixth Floor' and access.canDoubleJump(): return True
        elif location.locName == 'Top Floor' and access.canDoubleJump(): return True
        else: return False
    elif location.locRegion == 'Nostalgia Cape' and (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.canInsect():
        if location.mapCheckID == 'Ed Join' and access.canMove(16): return True
        if location.mapCheckID != 'Ed Join': return True
        else: return False
    elif location.locRegion == 'East Coast Cave' and (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.canInsect(): return True
    elif location.locRegion == 'Pirate Ship Eleftheria' and (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.canInsect() and access.readNote1():
        if location.locName == 'Submerged Hold' and access.canUnderwater(): return True
        elif location.locName == 'Hold':
            if location == 'TBOX01' and access.canUnderwater(): return True
            elif location != 'TBOX01': return True
            else: return False
        elif location.locName == 'Accessway': return True
        elif location.locName == 'Crew Quarters': return True
        elif location.locName == 'Deck': return True
        elif location.locName == 'Stairwell': return True
        else: return True
    elif location.locRegion == 'Balado Monastery':
        if location.locName == 'Basement' and access.canSeeDark():
            if (location.mapCheckID == 'TBOX01' or location.mapCheckID == 'TBOX02' or location.mapCheckID == 'TBOX03') and access.canClimb() and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6() and (access.canDoubleJump() or access.canSwampWalk()) and access.canMove(22) and access.canUnderwater(): return True
            elif (location.mapCheckID == 'TBOX04' or location.mapCheckID == 'TBOX05') and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and (access.past2() or (access.past3() and access.dana())) and access.past5(): return True
            else: return False
        elif location.locName == 'Entrance' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and (access.past2() or (access.past3() and access.dana())) and access.past5():
            if (location.mapCheckID == 'TBOX01' or location.mapCheckID == 'TBOX02' or location.mapCheckID == 'TBOX03') and access.canSeeDark(): return True
            elif location.mapCheckID not in ['TBOX01','TBOX02','TBOX03']: return True
            else: return False
        else: return False
    elif location.locRegion == 'Archeozoic Chasm' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and (access.past2() or (access.past3() and access.dana())) and access.past5():
        if location.locName == 'Entrance': return True
        elif location.locName == 'Cliffs Overlooking Crater':
            if location.mapCheckID == 'TBOX02' and access.canMove(23): return True
            elif location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Whirlpools': return True
        elif location.locName == 'Submerged Cave':
            if location.mapCheckID == 'TBOX01': return True
            elif location.mapCheckID != 'TBOX01' and access.canUnderwater(): return True
            else: return False
        elif location.locName == 'Water Vents' and access.canUnderwater(): return True
        elif location.locName == 'Sunken Eternia Ruins West' and access.canUnderwater(): return True
        elif location.locName == 'Sunken Eternia Ruins East' and access.canUnderwater(): return True
        elif location.locName == 'Boss Arena' and access.canUnderwater(): return True
        else: return False
    elif location.locRegion == 'Vista Ridge' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()): 
        if location.locName == 'Vista Ridge Upper' and access.canMove(21) and access.canDoubleJump(): return True
        if location.locName == 'Vista Ridge Lower' and access.canMove(14) and access.canSwampWalk() and access.canInsect() and access.fullParty() and access.canSeeDark(): return True
    elif location.locRegion == 'Lodinia Marshland' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()):
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
    elif location.locRegion == 'Valley of Kings' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6():
        if location.locName == 'Valley of Kings - Camp' and access.canInsect(): return True
        elif location.locName == 'Entrance': return True
        elif location.locName == 'Northern Lower Level': return True
        elif location.locName == 'Mid-Boss Arena' and access.canUndead(): return True
        elif location.locName == 'Stairway (Statue Doors)' and access.canUndead(): return True
        elif location.locName == 'End' and access.canUndead():
            if (location.mapCheckID == 'TBOX01' or location.mapCheckID == 'TBOX02') and access.canDoubleJump(): return True
            elif location.mapCheckID == 'TBOX03' or location.mapCheckID == 'TBOX04': return True
            else: return False
        elif location.locName == 'Boss Arena' and access.canUndead(): return True
        elif location.locName == 'Seren Garden' and access.canUndead(): return True
        else: return False
    elif location.locRegion == 'The Submerged Cemetery' and access.canSeeDark() and access.canClimb() and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6() and (access.canDoubleJump() or access.canSwampWalk()) and access.canMove(22) and access.canUnderwater(): return True
    elif location.locRegion == 'Solitude Island' and access.hasBoat(): return True
    elif location.locRegion == 'Eternal Hill'and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6() and access.past7(): return True
    elif location.locRegion == 'Octus Overlook' and access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()):
        if (location.locName == 'Path of the Frozen Era' or location.locName == 'Path of the Ocean Era' or location.locName == 'Path of the Sky Era'): return True
        elif location.locName == 'Path of the Insectoid Era': 
            if location.mapCheckID == 'TBOX02' and access.canDoubleJump(): return True
            elif location.mapCheckID != 'TBOX02': return True
            else: return False
        elif location.locName == 'Selection Sphere':
            if parameters.goal == 'Find Crew' and access.canMove(parameters.numGoal): return True
            elif parameters.goal == 'Seiren Escape' and access.hasBoat() and access.hasMistilteinn() and access.hasChart(): return True
        else: return False
    else: return False

def canDiscover(access,requiredDiscoveries):
    discoveryCount = 1 #1 discovery in sphere 0

    if access.canMove(6) or access.canClimb():
        discoveryCount+=1
    if access.canClimb():
        discoveryCount+=2
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canSeeDark():
        discoveryCount+=1
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())):
        discoveryCount+=3
    if access.canMove(11) and access.canClimb():
        discoveryCount+=1
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canInsect():
        discoveryCount+=1
    if (access.canMove(8) or ((access.canMove(6) or access.canClimb()) and access.canDoubleJump())) and access.canInsect() and (access.canDoubleJump() or access.canSwampWalk()):
        discoveryCount+=1
    if access.canMove(11) and access.canSwampWalk(): 
        discoveryCount+=1
    if access.canMove(14) and access.canClimb():
        discoveryCount+=1
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith():
        discoveryCount+=2
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and access.past4():
        discoveryCount+=1
    if access.canClimb() and access.canDoubleJump() and access.past1() and access.canAncient() and access.canSmith():
        discoveryCount+=1
    if (access.canMove(6) or access.canClimb()) and access.canDoubleJump() and access.canInsect():
        discoveryCount+=2
    if access.canUnderwater() and access.canMove(11) and access.canClimb():
        discoveryCount+=1
    if access.canClimb() and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6() and (access.canDoubleJump() or access.canSwampWalk()) and access.canMove(22) and access.canUnderwater():
        discoveryCount+=1
    if access.canClimb() and access.canDoubleJump() and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.canSwampWalk():
        discoveryCount+=1
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6() and access.canUndead():
        discoveryCount+=1
    if access.canClimb() and (access.canMove(8) or access.canDoubleJump()) and access.past1() and access.canAncient() and access.canSmith() and ((access.past2() and access.past3()) or access.dana()) and access.past6() and access.past7():
        discoveryCount+=1

    if discoveryCount >= requiredDiscoveries:
        return True
    return False

    
    

    
        

    
            
    
    
