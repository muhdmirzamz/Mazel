//
//  RenderMainMenu.cpp
//  Mazel
//
//  Created by Muhd Mirza on 13/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderMainMenu.h"

using namespace std;

RenderMainMenu::RenderMainMenu() {
	
}

void RenderMainMenu::renderMainMenuBackground(SDL_Renderer *mainMenuRenderer) {
	SDL_RenderClear(mainMenuRenderer);
	SDL_SetRenderDrawColor(mainMenuRenderer, 240, 240, 240, 0);
}

void RenderMainMenu::renderMainMenuLogo(SDL_Renderer *mainMenuRenderer2, SDL_Texture *logoTexture) {
	SDL_Rect logoTextureRect;

	logoTextureRect.x = 180;
	logoTextureRect.y = 50;
	logoTextureRect.w = 300;
	logoTextureRect.h = 300;
	SDL_RenderCopy(mainMenuRenderer2, logoTexture, NULL, &logoTextureRect);
}

void RenderMainMenu::renderMainMenuGrassBackground(SDL_Renderer *mainMenuRenderer3, SDL_Texture *grassBackgroundTexture) {
	SDL_Rect mainMenuHalfBackGroundRect;

	mainMenuHalfBackGroundRect.x = 0;
	mainMenuHalfBackGroundRect.y = 280;
	mainMenuHalfBackGroundRect.w = WINDOW_WIDTH;
	mainMenuHalfBackGroundRect.h = 200;
	SDL_RenderCopy(mainMenuRenderer3, grassBackgroundTexture, NULL, &mainMenuHalfBackGroundRect);
}

void RenderMainMenu::renderMainMenuStartButton(SDL_Renderer *mainMenuRenderer4, SDL_Texture *startButton) {
	SDL_Rect startRect;
	
	startRect.x = 200;
	startRect.y = 345;
	startRect.w = 200;
	startRect.h = 200;
	SDL_RenderCopy(mainMenuRenderer4, startButton, NULL, &startRect);
}

void RenderMainMenu::renderMainMenuBall(SDL_Renderer *mainMenuRenderer5, SDL_Texture *ballTexture, SDL_Rect ballRect) {
	SDL_RenderCopy(mainMenuRenderer5, ballTexture, NULL, &ballRect);
}