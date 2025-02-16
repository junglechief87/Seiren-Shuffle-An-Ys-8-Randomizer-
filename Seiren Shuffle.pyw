import customtkinter as ctk
from tkinter import messagebox, filedialog
import random
import os.path
import shared.classr as classr
from randomizer.rngPatcher import *
from patch.chestPatcher import *
from patch.miscPatches import *
import json
import time
import threading

# Set appearance mode and color theme
ctk.set_appearance_mode("System")  # Can be System, Dark, Light
ctk.set_default_color_theme("blue")
FRAME_TITLE_STYLE = {
    "text_color": "#D3D3D3",
    "font": ("Segoe UI", 14, "bold"), 
    "anchor": "w",
}

SETTINGS_FILE = "seirenShuffleSettings.json"

class SeedFrame(ctk.CTkFrame):
  def __init__(self, master, ):
    super().__init__(master)
    self.grid_columnconfigure(0, weight=1)
    self.seed_var = ctk.StringVar(value=str(int(random.random()*pow(10,16))))

    # Configure grid columns to distribute space equally
    self.grid_columnconfigure(( 1, 2, 3, 4), weight=1)  # Spread out evenly

    # Frame's Title
    self.title = ctk.CTkLabel(self, text="Seed", **FRAME_TITLE_STYLE)
    self.title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w")

    # Seed Entry Frame (to group label & entry together)
    self.seed_entry_frame = ctk.CTkFrame(self, fg_color="transparent")
    self.seed_entry_frame.grid(row=1, column=0, padx=0, pady=0, sticky="w")  # Centered in column 1

    # Seed Entry
    self.seed_entry_label = ctk.CTkLabel(self.seed_entry_frame, text="Seed#: ")
    self.seed_entry_label.grid(row=0, column=0, padx=5, pady=5)

    self.seed_entry = ctk.CTkEntry(self.seed_entry_frame, textvariable=self.seed_var , validate="key", validatecommand=(self.register(self.validate_seed_input), "%P"))
    self.seed_entry.grid(row=0, column=1, padx=5, pady=5)

    # Buttons
    self.new_seed_button = ctk.CTkButton(self, text="New Seed", command=self.newSeedCallback)
    self.new_seed_button.grid(row=1, column=2, padx=5, pady=5)

    self.import_seed_button = ctk.CTkButton(self, text="Import Seed", command=self.importSeedCallback)
    self.import_seed_button.grid(row=1, column=3, padx=5, pady=5)

  def validate_seed_input(self, value):
    """Allow only numbers in the seed entry."""
    return (value.isdigit() and int(value) < pow(10,16)) or value == ''

  def newSeedCallback(self):
    new_seed = int(random.random()*pow(10,16))
    self.seed_var.set((new_seed))

  def importSeedCallback(self):
    file_path = filedialog.askopenfilename(
      title="Select Seed File",
      filetypes=(("Text Files", "*.csv;*.txt"), ("All Files", "*.*")),
      initialdir=os.getcwd()
    )
    if file_path:
      self.master.importSeed(file_path)

class ModeFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=0)
        self.grid_columnconfigure(1, weight=1)
        # Frame's Title
        self.title = ctk.CTkLabel(self, text="Character Mode", **FRAME_TITLE_STYLE)
        self.title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w", columnspan=2)

        # Mode Label and OptionBox
        self.mode_label = ctk.CTkLabel(self, text="Mode: ")
        self.mode_label.grid(row=1, column=0, padx=5, pady=(5, 0), sticky="w")

        self.character_mode = ctk.StringVar(value="Standard")  # Default value
        self.option_menu = ctk.CTkOptionMenu(self, variable=self.character_mode, values=["Standard", "Past Dana"], command=self.charModeChange)
        self.option_menu.grid(row=1, column=1, padx=5, pady=5, sticky="w")
        

    def charModeChange(self, choice):
        self.master.handle_char_mode_change(choice)

class SelectionSphereFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=1)
        
        # Frame's Title
        self.title = ctk.CTkLabel(self, text="Selection Sphere Access", **FRAME_TITLE_STYLE)
        self.title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w")

        # Goal Option Menu
        self.goal_label = ctk.CTkLabel(self, text="Mode: ")
        self.goal_label.grid(row=1, column=0, padx=5, pady=5, sticky="w")

        self.goal_var = ctk.StringVar(value="Release the Psyches")
        self.goal_option_menu = ctk.CTkOptionMenu(self, variable=self.goal_var,
                                                  values=["Release the Psyches", "Seiren Escape", "Find Crew"], 
                                                  command=self.goalChange)
        self.goal_option_menu.grid(row=1, column=1, padx=5, pady=5, sticky="ew")

        # Goal Count Scale
        self.goal_count_scale = ctk.CTkSlider(self, from_=1, to=4, number_of_steps=3, command=self.updateGoalCount,width=300)
        self.goal_count_scale.set(4)
        self.goal_count_scale.grid(row=2, column=1, padx=5, pady=5, sticky="ew")

        self.goal_count_label = ctk.CTkLabel(self, text="Goal count: ")
        self.goal_count_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")

        # Goal Count Value Label (For displaying the value next to the slider)
        self.goal_count_value_label = ctk.CTkLabel(self, text="4")
        self.goal_count_value_label.grid(row=2, column=2, padx=5, pady=5, sticky="w")

        # Octus Number Scale
        self.octus_num_label = ctk.CTkLabel(self, text="Goal count to open Octus: ")
        self.octus_num_label.grid(row=3, column=0, padx=5, pady=5, sticky="w")

        self.octus_num_scale = ctk.CTkSlider(self, from_=0, to=4, number_of_steps=3, command=self.updateOctusNum,width=300)
        self.octus_num_scale.set(2)
        self.octus_num_scale.grid(row=3, column=1, padx=5, pady=5, sticky="ew")

        # Octus Number Value Label (For displaying the value next to the slider)
        self.octus_num_value_label = ctk.CTkLabel(self, text="2")
        self.octus_num_value_label.grid(row=3, column=2, padx=5, pady=5, sticky="w")

        # Call goalChange once to initialize the GUI
        self.goalChange(self.goal_var.get())

    def goalChange(self, choice):
        """ Update sliders and their ranges based on selected goal """
        if choice == "Release the Psyches":
            # Enable both sliders and set range from 1 to 4
            self.set_slider_range(self.goal_count_scale, 1, 4)
            self.set_slider_range(self.octus_num_scale, 1, 4)
            self.numbersOfSteps = 3  # Number of steps = range - 1
            self.show_sliders(True)

            # Set sliders to pre-determined values
            self.goal_count_scale.set(4)
            self.octus_num_scale.set(2)

            # Update the number labels
            self.goal_count_value_label.configure(text="4")
            self.octus_num_value_label.configure(text="2")

        elif choice == "Find Crew":
            # Enable both sliders and set range from 1 to 28
            self.set_slider_range(self.goal_count_scale, 1, 28)
            self.set_slider_range(self.octus_num_scale, 1, 28)
            self.numbersOfSteps = 27  # Number of steps = range - 1
            self.show_sliders(True)

            # Set sliders to pre-determined values
            self.goal_count_scale.set(24)
            self.octus_num_scale.set(18)

            # Update the number labels
            self.goal_count_value_label.configure(text="24")
            self.octus_num_value_label.configure(text="18")

        elif choice == "Seiren Escape":
            # Disable both sliders and hide them, as well as value labels
            self.show_sliders(False)

    def set_slider_range(self, slider, start, end):
        # Set the range of the slider
        slider.configure(from_=start, to=end)
        slider.configure(number_of_steps=end - start)

    def show_sliders(self, show):
        """ Show or hide both sliders and their value labels """
        if show:
            self.goal_count_scale.grid()
            self.octus_num_scale.grid()
            self.octus_num_label.grid()
            self.goal_count_label.grid()
            self.goal_count_value_label.grid()
            self.octus_num_value_label.grid()
        else:
            self.goal_count_scale.grid_remove()
            self.octus_num_scale.grid_remove()
            self.octus_num_label.grid_remove()
            self.goal_count_label.grid_remove()
            self.goal_count_value_label.grid_remove()
            self.octus_num_value_label.grid_remove()

    def updateGoalCount(self, value):
        """ Update goal count and its label """
        #print(f"Goal count updated to: {value}")
        self.goal_count_value_label.configure(text=str(int(float(value))))

    def updateOctusNum(self, value):
        """ Update octus number and its label """
        #print(f"Octus number updated to: {value}")
        self.octus_num_value_label.configure(text=str(int(float(value))))

class ShuffleLocationsFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=1)

        # Frame's Title
        self.title = ctk.CTkLabel(self, text="Shuffle locations", **FRAME_TITLE_STYLE)
        self.title.grid(row=0, column=0, padx=5, pady=5, sticky="w")

        # Shuffle Castaways Checkbox
        self.crew_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.crew_checkbox = ctk.CTkCheckBox(self, text="Shuffle Castaways", variable=self.crew_var)
        self.crew_checkbox.grid(row=1, column=0, padx=5, pady=5, sticky="w")

        # Shuffle Party Checkbox
        self.party_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.party_checkbox = ctk.CTkCheckBox(self, text="Shuffle Party", variable=self.party_var)
        self.party_checkbox.grid(row=1, column=1, padx=5, pady=5, sticky="w")

        # Skills w/ Boss Bonuses Checkbox
        self.skills_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.skills_checkbox = ctk.CTkCheckBox(self, text="Skills w/ Boss Bonuses", variable=self.skills_var)
        self.skills_checkbox.grid(row=1, column=2, padx=5, pady=5, sticky="w")

        # Dogi Intercept Rewards Checkbox
        self.dogi_intercept_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.dogi_intercept_checkbox = ctk.CTkCheckBox(self, text="Dogi Intercept Rewards", variable=self.dogi_intercept_var)
        self.dogi_intercept_checkbox.grid(row=2, column=0, padx=5, pady=5, sticky="w")

        # Master Kong Rewards Checkbox
        self.mk_rewards_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.mk_rewards_checkbox = ctk.CTkCheckBox(self, text="Master Kong Rewards", variable=self.mk_rewards_var)
        self.mk_rewards_checkbox.grid(row=2, column=1, padx=5, pady=5, sticky="w")

        # Silvia Checkbox
        self.silvia_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.silvia_checkbox = ctk.CTkCheckBox(self, text="Silvia", variable=self.silvia_var)
        self.silvia_checkbox.grid(row=2, column=2, padx=5, pady=5, sticky="w")

        # Mephorash Checkbox
        self.mephorash_var = ctk.BooleanVar(value=True)  # Default to True (checked)
        self.mephorash_checkbox = ctk.CTkCheckBox(self, text="Mephorash", variable=self.mephorash_var)
        self.mephorash_checkbox.grid(row=3, column=0, padx=5, pady=5, sticky="w")

        # Former Sanctuary Crypt Checkbox
        self.former_sanctuary_crypt_var = ctk.BooleanVar(value=False)  # Default to False (unchecked)
        self.former_sanctuary_crypt_checkbox = ctk.CTkCheckBox(self, text="Former Sanctuary Crypt", variable=self.former_sanctuary_crypt_var)
        self.former_sanctuary_crypt_checkbox.grid(row=3, column=1, padx=5, pady=5, sticky="w")

class ProgressionPlacementModifiersFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=1)

        # Frame's Title
        self.title = ctk.CTkLabel(self, text="Progression Placement Modifiers", **FRAME_TITLE_STYLE)
        self.title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w")

        # Jewel Trade Items
        self.jewel_trade_label = ctk.CTkLabel(self, text="Jewel Trade Items: ")
        self.jewel_trade_label.grid(row=1, column=0, padx=5, pady=5, sticky="w")
        
        self.jewel_trade_option_menu = ctk.CTkOptionMenu(self, values=[
            "None", "Jewel Trades Costing 1", "Jewel Trades Costing <= 2", 
            "Jewel Trades Costing <= 3", "Jewel Trades Costing <= 10", "All"
        ])
        self.jewel_trade_option_menu.set("Jewel Trades Costing <= 10")
        self.jewel_trade_option_menu.grid(row=1, column=1, padx=5, pady=5, sticky="ew", columnspan=3)

        # Fish Trades
        self.fish_trade_label = ctk.CTkLabel(self, text="Fish Trades: ")
        self.fish_trade_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")
        
        self.fish_trade_option_menu = ctk.CTkOptionMenu(self, values=["None", "1", "2", "3", "4", "5", "6"])
        self.fish_trade_option_menu.set("6")
        self.fish_trade_option_menu.grid(row=2, column=1, padx=5, pady=5, sticky="ew")

        # Food Trades
        self.food_trade_label = ctk.CTkLabel(self, text="Food Trades: ")
        self.food_trade_label.grid(row=3, column=0, padx=5, pady=5, sticky="w")
        
        self.food_trade_option_menu = ctk.CTkOptionMenu(self, values=["None", "1", "2", "3", "4", "5", "6"])
        self.food_trade_option_menu.set("6")
        self.food_trade_option_menu.grid(row=3, column=1, padx=5, pady=5, sticky="ew")

        # Map Completion
        self.map_completion_label = ctk.CTkLabel(self, text="Map Completion: ")
        self.map_completion_label.grid(row=2, column=2, padx=5, pady=5, sticky="w")
        
        self.map_completion_option_menu = ctk.CTkOptionMenu(self, values=["None", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%"])
        self.map_completion_option_menu.set("70%")
        self.map_completion_option_menu.grid(row=2, column=3, padx=5, pady=5, sticky="ew")

        # Discoveries
        self.discoveries_label = ctk.CTkLabel(self, text="Discoveries: ")
        self.discoveries_label.grid(row=3, column=2, padx=5, pady=5, sticky="w")
        
        self.discoveries_option_menu = ctk.CTkOptionMenu(self, values=["None", "Half(12)", "All(24)"])
        self.discoveries_option_menu.set("All(24)")
        self.discoveries_option_menu.grid(row=3, column=3, padx=5, pady=5, sticky="ew")

class PacingModifiersFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=1)
        
        # Frame's Title
        self.title = ctk.CTkLabel(self, text="Pacing Modifiers", **FRAME_TITLE_STYLE)
        self.title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w")

        # Experience Multiplier (Slider)
        self.experience_multiplier_label = ctk.CTkLabel(self, text="Experience Multiplier: ")
        self.experience_multiplier_label.grid(row=1, column=0, padx=5, pady=5, sticky="nw", )
        
        self.experience_multiplier_scale = ctk.CTkSlider(self)
        self.experience_multiplier_scale.grid(row=1, column=1, padx=5, pady=5, sticky="ew", columnspan=3)
        self.experience_multiplier_scale.configure(from_=0, to=10, number_of_steps=10, command=self.update_experience_multiplier)
        self.experience_multiplier_scale.set(4)

        self.experience_multiplier_value = ctk.CTkLabel(self, text="4", width=25)
        self.experience_multiplier_value.grid(row=1, column=4, padx=(0, 5), pady=5, sticky="w")
        
        # Exp Mult Growth Rate (Slider)
        self.exp_mult_growth_rate_label = ctk.CTkLabel(self, text="Exp Mult Growth Rate (%): ")
        self.exp_mult_growth_rate_label.grid(row=2, column=0, padx=5, pady=5, sticky="nw")
        
        self.exp_mult_growth_rate_scale = ctk.CTkSlider(self)
        self.exp_mult_growth_rate_scale.grid(row=2, column=1, padx=5, pady=5, sticky="ew", columnspan=3)
        self.exp_mult_growth_rate_scale.configure(from_=0, to=10, number_of_steps=10, command=self.update_exp_mult_growth_rate)
        self.exp_mult_growth_rate_scale.set(3)

        self.exp_mult_growth_rate_value = ctk.CTkLabel(self, text="3", width=25) 
        self.exp_mult_growth_rate_value.grid(row=2, column=4, padx=(0, 5), pady=5, sticky="w")


        # Example of the exp growth
        self.title = ctk.CTkLabel(self, text="Examples", fg_color="transparent")
        self.title.grid(row=0, column=5, padx=(5,5), pady=(5, 0))

        self.example_2_boss_label = ctk.CTkLabel(self, text="2 bosses: " + self.growthExample(2) + "x")
        self.example_2_boss_label.grid(row=1, column=5, padx=(5,5), )
        
        self.example_3_boss_label = ctk.CTkLabel(self, text="3 bosses: " + self.growthExample(3) + "x")
        self.example_3_boss_label.grid(row=2, column=5, padx=(5,5), )
        
        self.example_5_boss_label = ctk.CTkLabel(self, text="5 bosses: " + self.growthExample(5) + "x")
        self.example_5_boss_label.grid(row=3, column=5, padx=(5,5), )

        self.example_8_boss_label = ctk.CTkLabel(self, text="8 bosses: " + self.growthExample(8) + "x")
        self.example_8_boss_label.grid(row=4, column=5, padx=(5,5), )

        self.update_examples()
    

        # Additional Intercept Rewards Checkbox
        self.int_rewards_var = ctk.BooleanVar(value=True)
        self.int_rewards_checkbox = ctk.CTkCheckBox(self, text="Additional Intercept Rewards", variable=self.int_rewards_var)
        self.int_rewards_checkbox.grid(row=3, column=0, padx=5, pady=5, sticky="w")

        # Battle Logic Checkbox
        self.battle_logic_var = ctk.BooleanVar(value=True)
        self.battle_logic_checkbox = ctk.CTkCheckBox(self, text="Battle Logic", variable=self.battle_logic_var)
        self.battle_logic_checkbox.grid(row=3, column=1, padx=5, pady=5, sticky="w")

        # Progressive Super Weapons Checkbox
        self.super_weapons_var = ctk.BooleanVar(value=True)
        self.super_weapons_checkbox = ctk.CTkCheckBox(self, text="Progressive Super Weapons", variable=self.super_weapons_var)
        self.super_weapons_checkbox.grid(row=3, column=2, padx=5, pady=5, sticky="w")

        # Octus Paths Opened Checkbox
        self.open_paths_var = ctk.BooleanVar(value=True)
        self.open_paths_checkbox = ctk.CTkCheckBox(self, text="Octus Paths Opened", variable=self.open_paths_var)
        self.open_paths_checkbox.grid(row=4, column=0, padx=5, pady=5, sticky="w")

        # Extra Flames Stones Checkbox
        self.ex_flame_stones_var = ctk.BooleanVar(value=True)
        self.ex_flame_stones_checkbox = ctk.CTkCheckBox(self, text="Extra Flames Stones", variable=self.ex_flame_stones_var)
        self.ex_flame_stones_checkbox.grid(row=4, column=1, padx=5, pady=5, sticky="w")

        # Recipes Come w/ Ingredients Checkbox
        self.extra_ingredients_var = ctk.BooleanVar(value=True)
        self.extra_ingredients_checkbox = ctk.CTkCheckBox(self, text="Recipes Come w/ Ingredients", variable=self.extra_ingredients_var)
        self.extra_ingredients_checkbox.grid(row=4, column=2, padx=5, pady=5, sticky="w")

        # North side open checkbox
        self.northsideOpen_var = ctk.BooleanVar(value=False)
        self.northsideOpen_checkbox = ctk.CTkCheckBox(self, text="North Side Open", variable=self.northsideOpen_var)
        self.northsideOpen_checkbox.grid(row=5, column=0, padx=5, pady=5, sticky="w")


    def update_examples(self):
        """ Update example labels dynamically based on the sliders' values. """
        self.example_2_boss_label.configure(text=f"2 bosses: {self.growthExample(2)}x")
        self.example_3_boss_label.configure(text=f"3 bosses: {self.growthExample(3)}x")
        self.example_5_boss_label.configure(text=f"5 bosses: {self.growthExample(5)}x")
        self.example_8_boss_label.configure(text=f"8 bosses: {self.growthExample(8)}x")

        # Update UI immediately
        self.update_idletasks()

    # Update function for Experience Multiplier
    def update_experience_multiplier(self, value):
        self.experience_multiplier_value.configure(text=f"{int(float(value))}")
        self.update_examples()

    # Update function for Exp Mult Growth Rate
    def update_exp_mult_growth_rate(self, value):
        self.exp_mult_growth_rate_value.configure(text=f"{int(float(value))}")
        self.update_examples()

    def growthExample(self, bossCount):
        baseExpMult = float(self.experience_multiplier_scale.get())
        expMultGrowth = float(self.exp_mult_growth_rate_scale.get())

        bossGrowthExample = baseExpMult * (pow((1 + expMultGrowth / 100), int(bossCount)))

        # Doing this way to fix a problem where the frame would resize to adjust the extra digit in 10.04 as opposed to 9.04 (3 digits)... sad fix but a fix nonetheless 
        return f"{bossGrowthExample:.1f}" if bossGrowthExample >= 10 else f"{bossGrowthExample:.2f}"

class FinalBossSettingsFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=1)
        
        # Frame's Title
        self.final_boss_title = ctk.CTkLabel(self, text="Final Boss Settings", **FRAME_TITLE_STYLE)
        self.final_boss_title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w")

        # Final Boss Selection
        self.final_boss_label = ctk.CTkLabel(self, text="Final Boss:")
        self.final_boss_label.grid(row=1, column=0, padx=5, pady=5, sticky="w")

        self.final_boss_option = ctk.CTkOptionMenu(
            self, 
            values=["Theos de Endogram", "Origin of Life", "Both"],
            command=self.finalBossChange,
            dynamic_resizing=False,
            width=200
        )
        self.final_boss_option.grid(row=1, column=1, padx=5, pady=5, sticky="ew")

        # Theos Start Phase
        self.theos_start_label = ctk.CTkLabel(self, text="Theos Start Phase:")
        self.theos_start_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")

        self.theos_start_option = ctk.CTkOptionMenu(self, values=["First", "Second", "Final"])
        self.theos_start_option.grid(row=2, column=1, padx=5, pady=5, sticky="ew")

        # Origin Care Package
        self.origin_care_label = ctk.CTkLabel(self, text="Origin Care Package:")
        self.origin_care_label.grid(row=3, column=0, padx=5, pady=5, sticky="w")

        self.origin_care_option = ctk.CTkOptionMenu(self, values=["Generous", "Lite", "None"])
        self.origin_care_option.grid(row=3, column=1, padx=5, pady=5, sticky="ew")
        self.origin_care_option.configure(state="disabled")

        # Origin Start Phase
        self.origin_start_label = ctk.CTkLabel(self, text="Origin Start Phase:")
        self.origin_start_label.grid(row=4, column=0, padx=5, pady=5, sticky="w")

        self.origin_start_option = ctk.CTkOptionMenu(self, values=["First", "Final"])
        self.origin_start_option.grid(row=4, column=1, padx=5, pady=5, sticky="ew")
        self.origin_start_option.configure(state="disabled")


    def finalBossChange(self, choice):
        """Update option menu states based on final boss selection"""
        if choice == "Theos de Endogram":
            self.origin_care_option.configure(state="disabled")
            self.origin_start_option.configure(state="disabled")
            self.theos_start_option.configure(state="normal")
            
        elif choice == "Origin of Life":
            self.origin_care_option.configure(state="disabled")
            self.origin_start_option.configure(state="normal")
            self.theos_start_option.configure(state="disabled")
            
        elif choice == "Both":
            self.origin_care_option.configure(state="normal")
            self.origin_start_option.configure(state="normal")
            self.theos_start_option.configure(state="normal")

        # Update UI immediately
        self.update_idletasks()

class MiscSettingsFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)
        self.grid_columnconfigure(0, weight=1)

        # Frame's Title
        self.title = ctk.CTkLabel(self, text="Misc", **FRAME_TITLE_STYLE)
        self.title.grid(row=0, column=0, padx=5, pady=(5, 0), sticky="w")

        # Shuffle BGM Checkbox
        self.shuffle_bgm_var = ctk.BooleanVar(value=False)
        self.shuffle_bgm_checkbox = ctk.CTkCheckBox(self, text="Shuffle BGM", variable=self.shuffle_bgm_var)
        self.shuffle_bgm_checkbox.grid(row=1, column=0, padx=5, pady=5, sticky="w")

        # Essence Key Sanity Checkbox
        self.essence_key_sanity_var = ctk.BooleanVar(value=False)
        self.essence_key_sanity_checkbox = ctk.CTkCheckBox(self, text="Essence Key Sanity", variable=self.essence_key_sanity_var)
        self.essence_key_sanity_checkbox.grid(row=2, column=0, padx=5, pady=5, sticky="w")

        # Create a frame to hold both widgets
        self.hints_frame = ctk.CTkFrame(self, fg_color="transparent")
        self.hints_frame.grid(row=3, column=0, sticky="w", )

        # Hints Checkbox
        self.hints_var = ctk.BooleanVar(value=False)
        self.hints_checkbox = ctk.CTkCheckBox(self.hints_frame, text="Hints", variable=self.hints_var)
        self.hints_checkbox.pack(side="left", padx=5, pady=5)

        # Customize Button
        self.customize_button = ctk.CTkButton(self.hints_frame, text="Customize Hints", command=self.open_hints_customization)
        self.customize_button.pack(side="left", padx=0, pady=5)

        # Initialize hint variables
        self.adventuring_gear_hints = ctk.IntVar(value=1)
        self.castaway_hints = ctk.IntVar(value=3)
        self.foolish_location_hints = ctk.IntVar(value=5)

    def open_hints_customization(self):
        # Create popup window
        popup = ctk.CTkToplevel(self)
        popup.title("Hints Customization")
        popup.geometry("400x250")
        popup.grab_set()  # Make popup modal

        # Configure grid layout
        popup.grid_columnconfigure(1, weight=1)

        # Adventuring Gear Hints
        ctk.CTkLabel(popup, text="Adventuring Gear Hints:").grid(row=0, column=0, padx=10, pady=5, sticky="w")
        slider1 = ctk.CTkSlider(popup, variable=self.adventuring_gear_hints, from_=0, to=7, number_of_steps=7)
        slider1.grid(row=0, column=1, padx=10, pady=5, sticky="ew")
        ctk.CTkLabel(popup, textvariable=self.adventuring_gear_hints).grid(row=0, column=2, padx=10, pady=5)

        # Castaway Hints
        ctk.CTkLabel(popup, text="Castaway Hints:").grid(row=1, column=0, padx=10, pady=5, sticky="w")
        slider2 = ctk.CTkSlider(popup, variable=self.castaway_hints, from_=0, to=7, number_of_steps=7)
        slider2.grid(row=1, column=1, padx=10, pady=5, sticky="ew")
        ctk.CTkLabel(popup, textvariable=self.castaway_hints).grid(row=1, column=2, padx=10, pady=5)

        # Foolish Location Hints
        ctk.CTkLabel(popup, text="Foolish Location Hints:").grid(row=2, column=0, padx=10, pady=5, sticky="w")
        slider3 = ctk.CTkSlider(popup, variable=self.foolish_location_hints, from_=0, to=7, number_of_steps=7)
        slider3.grid(row=2, column=1, padx=10, pady=5, sticky="ew")
        ctk.CTkLabel(popup, textvariable=self.foolish_location_hints).grid(row=2, column=2, padx=10, pady=5)

        # Close button
        ctk.CTkButton(popup, text="Close", command=popup.destroy).grid(row=3, column=0, columnspan=3, pady=10)

class CommandsFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)

        self.grid_columnconfigure((0, 1, 2), weight=1)
        self.grid_rowconfigure(0, weight=1)  # Empty space above buttons
        self.grid_rowconfigure(1, weight=0)  # Row for buttons
        self.grid_rowconfigure(2, weight=1)  # Empty space below buttons
        
        # Buttons
        self.saveSettingsButton = ctk.CTkButton(self, text="Save Settings", command=self.saveSettingsCallback)
        self.saveSettingsButton.grid(row=1, column=0, padx=5, pady=5,)

        self.patch_files_button = ctk.CTkButton(self, text="Patch Files", command=self.patchFiles)
        self.patch_files_button.grid(row=1, column=1, padx=5, pady=5,)

        self.generate_seed_button = ctk.CTkButton(self, text="Generate Seed", command=self.generateSeed)
        self.generate_seed_button.grid(row=1, column=2, padx=5, pady=5)

    def saveSettingsCallback(self):
        self.master.saveSettings()

    def patchFiles(self):
        self.master.patch_files_callback()
    
    def generateSeed(self):
        self.master.generate_seed_callback()

class App(ctk.CTk):
    def __init__(self):
        super().__init__()

        # Set window icon
        # os.path.dirname(os.path.realpath(sys.executable)) + "/shared/ysR Logo.ico"
        icon_path = "./shared/ysR Logo.ico"
        self.iconbitmap(icon_path)

        self.title('Seiren Shuffle (An Ys 8 Rando)')
        self.geometry("1200x750+0+0")
        self.grid_columnconfigure((0, 1,), weight=1)
        self.grid_rowconfigure((0, 1, 2, 3, 4), weight=1)
        
        self.seedFrame = SeedFrame(self)
        self.seedFrame.grid(row=0, column=0, padx=5, pady=5, sticky="news",)

        self.modeFrame = ModeFrame(self)
        self.modeFrame.grid(row=0, column=1, padx=5, pady=5, sticky="news")

        self.selectionsphereFrame = SelectionSphereFrame(self)
        self.selectionsphereFrame.grid(row=1, column=0, padx=5, pady=5, sticky="news")

        self.shuffleLocationsFrame = ShuffleLocationsFrame(self)
        self.shuffleLocationsFrame.grid(row=2, column=0, padx=5, pady=5, sticky="news")

        self.progressionPlacementModifiersFrame = ProgressionPlacementModifiersFrame(self)
        self.progressionPlacementModifiersFrame.grid(row=1, column=1, padx=5, pady=5, sticky="news", )

        self.pacingModifiersFrame = PacingModifiersFrame(self)
        self.pacingModifiersFrame.grid(row=2, column=1, padx=5, pady=5, sticky="news")

        self.finalBossSettingsFrame = FinalBossSettingsFrame(self)
        self.finalBossSettingsFrame.grid(row=3, column=0, padx=5, pady=5, sticky="news")

        self.miscSettingsFrame = MiscSettingsFrame(self)
        self.miscSettingsFrame.grid(row=3, column=1, padx=5, pady=5, sticky="news")

        self.commandsFrame = CommandsFrame(self)
        self.commandsFrame.grid(row=4, column=0, padx=5, pady=5, sticky="news", columnspan=2)

        #Load settings if settings file exists
        self.loadSettings()
        
    def saveSettings(self):
        try:
            """Save all current settings to a JSON file"""
            settings = {
                # Seed Frame
                "seed": self.seedFrame.seed_var.get(),
                
                # Mode Frame
                "characterMode": self.modeFrame.character_mode.get(),
                
                # Selection Sphere Frame
                "goal": self.selectionsphereFrame.goal_var.get(),
                "goalCount": int(float(self.selectionsphereFrame.goal_count_scale.get())),
                "octusNum": int(float(self.selectionsphereFrame.octus_num_scale.get())),
                
                # Shuffle Locations Frame
                "crew": self.shuffleLocationsFrame.crew_var.get(),
                "party": self.shuffleLocationsFrame.party_var.get(),
                "skills": self.shuffleLocationsFrame.skills_var.get(),
                "dogiIntercept": self.shuffleLocationsFrame.dogi_intercept_var.get(),
                "mkRewards": self.shuffleLocationsFrame.mk_rewards_var.get(),
                "silvia": self.shuffleLocationsFrame.silvia_var.get(),
                "mephorash": self.shuffleLocationsFrame.mephorash_var.get(),
                "formerSanctuaryCrypt": self.shuffleLocationsFrame.former_sanctuary_crypt_var.get(),
                
                # Progression Placement Modifiers
                "jewelTradeItems": self.progressionPlacementModifiersFrame.jewel_trade_option_menu.get(),
                "fishTrades": self.progressionPlacementModifiersFrame.fish_trade_option_menu.get(),
                "foodTrades": self.progressionPlacementModifiersFrame.food_trade_option_menu.get(),
                "mapCompletion": self.progressionPlacementModifiersFrame.map_completion_option_menu.get(),
                "discoveries": self.progressionPlacementModifiersFrame.discoveries_option_menu.get(),
                
                # Pacing Modifiers
                "experienceMultiplier": int(self.pacingModifiersFrame.experience_multiplier_scale.get()),
                "expMultGrowthRate": int(self.pacingModifiersFrame.exp_mult_growth_rate_scale.get()),
                "intRewards": self.pacingModifiersFrame.int_rewards_var.get(),
                "battleLogic": self.pacingModifiersFrame.battle_logic_var.get(),
                "superWeapons": self.pacingModifiersFrame.super_weapons_var.get(),
                "openPaths": self.pacingModifiersFrame.open_paths_var.get(),
                "exFlameStones": self.pacingModifiersFrame.ex_flame_stones_var.get(),
                "extraIngredients": self.pacingModifiersFrame.extra_ingredients_var.get(),
                "northsideOpen": self.pacingModifiersFrame.northsideOpen_var.get(),
                
                # Final Boss Settings
                "finalBoss": self.finalBossSettingsFrame.final_boss_option.get(),
                "theosStartPhase": self.finalBossSettingsFrame.theos_start_option.get(),
                "originCarePackage": self.finalBossSettingsFrame.origin_care_option.get(),
                "originStartPhase": self.finalBossSettingsFrame.origin_start_option.get(),
                
                # Misc Settings
                "shuffleBGM": self.miscSettingsFrame.shuffle_bgm_var.get(),
                "essenceKeySanity": self.miscSettingsFrame.essence_key_sanity_var.get(),
                "hints": self.miscSettingsFrame.hints_var.get(),
                "adventuringGearHints": self.miscSettingsFrame.adventuring_gear_hints.get(),
                "castawayHints": self.miscSettingsFrame.castaway_hints.get(),
                "foolishLocationHints": self.miscSettingsFrame.foolish_location_hints.get()
            }

            with open(SETTINGS_FILE, "w") as f:
                json.dump(settings, f, indent=4)
            self.show_notification("Settings saved successfully!")
        
        except Exception as e:
            messagebox.showerror("Error", f"Failed to save settings: {str(e)}")
    
    def loadSettings(self):
        """Load settings from JSON file if exists"""
        if not os.path.exists(SETTINGS_FILE):
            return

        try:
            with open(SETTINGS_FILE, "r") as f:
                settings = json.load(f)

            # Seed Frame
            #self.seedFrame.seed_var.set(settings.get("seed", str(int(random.random()*pow(10,16)))))

            # Mode Frame
            char_mode = settings.get("characterMode", "Standard")
            self.modeFrame.character_mode.set(char_mode)
            self.handle_char_mode_change(char_mode)

            # Selection Sphere Frame
            goal = settings.get("goal", "Release the Psyches")
            self.selectionsphereFrame.goal_var.set(goal)
            self.selectionsphereFrame.goalChange(goal)
            goal_count = settings.get("goalCount", 4)
            octus_num = settings.get("octusNum", 2)
            # Convert to float for CTkSlider
            self.selectionsphereFrame.goal_count_scale.set(float(goal_count))
            self.selectionsphereFrame.octus_num_scale.set(float(octus_num))
            # Manually update labels
            self.selectionsphereFrame.updateGoalCount(goal_count)
            self.selectionsphereFrame.updateOctusNum(octus_num)

            # Shuffle Locations Frame
            self.shuffleLocationsFrame.crew_var.set(settings.get("crew", True))
            self.shuffleLocationsFrame.party_var.set(settings.get("party", True))
            self.shuffleLocationsFrame.skills_var.set(settings.get("skills", True))
            self.shuffleLocationsFrame.dogi_intercept_var.set(settings.get("dogiIntercept", True))
            self.shuffleLocationsFrame.mk_rewards_var.set(settings.get("mkRewards", True))
            self.shuffleLocationsFrame.silvia_var.set(settings.get("silvia", True))
            self.shuffleLocationsFrame.mephorash_var.set(settings.get("mephorash", True))
            self.shuffleLocationsFrame.former_sanctuary_crypt_var.set(settings.get("formerSanctuaryCrypt", False))

            # Progression Placement Modifiers
            self.progressionPlacementModifiersFrame.jewel_trade_option_menu.set(
                settings.get("jewelTradeItems", "Jewel Trades Costing <= 10"))
            self.progressionPlacementModifiersFrame.fish_trade_option_menu.set(
                settings.get("fishTrades", "6"))
            self.progressionPlacementModifiersFrame.food_trade_option_menu.set(
                settings.get("foodTrades", "6"))
            self.progressionPlacementModifiersFrame.map_completion_option_menu.set(
                settings.get("mapCompletion", "70%"))
            self.progressionPlacementModifiersFrame.discoveries_option_menu.set(
                settings.get("discoveries", "All(24)"))

            # Pacing Modifiers
            exp_mult = settings.get("experienceMultiplier", 4)
            growth_rate = settings.get("expMultGrowthRate", 3)            
            # Convert to float and force update
            self.pacingModifiersFrame.experience_multiplier_scale.set(float(exp_mult))
            self.pacingModifiersFrame.exp_mult_growth_rate_scale.set(float(growth_rate))
            # Update labels and examples
            self.pacingModifiersFrame.update_experience_multiplier(exp_mult)
            self.pacingModifiersFrame.update_exp_mult_growth_rate(growth_rate)
            self.pacingModifiersFrame.update_examples()

            self.pacingModifiersFrame.int_rewards_var.set(settings.get("intRewards", True))
            self.pacingModifiersFrame.battle_logic_var.set(settings.get("battleLogic", True))
            self.pacingModifiersFrame.super_weapons_var.set(settings.get("superWeapons", True))
            self.pacingModifiersFrame.open_paths_var.set(settings.get("openPaths", True))
            self.pacingModifiersFrame.ex_flame_stones_var.set(settings.get("exFlameStones", True))
            self.pacingModifiersFrame.extra_ingredients_var.set(settings.get("extraIngredients", True))
            self.pacingModifiersFrame.northsideOpen_var.set(settings.get("northsideOpen", False))

            # Final Boss Settings
            final_boss = settings.get("finalBoss", "Theos de Endogram")
            self.finalBossSettingsFrame.final_boss_option.set(final_boss)
            self.finalBossSettingsFrame.theos_start_option.set(
                settings.get("theosStartPhase", "First"))
            self.finalBossSettingsFrame.origin_care_option.set(
                settings.get("originCarePackage", "Generous"))
            self.finalBossSettingsFrame.origin_start_option.set(
                settings.get("originStartPhase", "First"))
            self.finalBossSettingsFrame.finalBossChange(final_boss)

            # Misc Settings
            self.miscSettingsFrame.shuffle_bgm_var.set(settings.get("shuffleBGM", False))
            self.miscSettingsFrame.essence_key_sanity_var.set(settings.get("essenceKeySanity", False))
            self.miscSettingsFrame.hints_var.set(settings.get("hints", False))
            self.miscSettingsFrame.adventuring_gear_hints.set(
                settings.get("adventuringGearHints", 1))
            self.miscSettingsFrame.castaway_hints.set(
                settings.get("castawayHints", 3))
            self.miscSettingsFrame.foolish_location_hints.set(
                settings.get("foolishLocationHints", 5))

        except Exception as e:
            messagebox.showerror("Error", f"Failed to load settings: {str(e)}")

    def importSeed(self, file_path):
        try:
            with open(file_path, 'r') as f:
                lines = f.readlines()

            settings = {}
            current_section = None
            
            for line in lines:
                line = line.strip()
                if not line:
                    continue

                # Stop processing when we reach Locations section
                if line == "Locations:":
                    break
                
                # Handle section headers
                if line.endswith(':'):
                    current_section = line[:-1]
                    continue
                    
                # Parse key-value pairs
                if ':' in line:
                    key, value = line.split(':', 1)
                    key = key.strip()
                    value = value.strip()
                    
                    # Handle special cases
                    if key == "Seed#":
                        settings["seed"] = value
                    elif key == "Number":
                        settings["goalCount"] = value
                    elif key == "Goal count to open Octus":
                        settings["octusNum"] = value
                    else:
                        settings[key] = value
            #print(settings)
            # Map CSV keys to GUI components
            key_mapping = {
                'seed': (self.seedFrame.seed_var, 'set'),
                'Game Mode': (self.modeFrame.character_mode, 'set'),
                'Shuffle Party': (self.shuffleLocationsFrame.party_var, 'set'),
                'Shuffle Crew': (self.shuffleLocationsFrame.crew_var, 'set'),
                'Skills w/ Boss Bonuses': (self.shuffleLocationsFrame.skills_var, 'set'),
                'Jewel Trades': (self.progressionPlacementModifiersFrame.jewel_trade_option_menu, 'set'),
                'Discoveries': (self.progressionPlacementModifiersFrame.discoveries_option_menu, 'set'),
                'Map Completion': (self.progressionPlacementModifiersFrame.map_completion_option_menu, 'set'),
                'Food Trades': (self.progressionPlacementModifiersFrame.food_trade_option_menu, 'set'),
                'Fish Trades': (self.progressionPlacementModifiersFrame.fish_trade_option_menu, 'set'),
                'Dogi Intercept Rewards': (self.shuffleLocationsFrame.dogi_intercept_var, 'set'),
                'Master Kong': (self.shuffleLocationsFrame.mk_rewards_var, 'set'),
                'Silvia': (self.shuffleLocationsFrame.silvia_var, 'set'),
                'Mephorash': (self.shuffleLocationsFrame.mephorash_var, 'set'),
                'Former Sanctuary Crypt': (self.shuffleLocationsFrame.former_sanctuary_crypt_var, 'set'),
                'Additional Intercept Rewards': (self.pacingModifiersFrame.int_rewards_var, 'set'),
                'Experience Multiplier': (self.pacingModifiersFrame.experience_multiplier_scale, 'set'),
                'Exp Mult Growth Rate (%)': (self.pacingModifiersFrame.exp_mult_growth_rate_scale, 'set'),
                'Battle Logic': (self.pacingModifiersFrame.battle_logic_var, 'set'),
                'Progressive Super Weapons': (self.pacingModifiersFrame.super_weapons_var, 'set'),
                'Open Octus Paths': (self.pacingModifiersFrame.open_paths_var, 'set'),
                'Extra Flame Stones': (self.pacingModifiersFrame.ex_flame_stones_var, 'set'),
                'Recipes Come w\\ Ingredients': (self.pacingModifiersFrame.extra_ingredients_var, 'set'),
                'North Side Open': (self.pacingModifiersFrame.northsideOpen_var, 'set'),
                'Final Boss': (self.finalBossSettingsFrame.final_boss_option, 'set'),
                'Theos Start Phase': (self.finalBossSettingsFrame.theos_start_option, 'set'),
                'Origin Start Phase': (self.finalBossSettingsFrame.origin_start_option, 'set'),
                'Origin Care Package': (self.finalBossSettingsFrame.origin_care_option, 'set'),
                'BGM shuffle': (self.miscSettingsFrame.shuffle_bgm_var, 'set'),
                'Essence Key Sanity': (self.miscSettingsFrame.essence_key_sanity_var, 'set'),
                'Hints': (self.miscSettingsFrame.hints_var, 'set'),
                'Adventuring Gear Hints': (self.miscSettingsFrame.adventuring_gear_hints, 'set_int'),
                'Castaway Hints': (self.miscSettingsFrame.castaway_hints, 'set_int'),
                'Foolish Location Hints': (self.miscSettingsFrame.foolish_location_hints, 'set_int')
            }
            
            # Apply settings to GUI with type handling
            for csv_key, (gui_component, action) in key_mapping.items():
                if csv_key in settings:
                    value = settings[csv_key]
                    try:
                        if action == 'set':
                            if isinstance(gui_component, ctk.BooleanVar):
                                gui_component.set(value.lower() == "true")
                            elif isinstance(gui_component, (ctk.IntVar, ctk.StringVar)):
                                gui_component.set(value)
                            elif isinstance(gui_component, ctk.CTkOptionMenu):
                                gui_component.set(value)
                            elif isinstance(gui_component, ctk.CTkSlider):
                                gui_component.set(float(value))
                        elif action == 'set_int':
                            gui_component.set(int(value))
                    except Exception as e:
                        print(f"Error setting {csv_key}: {str(e)}")

            # Special handling for Selection Sphere Frame
            goal = settings.get("Goal", "Release the Psyches")
            goal_count = int(settings.get("goalCount", 4))
            octus_num = int(settings.get("octusNum", 2))

            # Set goal first as it affects slider ranges
            self.selectionsphereFrame.goal_var.set(goal)
            self.selectionsphereFrame.goalChange(goal)  # This updates slider ranges
            
            # Now set slider values after ranges are updated
            self.selectionsphereFrame.goal_count_scale.set(goal_count)
            self.selectionsphereFrame.octus_num_scale.set(octus_num)
            
            # Directly update the labels with the integer values
            self.selectionsphereFrame.goal_count_value_label.configure(text=str(goal_count))
            self.selectionsphereFrame.octus_num_value_label.configure(text=str(octus_num))

            # Pacing Modifiers
            exp_mult = float(settings.get("Experience Multiplier", 4))
            self.pacingModifiersFrame.experience_multiplier_scale.set(exp_mult)
            self.pacingModifiersFrame.update_experience_multiplier(exp_mult)
            
            growth_rate = float(settings.get("Exp Mult Growth Rate (%)", 3))
            self.pacingModifiersFrame.exp_mult_growth_rate_scale.set(growth_rate)
            self.pacingModifiersFrame.update_exp_mult_growth_rate(growth_rate)

            # Force UI updates
            self.selectionsphereFrame.update_idletasks()
            self.pacingModifiersFrame.update_examples()

            # Update character mode dependencies
            self.handle_char_mode_change(settings.get("Game Mode", "Standard"))

            # Update final boss dependencies
            self.finalBossSettingsFrame.finalBossChange(settings.get("Final Boss", "Theos de Endogram"))

            # Update examples in pacing modifiers
            self.pacingModifiersFrame.update_examples()

            self.show_notification("Seed imported successfully!")

        except Exception as e:
            messagebox.showerror("Import Error", f"Failed to import seed: {str(e)}")

    def handle_char_mode_change(self, mode):
        # Get references to affected components
        shuffle_frame = self.shuffleLocationsFrame
        boss_frame = self.finalBossSettingsFrame
        sphere_frame = self.selectionsphereFrame
        
        # Update skills and MK rewards checkboxes
        if mode == "Past Dana":
            shuffle_frame.skills_checkbox.configure(state="disabled")
            shuffle_frame.skills_var.set(False)
            shuffle_frame.mk_rewards_checkbox.configure(state="disabled")
            shuffle_frame.mk_rewards_var.set(False)
            shuffle_frame.party_checkbox.configure(state="disabled")
            shuffle_frame.party_var.set(True)
            
            # Disable boss options
            boss_frame.final_boss_option.configure(state="disabled")
            boss_frame.origin_care_option.configure(state="disabled")
            boss_frame.origin_start_option.configure(state="disabled")
            boss_frame.theos_start_option.configure(state="disabled")
            
            # Handle goal count scaling
            if sphere_frame.goal_var.get() == "Release the Psyches":
                sphere_frame.set_slider_range(sphere_frame.goal_count_scale, 1, 5)
                sphere_frame.goal_count_scale.set(3)
                sphere_frame.goal_count_value_label.configure(text="3")
        else:
            shuffle_frame.skills_checkbox.configure(state="normal")
            shuffle_frame.mk_rewards_checkbox.configure(state="normal")
            shuffle_frame.party_checkbox.configure(state="normal")
            # Enable boss options
            boss_frame.final_boss_option.configure(state="normal")
            boss_frame.origin_care_option.configure(state="normal" if 
                boss_frame.final_boss_option.get() == "Both" else "disabled")
            boss_frame.origin_start_option.configure(state="normal")
            boss_frame.theos_start_option.configure(state="normal")
            
            # Reset goal count scaling
            if sphere_frame.goal_var.get() == "Release the Psyches":
                sphere_frame.set_slider_range(sphere_frame.goal_count_scale, 1, 4)
                sphere_frame.goal_count_scale.set(3)
                sphere_frame.goal_count_value_label.configure(text="3")

        # Update any dependent UI components
        self.update_idletasks()
    
    def patch_files_callback(self):
        try:
            cleanChests()
            miscFixes()
            self.show_notification("Patch Complete!")
        except Exception as e:
            messagebox.showerror("Error", f"Patching failed: {str(e)}")

    def generate_seed_callback(self):
        try:
            parameters = classr.guiInput()
            # Get all parameters from GUI components
            parameters.getSeed(self.seedFrame.seed_var.get())
            
            # Selection Sphere Parameters
            parameters.getGoal(
                self.selectionsphereFrame.goal_var.get(),
                int(self.selectionsphereFrame.goal_count_scale.get()),
                int(self.selectionsphereFrame.octus_num_scale.get()),
                self.modeFrame.character_mode.get()
            )
            
            # Shuffle Locations
            parameters.getShuffleLocations(
                self.shuffleLocationsFrame.party_var.get(),
                self.shuffleLocationsFrame.crew_var.get(),
                self.shuffleLocationsFrame.skills_var.get()
            )
            
            # Progression Modifiers
            parameters.getProgressionMods(
                self.progressionPlacementModifiersFrame.jewel_trade_option_menu.get(),
                self.progressionPlacementModifiersFrame.fish_trade_option_menu.get(),
                self.progressionPlacementModifiersFrame.discoveries_option_menu.get(),
                self.progressionPlacementModifiersFrame.map_completion_option_menu.get(),
                self.progressionPlacementModifiersFrame.food_trade_option_menu.get(),
                self.shuffleLocationsFrame.dogi_intercept_var.get(),
                self.shuffleLocationsFrame.mk_rewards_var.get(),
                self.shuffleLocationsFrame.silvia_var.get(),
                self.shuffleLocationsFrame.mephorash_var.get()
            )
            
            # Other Toggles
            parameters.getOtherToggles(
                self.pacingModifiersFrame.int_rewards_var.get(),
                self.pacingModifiersFrame.battle_logic_var.get(),
                self.pacingModifiersFrame.super_weapons_var.get(),
                self.pacingModifiersFrame.open_paths_var.get(),
                self.pacingModifiersFrame.ex_flame_stones_var.get(),
                self.pacingModifiersFrame.extra_ingredients_var.get(),
                self.pacingModifiersFrame.northsideOpen_var.get(),
            )
            
            # Experience Multipliers
            parameters.getExpMult(
                float(self.pacingModifiersFrame.experience_multiplier_scale.get()),
                float(self.pacingModifiersFrame.exp_mult_growth_rate_scale.get())
            )
            
            # Final Boss Settings
            parameters.getFinalBoss(
                self.finalBossSettingsFrame.final_boss_option.get(),
                self.finalBossSettingsFrame.theos_start_option.get(),
                self.finalBossSettingsFrame.origin_start_option.get(),
                self.finalBossSettingsFrame.origin_care_option.get()
            )
            
            # Misc Settings
            parameters.getMiscSettings(
                self.miscSettingsFrame.shuffle_bgm_var.get(),
                self.miscSettingsFrame.essence_key_sanity_var.get(),
                self.shuffleLocationsFrame.former_sanctuary_crypt_var.get(),
                self.miscSettingsFrame.hints_var.get(),
                self.miscSettingsFrame.adventuring_gear_hints.get(),
                self.miscSettingsFrame.castaway_hints.get(),
                self.miscSettingsFrame.foolish_location_hints.get()
            )
            
            # Execute main patcher and save
            rngPatcherMain(parameters)
            self.show_notification("Seed Generation Complete!")
            
        except Exception as e:
            messagebox.showerror("Error", f"Seed generation failed: {str(e)}")
    
    def show_notification(self, message, color = "#90ee90"):
        """Show a temporary notification toast in the bottom-right corner"""
        toast = ctk.CTkToplevel(self)
        toast.overrideredirect(True)  # Remove window decorations
        
        # Set background color matching your theme
        toast.configure(background="transparent")
        
        # Create message label
        label = ctk.CTkLabel(toast, text=message, 
                            fg_color="transparent",
                            text_color=color,
                            font=("Arial", 14, "bold")
                            )
        label.pack(padx=20, pady=10)
    
        # Calculate position (bottom-right of main window)
        x = self.winfo_x() + self.winfo_width() - 320
        y = self.winfo_y() + self.winfo_height() - 100
        toast.geometry(f"+{x}+{y}")
        
        # Animate fade-out after 3 seconds
        toast.after(3000, lambda: self.fade_out(toast))

    def fade_out(self, toast):
        """Gradually fade out the notification"""
        alpha = 1.0
        for i in range(10):
            alpha -= 0.1
            toast.attributes("-alpha", alpha)
            toast.update()
            time.sleep(0.05)
        toast.destroy()


if __name__ == "__main__":
    app = App()
    #app.protocol("WM_DELETE_WINDOW", lambda: close(app))
    app.mainloop()