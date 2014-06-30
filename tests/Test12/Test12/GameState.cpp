
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
/*
void GameState::setupWindow(SDL_Window *window) {
	window = SDL_CreateWindow(
	"Test12",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
}

void GameState::setupRenderer(SDL_Renderer *renderer, SDL_Window *window2) {
	renderer = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
}

void GameState::setRunning(bool running) {
	running = true;
}
*/



bool GameState::setupWindow(SDL_Window *window) {
	window = SDL_CreateWindow(
	"Test12",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
				
	if (!window) {
		return false;
	}
	
	return true;
}

bool GameState::setupRenderer(SDL_Renderer *renderer, SDL_Window *window2) {
	renderer = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!renderer) {
		return false;
	}
	
	return true;
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

void GameState::showErrorMessage(string level, string comp) {
	cout << level << " " << comp << " unable to be initiaiised!\n";
}

GameState::~GameState() {
}
