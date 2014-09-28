//
//  MainMenu.h
//  Mazel
//	Game Main Menu
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__MainMenu__
#define __Mazel__MainMenu__

#include <iostream>

#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
	
		void setup();
		void setupObjects();
		void setupTextures();
		void setupBall();
		
		void run();
		
		void event();
		void checkCollision();
		
		void update();
		void render();
		
		void cleanup();
		
	private:
		Background _backgroundObject;
		Background *_background;
		
		Background _grassObject;
		Background *_grass;
		
		Gui _logoObject;
		Gui *_logo;
		
		Gui _startObject;
		Gui *_start;
		
		Gui _instructionsObject;
		Gui *_instructions;
		
		Ball ballObject;
		Ball *_ball;
};

#endif /* defined(__Mazel__MainMenu__) */
