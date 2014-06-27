
//
//  GameState.cpp
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
}

SDL_Window* GameState::setupWindow(string level, string comp) {
	_window = SDL_CreateWindow(
	"Test12",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << level << " " << comp << " failed to initialise!\n";
	}
	
	return _window;
}

SDL_Renderer* GameState::setupRenderer(SDL_Window *window, string level, string comp) {
	_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_window) {
		cout << level << " " << comp << " failed to initialise!\n";
	}

	return _renderer;
}

void GameState::setRunning(bool running) {
	running = true;
}

// need this function to access a similar function in GameManager class
void GameState::changeState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(state);
	delete gameManager;
}

GameState::~GameState() {
}
