# Seiren-Shuffle-An-Ys-8-Randomizer-
*This is for the Steam release of Ys 8 only*

Ys 8 is a game about an adventurer, Adol, who gets stranded on the deserted Island of Seiren after a shipwreck and must escape while solving the island's many mysteries. Over the course of the adventure Adol must also find other castaways who got stranded from the same shipwreck and this is where the rando kicks off. The rando starts after the game's prologue and plops Adol right into the heart of Castaway Village, the home base of the survivors on the deserted Island of Seiren. So now it's time to begin exploring and discovering what this island is and find a way to escape it. Let's get into how to set this up.

## Installation

Installation should be pretty simple. 
1. Download the package with the script files and "Seiren Shuffle.exe" from the most recent release then extract the contents to your root Ys 8 folder.
2. (Note that before this next step you might want to copy your Ys 8 "Scripts" and "Maps" folders as those are going to be edited heavily during installation of the rando and you'll need to do a fresh install to return the game to normal functionality otherwise.) Place the scripts folder and "Seiren Shuffle.exe" in the root directory for Ys 8, the default path should be something like "SteamLibrary\steamapps\common\Ys VIII Lacrimosa of Dana". 
3. Select yes to overwrite any files it prompts you on.
5. Once this step is finished the rando gui can be launched by simply selecting the "Seiren Shuffle.exe".
6. Before generating a seed the first thing that should be done is clicking the "Patch Files"(This only needs to be done the first time running the randomizer), this will do another round of file edits to the base game needed for the rando.
7. Once that patch is complete feel free to toy with settings and generate a seed, start the game, then select new game, and you should be good to go.
*A note on the edits this makes to the original game - The rando messes with the game's intended structure heavily so loading saves from the vanilla game will have unintended consequences, the saves won't be broken or anything just don't expect your old save files to work as intended while the rando is installed, saves from the rando will work fine.

## Settings
![settings example](https://i.imgur.com/Ig9naCM.png)

### Seed: 
The is the unique identifier for the randomization of your playthrough. Seeds with the same settings and number here should generate the same playthrough.

### Goal:
This sets the goal for your seed and the required amount. The goal and the required number are used to determine when the player will gain access to the Selection Sphere, the game's final room that leads to the final boss. Right now the only goal in the rando finding castaways and the required amount is how many that need to be found before the selection sphere unlocks. More goals are planned post 1.0.

### Shuffle Locations:
**Shuffle Castaways**: This sets whether or not the castaways, the other people stranded on the island that you're searching for that aren't party members, will be included in the shuffle. With this off they will be acquired in their original locations. (Note the rando alters the original game behavior so you never lose castaways regardless of this setting).

**Shuffle Party**: This sets whether or not the part members will be included in the shuffle. With this off they will be acquired in their original locations. (Note the rando alters the original game behavior so you never lose party members regardless of this setting).

### Progression Placement Modifiers:
These are settings that modify how much players may need to do of certain activities other than running around the island and exploring. These settings only affect where progression items will land, other useful non-progression items, could still land in the spots you have turned off.

**Jewel Trade Items**: These are the *Prismatic Jewel* trades at Dina's shop. In order to access these *Dina* must first join the village. Extra Prismatic Jewels have been added to the item pool and are considered for Dina's Jewel locations up to the item that costs 10 Prismatic Jewels. The 25 Jewel location is tied to finding the fishing rod and also having access up to Pangai Plains Night Exploration, this is for Jewel farming. The reason 25 more Jewels weren't added to the item pool was to both avoid flooding the pool completely and to preserve the 25 Jewel location as a "Masochist Location", the default settings use all Jewel locations of 10 or less and there are enough Jewels from checks to buy everything 10 or less. There are 10 Trades total: 4 costing 1 Jewel, 3 costing 2 Jewels, 1 costing 3 Jewels, 1 costing 10 Jewels, and 1 costing 25 Jewels.

**Fish Trades**: These are the rewards the player gets for turning in 4,8,12,16,20, and 24 unique fish to Shoebill. *Shoebill* joining the village is **not** required for these and those large numbers of fish required have been greatly reduced. The 6 rewards are now at 1,2,3,4,5,6 unique fish. The *fishing rod* is required to make these checks.

**Food Trades**: These are the rewards the player gets for turning in 2,4,6,8,10, and 12 unique cooked recipes to Mishy Mishy. The numbers of recipes required has been greatly reduced. The 6 rewards are now at 1,2,3,4,5,6 unique recipes. Access to Gendarme's Midpoint is required to make this check, as well as access to 6 *unique recipes*.

**Map Completion**: These are the rewards given by Euron/Captain Barbaros for filling in the map of Seiren Island. *Euron* joining the village is required to make these checks. The requirements are loosely based on the amount of world access each progression item adds with a generous margin of error in favor of the player and the *Eagle Eye Orb* is considered required for percents 60 or greater. Note that the setting caps at 90%. Logically progression can never land at 100% as 100% access to the island would necessitate having all progression items.

**Discoveries**: This is only two rewards, so both are on by default. While finding all 24 would be a lot, the odds progression ends up here are low and most of the discoveries are both along the way and useful for getting around the island, they open up new fast travel spots. So all 24 are still required for the second reward with 12 required for the first, *Austin* joining the village is also required.

**Dogi Intercept Rewards**: Dogi gives out 5 rewards for completing specific intercept stages. They are at stages 2,3,5,7, and 9. This setting is only an on or off setting and *Dogi* is *not* required to have joined the village. Most of these rewards aren't really more out of the way than others. The way intercepts unlock is also different in the rando and will be covered more in the "New Progression Items" section. A quick summary is they're now unlocked via *T's Memos* that are found in the world, so specific numbers of those are required to get these rewards: 1 for stages 1-7 and 3 for stage 9. 

### Speed Hacks:
These are settings that help with the pacing of the rando. Like most randos Seiren Shuffle is designed to be complete-able in a single sitting, these settings are meant to help with that. Most RPG randos use things like an exp multiplier for this. Seiren Shuffle uses some slightly different methods for pumping the player with experience and tools.
**Lucky Checks**: This setting makes specific random checks more rewarding by having an additional reward appear after the initial item placed at that check. These additional rewards can be the following: 
- *Big* gives 3 Tempest Elixirs (Raises a character 1 level times 3).
- *Medium* gives 3 Hermit's Remedy (Gives a character 10,000 experience times 3).
- *Small* gives 5 Bitter Remedy (Gives a character 1000 experience times 5).
**Additional Intercept Rewards**: This settings causes intercepts to give out up to four additional rewards after returning to Castaway Village post intercept. Tempest Elixirs are always given out at some rate but there are also rewards to help players upgrade weapons as well as exp and stat increasing food rewards. This setting is highly encouraged as it helps a lot with endgame prep work. 

## New Progression Items
The randomizer features a variety of new progression items that are meant to take story gated events and turn them into item gated events to improve the overall experience of the rando. 

The biggest edition is the Dana past event items. Throughout the original game Adol would have flashbacks to the ancient era of the Eternians were the player would take control of the titular Dana. In the past certain things Dana did would affect and change the present and certain events would be required for player progression. These sequences were pretty brief and mostly involved running around talking to NPCs and getting lore dumps. There was one optional dungeon but it was a pretty bulky linear dungeon. None of that is really great content for a randomizer so instead certain items now trip game flags for having completed all the side quests and main quests from a particular flashback. Here is the list, you'll notice most of them are based on key items from the past events:
- *Maiden Journal*: This one spawns the tree to the Primordial Passage which leads to Mount Gendarme.
- *Blue Seal of Whirling Water*: This one spawns the tree that leads into the Capital of Eternia and also completes the quest related to waterway repair, which spawns a chest in the Titis Primeval Forest.
- *Green Seal of Roaring Stone*: This one spawns the tree that leads to The Temple of the Great Tree and also completes the quest related to the lost key, which opens a doorway in The Ruins of Eternia with 3 chests behind it.
- *Golden Seal of Piercing Light*: This one spawns the tree that leads into Baja Tower and also completes the quest for helping animals which spawns a new discovery on Pangaia Plains
- *Frozen Flower*: This one spawns the tree that protects The Palace and also completes the quest related to repairing The Monestary Door, which grants access to the optional dungeon Balado Monestary.
- *Treasure Chest Key*: This one spawns the tree that grants access to the back half of Lodinia Marsh and is itself a key for a locked chest in the one accessible residence in The Ruins of Eternia.
- *Shrine Maiden Amulate*: This one is both a useful accessory while also unlocking the path to The Hill of Eternity, which is a discovery and one check. Seren Garden is restored by default in the rando though the Mistilteinn spot still requires dealing with the Wardens of Evolution.

There are now items that upgrade the shops, which includes all shops (Trade, Craft, Tailor, Smith, Brew) and unlocks new weapons to "Reforge"(Access to the shops still requires the requisite castaways that run them first). The items used for this are the 5 *Flame Stones* plus the one *Orichalcum* and they unlock the upgrades progressively(in a linear order). You may be suprised to hear that in the original game the Flame Stones actually did nothing mechanically, the game's story event flags controlled the shops completely and the Flame Stones were only a guide post to let the player know the shops were upgraded, so now they actually do something and story events should no longer upgrade the shops. Hummel also gets a free weapon upgrade from shop upgrading too(This is because his reforge chain is incomplete with his starting weapon in the original game due to him leaving the party and rejoining much later so he's given his rejoin weapon as a bonus when the shops are at a certain level or when doing the next thing I will mention). The Orichalcum has an additional function, turning it into Kathleen triggers the event where the current party all get their weapons upgraded to damage Saurians, Adol, Laxia, Ricotta, Sahad, and Hummel* (Hummel gets an upgrade in the rando from this event, he didn't in the original game). This event also flips the game flag to allow the player to defeat enemies flaged as Saurians, which is very few enemies out in the world but a lot in intercepts.

*Ts Memos* now unlock Intercepts in 4 different stages, progressively(in a linear order). The first memo unlocks the raid practice options for the first 7 stages, the second memo unlocks the first 7 hunts, the third memo unlocks the last mix of hunts and raids excluding the endless raids, and the last memo unlocks the endless raids. This also means that all but one of Dogi's raid rewards can be acquired from the first memo. Dogi's reward for raid stage 9 requries 3 memos. *Dogi* is *not* required to access raids.

The Pirate's *Logbook* from the East Coast Cave Docks lowers the gangway that grants access to the Eleftheria now, in the original game this event was tied to the treasure chest itself, not finding the logbook.

The *Glow Stone* is an item of limited utility in the original game, very few areas were dark enough to make it remotely useful (this might depend a little on your monitor though and it is still logically required for items in some of those dark rooms but not really necessary). To improve it's utility it now unlocks Night Hunts too. The night hunt versions of Towering Coral Forest and Mount Gendarme are quality checks per minute plays and Pangaia Plains Night is a quality exp per minute play, so this adds greater importance to this item of questionable merit. 

The *Ship Blueprints* open repair the boat that leads to Solitude Island.

## Other Notes for Progression
A couple quick notes that might not be immediately obvious.

The player can still access the *enhance* feature for weapons before getting Kathleen by interacting with the stump near the forge, just like the original game the player had access to some of the village features though in a greatly limited capacity before finding the villagers that run specific shops.

- *Dina* is logically required for getting rid of insect nests, her joining grants the player the abiltiy to trade which is access to Insect Repellant and the player will also get 10 Insect Repellant upon having her join.
- *Kathleen* is access to reforge and armor smith.
- *Licht* is access to the main brew feature.
- *Alison* is access to the tailor.
- *Euron* is access to both showing the map for map completion rewards and accessory craft.
- *Austin* is access to rewards for finding discoveries.
- *Little Paro* doesn't count toward overall village numbers. In the original game Shoebill and Master Kong didn't either but I used some of the extra Castaway allocations to make them count. However I was one short to make Paro count and Paro is a small bird so it honestly makes sense he wouldn't be help moving large objects.
- *Octus Overlook* is open from the start of the game and if it can be reached then it can be entered, only Selection Sphere access is tied to the goal.
- The vanilla *Licht* check leads to the whole sequence that ends in the Kiergaard boss fight. Defeating Kiergaard gives the player the vanilla Quina joining event check.
- Defeating *Avalodragil* normally triggers the events that have the vanilla Dogi and Paro joining events along with the Fishing Rod check. These are rewarded after the boss fight instead. Normally Barbaros would join here too but his join event was moved to after the end of Waterdrop Cave for balance reasons (There would have been no reason to fight the boss otherwise).
- There was a check added to the monolith scene at the top of Baja Tower, this was because there were no checks behind the boss of Baja Tower otherwise. 

## Final Notes
Here is a list of all checks in the rando for assistance: [Checks](https://docs.google.com/spreadsheets/d/e/2PACX-1vTk6waI_Ymz1SiK90FnF1b2hDCgdZCVTrhFAX-O2-K_ovf0R3HA07AI90D5vQXPKrYBoMxH4Zu7tclx/pubhtml)
At this point everything in the game should be randomized other than quest rewards, which I ultimately decided weren't worth it and flagged most of the quests as completed on startup (a majority of the quest rewards are pretty meh and the quests are mostly about building rep for the "good ending" and the few quest rewards that were decent were added to the shuffle and have the potential to still appear). If you find anything that you think isn't that isn't a quest reward feel free to let me know. Locations generally aren't difficult to add.

The core of the randomizer uses a large script file to drive what items are and what items do, this is much more flexible than simply placing new items in chests. Ys 8 chests take a script as an agrument that is then executed on open and this is what's used to give out rewards from the chests. To make sure the chests stay closed junk has been filled into every chests that does nothing, this is why you see an initial chest popup before the actual item you get. I would love to find a way to supress the initial chest message. I spent some time dissecting the chest function in Cheat Engine looking for a way to do this but didn't find one. If you'd like to look into this then let me know and I can provide some of the notes I took on the game's chest function. 

This project is open source and I accept all who would like to help or add to the rando.

Please use the issue tracker built into github for reporting issues as it's much easier to track stuff that way, if you reach out to me directly I might forget. 

As always... **Good Luck! Have Fun!**



