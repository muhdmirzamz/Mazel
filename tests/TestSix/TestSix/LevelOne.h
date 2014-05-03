//
//  LevelOne.h
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSix__LevelOne__
#define __TestSix__LevelOne__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

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
	void renderRectangle();
	
	bool checkRightCollision(SDL_Rect testRect);
	bool checkLeftCollision(SDL_Rect testRectTwo);
	
private:
	SDL_Window *_window;
	SDL_Renderer *_renderer;
	SDL_Event _event;
	
	bool _running;
	
	GameState *_gameState;
	
	SDL_Rect _rect;
	int _speed;
};

#endif /* defined(__TestSix__LevelOne__) */
