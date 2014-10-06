//
//  main.cpp
//  TestFour
//
//  Created by Muhd Mirza on 24/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include <SDL2/SDL.h>

#include "MainMenu.h"
#include "GameManager.h"

using namespace std;

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		return true;
	}
	
	return false;
}

int main(int argc, const char * argv[])
{
	if (!(init())) {
		cout << "SDL failed to initialise!\n";
	}
	
	GameManager *gameManager = new GameManager();
	gameManager->changeState(0);
	
	delete gameManager;
	SDL_Quit();
	
    return 0;
}

