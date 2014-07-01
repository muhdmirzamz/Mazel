//
//  MainMenu.h
//  Test13
//
//  Created by Muhd Mirza on 1/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test13__MainMenu__
#define __Test13__MainMenu__

#include <iostream>

#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
	
		void run();
		void render();
		
	private:
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
	
		bool _running;
};

#endif /* defined(__Test13__MainMenu__) */
