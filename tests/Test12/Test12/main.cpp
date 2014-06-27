//
//  main.cpp
//  Test12
//	Program starting point
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "SDL.h"

#include "GameManager.h"

using namespace std;

// use this function to initialise SDL
bool init() {
	// if SDL_VIDEO initialises successfully, return true
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		return true;
	}
	
	return false;
}

int main(int argc, const char * argv[])
{
	// if SDL failed to initialise, output error messaga and end program
	if (!init()) {
		cout << "SDL failed to initialise!\n";
	}
	
	// program starting point is here
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(0); // switch to main menu
	delete gameManager;
	
	SDL_Quit();
    return 0;
}

