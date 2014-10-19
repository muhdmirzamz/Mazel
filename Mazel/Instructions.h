//
//  InstructionsPage.h
//  Mazel
//	An instructions page for basic controls
//
//  Created by Muhd Mirza on 12/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__InstructionsPage__
#define __Mazel__InstructionsPage__

#include <iostream>

#include "GameState.h"

using namespace std;

class Instructions: public GameState {
	public:
		Instructions();
		
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

#endif /* defined(__Mazel__InstructionsPage__) */
