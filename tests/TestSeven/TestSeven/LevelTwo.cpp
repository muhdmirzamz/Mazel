//
//  LevelTwo.cpp
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelTwo.h"

using namespace std;

LevelTwo::LevelTwo() {
	_windowWidth = 640;
	_windowHeight = 480;
	
	_window = SDL_CreateWindow(
	"TestSeven",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	_windowWidth,
	_windowHeight,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "LevelTwo window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "LevelTwo renderer failed to initialise!\n";
	}
	
	_running = true;
	_gameState = new GameState();
}

void LevelTwo::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void LevelTwo::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			_running = false;
		}
	}
}

void LevelTwo::update() {
	SDL_RenderPresent(_renderer);
}

void LevelTwo::render() {
	renderBackground();
}

void LevelTwo::renderBackground() {
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
}