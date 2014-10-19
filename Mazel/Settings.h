//
//  SettingsPage.h
//  Mazel
//	Settings for the whole game
//
//  Created by Muhd Mirza on 8/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__SettingsPage__
#define __Mazel__SettingsPage__

#include <iostream>

#include "GameState.h"

using namespace std;

class Settings: public GameState {
	public:
		Settings();
	
		void setup();
		void setupObjects();
		void setupTextures();
		
		void run();
		
		void event();
	
		int getLives();
	
		int chosenDifficulty();
		void decrementLives();
		bool isPlayerDeadInEasyDifficulty();
		bool isPlayerDeadInDifficultDifficulty();
		bool isPlayerDeadInHardDifficulty();
	
		bool isPracticeModeEnabled();
		bool doEnemyExists();
	
		void didSelectLevelMode();
		void didSelectPracticeMode();
		void didSelectSurvivalMode();
		int selectedMode();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		Background _backgroundObject;
		Background *_background;
	
		// difficulty settings
		Gui _difficultyObject;
		Gui *_difficulty;
	
		Gui _difficultyGuideObject;
		Gui *_difficultyGuide;
	
		Gui _easyDifficultyObject;
		Gui *_easyDifficulty;
	
		Gui _difficultDifficultyObject;
		Gui *_difficultDifficulty;
		
		Gui _hardDifficultyObject;
		Gui *_hardDifficulty;
	
		// enable practice mode settings
		Gui _practiceModeToggleObject;
		Gui *_practiceModeToggle;
	
		Gui _enablePracticeModeObject;
		Gui *_enablePracticeMode;
	
		Gui _disablePracticeModeObject;
		Gui *_disablePracticeMode;
	
		// enable enemies in practice mode settings
		Gui _enableEnemyInPracticeModeObject;
		Gui *_enableEnemyInPracticeMode;
	
		Gui _enableEnemyObject;
		Gui *_enableEnemy;
	
		Gui _disableEnemyObject;
		Gui *_disableEnemy;
	
		// back button
		Gui _backButtonObject;
		Gui *_backButton;
};

#endif /* defined(__Mazel__SettingsPage__) */
