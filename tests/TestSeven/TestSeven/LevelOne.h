//
//  LevelOne.h
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSeven__LevelOne__
#define __TestSeven__LevelOne__

#include <iostream>

#include "GameState.h"

using namespace std;

class LevelOne: public GameState {
public:
	LevelOne();
	
	void run();
	
	void event();
	void update();
	void render();
	void renderBackground();
	
private:
	int _windowWidth;
	int _windowHeight;

	SDL_Window *_window;
	SDL_Renderer *_renderer;
	SDL_Event _event;
	
	bool _running;
	GameState *_gameState;
};

#endif /* defined(__TestSeven__LevelOne__) */
