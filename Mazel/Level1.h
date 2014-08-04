//
//  Level1.h
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Level1__
#define __Mazel__Level1__

#include <iostream>

#include "GameState.h"

using namespace std;

class Level1: public GameState {
	public:
		Level1();
		
		// inherited functions to override
		void setup();
		void run();
		void event();
		void update();
		void render();
		void cleanup();
		
	private:
		SDL_Window *_window; // free
		SDL_Window *_windowRef;
		SDL_Renderer *_renderer; // free
		SDL_Renderer *_rendererRef;
		SDL_Event _event;
		
		bool _running;
		
		//SDL_Surface *_icon;
};

#endif /* defined(__Mazel__Level1__) */
