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
#include "GameState.h"

using namespace std;

bool init() {
	// if SDL initialises, along with its video commponent, return true
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		return true;
	}
	
	return false;
}

int main(int argc, const char *argv[])
{
	if (!init()) {
		cout << "SDL failed to initialise! SDL Error message: " << SDL_GetError() << endl;
	}

	GameManager *gameManager = NULL;
#if DEBUG_MODE == true
	gameManager->changeGameState(BASIC_LEVEL);
#else
	gameManager->changeGameState(INTRO_SCENE); // go to intro scene
#endif

	SDL_Quit();
	return 0;
}


