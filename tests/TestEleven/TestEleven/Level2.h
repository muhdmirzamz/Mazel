//
//  Level2.h
//  TestEleven
//
//  Created by Muhd Mirza on 25/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__Level2__
#define __TestEleven__Level2__

#include <iostream>

#include "GameState.h"
#include "RenderObject.h"

using namespace std;

class Level2: public GameState {
	public:
		Level2();
		
		void run();
		void event();
		void update();
		void render();
		void cleanUp();
		
	private:
		int _windowWidth;
		int _windowHeight;
		
		GameState *_gameState;
		
		SDL_Renderer *_renderer;
		SDL_Window *_window;
		SDL_Event _event;
		
		bool _running;
		
		RenderObject *_renderObject;
};

#endif /* defined(__TestEleven__Level2__) */
