//
//  GameState.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"

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


