import random
import os
import sys
from collections import defaultdict
import csv

# Bulletin board character portraits
PORTRAITS = [
    "DRCHA_ADOL",               # アドル（手帳には載らない）
    "DRCHA_LAXIA",              # ラクシャ
    "DRCHA_SAHAD",              # サハド
    "DRCHA_HUMMEL",             # ヒュンメル
    "DRCHA_RICOTTA",            # リコッタ
    "DRCHA_DANA",               # ダーナ★１（非仲間）
    # 漂流者
    "DRCHA_DOGI",               # ドギ
    "DRCHA_BARBAROSS",          # バルバロス船長★１（生存）
    "DRCHA_ALISON",             # アリスン
    "DRCHA_ED",                 # エド
    "DRCHA_BABY",               # アリスンの子供★ホープ（色違い）
    "DRCHA_CURRAN",             # カーラン卿★１（生存）
    "DRCHA_KIERGAARD",          # キルゴール★１（生存）
    "DRCHA_KATRIN",             # カトリーン
    "DRCHA_NIA",                # シスター・ニア
    "DRCHA_DINA",               # ディナ
    "DRCHA_AARON",              # エアラン
    "DRCHA_REJA",               # レーヤ
    "DRCHA_MIRALDA",            # ミラルダ
    "DRCHA_LICHT",              # リヒト
    "DRCHA_KUINA",              # クイナ
    "DRCHA_AUSTEN",             # オースティン
    "DRCHA_SILVIA",             # シルヴィア
    "DRCHA_THANATOS",           # タナトス
    "DRCHA_KASHU",              # カシュー
    "DRCHA_FRANZ",              # フランツ
    "DRCHA_GRISELDA",           # グリゼルダ
    # その他
    "DRCHA_PARO",               # リトル・パロ
    "DRCHA_BALAENICEPS_REX",    # ハシビロコウ
    "DRCHA_SKILLMONKY",         # マスターコング★１（非協力）
    "DRCHA_OLGA",               # オルガ
    "DRCHA_SARAI",              # サライ
    "DRCHA_RASTELL",            # ラステル
    "DRCHA_IO",                 # イオ
    "DRCHA_HUDDLA",             # ヒドゥラ
    "DRCHA_MINOS",              # ミノス
    "DRCHA_NESTOLE",            # ネストール
    "DRCHA_URRA",               # ウーラ★１（フードあり）
    "DRCHA_MAIA",               # 大地神マイア
    # 派生
    "DRCHA_KIERGAARD2",         # キルゴール★２（死亡）
    "DRCHA_BARBAROSS2",         # バルバロス船長★２（死亡）
    "DRCHA_CURRAN2",            # カーラン卿★２（死亡）
    "DRCHA_CURRAN3",            # カーラン卿★３（復活）
    "DRCHA_DANA2",              # ダーナ★２（仲間）
    "DRCHA_BABY2",              # アリスンの子供★ルーク（色違い）
    "DRCHA_BABY3",              # アリスンの子供★ウィル（色違い）
    "DRCHA_AUSTEN2",            # オースティン★２（改心）
    "DRCHA_SKILLMONKY2",        # マスターコング★２（協力）
    "DRCHA_URRA2",              # ウーラ★２（フード無し）
]

SKILLS = {
    "SKILL_ADOL_SP_C1": "Sonic Slide",
    "SKILL_ADOL_SP_C2": "Arc Shot",
    "SKILL_ADOL_SP_C3": "Rising Slash",
    "SKILL_ADOL_SP_C4": "Sword Impact",
    "SKILL_ADOL_SP_B1": "Force Edge",
    "SKILL_ADOL_SP_B2": "Aerial Spin",
    "SKILL_ADOL_SP_B3": "Sky Drive",
    "SKILL_ADOL_SP_B4": "Tornado Sword",
    "SKILL_ADOL_SP_B5": "Aura Blade",
    "SKILL_ADOL_SP_A1": "Blade Rush",
    "SKILL_ADOL_SP_A2": "Thrust Storm",
    "SKILL_ADOL_SP_A3": "Brave Charge",
    "SKILL_SAHAD_SP_C1": "High Wave",
    "SKILL_SAHAD_SP_C2": "Grand Anchor",
    "SKILL_SAHAD_SP_C3": "Wild Appeal",
    "SKILL_SAHAD_SP_C4": "Gale Blow",
    "SKILL_SAHAD_SP_B1": "Vortex",
    "SKILL_SAHAD_SP_B2": "Great Ram",
    "SKILL_SAHAD_SP_B3": "Power Strike",
    "SKILL_SAHAD_SP_B4": "Seine Toss",
    "SKILL_SAHAD_SP_B5": "Upper Break",
    "SKILL_SAHAD_SP_A1": "Magna Wave",
    "SKILL_SAHAD_SP_A2": "Raging Deluge",
    "SKILL_SAHAD_SP_A3": "Spiral Anchor",
    "SKILL_LAXIA_SP_C1": "Dagger Fling",
    "SKILL_LAXIA_SP_C2": "Wake Up!",
    "SKILL_LAXIA_SP_C3": "Rapid Thrust",
    "SKILL_LAXIA_SP_C4": "Needle Break",
    "SKILL_LAXIA_SP_B1": "Stun Thrust",
    "SKILL_LAXIA_SP_B2": "Blitz Charge",
    "SKILL_LAXIA_SP_B3": "Sylphid's Kiss",
    "SKILL_LAXIA_SP_B4": "Spark Chaser",
    "SKILL_LAXIA_SP_B5": "Eagle Lancer",
    "SKILL_LAXIA_SP_A1": "Piercing Tempest",
    "SKILL_LAXIA_SP_A2": "Precious Impact",
    "SKILL_LAXIA_SP_A3": "Lethal Raid",
    "SKILL_HUMMEL_SP_C1": "Burst Shot",
    "SKILL_HUMMEL_SP_C2": "Venomous Bullet",
    "SKILL_HUMMEL_SP_C3": "Somersault",
    "SKILL_HUMMEL_SP_C4": "Quaker",
    "SKILL_HUMMEL_SP_B1": "Guilty Raid",
    "SKILL_HUMMEL_SP_B2": "Triple Bomber",
    "SKILL_HUMMEL_SP_B3": "Judgment",
    "SKILL_HUMMEL_SP_B4": "Counter Trick",
    "SKILL_HUMMEL_SP_B5": "Assault Rain",
    "SKILL_HUMMEL_SP_A1": "Hasty Valor",
    "SKILL_HUMMEL_SP_A2": "Prominence Shot",
    "SKILL_HUMMEL_SP_A3": "Firecracker",
    "SKILL_RICOTTA_SP_C1": "Wild Spin",
    "SKILL_RICOTTA_SP_C2": "Handmade Trap",
    "SKILL_RICOTTA_SP_C3": "Screw Fang",
    "SKILL_RICOTTA_SP_C4": "Bandit Tackle",
    "SKILL_RICOTTA_SP_B1": "Flame Swing",
    "SKILL_RICOTTA_SP_B2": "Mighty Orbit",
    "SKILL_RICOTTA_SP_B3": "Rumble Thorn",
    "SKILL_RICOTTA_SP_B4": "Beast Attack",
    "SKILL_RICOTTA_SP_B5": "Green Whip",
    "SKILL_RICOTTA_SP_A1": "Triple Bang",
    "SKILL_RICOTTA_SP_A2": "Spiral Drive",
    "SKILL_RICOTTA_SP_A3": "Dino Throw",
    "SKILL_DANA_SP_C1": "Twin Edge",
    "SKILL_DANA_SP_C2": "Sonic Rise",
    "SKILL_DANA_SP_C3": "Elemental Shot",
    "SKILL_DANA_SP_C4": "Dragon Spirit",
    "SKILL_DANA_SP_B1": "Earth Dragon",
    "SKILL_DANA_SP_B2": "Twin Moon Blade",
    "SKILL_DANA_SP_B3": "Boomerang Edge",
    "SKILL_DANA_SP_B4": "Dragon Wave",
    "SKILL_DANA_SP_B5": "Mistral Edge",
    "SKILL_DANA_SP_A1": "Ice Age",
    "SKILL_DANA_SP_A2": "Spiel Round Dance",
    "SKILL_DANA_SP_A3": "Water Burst",
}

class Hint:
    def __init__(self, itemName, quantity, charPortrait, locRegion, locName = '', mapCheckID = '', isFoolish = False, isRequired = False, displayFullLoc = False):
        self.itemName = itemName
        self.quantity = quantity
        self.isFoolish = isFoolish
        self.isRequired = isRequired #we will define this in spoiler log generation
        self.charPortrait = charPortrait
        self.locRegion = locRegion
        self.locName = locName
        self.mapCheckID = mapCheckID
        self.displayFullLoc = displayFullLoc

#This function will create and return a list of all hints that will be displayed ingame
def createHints(shuffledLocations, parameters):
    random.seed(parameters.seed)
    regionHasProgression = findBarrenRegions(shuffledLocations, parameters)
    barrenLocs = []
    castawayLocs = []
    alreadyPickedKathleen = 0 #just a flag so select only 1 flame stone
    randomLocs = [] #I will be giving full location for random checks
    usefulAdventuringGearLocs = []
    nonRegions = ["Starting Skill", "Lombardia"]# We will also remove some awkward ones like "Adol Starting Skill" as these aren't really checks
    nonItems = ["Defeated", "End the Lacrimosa"]# Removing the "Boss defeated" item
    seenBarrenRegions = set()

    for location in shuffledLocations:
        if any(nonRegion in location.locRegion for nonRegion in nonRegions) or any(nonItem in location.itemName for nonItem in nonItems):
            continue  # Skip to the next iteration
        hint = Hint(
                    itemName=location.itemName,
                    quantity=location.quantity,
                    charPortrait=random.choice(list(PORTRAITS)),
                    locRegion=location.locRegion,
                    locName=location.locName,
                    mapCheckID=location.mapCheckID,
                )
        if regionHasProgression[location.locRegion] == True: #has progression
            if location.itemName in ["Grip Gloves", "Glow Stone", "Archeopteryx Wings", "Gale Feather", "Hermit's Scale", "Purifying bell", "Float Shoes"]:
                usefulAdventuringGearLocs.append(hint)
            elif location.crew:
                if location.itemID == 778 and alreadyPickedKathleen:
                    hint.locName = location.locName
                    hint.mapCheckID = location.mapCheckID
                    hint.displayFullLoc = True
                    randomLocs.append(hint)
                else:
                    if location.itemID == 778:
                        hint.itemName == "Kathleen"
                    castawayLocs.append(hint)
                    alreadyPickedKathleen = 1
            else:
                hint.locName = location.locName
                hint.mapCheckID = location.mapCheckID
                hint.displayFullLoc = True
                randomLocs.append(hint)
        else: #region is barren
            if hint.locRegion not in seenBarrenRegions:
                hint.isFoolish = True
                barrenLocs.append(hint)
                seenBarrenRegions.add(hint.locRegion)


    #Now we shuffle the lists, and pick the ones we want, merge them in the same list and return
    random.shuffle(castawayLocs)
    random.shuffle(usefulAdventuringGearLocs)
    random.shuffle(randomLocs) #unused for now
    random.shuffle(barrenLocs)

    #Here it is probably a good idea to set these quantities in the randomizer user interface for customizeable hints
    numberOfAdventureGearLocs = min(len(usefulAdventuringGearLocs), int(parameters.adventuringGearHints))
    numberOfRandomLocs = min(len(randomLocs), 3) #unused for now
    numberOfCastawayLocs = min(len(castawayLocs), int(parameters.castawayHints))
    numberOfBarrenLocs = min(len(barrenLocs), int(parameters.foolishHints))

    selected_useful_adventure_gear = usefulAdventuringGearLocs[:numberOfAdventureGearLocs]
    selected_random_locs = randomLocs[:numberOfRandomLocs]
    selected_castaways = castawayLocs[:numberOfCastawayLocs]
    selected_barren_locs = barrenLocs[:numberOfBarrenLocs]

    hints = (
    selected_useful_adventure_gear
    + selected_castaways
    + selected_barren_locs
    )

    ''' removing the random_locs from the hints as from testing these seem useless majority of the time. There should be better ways of implementing additional hints
    hints = (
    selected_useful_adventure_gear
    + selected_random_locs
    + selected_castaways
    + selected_barren_locs
    )
    '''

    '''
    for i, hint in enumerate(hints, start=1):
        if "SKILL_" in hint.itemName:
            hint.itemName = SKILLS[hint.itemName]
        print(f"Hint {i}:")
        print(f"  Item Name: {hint.itemName}")
        print(f"  Quantity: {hint.quantity}")
        print(f"  Is Foolish: {hint.isFoolish}")
        print(f"  Is Required: {hint.isRequired}")
        print(f"  Character Portrait: {hint.charPortrait}")
        print(f"  Location Region: {hint.locRegion}")
        print(f"  Location Name: {hint.locName}")
        print(f"  Map Check ID: {hint.mapCheckID}")
        print("-" * 30)
    '''
    return hints #list of Hint of all hints to be displayed

def determine_progression(shuffledLocations, parameters):
    """
    This function will determine whether some progression items that lock multiple checks are indeed progression or not.
    if Mishy Rewards is barren then all recipes are junk
    if Jewel Trade is barren then all prismatic jewel are junk
    if Fish Trade is barren then fishing rod is junk
    """
    # Initial assumptions: both are progression
    is_jewel_progression = False
    is_recipe_progression = False
    is_fish_progression = False
    is_essence_key_progression = False

    # Progression items for tracking
    jewel_trade_rewards = []
    mishy_rewards = []
    fish_rewards = []
    essence_key_rewards = []
    for location in shuffledLocations:
        if location.locName == "Mishy Rewards":
            mishy_rewards.append(location)
        elif location.locName == "Jewel Trade":
            jewel_trade_rewards.append(location)
        elif location.locName == "Fish Trade":
            fish_rewards.append(location)
        elif parameters.formerSanctuaryCrypt and "Former Sanctuary Crypt" in location.locRegion:
        # Exclude the only 3 checks that don't require any essence key stone
            if not (
            location.locRegion == "Former Sanctuary Crypt - B1" and
            location.locName == "Entrance" and
            location.mapCheckID in {"TBOX01", "TBOX02", "TBOX03"}
            ):
                essence_key_rewards.append(location)

    while True:
        # Previous states for comparison
        prev_jewel_progression = is_jewel_progression
        prev_recipe_progression = is_recipe_progression
        prev_fish_progression = is_fish_progression
        prev_essence_key_progression = is_essence_key_progression

        # Determine if Jewel Trade rewards progression
        for location in jewel_trade_rewards:
            if is_jewel_progression or (location.progression and location.itemName != "Prismatic Jewel" and "Recipe Book" not in location.itemName and location.itemName != "Fishing Rod" and location.itemName != "Essence Key Stone"):
                is_jewel_progression = True
            elif "Recipe Book" in location.itemName and is_recipe_progression:
                is_jewel_progression = True
            elif location.itemName == "Fishing Rod" and is_fish_progression:
                is_jewel_progression = True
            elif location.itemName == "Essence Key Stone" and is_essence_key_progression:
                is_jewel_progression = True


        # Determine if Mishy Rewards rewards progression
        for location in mishy_rewards:
            if is_recipe_progression or (location.progression and location.itemName != "Prismatic Jewel" and "Recipe Book" not in location.itemName and location.itemName != "Fishing Rod" and location.itemName != "Essence Key Stone"):
                is_recipe_progression = True
            elif location.itemName == "Prismatic Jewel" and is_jewel_progression:
                is_recipe_progression = True
            elif location.itemName == "Fishing Rod" and is_fish_progression:
                is_recipe_progression = True
            elif location.itemName == "Essence Key Stone" and is_essence_key_progression:
                is_recipe_progression = True

        
        # Determine if fish rewards progression
        for location in fish_rewards:
            if is_fish_progression or (location.progression and location.itemName != "Prismatic Jewel" and "Recipe Book" not in location.itemName and location.itemName != "Fishing Rod" and location.itemName != "Essence Key Stone"):
                is_fish_progression = True
            elif location.itemName == "Prismatic Jewel" and is_jewel_progression:
                is_fish_progression = True
            elif "Recipe Book" in location.itemName and is_recipe_progression:
                is_jewel_progression = True
            elif location.itemName == "Essence Key Stone" and is_essence_key_progression:
                is_jewel_progression = True
        
        for location in essence_key_rewards:
            if is_essence_key_progression or (location.progression and location.itemName != "Prismatic Jewel" and "Recipe Book" not in location.itemName and location.itemName != "Fishing Rod" and location.itemName != "Essence Key Stone"):
                is_essence_key_progression = True
            elif location.itemName == "Prismatic Jewel" and is_jewel_progression:
                is_fish_progression = True
            elif "Recipe Book" in location.itemName and is_recipe_progression:
                is_jewel_progression = True
            elif location.itemName == "Fishing Rod" and is_fish_progression:
                is_recipe_progression = True

        # Break loop if no changes
        if (is_jewel_progression == prev_jewel_progression and
            is_recipe_progression == prev_recipe_progression and 
            is_fish_progression == prev_fish_progression and
            is_essence_key_progression == prev_essence_key_progression):
            break

    return {
        "JewelTrade": is_jewel_progression,
        "MishyRewards": is_recipe_progression,
        "FishRewards": is_fish_progression,
        "EssenceKey": is_essence_key_progression
    }



def findBarrenRegions(shuffledLocations, parameters):
    # isRegionNotBarren["region"]: True => has progression
    # isRegionNotBarren["region"]: False => is barren
    isRegionNotBarren = defaultdict(bool)
    nonItems = ["Defeated", "End the Lacrimosa", "Prismatic Jewel", "Fishing Rod", "Recipe Book", "Essence Key Stone"]# Removing the "Boss defeated" item
    isChainLocsProgression = determine_progression(shuffledLocations, parameters)
    isJewelProgression = isChainLocsProgression["JewelTrade"]
    isRecipeProgression = isChainLocsProgression["MishyRewards"]
    isRodProgression = isChainLocsProgression["FishRewards"]
    isEssenceKeyProgression = isChainLocsProgression["EssenceKey"]

    for location in shuffledLocations:
        # once a location.progression = True, the value in the dict will always be true
        isRegionNotBarren[location.locRegion] = (
            isRegionNotBarren[location.locRegion] or 
            location.itemName == "Gale Feather" or
            (location.progression and not any(nonItem in location.itemName for nonItem in nonItems)) or 
            (location.itemName == "Prismatic Jewel" and isJewelProgression) or
            (location.itemName == "Fishing Rod" and isRodProgression) or
            ("Recipe Book" in location.itemName and isRecipeProgression) or
            (location.itemName == "Essence Key Stone" and isEssenceKeyProgression)
            )

    return isRegionNotBarren
    

def format_hint(itemName, quantity, hintNumber, isFoolish, isRequired, charPortrait, locRegion, displayFullLoc, locName = '', mapCheckID = ''):
    
    hintNumberText = "Hint " + str(hintNumber)

    isRequiredText = "QUEST_KIND_KEY" if isRequired else "QUEST_KIND_NORMAL"

    if "SKILL_" in itemName:
        itemName = SKILLS[itemName]

    itemText = ''
    if quantity == 1:
          itemText =  itemName
    else:
        itemText = itemName + " x" + str(quantity)

    specificLocationText = ''
    if displayFullLoc:
        specificLocationText = locName

    if isFoolish:
        itemName = ""
        formattedDescription = f"""
They say that exploring \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t
{locRegion} is a foolish choice \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t
"""
    else:
        formattedDescription = f"""
They say that \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t
{locRegion} {specificLocationText} rewards {itemText}\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t
"""
        
    return (
        f"[QUEST]\tGF_TBOX_DUMMY130\t\t\t{itemName}\t{hintNumberText}\t{hintNumberText}\tGF_NPC_2_02_START_EXPLORE\tGF_NPC_2_02_START_EXPLORE\t"
        f"GF_NPC_2_11_JOIN_DINA\tGF_NPC_7_01_GOTO_TEM\tSMI_NONE\t\t\t\t\t\t\t\t\t-1\t{charPortrait}\t{isRequiredText}\t"
        f"{formattedDescription}"
        f"[QUESTSTATE]\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n"
        f"DF_QS200_START\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n"
        f"[QUESTEND]\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n"
    )

# This function is responsible for writing the hints on the quest.csv file to display them in the bulletin board. If hints are off it will Clear the hints from the file
def generateHint(hints, parameters):
    random.seed(parameters.seed)
    exe_dir = os.path.dirname(sys.executable)
    csv_path = os.path.join(exe_dir, 'text', 'en', 'quest.csv')
    flag = "// Start of hints\n"
    quest_ind = '[QUEST]'

    try:
        try:
            with open(csv_path, "r", encoding="utf-8") as file:
                lines = file.readlines()
        except FileNotFoundError:
            lines = []

        # This is to comment out vanilla quest text from the board, while still preserving the file. 
        # Quests don't do anything in the rando except a couple of the flags are useful for some events
        # This makes the presentation a little cleaner.
        for index,line in enumerate(lines):
            if quest_ind in line and line[0] != '/':
                newline = '//' + line
                lines[index] = newline

        # Locate the flag (created this to preserve the quest.csv file structure)
        if flag in lines:
            flag_index = lines.index(flag) + 1
            content_above_flag = lines[:flag_index]  # Keep everything above and including the flag
        else:
            content_above_flag = lines + [flag]  # Add the flag if not found
            flag_index = len(content_above_flag)

        formattedHints = []
        for index, hint in enumerate(hints, start=1):
            formattedHints.append(
                format_hint(
                    itemName=hint.itemName,
                    hintNumber=index,
                    isRequired=hint.isRequired,
                    isFoolish=hint.isFoolish,
                    charPortrait=hint.charPortrait,
                    quantity=hint.quantity,
                    locRegion=hint.locRegion,
                    locName=hint.locName,
                    mapCheckID=hint.mapCheckID,
                    displayFullLoc=hint.displayFullLoc
                )
            )

        # Combine content above the flag with new hints
        updated_content = content_above_flag + formattedHints

        # Write the updated content back to the file
        with open(csv_path, "w", encoding="utf-8") as file:
            file.writelines(updated_content)

        #print("The CSV file has been updated.")

    except Exception as e:
        print(f"An error occurred: {e}")

if "__name__" == "__main__":
  hints = [
      {
          "item_name": "Sturdy Lumber",
          "quantity": 3,
          "locRegion": "Pirate Ship Eleftheria",
          "locName": "Submerged Hold",
          "mapCheckID": "TBOX01",
          "isFoolish": True,
          "is_required": False,
      },
      {
          "item_name": "Bone Necklace",
          "quantity": 1,
          "locRegion": "Pirate Ship Eleftheria",
          "locName": "Submerged Hold",
          "mapCheckID": "TBOX01",
          "isFoolish": False,
          "is_required": True,
      },
  ]

  csv_file_path = "quest.csv"
  generateHint(hints)
