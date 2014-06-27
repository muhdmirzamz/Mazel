//
//  RenderObject.cpp
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderObject.h"

using namespace std;

RenderObject::RenderObject() {
	
}
void RenderObject::renderMainMenuBackground(SDL_Renderer *mainMenuBackgroundRenderer) {
	SDL_SetRenderDrawColor(mainMenuBackgroundRenderer, 0, 255, 0, 0);
	SDL_RenderClear(mainMenuBackgroundRenderer);
}