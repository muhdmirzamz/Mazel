//
//  LevelOne.h
//  TestFour
//
//  Created by Muhd Mirza on 24/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestFour__LevelOne__
#define __TestFour__LevelOne__

#include <iostream>

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

#include "GameState.h"

class LevelOne: public GameState {
	public:
		LevelOne();
		
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

#endif /* defined(__TestFour__LevelOne__) */
