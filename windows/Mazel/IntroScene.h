//
//  IntroScene.h
//  Mazel
//	A simple intro scene before going to the main menu
//
//  Created by Muhd Mirza on 6/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__IntroScene__
#define __Mazel__IntroScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class IntroScene: public GameState {
	public:
		IntroScene();
		
		void setup();
		void setupObjects();
		void setupTextures();
		
		void run();
		
		void event();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		Background backgroundObject;
		Background *_background;
		
		Gui _introLogoObject;
		Gui *_introLogo;
		
		Gui _continueButtonObject;
		Gui *_continueButton;
};

#endif /* defined(__Mazel__IntroScene__) */
