//
//  LevelOne.cpp
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelOne.h"

using namespace std;

LevelOne::LevelOne() {
	_windowWidth = 640;
	_windowHeight = 480;
	
	_window = SDL_CreateWindow(
	"TestTen",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	_windowWidth,
	_windowHeight,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "MainMenu windows failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "Renderer failed to initialise!\n";
	}
	
	_running = true;
	
	_renderObject = new RenderObject();
}

void LevelOne::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void LevelOne::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			cleanUp();
			
			_running = false;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_c) {
				cleanUp();
			
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
	_renderObject->renderLevelOneBackground(_renderer);
}

void LevelOne::cleanUp() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
	delete _renderObject;
	_renderObject = NULL;
}