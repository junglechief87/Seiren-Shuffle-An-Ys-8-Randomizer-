# Seiren-Shuffle-An-Ys-8-Randomizer-
*This is for the Steam release of Ys 8 only*

Ys 8 is a game about an adventurer, Adol, who gets stranded on the deserted Island of Seiren after a shipwreck and must escape while solving the island's many mysteries. Over the course of the adventure Adol must also find other castaways who got stranded from the same shipwreck and this is where the rando kicks off. The rando starts after the game's prologue and plops Adol right into the heart of Castaway Village, the home base of the survivors on the deserted Island of Seiren. So now it's time to begin exploring and discovering what this island is and find a way to escape it. Let's get into how to set this up.

## Installation

Installation should be pretty simple. 
1. Download the SeirenShuffle.zip file from the latest release.
2. (Note that before this next step you might want to copy your Ys 8 "Scripts" and "Maps" folders as those are going to be edited heavily during installation of the rando and you'll need to do a fresh install to return the game to normal functionality otherwise.) Extract the contents of the SeirenShuffle.zip to the root directory of Ys8.
3. Select yes to overwrite any files it prompts you on.
5. Once this step is finished the rando gui can be launched by simply selecting the "Seiren Shuffle.exe".
6. Before generating a seed the first thing that should be done is clicking the "Patch Files"(This only needs to be done the first time running the randomizer), this will do another round of file edits to the base game needed for the rando.
7. Once that patch is complete feel free to toy with settings and generate a seed, start the game, then select new game, and you should be good to go.
*A note on the edits this makes to the original game - The rando messes with the game's intended structure heavily so loading saves from the vanilla game will have unintended consequences, the saves won't be broken or anything just don't expect your old save files to work as intended while the rando is installed, saves from the rando will work fine.


## Settings
![settings example](https://github.com/junglechief87/Seiren-Shuffle-An-Ys-8-Randomizer-/blob/main/shared/Main%20Interface.png?raw=true)

### Seed: 
This is the unique identifier for the randomization of your playthrough. Seeds with the same settings and number here should generate the same playthrough.

### Character Mode: 
This setting changes what characters you will be controlling on your playthrough.

 - **Standard**: The playable characters are the 6 default ones: Adol, Laxia, Sahad, Hummel, Ricotta, and Dana.  

 - **Past Dana**: The playthrough will start with Past Dana as well as Gratika and Luminous. No additional skills can be learned aside from the 4 starting ones. You will also start with the Pierce Medal and Strike Medal in your inventory since all 3 Danas hit with Slash type. Io will always be her final boss.

### Selection Sphere Access:
This sets the goal for your seed and the required amount. The goal and the required number are used to determine when the player will gain access to the Selection Sphere, the game's final room that leads to the final boss. 

**Find Crew**: This is short for finding castaways and the required amount is how many that need to be found before the Selection Sphere unlocks. This is tied to the same counts used for moving objects in the world. There are 28 possible and the goal number can be set to any number from 1-28. So this is essentially an X of 28 item hunt.

**Seiren Escape**: This is essentially finding three specific items scattered between the checks. Those items are *Seiren Nautical Chart*, *Ship Blueprints*, and *Mistilteinn*. The goal number does nothing here and is disabled with this setting.

**Release the Psyches**: This mode sets the goal to beating x of 4 of the Wardens of Evolution to gain access to the Selection Sphere. The Wardens can be any of the original 4 or Le-Kyanos or Melaiduma if Former Sanctuary Crypt is turned off. For Past Dana it's the chamber guardians, Le-Erythos or Melaiduma with the same condition. To access the bosses interact with the checkpoint crystal in Castaway Village, there you can see which Wardens are required to win, the boss you'll be fighting at each loaction is in paranthesis and the location or the major boss required to unlock the fight is listed first. When the specified boss is defeated the option on the crystal will become selectable. 

**Untouchable**: This setting is pretty simple: reach the bottom of the Former Sanctuary Crypt and defeat Melaiduma to unlock the final boss in the Selection Sphere. This setting forces Former Sanctuary Crypt on. The goal number does nothing here and is disabled with this setting.

**Goal count to open Octus**: This sets the number of goal items required to open up the entrance to the Tree of Origin, the Tree of Origin is a powerful grinding location with a ton of easy mini bosses and a lot of fast checks if "Octus Paths Opened" is turned on. This setting is disabled under the "Seiren Escape" and "Untouchable" options. 

### Shuffle Locations:
**Shuffle Castaways**: This sets whether or not the castaways, the other people stranded on the island that you're searching for that aren't party members, will be included in the shuffle. With this off they will be acquired in their original locations. (Note the rando alters the original game behavior so you never lose castaways regardless of this setting).

**Shuffle Party**: This sets whether or not the part members will be included in the shuffle. With this off they will be acquired in their original locations. (Note the rando alters the original game behavior so you never lose party members regardless of this setting).

**Skills w/ Boss Bonuses**: This setting adds two checks to every boss, with the exception for some of the mini bosses in places like Octus, and then removes skill learning from the game. These extra boss checks are added to the pool to facilitate the skills that are now added to the item pool. Skills can be found at any location.

**Discovery-Sanity**: This setting puts the landmarks in the pool, the landmarks themselves also become checks. Finding a landmark unlocks the ability to warp to it on the map. This mode drastically changes logic and movement around the world.

### Progression Placement Modifiers:
These are settings that modify how much players may need to do of certain activities other than running around the island and exploring. These settings only affect where progression items will land, other useful non-progression items, could still land in the spots you have turned off.

**Jewel Trade Items**: These are the *Prismatic Jewel* trades at Dina's shop. In order to access these *Dina* must first join the village. Extra Prismatic Jewels have been added to the item pool and are considered for Dina's Jewel locations up to the item that costs 10 Prismatic Jewels. The 25 Jewel location is tied to finding the fishing rod and also having access up to Pangai Plains Night Exploration, this is for Jewel farming. The reason 25 more Jewels weren't added to the item pool was to both avoid flooding the pool completely and to preserve the 25 Jewel location as a "Masochist Location", the default settings use all Jewel locations of 10 or less and there are enough Jewels from checks to buy everything 10 or less. There are 10 Trades total: 4 costing 1 Jewel, 3 costing 2 Jewels, 1 costing 3 Jewels, 1 costing 10 Jewels, and 1 costing 25 Jewels.

**Fish Trades**: These are the rewards the player gets for turning in 4,8,12,16,20, and 24 unique fish to Shoebill. *Shoebill* joining the village is **not** required for these and those large numbers of fish required have been greatly reduced. The 6 rewards are now at 1,2,3,4,5,6 unique fish. The *fishing rod* is required to make these checks.

**Food Trades**: These are the rewards the player gets for turning in 2,4,6,8,10, and 12 unique cooked recipes to Mishy Mishy. The numbers of recipes required has been greatly reduced. The 6 rewards are now at 1,2,3,4,5,6 unique recipes. Access to Gendarme's Midpoint is required to make this check, as well as access to 6 *unique recipes*.

**Map Completion**: These are the rewards given by Euron/Captain Barbaros for filling in the map of Seiren Island. *Euron* joining the village is required to make these checks. The requirements are loosely based on the amount of world access each progression item adds with a generous margin of error in favor of the player and the *Eagle Eye Orb* is considered required for percents 60 or greater. Note that the setting caps at 90%. Logically progression can never land at 100% as 100% access to the island would necessitate having all progression items.

**Discoveries**: This is only two rewards, so both are on by default. While finding all 24 would be a lot, the odds progression ends up here are low and most of the discoveries are both along the way and useful for getting around the island, they open up new fast travel spots. So all 24 are still required for the second reward with 12 required for the first, *Austin* joining the village is also required.

**Dogi Intercept Rewards**: Dogi gives out 5 rewards for completing specific intercept stages. They are at stages 2,3,5,7, and 9. This setting is only an on or off setting and *Dogi* is *not* required to have joined the village. Most of these rewards aren't really more out of the way than others. The way intercepts unlock is also different in the rando and will be covered more in the "New Progression Items" section. A quick summary is they're now unlocked via *T's Memos* that are found in the world, so specific numbers of those are required to get these rewards: 1 for stages 1-7 and 3 for stage 9.

**Master Kong Rewards**: Sets whether Master Kong can have progression, this is a fairly lengthy chain that spans the game.

**Silvia**: Sets whether Silvia can block progression. This only refers to the optional boss fight.

**Maphorash**: Sets whether Maphorash can block progression. Maphorash is the highest level optional fight in the game and the Silent Tower is high requirement location.

**Former Sanctuary Crypt**: Sets whether Former Sanctuary Crypt is added to the item pool. If turned off the dungeon is closed. All essence key stones are placed within the dungeon unless Essence Key Sanity is on.

### Pacing Modifiers:
These are settings that help with the pacing of the rando. Like most randos Seiren Shuffle is designed to be complete-able in a single sitting, these settings are meant to help with that.   

**Experience Multiplier**: Pretty straighforward, classic multiplier to EXP. I generally reccomend higher values here than what you might be used to in other randos. The new version removes the game's EXP scaling based on enemy level to help smooth the curve out and keep the player from "slingshotting" to high levels too quickly. This has the consequence that enemies give half their base EXP(the base exp value for enemies in Ys 8 is based on them being slightly higher level than the player, if they're considered the same level as the player then they drop to almost half EXP and the scaling patch makes the game think the player is always equal level to the enemy).  

**Exp Mult Growth Rate**: There are 13 bosses that are considered Major or Dungeon Bosses, each will add an small multiplier to the base EXP multiplier. The right side of the pacing modifiers breaks down how the math plays out to help the player determine how they'd like these options set.  

**Additional Intercept Rewards**: This settings causes intercepts to give out up to four additional rewards after returning to Castaway Village post intercept. Tempest Elixirs are always given out at some rate but there are also rewards to help players upgrade weapons as well as exp and stat increasing food rewards. This setting is highly encouraged as it helps a lot with endgame prep work.  

**Battle Logic**: This attempts to help smooth over the combat pacing by guaranteeing the player always has access to some amount of strength for each boss, highly recommended this be left on expecially for Inferno.  

**Progressive Super Weapons**: Both the Mistilteinn and Spirit Ring are in the pools now. If the player finds either with this option on they will instead be given the Broken Mistilteinn or Broken Spirit Ring. Once the forge is raised to max level speaking with Kathleen will prompt the player to fix the broken weapon and will give the Adol the Mistilteinn or Dana the Spirit Ring.  

**Octus Paths Opened**: All the bridges in Octus will start lowered, all the bosses and mini-bosses are still present but do not need to be defeated to access everywhere in the dungeon. The mini-bosses are still an amazing EXP farm.  

**Extra Flame Stones**: Adds 3 Flame Stones to the item pool, makes hitting max level in any run more likely without being excessive. There are 7 Flame Stones by default so this puts it to a nice round 10.  

**Recipes come w/ Ingredients**: This grants the player all ingredients necessary to cook a dish upon obtaining their respective Recipe Book.  

**North Side Open**: The playthrough will start with the Crystal Checkpoint to Temple Approach unlocked. This means that completing Mt Gendarme is no longer mandatory to access the North Side.
And it also means that you may need to explore the North Side while underlevelled.  

**Infinity Mode**: This activates Infinity Mode in the game. This is a New Game+ modes that drastically scales up enemy levels. It is recommended you upgrade your starting loadout drastically with this setting on. The lowest level enemies are in the mid-60s and the highest level enemy is 120 with this flag set.

**Starting Loadout**: This extra menu lets you start the game with a variety of helpful tools.
![settings example](https://github.com/junglechief87/Seiren-Shuffle-An-Ys-8-Randomizer-/blob/main/shared/Starting%20Loadout.png?raw=true)
  - *Starting Level*: Fairly self explanatory, lets you set the level for your initial scharacter, default is 3.
  - *Flame Stone Level*: Let's you set the forge level for Kathrine and also upgrades any other shops similarly.
  - *Weapon Level*: Starts the player with weapons of the equivalent forge level instead of needing to upgrade to them.
  - *Armor Level*: Similar to above but there's an extra level to start with the Pure Orichalcum armor.
  - *All Recipes*: Let's the player start with every recipe known.
  - *Max Ingredients*: Starts the player with a stack of 999 or 99 on Inferno of every item required to make a recipe. 
  - *Dina-Trade*: Starts the player with Dina's shop unlocked and Dina as a crew member.
  - *Alison-Tailor*: Starts the game with Alison shop unlocked and Alison as a crew member.
  - *Euron-Craft*: Starts the player with Euron's shop unlocked and Euron as a crew member.
  - *Licht-Medicine*: Starts the game with Licht's shop unlocked and Licht as a crew member.
  - *Adventure Gear*: Lets the player start with any selected Adventure Gear and set the number of slots for gear as well.

### Final Boss Settings:
**Final Boss**: Sets which boss will be the final one, Theos, Origin, or both. If set to both the fights happen consecutively.  

**Theos Start Phase**: Sets which phase the Theos fight will start in. First is normal, Second is the circular platform with the crystals, Final is the head.  

**Origin Care Package**: Origin is a long fight and a decently higher level than Theos. Since the Abyss is skipped in the rando there's an option here to help the player if they're doing both fights consecutively. Lite gives the player a few ripe items and recipes, generous gives the player stacks of ripe items and recipes.  

**Origin Start Phase**: Sets which phase the Origin fight starts in. First is the mobbing phase, second is the main boss.  

### Misc Settings:  
**Shuffle BGM**: (This setting will modify the file ./text/bgmtbl.tbl so you may want to make a copy of it if you want to keep the original file) Shuffles the background tracks from the "bgm" folder from the game. This setting also allows for audio files that are external to Ys VIII. In order to add new tracks, add .OGG files to the "bgm" folder in the root directory of Ys VIII. Make sure the file names are at most 8 characters long.  

**Essence Key Sanity**: If Former Sanctuary Crypt setting is on, the Essence Key Stones can be placed anywhere in the game and not just within the dungeon itself.

**Hints**: If Hints setting is on, a set of hints will be displayed on the bulletin board in castaway village. They can also be seen in the quest menu. You can also customize the amount of each type of hint that will be displayed.
  - *Adventuring Gear Hints*: Hints the Region where you will find a mentioned Adventuring Gear.
  The only hintable Adventuring Gears are the ones that lock progression and the Gale Feather
  - *Castaway Hints*: Hints the Region where you will find a mentioned Castaway.
  - *Foolish Location Hints*: Hints a region where you will not find any progression items.

**Customize Starting Characters**: Lets the player set which starting characters they're allowed to get. Setting only one in the pool guarantees that is the starting character.

## New Progression Items
The randomizer features a variety of new progression items that are meant to take story gated events and turn them into item gated events to improve the overall experience of the rando. 

- The biggest edition is the Dana past event items. Throughout the original game Adol would have flashbacks to the ancient era of the Eternians were the player would take control of the titular Dana. In the past certain things Dana did would affect and change the present and certain events would be required for player progression. These sequences were pretty brief and mostly involved running around talking to NPCs and getting lore dumps. There was one optional dungeon but it was a pretty bulky linear dungeon. None of that is really great content for a randomizer so instead certain items now trip game flags for having completed all the side quests and main quests from a particular flashback. Here is the list, you'll notice most of them are based on key items from the past events:
  - *Maiden Journal*: This one spawns the tree to the Primordial Passage which leads to Mount Gendarme.
  - *Blue Seal of Whirling Water*: This one spawns the tree that leads into the Capital of Eternia and also completes the quest related to waterway repair, which spawns a chest in the Titis Primeval Forest.
  - *Green Seal of Roaring Stone*: This one spawns the tree that leads to The Temple of the Great Tree and also completes the quest related to the lost key, which opens a doorway in The Ruins of Eternia with 3 chests behind it.
  - *Golden Seal of Piercing Light*: This one spawns the tree that leads into Baja Tower and also completes the quest for helping animals which spawns a new discovery on Pangaia Plains.
  - *Frozen Flower*: This one spawns the tree that protects The Palace and also completes the quest related to repairing The Monestary Door, which grants access to the optional dungeon Balado Monestary.
  - *Treasure Chest Key*: This one spawns the tree that grants access to the back half of Lodinia Marsh and is itself a key for a locked chest in the one accessible residence in The Ruins of Eternia.
  - *Shrine Maiden Amulate*: This one is both a useful accessory while also unlocking the path to The Hill of Eternity, which is a discovery and one check. Seren Garden is restored by default in the rando though the Mistilteinn spot still requires dealing with the Wardens of Evolution.  
  - *Jade Pendant*: This is the Pendant from Vanila that boosts the damage against saurians. It will also open the path to the Former Sanctuary Crypt if the setting is active.

- There are now items that upgrade the shops, which includes all shops (Trade, Craft, Tailor, Smith, Brew) and unlocks new weapons to "Reforge"(Access to the shops still requires the requisite castaways that run them first). The items used for this are 7 *Flame Stones* and they unlock the upgrades progressively(in a linear order). You may be suprised to hear that in the original game the Flame Stones actually did nothing mechanically, the game's story event flags controlled the shops completely and the Flame Stones were only a guide post to let the player know the shops were upgraded, so now they actually do something and story events should no longer upgrade the shops. Hummel also gets a free weapon upgrade from shop upgrading too(This is because his reforge chain is incomplete with his starting weapon in the original game due to him leaving the party and rejoining much later so he's given his rejoin weapon as a bonus when the shops are at a certain level or when doing the next thing I will mention). The Orichalcum has an additional function, turning it into Kathleen triggers the event where the current party all get their weapons upgraded to damage Saurians, Adol, Laxia, Ricotta, Sahad, and Hummel* (Hummel gets an upgrade in the rando from this event, he didn't in the original game). This event also flips the game flag to allow the player to defeat enemies flaged as Saurians, which is very few enemies out in the world but a lot in intercepts. New in 2.0 Kathleen and the Orichalcum are part of the progressive Flame Stone path. The first Flame Stone found will give the player Kathleen.

- *Ts Memos* now unlock Intercepts in 4 different stages, progressively(in a linear order). The first memo unlocks the raid practice options for the first 7 stages, the second memo unlocks the first 7 hunts, the third memo unlocks the last mix of hunts and raids excluding the endless raids, and the last memo unlocks the endless raids. This also means that all but one of Dogi's raid rewards can be acquired from the first memo. Dogi's reward for raid stage 9 requries 3 memos. *Dogi* is *not* required to access raids.

- The Pirate's *Logbook* from the East Coast Cave Docks lowers the gangway that grants access to the Eleftheria now, in the original game this event was tied to the treasure chest itself, not finding the logbook.

- The *Glow Stone* is an item of limited utility in the original game, very few areas were dark enough to make it remotely useful (this might depend a little on your monitor though and it is still logically required for items in some of those dark rooms but not really necessary). To improve it's utility it now unlocks Night Hunts too. The night hunt versions of Towering Coral Forest and Mount Gendarme are quality checks per minute plays and Pangaia Plains Night is a quality exp per minute play, so this adds greater importance to this item of questionable merit. 

- The *Ship Blueprints* repair the boat that leads to Solitude Island.

- Characters that didn't have early game weapons now have them and will recieve these weapons for free from Kathleen at the appropriate shop levels, assuming they aren't a downgrade.

## Other Notes for Progression
A couple quick notes that might not be immediately obvious.

The player can still access the *enhance* feature for weapons before getting Kathleen by interacting with the stump near the forge, just like the original game the player had access to some of the village features though in a greatly limited capacity before finding the villagers that run specific shops.

- *Dina* is logically required for getting rid of insect nests, her joining grants the player the abiltiy to trade, including Jewel Trades, which is access to Insect Repellant and the player will also get 10 Insect Repellant upon having her join.
- *Kathleen* is access to reforge and armor smith.
- *Licht* is access to the main brew feature.
- *Alison* is access to the tailor.
- *Euron* is access to both showing the map for map completion rewards and accessory craft.
- *Austin* is access to rewards for finding discoveries.
- *Octus Overlook* is open from the start of the game and if it can be reached then it can be entered, only Selection Sphere access is tied to the goal.
- The vanilla *Licht* check leads to the whole sequence that ends in the Kiergaard boss fight. Defeating Kiergaard gives the player the vanilla Quina joining event check.
- Defeating *Avalodragil* normally triggers the events that have the vanilla Dogi and Paro joining events along with the Fishing Rod check. These are rewarded after the boss fight instead. Normally Barbaros would join here too but his join event was moved to after the end of Waterdrop Cave for balance reasons (There would have been no reason to fight the boss otherwise).
- There was a check added to the monolith scene at the top of Baja Tower, this was because there were no checks behind the boss of Baja Tower otherwise.
- *Ricotta* will get an item dropped on her the second she enters Castaway Village for the first time, including if you got her as a starting character, this is the scene where she would meet Shoebill and Shoebill would officially join.
- Remember that *Dana* can open essence doors, there are two in the game, they are highly relevant to progression. 

## Final Notes
Here is a list of all checks in the rando for assistance, as well as some other useful lists: [Checks](https://docs.google.com/spreadsheets/d/e/2PACX-1vTk6waI_Ymz1SiK90FnF1b2hDCgdZCVTrhFAX-O2-K_ovf0R3HA07AI90D5vQXPKrYBoMxH4Zu7tclx/pubhtml)

At this point everything in the game should be randomized other than quest rewards, which I ultimately decided weren't worth it and flagged most of the quests as completed on startup (a majority of the quest rewards are pretty meh and the quests are mostly about building rep for the "good ending" and the few quest rewards that were decent were added to the shuffle and have the potential to still appear). The only quest that's tied to logic in any way is defeating Master Kong. There is one check tied to the event for beating Master Kong all six times, where he joined the village in the original game, and the quest becomes available when Ricotta is found. If you find anything that you think isn't randomized that isn't a quest reward feel free to let me know. Locations generally aren't difficult to add.

The core of the randomizer uses a large script file to drive what items are and what items do, this is much more flexible than simply placing new items in chests. Ys 8 chests take a script as an agrument that is then executed on open and this is what's used to give out rewards from the chests. To make sure the chests stay closed junk has been filled into every chest that does nothing, this is why you see an initial chest popup before the actual item you get. I would love to find a way to supress the initial chest message. I spent some time dissecting the chest function in Cheat Engine looking for a way to do this but didn't find one. If you'd like to look into this then let me know and I can provide some of the notes I took on the game's chest function. 

The "Seiren Shuffle.exe" can sometimes flag as a virus by windows defender, it's a false positive. This is a known issue with pyinstaller's single ".exe" compiles. 

I don't know why but the close method that appJar uses seems kinda sloppy, so the gui seems to always need to have close hit twice to actually close. The extra "Yes/No" close menus is for feedback, so you know it did something when you hit close. 

This project is open source and I accept all who would like to help or add to the rando.

Please use the issue tracker built into github for reporting issues as it's much easier to track stuff that way, if you reach out to me directly I might forget. 

As always... **Good Luck! Have Fun!**
