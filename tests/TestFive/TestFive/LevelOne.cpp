//
//  LevelOne.cpp
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelOne.h"

using namespace std;

LevelOne::LevelOne() {
	_window = SDL_CreateWindow(
	"TestFive",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	640,
	480,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "LevelOne window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "LevelOne renderer failed to initialise!\n";
	}
	
	_running = true;
}

void LevelOne::run() {
	while (_running) {
		events();
		update();
		render();
	}
}

void LevelOne::events() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			SDL_DestroyWindow(_window);
			_window = NULL;
			SDL_DestroyRenderer(_renderer);
			_renderer = NULL;
		
			_running = false;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_a) {
				SDL_DestroyWindow(_window);
				_window = NULL;
				SDL_DestroyRenderer(_renderer);
				_renderer = NULL;
				_running = false;
				
				_gameState->changeGameState(2);
			}
		}
	}
}

void LevelOne::update() {
	SDL_RenderPresent(_renderer);
}

void LevelOne::render() {
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
	SDL_RenderClear(_renderer);
}