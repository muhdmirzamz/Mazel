//
//  Obstacle.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Obstacle.h"

static const int BASIC_LEVEL_FINISH_RECT_WIDTH = 50;
static const int BASIC_LEVEL_FINISH_RECT_HEIGHT = 80;

Obstacle::Obstacle() {
	
}

void Obstacle::loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer) {
	// load image
	_obstacleImage = SDL_LoadBMP(filePathOfImage.c_str());
	
	// get rid of white background
	// comment out for debugging
	SDL_SetColorKey(_obstacleImage, SDL_TRUE, SDL_MapRGB(_obstacleImage->format, 255, 255, 255));
	
	_obstacleTexture = SDL_CreateTextureFromSurface(renderer, _obstacleImage);
	if (!_obstacleTexture) {
		cout << "Failed to create texture from surface\n";
	}
	
	// remember to free surface
	SDL_FreeSurface(_obstacleImage);
	_obstacleImage = NULL;
}

void Obstacle::plotObstacle(int x, int y, int w, int h) {
	_obstacleRect.x = x;
	_obstacleRect.y = y;
	_obstacleRect.w = w;
	_obstacleRect.h = h;
}

void Obstacle::plotFinishRect(int xPos, int yPos) {
	_obstacleRect.x = xPos;
	_obstacleRect.y = yPos;
	_obstacleRect.w = BASIC_LEVEL_FINISH_RECT_WIDTH;
	_obstacleRect.h = BASIC_LEVEL_FINISH_RECT_HEIGHT;
}

int Obstacle::getX() {
	return _obstacleRect.x;
}

int Obstacle::getY() {
	return _obstacleRect.y;
}

int Obstacle::getW() {
	return _obstacleRect.w;
}

int Obstacle::getH() {
	return _obstacleRect.h;
}

void Obstacle::render(SDL_Renderer *obstacleRenderer) {
	SDL_SetRenderDrawColor(obstacleRenderer, 0, 0, 255, 0);
	SDL_RenderFillRect(obstacleRenderer, &_obstacleRect);
}

void Obstacle::renderImage(SDL_Renderer *obstacleImageRenderer) {
	SDL_RenderCopy(obstacleImageRenderer, _obstacleTexture, NULL, &_obstacleRect);
}