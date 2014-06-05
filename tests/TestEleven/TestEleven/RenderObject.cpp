//
//  RenderObject.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderObject.h"

using namespace std;

RenderObject::RenderObject() {
	
}

void RenderObject::renderMainMenuBackground(SDL_Renderer *rendererMainMenu) {
	SDL_SetRenderDrawColor(rendererMainMenu, 255, 0, 0, 0);
	SDL_RenderClear(rendererMainMenu);
}

void RenderObject::renderLevel1Background(SDL_Renderer *rendererLevel1) {
	SDL_SetRenderDrawColor(rendererLevel1, 0, 255, 0, 0);
	SDL_RenderClear(rendererLevel1);
}

void RenderObject::renderLevel2Background(SDL_Renderer *rendererLevel2) {
	SDL_SetRenderDrawColor(rendererLevel2, 0, 0, 255, 0);
	SDL_RenderClear(rendererLevel2);
}

void RenderObject::renderMainMenuSquare(SDL_Renderer *rendererMainMenuSquare, SDL_Rect rect1) {
	SDL_SetRenderDrawColor(rendererMainMenuSquare, 0, 255, 0, 0);
	SDL_RenderFillRect(rendererMainMenuSquare, &rect1);
}

void RenderObject::renderMainMenuTitle(SDL_Renderer *rendererMainMenuTitle, SDL_Rect rect2) {
	SDL_SetRenderDrawColor(rendererMainMenuTitle, 0, 50, 100, 0);
	SDL_RenderFillRect(rendererMainMenuTitle, &rect2);
}

void RenderObject::renderLevel1PlayerRectangle(SDL_Renderer *rendererLevel1PlayerRectangle, SDL_Rect rect3) {
	SDL_SetRenderDrawColor(rendererLevel1PlayerRectangle, 0, 0, 255, 0);
	SDL_RenderFillRect(rendererLevel1PlayerRectangle, &rect3);
}

void RenderObject::renderLevel1RectangleObstacle(SDL_Renderer *rendererLevel1RectangleObstacle, SDL_Rect rect4) {
	SDL_SetRenderDrawColor(rendererLevel1RectangleObstacle, 0, 0, 255, 0);
	SDL_RenderFillRect(rendererLevel1RectangleObstacle, &rect4);
}