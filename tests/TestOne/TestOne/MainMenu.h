//
//  MainMenu.h
//  TestOne
//
//  Created by Muhd Mirza on 19/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestOne__MainMenu__
#define __TestOne__MainMenu__

#include <iostream>

#include "SDL_video.h"
#include "SDL_events.h"
#include "SDL_surface.h"

#include "GameState.h"

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void run();
		void events();
		void update();
		void render();
	
	private:
		SDL_Window *window;
		SDL_Surface *mainSurface;
		SDL_Event event;
		
		bool running;
};

#endif /* defined(__TestOne__MainMenu__) */
