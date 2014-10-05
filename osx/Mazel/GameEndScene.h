//
//  GameEndScene.h
//  Mazel
//	Screen when the user finishes the game
//
//  Created by Muhd Mirza on 16/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameEndScene__
#define __Mazel__GameEndScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class GameEndScene: public GameState {
	public:
		GameEndScene();
		
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
		
		Gui _backgroundImageObject;
		Gui *_backgroundImage;
};

#endif /* defined(__Mazel__GameEndScene__) */
