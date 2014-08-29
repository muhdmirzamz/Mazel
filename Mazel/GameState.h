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

// include all files which level classes require
// level classes only need to import this class(GameState.h)
#include "Includes.h"
#include "Render.h"
#include "Collision.h"

enum GameStates {
	INTRO_SCENE,
	MAIN_MENU,
	BASIC_LEVEL, // a bunch of levels, not just one
	GAME_OVER,
	EXIT
};

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
	
		inline void printErrorMessage(string level, string component) {
			cout << level << " " << component << " failed to initialise!\n";
			cout << SDL_GetError() << endl;
		}
		
		/* virtual functions to be inherited by individual sub classes */
	
		// setup
		virtual void setup(); // use this function to increase code readability
		virtual void setupObjects(); // set up other classes objects, mostly pointers
		virtual void setupTextures(); // sets up textures
		virtual void setupBall(); // sets up ball
		virtual void setupFinishRect(); // sets up finish line
		virtual void setupObstacles(); // sets up obstacles
		
		/*
			due to the nature of the function
			there needs to be 2 variables of the same type
			declared in each subclass due to memory issues
			example: SDL_Window *window and SDL_Window *windowRef
		*/
		virtual SDL_Window* initWindow(SDL_Window *window);
		virtual SDL_Renderer* initRenderer(SDL_Window *window2, SDL_Renderer *renderer);
		virtual void setIcon(SDL_Window *window3, SDL_Surface *icon, const string filePathOfIcon);
		virtual SDL_Texture* loadImageOntoTexture(SDL_Surface *imageSurface, string filePathOfImage, SDL_Texture *imageTexture, SDL_Renderer *renderer2);
		
		// loop
		virtual void run(); // main game loop
		
		// events
		virtual void event(); // handles events
		virtual void changeState(int state); // change state
		virtual void checkCollision(); // check for collision
		
		// update and render
		virtual void update(); // updates game variables
		virtual void render(); // render the updated look
		
		// cleanup
		virtual void cleanup(); // release allocated memory
	
	private:
};

#endif /* defined(__Mazel__GameState__) */
