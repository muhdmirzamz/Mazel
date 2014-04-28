//
//  LevelTwo.h
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestFive__LevelTwo__
#define __TestFive__LevelTwo__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "GameState.h"

using namespace std;

class LevelTwo: public GameState {
	public:
		LevelTwo();
		
		void run();
		
		void events();
		void update();
		void render();
	
	private:
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		GameState *_gameState;
};

#endif /* defined(__TestFive__LevelTwo__) */
