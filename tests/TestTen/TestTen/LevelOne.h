//
//  LevelOne.h
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__LevelOne__
#define __TestTen__LevelOne__

#include <iostream>

#include "GameState.h"
#include "RenderObject.h"

using namespace std;

class LevelOne: public GameState {
	public:
		LevelOne();
	
		void run();
		void event();
		void update();
		void render();
		void cleanUp();
	
	private:
		int _windowWidth;
		int _windowHeight;
		
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		GameState *_gameState;
		RenderObject *_renderObject;
};
#endif /* defined(__TestTen__LevelOne__) */
