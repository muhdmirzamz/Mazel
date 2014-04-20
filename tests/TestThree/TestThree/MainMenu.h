//
//  MainMenu.h
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestThree__MainMenu__
#define __TestThree__MainMenu__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "GameManager.h"
#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		~MainMenu();
		
		void run();
	
		void events();
		void update();
		void render();
		
	private:
		bool running;
		
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Event event;
		
		GameManager *gameManager;
};

#endif /* defined(__TestThree__MainMenu__) */
