
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

// need this function to access a similar function in GameManager class
void GameState::changeState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(state);
	delete gameManager;
}

void GameState::showErrorMessage(string level, string comp) {
	cout << level << " " << comp << " failed to initialise!\n" << endl;
}

bool GameState::setupWindow() {
	_window = SDL_CreateWindow(
	"Test12",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		return false;
	}
	
	return true;
}

bool GameState::setupRenderer() {
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		return false;
	}
	
	return true;
}

void GameState::startRunning() {
	_running = false;
}