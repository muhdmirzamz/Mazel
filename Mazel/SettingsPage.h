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

class SettingsPage: public GameState {
	public:
		SettingsPage();
	
		void setup();
		void setupObjects();
		void setupTextures();
		
		void run();
		
		void event();
		int getDifficulty();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		Background _backgroundObject;
		Background *_background;
	
		Gui _difficultyObject;
		Gui *_difficulty;
	
		Gui _easyDifficultyObject;
		Gui *_easyDifficulty;
	
		Gui _difficultDifficultyObject;
		Gui *_difficultDifficulty;
		
		Gui _hardDifficultyObject;
		Gui *_hardDifficulty;
	
		Gui _backButtonObject;
		Gui *_backButton;
};

#endif /* defined(__Mazel__SettingsPage__) */
