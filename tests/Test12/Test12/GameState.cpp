
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

void GameState::setupWindow(SDL_Window *window) {
	window = SDL_CreateWindow(
	"Test12",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	
	if (window == NULL) {
		cout << "Problem\n";
	}
}

void GameState::setupRenderer(SDL_Renderer *renderer, SDL_Window *window2) {
	renderer = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (renderer == NULL) {
		cout << "Problem\n";
	}
}

void GameState::setRunning(bool running) {
	running = true;
}

void GameState::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void GameState::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			_running = false;
		}
	}
}

void GameState::update() {
	SDL_RenderPresent(_renderer);
}

void GameState::render() {
}

void GameState::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
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

SDL_Window* GameState::getWindow() {
	return _window;
}

SDL_Renderer* GameState::getRenderer() {
	return _renderer;
}

bool GameState::getRunningVar() {
	return _running;
}

SDL_Event GameState::getEvent() {
	return _event;
}

GameState::~GameState() {
}
