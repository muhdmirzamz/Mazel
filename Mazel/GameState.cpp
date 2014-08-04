//
//  GameState.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
	
}

GameState::~GameState() {
}

SDL_Window* GameState::initWindow(SDL_Window *window) {
	window = SDL_CreateWindow(
	  "Mazel",
	  WINDOW_X_POS,
	  WINDOW_Y_POS,
	  WINDOW_WIDTH,
	  WINDOW_HEIGHT,
	  SDL_WINDOW_SHOWN
	);
	
	if (!window) {
		cout << "Window failed to initialise!\n";
	}
	
	return window;
}

SDL_Renderer* GameState::initRenderer(SDL_Window *window2, SDL_Renderer *renderer) {
	renderer = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!renderer) {
		cout << "Renderer failed to initialise!\n";
	}
	
	return renderer;
}
/*
void GameState::setIcon(SDL_Window *window3, SDL_Surface *icon, const string filePathOfIcon) {
	icon = SDL_LoadBMP(filePathOfIcon.c_str());
	if (!icon) {
		cout << "Window icon failed to initialise!\n";
	}

	SDL_SetWindowIcon(window3, icon);
}
*/
SDL_Texture* GameState::loadImageOntoTexture
(SDL_Surface *imageSurface, string filePathOfImage, SDL_Texture *imageTexture, SDL_Renderer *renderer2) {
	// load image
	imageSurface = SDL_LoadBMP(filePathOfImage.c_str());
	
	// get rid of white background
	SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface->format, 255, 255, 255));
	
	imageTexture = SDL_CreateTextureFromSurface(renderer2, imageSurface);
	if (!imageTexture) {
		cout << "Failed to create texture from surface\n";
	}
	
	// remember to free surface
	SDL_FreeSurface(imageSurface);
	imageSurface = NULL;
	
	return imageTexture;
}

void GameState::setup() {
	
}

void GameState::run() {
	
}

void GameState::event() {
	
}

void GameState::update() {
	
}

void GameState::render() {
	
}

void GameState::cleanup() {
	
}

void GameState::changeState(int state) {
	GameManager *gameManager = NULL;
	gameManager->changeGameState(state);
}



