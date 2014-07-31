//
//  GameState.h
//  Mazel
//	this class forms the base of every class that represents a running
//	process, examples are levels, main menu etc
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameState__
#define __Mazel__GameState__

#include <iostream>

// include SDL video component header files
// sub classes can also inherit these files
#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"
#include "SDL_surface.h"

// error header file
#include "SDL_error.h"

// define constant window variables
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_X_POS 0
#define WINDOW_Y_POS 0

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState(); // need for polymorphism
	
		// inline function for performance since it's just error messages
		inline void printErrorMessage(string level, string component) {
			cout << level << " " << component << " failed to initialise!\n";
			cout << SDL_GetError() << endl;
		}
		
		// virtual functions to be inherited by individual sub classes
		// these two functions help to reduce boilerplate code for
		// initialising window and renderer variables
		
		// due to the nature of the function
		// there needs to be 2 variables of the same type
		// declared in each subclass due to memory issues
		virtual SDL_Window* initWindow(SDL_Window *window);
		virtual SDL_Renderer* initRenderer(SDL_Window *window2, SDL_Renderer *renderer);
		
		virtual void setup(); // use this function to increase code readability
		virtual void run(); // main game loop
		virtual void event(); // handles events
		virtual void update(); // updates game variables
		virtual void render(); // render the updated look
		virtual void cleanup(); // release allocated memory
	
	private:
};

#endif /* defined(__Mazel__GameState__) */
