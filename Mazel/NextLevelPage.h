//
//  NextLevelPage.h
//  Mazel
//	A simple screen indicating the user to the next level
//
//  Created by Muhd Mirza on 13/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__NextLevelPage__
#define __Mazel__NextLevelPage__

#include <iostream>

#include "GameState.h"

using namespace std;

class NextLevelPage: public GameState {
	public:
		NextLevelPage();
		
		void setup();
		void setupObjects();
		void setupTextures();
		
		void run();
		
		void event();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		Gui _guiObject;
		Gui *_gui;
};

#endif /* defined(__Mazel__NextLevelPage__) */
