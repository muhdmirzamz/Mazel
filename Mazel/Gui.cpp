//
//  Gui.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Gui.h"

// constants for main menu start image
static const int START_IMAGE_WIDTH_HEIGHT = 150;

// constants for main menu instructions image
static const int INSTRUCTIONS_IMAGE_WIDTH_HEIGHT = 150;

// constants for main menu settings image
static const int SETTINGS_IMAGE_WIDTH_HEIGHT = 150;

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

void Gui::plotStartImage(int startXPos, int startYPos) {
	_guiRect.x = startXPos;
	_guiRect.y = startYPos;
	_guiRect.w = START_IMAGE_WIDTH_HEIGHT;
	_guiRect.h = START_IMAGE_WIDTH_HEIGHT;
}

void Gui::plotInstructionsImage(int instructionsXPosition, int instructionsYPosition) {
	_guiRect.x = instructionsXPosition;
	_guiRect.y = instructionsYPosition;
	_guiRect.w = INSTRUCTIONS_IMAGE_WIDTH_HEIGHT;
	_guiRect.h = INSTRUCTIONS_IMAGE_WIDTH_HEIGHT;
}

void Gui::plotSettingsImage(int settingsXPosition, int settingsYPosition) {
	_guiRect.x = settingsXPosition;
	_guiRect.y = settingsYPosition;
	_guiRect.w = SETTINGS_IMAGE_WIDTH_HEIGHT;
	_guiRect.h = SETTINGS_IMAGE_WIDTH_HEIGHT;
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

void Gui::renderGUI(SDL_Renderer *guiRenderer2, int r, int g, int b) {
	SDL_SetRenderDrawColor(guiRenderer2, r, g, b, 0);
	SDL_RenderFillRect(guiRenderer2, &_guiRect);
}