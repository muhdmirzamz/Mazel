//
//  GameOverScene.h
//  Mazel
//	A game over screen
//
//  Created by Muhd Mirza on 21/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameOverScene__
#define __Mazel__GameOverScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class GameOverScene: public GameState {
	public:
		GameOverScene();
		
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
		
		Gui _imageObject;
		Gui *_image;
};

#endif /* defined(__Mazel__GameOverScene__) */
