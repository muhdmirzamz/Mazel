//
//  LevelTwo.cpp
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelTwo.h"

using namespace std;

LevelTwo::LevelTwo() {
	_window = SDL_CreateWindow(
	"TestFive",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	640,
	480,
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
		events();
		update();
		render();
	}
}

void LevelTwo::events() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			SDL_DestroyWindow(_window);
			_window = NULL;
			SDL_DestroyRenderer(_renderer);
			_renderer = NULL;
		
			_running = false;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym) {
				SDL_DestroyWindow(_window);
				_window = NULL;
				SDL_DestroyRenderer(_renderer);
				_renderer = NULL;
				_running = false;
			
				_gameState->changeGameState(0);
			}
		}
	}
}

void LevelTwo::update() {
	SDL_RenderPresent(_renderer);
}

void LevelTwo::render() {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
	SDL_RenderClear(_renderer);
}