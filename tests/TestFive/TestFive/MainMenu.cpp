//
//  MainMenu.cpp
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	_window = SDL_CreateWindow(
	"TestFive",
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
		cout << "MainMenu renderer failed to intialise!\n";
	}
	
	_running = true;
	
	_gameState = new GameState();
}

void MainMenu::run() {
	while (_running) {
		events();
		update();
		render();
	}
}

void MainMenu::events() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			_running = false;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_a) {
				SDL_DestroyWindow(_window);
				_window = NULL;
				SDL_DestroyRenderer(_renderer);
				_renderer = NULL;
				_running = false;
					
				_gameState->changeGameState(1);
			}
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
	SDL_RenderClear(_renderer);
}