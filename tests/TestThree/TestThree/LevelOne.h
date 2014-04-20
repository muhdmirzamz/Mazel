//
//  LevelOne.h
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestThree__LevelOne__
#define __TestThree__LevelOne__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "GameState.h"

using namespace std;

class LevelOne: public GameState {
	public:
		LevelOne();
		~LevelOne();
		
		void run();
		
		void events();
		void update();
		void render();
	
	private:
		bool running;
	
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Event event;
};

#endif /* defined(__TestThree__LevelOne__) */
