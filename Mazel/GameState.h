//
//  GameState.h
//  Mazel
//	this class forms the base of every class that a running
//	process, examples are levels, main menu etc
//	include all files which level classes require
//	level classes only need to import this class(GameState.h)
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameState__
#define __Mazel__GameState__

#include <iostream>

#include "Includes.h"
#include "GameManager.h"

#include "Ball.h"
#include "Obstacle.h"
#include "Enemy.h"
#include "Background.h"
#include "Gui.h"

enum GameStates {
	INTRO_SCENE,
	MAIN_MENU,
	INSTRUCTIONS_PAGE,
	BASIC_LEVEL, // a bunch of levels
	SETTINGS_PAGE,
	NEXT_LEVEL_PAGE,
	GAME_OVER,
	GAME_END,
	EXIT
};

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
	
		/* 
			available functions to be used by individual sub classes 
		*/
		
		inline void printErrorMessage(string level, string component) {
			cout << level << " " << component << " failed to initialise!\n";
			cout << SDL_GetError() << endl;
		}
	
		// setup
		virtual void setup(); // sets up the window, renderer, icons, and running flag
		virtual void setupObjects();
		virtual void setupTextures();
		
		/*
			balls and finish rectangles stay the same position throughout a collection of levels
			Obstacles and enemies dont
		*/
		virtual void setupBall(); // plots coordinates and sets speed
		virtual void setupFinishRect(); // plots coordinates
		virtual void setupObstaclesAndEnemies(); // plots coordinates and sets speed
		
		SDL_Window* initWindow(SDL_Window *window);
		SDL_Renderer* initRenderer(SDL_Window *window2, SDL_Renderer *renderer);
		void setIcon(SDL_Window *window3, SDL_Surface *icon, const string filePathOfIcon);
		
		// main game loop
		virtual void run();
		
		// events
		virtual void event();
		virtual void moveEnemy();
		void changeState(GameManager *gameManager, int state);
		virtual void checkBallAndWindowCollision();
		virtual void checkBallAndObstacleCollision();
		virtual void checkBallAndFinishRectangleCollision();
		virtual void checkBallAndEnemiesCollision();
		virtual void checkEnemiesAndWindowCollision();
		virtual void checkEnemiesAndObstacleCollision();
		
		// update and render
		virtual void update(); // updates game variables
		virtual void render(); // render the updated look
		
		// cleanup
		virtual void cleanup(); // release allocated memory
	
	// labelled as protected so that derived classes can inherit them
	protected:
		SDL_Window *_window; // remember to release the memory
		SDL_Window *_windowRef;
		SDL_Renderer *_renderer; // // remember to release the memory
		SDL_Renderer *_rendererRef;
		SDL_Event _event;
		
		bool _running;
		
		SDL_Surface *_icon;
		
		GameManager *_gameManager;
};

#endif /* defined(__Mazel__GameState__) */
