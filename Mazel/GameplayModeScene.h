//
//  GameplayModeScene.h
//  Mazel
//
//  Created by Muhd Mirza on 14/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameplayModeScene__
#define __Mazel__GameplayModeScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class GameplayModeScene: public GameState {
	public:
		GameplayModeScene();
	
		void setup();
		void setupObjects();
		void setupTextures();
		
		void run();
		
		void event();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		Background _backgroundObject;
		Background *_background;
	
		Gui _practiceModeObject;
		Gui *_practiceMode;
	
		Gui _levelModeObject;
		Gui *_levelMode;
	
		Gui _survivalModeObject;
		Gui *_survivalMode;
	
		Gui _backButtonObject;
		Gui *_backButton;
};

#endif /* defined(__Mazel__GameplayModeScene__) */
