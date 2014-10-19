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

// constants for images in fullscreen
static const int FULLSCREEN_START_IMAGE_WIDTH_HEIGHT = 300;
static const int FULLSCREEN_INSTRUCTIONS_IMAGE_WIDTH_HEIGHT = 300;
static const int FULLSCREEN_SETTINGS_IMAGE_WIDTH_HEIGHT = 300;

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

void Gui::plotFullscreenStartImage(int fullscreenStartXPos, int fullscreenStartYPos) {
	_guiRect.x = fullscreenStartXPos;
	_guiRect.y = fullscreenStartYPos;
	_guiRect.w = FULLSCREEN_START_IMAGE_WIDTH_HEIGHT;
	_guiRect.h = FULLSCREEN_START_IMAGE_WIDTH_HEIGHT;
}

void Gui::plotFullscreenInstructionsImage(int fullscreenInstructionsXPosition, int fullscreenInstructionsYPosition) {
	_guiRect.x = fullscreenInstructionsXPosition;
	_guiRect.y = fullscreenInstructionsYPosition;
	_guiRect.w = FULLSCREEN_INSTRUCTIONS_IMAGE_WIDTH_HEIGHT;
	_guiRect.h = FULLSCREEN_INSTRUCTIONS_IMAGE_WIDTH_HEIGHT;
}

void Gui::plotFullscreenSettingsImage(int fullscreenSettingsXPosition, int fullscreenSettingsYPosition) {
	_guiRect.x = fullscreenSettingsXPosition;
	_guiRect.y = fullscreenSettingsYPosition;
	_guiRect.w = FULLSCREEN_SETTINGS_IMAGE_WIDTH_HEIGHT;
	_guiRect.h = FULLSCREEN_SETTINGS_IMAGE_WIDTH_HEIGHT;
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