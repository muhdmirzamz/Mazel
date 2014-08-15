//
//  RenderLevel2.cpp
//  Mazel
//
//  Created by Muhd Mirza on 15/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderLevel2.h"

using namespace std;

RenderLevel2::RenderLevel2() {
	
}

void RenderLevel2::renderLevel2Background(SDL_Renderer *level2Renderer) {
	SDL_SetRenderDrawColor(level2Renderer, 0, 100, 0, 0);
	SDL_RenderClear(level2Renderer);
}