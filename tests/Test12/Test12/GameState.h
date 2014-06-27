//
//  GameState.h
//  Test12
//	Every single level class inherits from this class
//	This class forms the base for every level class
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test12__GameState__
#define __Test12__GameState__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
		
		// set return type as bool to do if statement in different classes
		// for error messages
		virtual SDL_Window* setupWindow(string level, string comp);
		virtual SDL_Renderer* setupRenderer(SDL_Window *window, string level, string comp);
		virtual void setRunning(bool running);
		
		// make this an abstract class, not completely
		// every class inherits these functions except changeState(int state)
		virtual void run() = 0;
		virtual void event() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void cleanup() = 0;
		
		// these need not be virtual
		// need to use this through at least a pointer
		// so that you do not have to retype all these in different classes
		void changeState(int state);
		
	private:
		SDL_Window *_window;
		SDL_Renderer *_renderer;
};

#endif /* defined(__Test12__GameState__) */
