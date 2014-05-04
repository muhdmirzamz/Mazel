//
//  MainMenu.h
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSeven__MainMenu__
#define __TestSeven__MainMenu__

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
		void renderBackground();
		
		void freeResources();
		
	private:
		int _windowWidth;
		int _windowHeight;
	
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		GameState *_gameState;
		
		TextRender *_textRender;
};

#endif /* defined(__TestSeven__MainMenu__) */
