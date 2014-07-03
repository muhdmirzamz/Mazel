//
//  GameState.cpp
//  Test14
//
//  Created by Muhd Mirza on 2/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
	
}

GameState::~GameState() {
	
}

void GameState::printError(string level, string comp) {
	cout << level << " " <<  comp << " failed to initialise!\n";
}

SDL_Window* GameState::setupWindow(SDL_Window *window) {
	window = SDL_CreateWindow(
	"Test 14",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	
	if (!window) {
		cout << "Window fail\n";
	}
	
	return window;
}

SDL_Renderer* GameState::setupRenderer(SDL_Renderer *renderer, SDL_Window *window2) {
	renderer = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!renderer) {
		cout << "Renderer fail\n";
	}
	
	return renderer;
}

void GameState::event() {
	
}

void GameState::update() {
	
}

void GameState::render() {
	
}

void GameState::display() {
	
}

void GameState::handleWallCollision(SDL_Rect rect1, int windowWidth, int windowHeight, int speedX, int speedY) {
	if (rect1.x <= 0) {
		rect1.x += speedX;
	}
	
	if (rect1.x + rect1.w >= windowWidth) {
		rect1.y -= speedY;
	}
	
	if (rect1.y <= 0) {
		rect1.x += speedX;
	}
	
	if (rect1.y + rect1.h >= windowHeight) {
		rect1.y -= speedY;
	}
}

void GameState::cleanup() {
	
}

SDL_Texture* GameState::loadImage(SDL_Surface *image, SDL_Texture *imageTexture, SDL_Renderer *renderer, const string path, int r, int g, int b) {
	image = SDL_LoadBMP(path.c_str());
	if (!image) {
		cout << "Unable to load image\n";
	}
	
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, r, g, b));
	
	imageTexture = SDL_CreateTextureFromSurface(renderer, image);
	if (!imageTexture) {
		cout << "Texture failed to initialise!\n";
	}
	
	SDL_FreeSurface(image);
	image = NULL;
	
	return imageTexture;
}

void GameState::displayImage(SDL_Rect imageRect, int x, int y, int imageWidth, int imageHeight, SDL_Texture *imageTexture2, SDL_Renderer *renderer2) {
	imageRect.x = x;
	imageRect.y = y;
	imageRect.w = imageWidth;
	imageRect.h = imageHeight;
	
	/*
	// for debugging purposes
	cout << "X-axis: " << imageRect.x << endl;
	cout << "Y axis: " << imageRect.y << endl;
	cout << "Width: " << imageRect.w << endl;
	cout << "Height: " << imageRect.h << endl;
	*/
	SDL_RenderCopy(renderer2, imageTexture2, NULL, &imageRect);
}

void GameState::changeState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(state);
	delete gameManager;
}