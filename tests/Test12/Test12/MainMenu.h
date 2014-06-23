//
//  MainMenu.h
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test12__MainMenu__
#define __Test12__MainMenu__

#include <iostream>

// got to find a way to make including these files more efficient
#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void run();
		void event();
		void update();
		void render();
		
	private:
		SDL
};

#endif /* defined(__Test12__MainMenu__) */
