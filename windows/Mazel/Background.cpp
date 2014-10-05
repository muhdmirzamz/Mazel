//
//  Background.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Background.h"

Background::Background() {
	
}

void Background::loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer) {
	// load image
	_backgroundImage = SDL_LoadBMP(filePathOfImage.c_str());
	
	// get rid of white background
	// comment out for debugging
	SDL_SetColorKey(_backgroundImage, SDL_TRUE, SDL_MapRGB(_backgroundImage->format, 255, 255, 255));
	
	_backgroundTexture = SDL_CreateTextureFromSurface(renderer, _backgroundImage);
	if (!_backgroundTexture) {
		cout << "Failed to create texture from surface\n";
	}
	
	// remember to free surface
	SDL_FreeSurface(_backgroundImage);
	_backgroundImage = NULL;
}

void Background::plotBackground(int x, int y, int w, int h) {
	_backgroundRect.x = x;
	_backgroundRect.y = y;
	_backgroundRect.w = w;
	_backgroundRect.h = h;
}

void Background::renderIntroSceneBackground(SDL_Renderer *introSceneRenderer) {
	SDL_SetRenderDrawColor(introSceneRenderer, 0, 100, 100, 0);
	SDL_RenderClear(introSceneRenderer);
}

void Background::renderMainMenuBackground(SDL_Renderer *mainMenuRenderer) {
	SDL_SetRenderDrawColor(mainMenuRenderer, 240, 240, 240, 0);
	SDL_RenderClear(mainMenuRenderer);
}

void Background::renderBasicLevelBackground(SDL_Renderer *basicLevelRenderer) {
	SDL_SetRenderDrawColor(basicLevelRenderer, 240, 240, 240, 0);
	SDL_RenderClear(basicLevelRenderer);
}

void Background::renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer) {
	SDL_SetRenderDrawColor(gameOverSceneRenderer, 100, 150, 100, 0);
	SDL_RenderClear(gameOverSceneRenderer);
}

void Background::renderImage(SDL_Renderer *imageRenderer) {
	SDL_RenderCopy(imageRenderer, _backgroundTexture, NULL, &_backgroundRect);
}