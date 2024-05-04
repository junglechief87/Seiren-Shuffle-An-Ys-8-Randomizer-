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
        parameters.getGoal(app.getOptionBox("goal"),app.getScale("goalCount"))
        parameters.getShuffleLocations(app.getCheckBox("party"),app.getCheckBox("crew"),app.getCheckBox("skills"))
        parameters.getProgressionMods(app.getOptionBox("Jewel Trade Items: "),app.getOptionBox("Fish Trades: "),app.getOptionBox("Discoveries: "),app.getOptionBox("Map Completion: "),app.getOptionBox("Food Trades: "),app.getCheckBox("dogiIntercept"))
        parameters.getIntRewards(app.getCheckBox("intRewards"))
        parameters.getBattleLogic(app.getCheckBox("battleLogic"))
        parameters.getProgressiveSuperWeapons(app.getCheckBox("superWeapons"))
        parameters.getExpMult(float(app.getScale("XP Multiplier: ")))
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
        app.setCheckBox("superWeapons", ticked=True)
        app.setCheckBoxState("superWeapons","active")
    elif app.getOptionBox("goal") == "Seiren Escape":
        app.setScaleState("goalCount","disabled")
        app.setScaleRange("goalCount",0,0,0)
        app.setCheckBox("superWeapons", ticked=False)
        app.setCheckBoxState("superWeapons","disabled")

def close():
    return app.yesNoBox("Exit", "Close Application?")

with gui('Seiren Shuffle (An Ys 8 Rando)', '625x500',font = {'size':12}) as app:
    #The top versoin of the icon call is used for running the randomizer from source, the bottom version of the loop is for the executable compile, comment and uncomment accordingly.
    app.setIcon(os.path.dirname(os.path.realpath(__file__)) + "/shared/ysR Logo.ico") 
    #app.setIcon(os.path.dirname(os.path.realpath(sys.executable)) + "/shared/ysR Logo.ico")     
    app.setGuiPadding(10,10)
    app.startFrame("Seed",0)
    app.setSticky("n")
    app.addLabelNumericEntry("Seed#: ",0,0)
    app.setEntry("Seed#: ",parameters.seed)
    app.setSticky("n")
    app.addButton("New Seed", buttons,0,1)
    app.stopFrame()

    app.startLabelFrame("Selection Sphere Access: ",1,0,0)
    app.setSticky("ew")
    app.addOptionBox("goal", ["Find Crew", "Seiren Escape"],1,1,0)
    app.addScale("goalCount",1,2,3)
    app.setScaleIncrement("goalCount",1)
    app.showScaleValue("goalCount",True)
    app.showScaleIntervals("goalCount",5)
    app.setScaleLength("goalCount", 10)
    app.setScaleRange("goalCount",1,28,24)
    app.setOptionBoxChangeFunction("goal", goalChange)
    app.stopLabelFrame()

    app.startLabelFrame("Shuffle Locations",2,0,0)
    app.setSticky("ew")
    app.addNamedCheckBox("Shuffle Castaways", "crew",1,1)
    app.setCheckBox("crew", ticked=True)
    app.addNamedCheckBox("Shuffle Party", "party",1,2)
    app.setCheckBox("party", ticked=True)
    app.addNamedCheckBox("Boss Skill Bonuses", "skills",1,3)
    app.setCheckBox("skills", ticked=False)
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
    app.setOptionBox("Map Completion: ", "60%")
    app.addLabelOptionBox("Discoveries: ", ["None","Half(12)","All(24)"],2,1)
    app.setOptionBox("Discoveries: ", "All(24)")
    app.addNamedCheckBox("Dogi Intercept Rewards", "dogiIntercept",1,3)
    app.setCheckBox("dogiIntercept", ticked=True)
    app.stopFrame()
    app.stopLabelFrame()
    
    app.startLabelFrame("Other Modifiers",5,0)
    app.setSticky("ew")
    app.addLabelScale("XP Multiplier: ",1,0,3)
    app.setScaleIncrement("XP Multiplier: ",1)
    app.showScaleValue("XP Multiplier: ",True)
    app.showScaleIntervals("XP Multiplier: ",5)
    app.setScaleLength("XP Multiplier: ", 10)
    app.setScaleRange("XP Multiplier: ",0,10,3) 
    app.addNamedCheckBox("Additional Intercept Rewards", "intRewards",3,0)
    app.setCheckBox("intRewards", ticked=True)
    app.addNamedCheckBox("Battle Logic", "battleLogic",3,1)
    app.setCheckBox("battleLogic", ticked=True)
    app.addNamedCheckBox("Progressive Super Weapons", "superWeapons",3,3)
    app.setCheckBox("superWeapons", ticked=True)
    app.stopLabelFrame()

    app.startFrame("commands",6,0)
    app.setSticky("ew")
    app.addButtons(['Patch Files', 'Generate Seed'], [buttons, buttons],0,0)
    app.stopFrame()

    app.setFastStop(True)
    app.setStopFunction(close)
    app.go()
    
