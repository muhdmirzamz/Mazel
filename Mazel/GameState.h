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
#include "RenderIntroScene.h"
#include "RenderMainMenu.h"
#include "RenderLevel1.h"
#include "RenderLevel2.h"
#include "RenderGameOverScene.h"
#include "Collision.h"

// constant macro for event type
#define EVENT_TYPE _event.type

// constant macro for key press
#define PRESSED_KEY _event.key.keysym.sym

// constant macros for mouse cursor coordinates
#define POINT_AT_XPOS _event.motion.x
#define POINT_AT_YPOS _event.motion.y

// constant macros for mouse clicking coordinates
#define CLICK_AT_XPOS _event.button.x
#define CLICK_AT_YPOS _event.button.y

/*
	Currently, there are two ways to exit the game
	Apply this macro to the escape key and 'c' key
	for easy debugging
	Change to 0 if not debugging
*/
#define DEBUG_MODE 0

enum GameStates {
	INTRO_SCENE,
	MAIN_MENU,
	LEVEL_ONE,
	LEVEL_TWO,
	GAME_OVER,
	EXIT
};

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
		
		/* virtual functions to be inherited by individual sub classes */
		
		// due to the nature of the function
		// there needs to be 2 variables of the same type
		// declared in each subclass due to memory issues
		virtual SDL_Window* initWindow(SDL_Window *window);
		virtual SDL_Renderer* initRenderer(SDL_Window *window2, SDL_Renderer *renderer);
		virtual void setIcon(SDL_Window *window3, SDL_Surface *icon, const string filePathOfIcon);
		virtual SDL_Texture* loadImageOntoTexture(SDL_Surface *imageSurface, string filePathOfImage, SDL_Texture *imageTexture, SDL_Renderer *renderer2);
		
		// setup
		virtual void setup(); // use this function to increase code readability
		virtual void setupObjects(); // set up other classes objects, mostly pointers
		virtual void setupTextures(); // sets up textures
		virtual void setupBall(); // sets up ball
		virtual void setupFinishRect(); // sets up finish line
		virtual void setupObstacles(); // sets up obstacles
		
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
