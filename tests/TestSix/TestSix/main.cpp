//
//  main.cpp
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "GameManager.h"

#include "SDL.h"

using namespace std;

bool init() {
	if (SDL_Init(SDL_INIT_VIDEO) == 0) {
		return true;
	}
	
	return false;
}

int main(int argc, const char * argv[])
{
	if (!init()) {
		cout << "SDL failed to initialise!\n";
	}
	
	GameManager *gameManager = new GameManager();
	gameManager->changeState(0);
	delete gameManager;
	
	SDL_Quit();
	
    return 0;
}
