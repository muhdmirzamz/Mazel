//
//  MainMenu.h
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestFive__MainMenu__
#define __TestFive__MainMenu__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void run();
		
		void events();
		void update();
		void render();
		
		void renderBackground();
		void drawRectangle();
		
	private:
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		GameState *_gameState;
		
		SDL_Rect _rect;
		SDL_Rect _rectTwo;
		SDL_Rect _rectThree;
		SDL_Rect _rectFour;
		SDL_Rect _rectFive;
		SDL_Rect _rectSix;
		SDL_Rect _rectSeven;
		SDL_Rect _rectEight;
		SDL_Rect _rectNine;
};

#endif /* defined(__TestFive__MainMenu__) */
