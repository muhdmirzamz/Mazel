//
//  Level2.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 25/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Level2.h"

using namespace std;

Level2::Level2() {
	_windowHeight = 480;
	_windowWidth = 640;
	
	_window = SDL_CreateWindow(
	"Test 11",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	_windowWidth,
	_windowHeight,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "Level 2 window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "Level 2 renderer failed to initialise!\n";
	}
	
	_running = true;
	
	_renderObject = new RenderObject();
}

void Level2::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void Level2::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			cleanUp();
			_running = true;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_c) {
				cleanUp();
				_running = false;
			
				_gameState->changeGameState(0);
			}
		}

	}
}

void Level2::update() {
	SDL_RenderPresent(_renderer);
}

void Level2::render() {
	_renderObject->renderLevel2Background(_renderer);
}

void Level2::cleanUp() {
	delete _renderObject;
	_renderObject = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}