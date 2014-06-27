//
//  MainMenu.h
//  Test12
//	Main Menu page
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test12__MainMenu__
#define __Test12__MainMenu__

#include <iostream>

// got to find a way to make including these files more efficient
// done 
#include "GameState.h"
#include "RenderObject.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void run();
		void event();
		void update();
		void render();
		void cleanup();
		
	private:
		GameState *_gameState;
		
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		RenderObject *_renderObject;
};

#endif /* defined(__Test12__MainMenu__) */
