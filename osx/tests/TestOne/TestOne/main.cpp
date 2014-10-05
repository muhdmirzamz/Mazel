//
//  main.cpp
//  TestOne
//
//  Created by Muhd Mirza on 19/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "SDL.h"

#include "MainMenu.h"

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
		cout << "SDL failed to initialise\n";
	}
	
	MainMenu mainMenu;
	mainMenu.run();
    return 0;
}

