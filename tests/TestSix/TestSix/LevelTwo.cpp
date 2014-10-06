//
//  LevelTwo.cpp
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelTwo.h"

using namespace std;

LevelTwo::LevelTwo() {
	_window = SDL_CreateWindow(
	"TestSix",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	640,
	480,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "MainMenu window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "MainMenu renderer failed to initialise!\n";
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
			SDL_DestroyRenderer(_renderer);
			_renderer = NULL;
			SDL_DestroyWindow(_window);
			_window = NULL;
			delete _gameState;
			
			_running = false;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_c) {
				SDL_DestroyRenderer(_renderer);
				_renderer = NULL;
				SDL_DestroyWindow(_window);
				_window = NULL;
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