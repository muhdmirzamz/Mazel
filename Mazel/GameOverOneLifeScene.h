//
//  GameOverOneLifeScene.h
//  Mazel
//	class for game over scene when player chooses hard difficulty
//
//  Created by Muhd Mirza on 12/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameOverOneLifeScene__
#define __Mazel__GameOverOneLifeScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class GameOverOneLifeScene: public GameState {
	public:
		GameOverOneLifeScene();
	
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
	
		Gui _gameOverImageObject;
		Gui *_gameOverImage;
};

#endif /* defined(__Mazel__GameOverOneLifeScene__) */
