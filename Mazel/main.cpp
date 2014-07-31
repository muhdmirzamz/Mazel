//
//  main.cpp
//  Mazel
//	Program entry point
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "SDL.h"
#include "SDL_error.h"

#include "GameManager.h"

using namespace std;

bool init() {
	// if SDL initialises, along with its video commponent
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		return true;
	}
	
	return false;
}

int main(int argc, const char *argv[])
{
	// if video component fails to initialise
	// and if SDL fails to initialise
	// print out error message
	if (!init()) {
		cout << "SDL failed to initialise! SDL Error message: " << SDL_GetError() << endl;
	}
	
	// enter program through GameManager
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(0); // switch to Main Menu
	
	// release memory and quit SDL
	delete gameManager;
	SDL_Quit();
	return 0;
}


