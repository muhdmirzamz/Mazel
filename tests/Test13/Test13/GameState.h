//
//  GameState.h
//  Test13
//
//  Created by Muhd Mirza on 1/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test13__GameState__
#define __Test13__GameState__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
		
		void setup(SDL_Window **window, SDL_Renderer **renderer, bool running);
		
		virtual void run() = 0;
		
		virtual void event(SDL_Event event, bool runningVar);
		virtual void update(SDL_Renderer **renderer2);
		virtual void render();
		
		void changeState(int state);
		
	private:
};

#endif /* defined(__Test13__GameState__) */
