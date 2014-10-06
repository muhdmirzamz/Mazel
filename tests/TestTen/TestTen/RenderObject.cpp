//
//  RenderObject.cpp
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "SDL_render.h"

#include "RenderObject.h"

using namespace std;

RenderObject::RenderObject() {
}

void RenderObject::renderMainMenuBackground(SDL_Renderer *rendererMainMenuBackground) {
	SDL_SetRenderDrawColor(rendererMainMenuBackground, 255, 0, 0, 0);
	SDL_RenderClear(rendererMainMenuBackground);
}

void RenderObject::renderLevelOneBackground(SDL_Renderer *rendererLevelOneBackground) {
	SDL_SetRenderDrawColor(rendererLevelOneBackground, 0, 255, 0, 0);
	SDL_RenderClear(rendererLevelOneBackground);
}

void RenderObject::renderMainMenuSquare(SDL_Renderer *rendererMainMenuSquare, SDL_Rect mainMenuSquare) {
	SDL_SetRenderDrawColor(rendererMainMenuSquare, 0, 255, 0, 0);
	SDL_RenderFillRect(rendererMainMenuSquare, &mainMenuSquare);
}