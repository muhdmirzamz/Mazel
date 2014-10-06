//
//  Gui.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Gui.h"

// constants for main menu start image
static const int START_IMAGE_WIDTH = 150;
static const int START_IMAGE_HEIGHT = 150;

// constants for main menu instructions image
static const int INSTRUCTIONS_IMAGE_WIDTH = 200;
static const int INSTRUCTIONS_IMAGE_HEIGHT = 200;

Gui::Gui() {
	
}

void Gui::loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer) {
	// load image
	_guiImage = SDL_LoadBMP(filePathOfImage.c_str());
	
	// get rid of white background
	// comment out for debugging
	SDL_SetColorKey(_guiImage, SDL_TRUE, SDL_MapRGB(_guiImage->format, 255, 255, 255));
	
	_guiTexture = SDL_CreateTextureFromSurface(renderer, _guiImage);
	if (!_guiTexture) {
		cout << "Failed to create texture from surface\n";
	}
	
	// remember to free surface
	SDL_FreeSurface(_guiImage);
	_guiImage = NULL;
}

void Gui::plotGui(int x, int y, int w, int h) {
	_guiRect.x = x;
	_guiRect.y = y;
	_guiRect.w = w;
	_guiRect.h = h;
}

void Gui::plotStartImage(int xPos, int yPos) {
	_guiRect.x = xPos;
	_guiRect.y = yPos;
	_guiRect.w = START_IMAGE_WIDTH;
	_guiRect.h = START_IMAGE_HEIGHT;
}

void Gui::plotInstructionsImage(int xPosition, int yPosition) {
	_guiRect.x = xPosition;
	_guiRect.y = yPosition;
	_guiRect.w = INSTRUCTIONS_IMAGE_WIDTH;
	_guiRect.h = INSTRUCTIONS_IMAGE_HEIGHT;
}

int Gui::getX() {
	return _guiRect.x;
}

int Gui::getY() {
	return _guiRect.y;
}

int Gui::getW() {
	return _guiRect.w;
}

int Gui::getH() {
	return _guiRect.h;
}

void Gui::render(SDL_Renderer *guiRenderer) {
	SDL_RenderCopy(guiRenderer, _guiTexture, NULL, &_guiRect);
}