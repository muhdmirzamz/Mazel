//
//  RenderObject.cpp
//  Test14
//
//  Created by Muhd Mirza on 3/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderObject.h"

using namespace std;

RenderObject::RenderObject() {
	
}

void RenderObject::renderLevelOneBackground(SDL_Renderer *levelOneBackground) {
	SDL_SetRenderDrawColor(levelOneBackground, 0, 0, 255, 0);
	SDL_RenderClear(levelOneBackground);
}