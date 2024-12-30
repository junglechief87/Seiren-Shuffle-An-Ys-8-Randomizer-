from appJar import gui
import random
import os.path
import shared.classr as classr
from randomizer.rngPatcher import *
from patch.chestPatcher import *
from patch.miscPatches import *

seed=int(random.random()*pow(10,16))
parameters = classr.guiInput
parameters.getSeed(seed)

def buttons(inpt):
    if inpt == 'Patch Files':
        cleanChests()
        miscFixes()
        app.okBox("Task Complete", "Patch Complete!")

    elif inpt == 'Generate Seed':
        parameters.getSeed(app.getEntry("Seed#: "))
        parameters.getGoal(app.getOptionBox("goal"),app.getScale("goalCount"),app.getScale("octusNum"),app.getOptionBox("characterMode"))
        parameters.getShuffleLocations(app.getCheckBox("party"),app.getCheckBox("crew"),app.getCheckBox("skills"))
        parameters.getProgressionMods(app.getOptionBox("Jewel Trade Items: "),app.getOptionBox("Fish Trades: "), \
            app.getOptionBox("Discoveries: "),app.getOptionBox("Map Completion: "),app.getOptionBox("Food Trades: "),\
                app.getCheckBox("dogiIntercept"),app.getCheckBox("MKRewards"),app.getCheckBox("silvia"),app.getCheckBox("maphorash"))
        parameters.getOtherToggles(app.getCheckBox("intRewards"),app.getCheckBox("battleLogic"),app.getCheckBox("superWeapons"), \
            app.getCheckBox("openPaths"),app.getCheckBox("exFlameStones"),app.getCheckBox("extraIngredients"))
        parameters.getExpMult(float(app.getScale("Experience Multiplier: ")), float(app.getScale("Exp Mult Growth Rate (%): ")))
        parameters.getFinalBoss(app.getOptionBox("Final Boss: "),app.getOptionBox("Theos Start Phase: "),app.getOptionBox("Origin Start Phase: "), \
            app.getOptionBox("Origin Care Package: "))
        parameters.getEssenceKeySanity(app.getCheckBox("essenceKeySanity"))
        parameters.getFormerSanctuaryCrypt(app.getCheckBox("formerSanctuaryCrypt"))
        parameters.getShuffleBgm(app.getCheckBox("shuffleBGM"))
        parameters.getHint(app.getCheckBox("hints"))
        rngPatcherMain(parameters) 
        app.okBox("Task Complete", "Seed Generation Complete!")
        
    elif inpt == 'New Seed':
        seed=int(random.random()*pow(10,16))
        parameters.getSeed(seed)
        app.setEntry("Seed#: ",parameters.seed)

def goalChange():
    if app.getOptionBox("goal") == "Find Crew":
        app.setScaleState("goalCount","active")
        app.setScaleRange("goalCount",1,28,24)
        app.showScaleIntervals("goalCount",5)
        app.setScaleState("octusNum","active")
        app.setScaleRange("octusNum",1,28,18)
        app.showScaleIntervals("octusNum",5)
        app.setCheckBox("superWeapons", ticked=True)
        app.setCheckBoxState("superWeapons","active")
    elif app.getOptionBox("goal") == "Release the Psyches":
        app.setScaleState("goalCount","active")
        app.setScaleRange("goalCount",1,4,3)
        app.showScaleIntervals("goalCount",2)
        app.setScaleState("octusNum","active")
        app.setScaleRange("octusNum",1,4,2)
        app.showScaleIntervals("octusNum",2)
        app.setCheckBox("superWeapons", ticked=True)
    elif app.getOptionBox("goal") == "Seiren Escape":
        app.setScaleState("goalCount","disabled")
        app.setScaleRange("goalCount",0,0,0)
        app.setScaleState("octusNum","disabled")
        app.setScaleRange("octusNum",0,0,0)
        app.setCheckBox("superWeapons", ticked=False)
        app.setCheckBoxState("superWeapons","disabled")

def charModeChange():
    if app.getOptionBox("characterMode") == "Past Dana":
        app.setCheckBox("MKRewards", ticked=False)
        app.setCheckBoxState("MKRewards", "disabled")
        app.setOptionBoxState("Final Boss: ","disabled")
        app.setOptionBoxState("Origin Care Package: ","disabled")
        app.setOptionBoxState("Origin Start Phase: ","disabled")
        app.setOptionBoxState("Theos Start Phase: ","disabled")
    elif app.getOptionBox("characterMode") == "Standard":
        app.setCheckBox("MKRewards", ticked=True)
        app.setCheckBoxState("MKRewards", "active")
        app.setOptionBoxState("Final Boss: ","active")
        app.setOptionBoxState("Origin Care Package: ","active")
        app.setOptionBoxState("Origin Start Phase: ","active")
        app.setOptionBoxState("Theos Start Phase: ","active")

def finalBossChange():
    if app.getOptionBox("Final Boss: ") == "Theos de Endogram":
        app.setOptionBoxState("Origin Care Package: ","disabled")
        app.setOptionBoxState("Origin Start Phase: ","disabled")
        app.setOptionBoxState("Theos Start Phase: ","active")
    elif app.getOptionBox("Final Boss: ") == "Origin of Life":
        app.setOptionBoxState("Theos Start Phase: ","disabled")
        app.setOptionBoxState("Origin Care Package: ","disabled")
        app.setOptionBoxState("Origin Start Phase: ","active")
    elif app.getOptionBox("Final Boss: ") == "Both":
        app.setOptionBoxState("Theos Start Phase: ","active")
        app.setOptionBoxState("Origin Care Package: ","active")
        app.setOptionBoxState("Origin Start Phase: ","active")
def growthExample(bossCount):
    baseExpMult = float(app.getScale("Experience Multiplier: "))
    expMultGrowth = float(app.getScale("Exp Mult Growth Rate (%): "))

    bossGrowthExample = baseExpMult * (pow((1 + expMultGrowth / 100), int(bossCount)))

    return str(round(bossGrowthExample,2))

def growthUpdate():
    app.setLabel("2BossGrowth", "2 bosses:" + growthExample(2) + "x")
    app.setLabel("5BossGrowth", "5 bosses:" + growthExample(5) + "x")
    app.setLabel("8BossGrowth", "8 bosses:" + growthExample(8) + "x")
    app.setLabel("10BossGrowth", "10 bosses:" + growthExample(10) + "x")
    app.setLabel("13BossGrowth", "13 bosses:" + growthExample(13) + "x")

def close():
    return app.yesNoBox("Exit", "Close Application?")

with gui('Seiren Shuffle (An Ys 8 Rando)', '700x850',font = {'size':12}) as app:
    #The top versoin of the icon call is used for running the randomizer from source, the bottom version of the loop is for the executable compile, comment and uncomment accordingly.
    #app.setIcon(os.path.dirname(os.path.realpath(__file__)) + "/shared/ysR Logo.ico") 
    app.setIcon(os.path.dirname(os.path.realpath(sys.executable)) + "/shared/ysR Logo.ico")     
    app.setGuiPadding(10,10)
    app.startFrame("Seed",0)
    app.setSticky("n")
    app.addLabelNumericEntry("Seed#: ",0,0)
    app.setEntry("Seed#: ",parameters.seed)
    app.setSticky("n")
    app.addButton("New Seed", buttons,0,1)
    app.stopFrame()

    app.startLabelFrame("Mode:",1,0,0)
    app.addOptionBox("characterMode", ["Standard","Past Dana"])
    app.setOptionBoxChangeFunction("characterMode", charModeChange)
    app.stopLabelFrame()

    app.startLabelFrame("Selection Sphere Access: ",2,0,0)
    app.setSticky("ew")
    app.addOptionBox("goal", ["Release the Psyches","Seiren Escape","Find Crew"],1,0,0)
    app.addScale("goalCount",1,2,3)
    app.setScaleIncrement("goalCount",1)
    app.showScaleValue("goalCount",True)
    app.showScaleIntervals("goalCount",2)
    app.setScaleLength("goalCount", 10)
    app.setScaleRange("goalCount",1,4,3)
    app.setSticky("e")
    app.addLabel("octusNumLabel","Goal count to open Octus: ",2,0,0)
    app.setSticky("ew")
    app.addScale("octusNum",2,2,3)
    app.setScaleIncrement("octusNum",1)
    app.showScaleValue("octusNum",True)
    app.showScaleIntervals("octusNum",2)
    app.setScaleLength("octusNum", 10)
    app.setScaleRange("octusNum",0,4,2) 
    app.setOptionBoxChangeFunction("goal", goalChange)
    app.stopLabelFrame()

    app.startLabelFrame("Shuffle Locations",3,0,0)
    app.setSticky("ew")
    app.addNamedCheckBox("Shuffle Castaways", "crew",1,1)
    app.setCheckBox("crew", ticked=True)
    app.addNamedCheckBox("Shuffle Party", "party",1,2)
    app.setCheckBox("party", ticked=True)
    app.addNamedCheckBox("Skills w/ Boss Bonuses", "skills",1,3)
    app.setCheckBox("skills", ticked=True)
    app.stopLabelFrame()

    app.startLabelFrame("Progression Placement Modifiers")
    app.setSticky("w")
    app.startFrame("progression placement modifiers1",3,0)
    app.addLabelOptionBox("Jewel Trade Items: ", ["None","Jewel Trades Costing 1","Jewel Trades Costing <= 2","Jewel Trades Costing <= 3","Jewel Trades Costing <= 10","All"],1)
    app.setOptionBox("Jewel Trade Items: ", "Jewel Trades Costing <= 10")
    app.stopFrame()
    app.startFrame("progression placement modifiers2",4,0)
    app.setSticky("ew")
    app.addLabelOptionBox("Fish Trades: ", ["None","1","2","3","4","5","6"],1)
    app.setOptionBox("Fish Trades: ", "6")
    app.addLabelOptionBox("Food Trades: ", ["None","1","2","3","4","5","6"],2)
    app.setOptionBox("Food Trades: ", "6")
    app.addLabelOptionBox("Map Completion: ", ["None","10%","20%","30%","40%","50%","60%","70%","80%","90%"],1,1)
    app.setOptionBox("Map Completion: ", "70%")
    app.addLabelOptionBox("Discoveries: ", ["None","Half(12)","All(24)"],2,1)
    app.setOptionBox("Discoveries: ", "All(24)")
    app.addNamedCheckBox("Dogi Intercept Rewards", "dogiIntercept",1,3)
    app.setCheckBox("dogiIntercept", ticked=True)
    app.addNamedCheckBox("Master Kong Rewards", "MKRewards",2,3)
    app.setCheckBox("MKRewards", ticked=True)
    app.addNamedCheckBox("Silvia", "silvia",3,3)
    app.setCheckBox("silvia", ticked=True)
    app.addNamedCheckBox("Maphorash", "maphorash",4,3)
    app.setCheckBox("maphorash", ticked=True)
    app.addNamedCheckBox("Former Sanctuary Crypt", "formerSanctuaryCrypt",1,4)
    app.setCheckBox("formerSanctuaryCrypt", ticked=False)
    app.stopFrame()
    app.stopLabelFrame()
    
    app.startLabelFrame("Pacing Modifiers",6,0)
    app.setSticky("ew")
    app.startFrame("experience",1,0)
    app.setSticky("ew")
    app.addLabelScale("Experience Multiplier: ",1,0,3)
    app.setScaleIncrement("Experience Multiplier: ",1)
    app.showScaleValue("Experience Multiplier: ",True)
    app.showScaleIntervals("Experience Multiplier: ",5)
    app.setScaleLength("Experience Multiplier: ", 10)
    app.setScaleRange("Experience Multiplier: ",0,10,4) 
    app.addLabelScale("Exp Mult Growth Rate (%): ",3,0,3)
    app.setScaleIncrement("Exp Mult Growth Rate (%): ",1)
    app.showScaleValue("Exp Mult Growth Rate (%): ",True)
    app.showScaleIntervals("Exp Mult Growth Rate (%): ",5)
    app.setScaleLength("Exp Mult Growth Rate (%): ", 10)
    app.setScaleRange("Exp Mult Growth Rate (%): ",0,10,3)
    app.setScaleChangeFunction("Exp Mult Growth Rate (%): ", growthUpdate)
    app.setScaleChangeFunction("Experience Multiplier: ", growthUpdate)
    app.stopFrame()
    app.setSticky("ne")
    app.startLabelFrame("Examples",1,4)
    app.setSticky("ne")
    app.addLabel("2BossGrowth", "2 bosses:" + growthExample(2) + "x")
    app.addLabel("5BossGrowth", "5 bosses:" + growthExample(5) + "x")
    app.addLabel("8BossGrowth", "8 bosses:" + growthExample(8) + "x")
    app.addLabel("10BossGrowth", "10 bosses:" + growthExample(10) + "x")
    app.addLabel("13BossGrowth", "13 bosses:" + growthExample(13) + "x")
    app.stopLabelFrame()
    app.setSticky("ew")
    app.startFrame("pacingCheckBoxes",3,0,5)
    app.setSticky("nw")
    app.addNamedCheckBox("Additional Intercept Rewards", "intRewards",1,0)
    app.setCheckBox("intRewards", ticked=True)
    app.addNamedCheckBox("Battle Logic", "battleLogic",1,1)
    app.setCheckBox("battleLogic", ticked=True)
    app.addNamedCheckBox("Progressive Super Weapons", "superWeapons",1,2)
    app.setCheckBox("superWeapons", ticked=True)
    app.addNamedCheckBox("Octus Paths Opened", "openPaths",2,0)
    app.setCheckBox("openPaths", ticked=True)
    app.addNamedCheckBox("Extra Flames Stones", "exFlameStones",2,1)
    app.setCheckBox("exFlameStones", ticked=True)
    app.addNamedCheckBox("Recipes Come w\ Ingredients", "extraIngredients",2,2)
    app.setCheckBox("extraIngredients", ticked=True)
    app.stopFrame()
    app.stopLabelFrame()

    app.startLabelFrame("Final Boss Settings",7,0)
    app.setSticky("ew")
    app.addLabelOptionBox("Final Boss: ", ["Theos de Endogram","Origin of Life","Both"])
    app.setOptionBoxChangeFunction("Final Boss: ", finalBossChange)
    app.addLabelOptionBox("Theos Start Phase: ", ['First','Second','Final'],1,0)
    app.addLabelOptionBox("Origin Care Package: ", ['Generous','Lite','None'],0,1)
    app.addLabelOptionBox("Origin Start Phase: ", ['First','Final'],1,1)
    app.setOptionBoxState("Origin Care Package: ","disabled")
    app.setOptionBoxState("Origin Start Phase: ","disabled")
    app.setOptionBoxState("Theos Start Phase: ","active")
    app.stopLabelFrame()

    app.startLabelFrame("Misc Settings", 8, 0)
    app.setSticky("ew")
    app.addNamedCheckBox("Shuffle BGM", "shuffleBGM", 0, 1)
    app.setCheckBox("shuffleBGM", ticked=False)
    app.addNamedCheckBox("Essence Key Sanity", "essenceKeySanity", 0, 2)
    app.setCheckBox("essenceKeySanity", ticked=False)
    app.addNamedCheckBox("Hints", "hints", 0, 3)
    app.setCheckBox("hints", ticked=False)
    app.stopLabelFrame()

    app.startFrame("commands",9,0)
    app.setSticky("ew")
    app.addButtons(['Patch Files', 'Generate Seed'], [buttons, buttons],0,0)
    app.stopFrame()

    app.setFastStop(True)
    app.setStopFunction(close)
    app.go()
    
