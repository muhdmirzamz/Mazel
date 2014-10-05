//
//  LevelTwo.h
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__LevelTwo__
#define __TestTen__LevelTwo__

#include <iostream>

#include "GameState.h"

using namespace std;

class LevelTwo: public GameState {
	public:
		LevelTwo();
	
		void run();
		void event();
		void update();
		void render();
		void cleanUp();
		
		void renderBackground();
	
	private:
		int _windowWidth;
		int _windowHeight;
		
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		GameState *_gameState;
};

#endif /* defined(__TestTen__LevelTwo__) */
