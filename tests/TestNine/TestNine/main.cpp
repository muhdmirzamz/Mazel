//
//  main.cpp
//  TestNine
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "SDL.h"

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
	if (!init()) {
		cout << "SDL failed to initialise!\n";
	}
    return 0;
}

