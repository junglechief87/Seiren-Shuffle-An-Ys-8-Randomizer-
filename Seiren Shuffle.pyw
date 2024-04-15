from appJar import gui
import random
import shared.classr as classr
from randomizer.rngPatcher import *
from patch.chestPatcher import *
from patch.miscPatches import *

seed=int(random.random()*pow(10,16))
parameters = classr.guiInput
parameters.getSeed(seed)
parameters.getGoal('Find Crew', 24)

def buttons(inpt):
    if inpt == 'Patch Files':
        cleanChests()
        miscFixes()
        app.okBox("Task Complete", "Patch Complete!")

    elif inpt == 'Generate Seed':
        parameters.getSeed(app.getEntry("Seed#: "))
        parameters.getGoal(app.getOptionBox("Goal: "),app.getEntry("Goal Count: "))
        parameters.getLuckyChecks('big',app.getEntry("Big Lucky Checks: "))
        parameters.getLuckyChecks('med',app.getEntry("Medium Lucky Checks: "))
        parameters.getLuckyChecks('small',app.getEntry("Small Lucky Checks: "))
        parameters.getShuffleLocations(True,app.getCheckBox("party"),app.getCheckBox("crew"))
        parameters.getProgressionMods(app.getOptionBox("Jewel Trade Items: "),app.getOptionBox("Fish Trades: "),app.getOptionBox("Discoveries: "),app.getOptionBox("Map Completion: "),app.getOptionBox("Food Trades: "),app.getCheckBox("dogiIntercept"))
        parameters.getIntRewards(app.getCheckBox("intRewards"))
        rngPatcherMain(parameters) 
        app.okBox("Task Complete", "Seed Generation Complete!")
        
    elif inpt == 'New Seed':
        seed=int(random.random()*pow(10,16))
        parameters.getSeed(seed)
        app.setEntry("Seed#: ",parameters.seed)

with gui('Seiren Shuffle (An Ys 8 Rando)', '600x500',font = {'size':12}) as app:     
    app.setGuiPadding(10,10)
    app.startFrame("Seed",0)
    app.setSticky("n")
    app.addLabelNumericEntry("Seed#: ",0,0)
    app.setEntry("Seed#: ",parameters.seed)
    app.setSticky("n")
    app.addButton("New Seed", buttons,0,1)
    app.stopFrame()

    app.startFrame("goalFrame",1,0,0)
    app.setSticky("w")
    app.addLabelOptionBox("Goal: ", ["Find Crew"],1,0,0)
    app.addLabelEntry("Goal Count: ",1,1,0)
    app.setEntry("Goal Count: ",parameters.numGoal)
    app.stopFrame()

    app.startLabelFrame("Shuffle Locations",2,0,0)
    app.addNamedCheckBox("Shuffle Castaways", "crew",1,1)
    app.setCheckBox("crew", ticked=True)
    app.addNamedCheckBox("Shuffle Party", "party",1,2)
    app.setCheckBox("party", ticked=True)
    app.stopLabelFrame()

    app.startLabelFrame("Progression Placement Modifiers")
    app.startFrame("progression placement modifiers1",3,0)
    app.setSticky("NW")
    app.stretch = "column"
    app.addLabelOptionBox("Jewel Trade Items: ", ["None","Jewel Trades Costing 1","Jewel Trades Costing <= 2","Jewel Trades Costing <= 3","Jewel Trades Costing <= 10","All"],1)
    app.setOptionBox("Jewel Trade Items: ", "All")
    app.stopFrame()
    app.startFrame("progression placement modifiers2",4,0)
    app.setSticky("NEW")
    app.stretch = "column"
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
    
    app.setSticky("nw")
    app.startLabelFrame("Speed Hacks",5,0)
    app.stretch = "column"
    app.setSticky("nw")
    app.addLabel("luckyChecks","Lucky Checks:",0)
    app.setSticky("nw")
    app.addLabelNumericEntry("Big Lucky Checks: ",1)
    app.setEntry("Big Lucky Checks: ",7)
    app.addLabelNumericEntry("Medium Lucky Checks: ",2)
    app.setEntry("Medium Lucky Checks: ",7)
    app.addLabelNumericEntry("Small Lucky Checks: ",3)
    app.setEntry("Small Lucky Checks: ",10)
    app.addNamedCheckBox("Additional Intercept Rewards: ", "intRewards",1,3)
    app.setCheckBox("intRewards", ticked=True)
    app.stopLabelFrame()

    app.startFrame("commands",6,0)
    app.setSticky("ne")
    app.addButtons(['Patch Files', 'Generate Seed'], [buttons, buttons],0,0)
    app.stopFrame()

app.go()
