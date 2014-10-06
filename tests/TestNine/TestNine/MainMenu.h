//
//  MainMenu.h
//  TestNine
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestNine__MainMenu__
#define __TestNine__MainMenu__

#include <iostream>

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
		int _windowWidth;
		int _windowHeight;
	
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
};

#endif /* defined(__TestNine__MainMenu__) */
