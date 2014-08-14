//
//  Level1.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Level1.h"

using namespace std;

Level1::Level1() {
	setup();
}

void Level1::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("Level 1", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Level 1", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_renderLevel1 = new RenderLevel1();
	if (!_renderLevel1) {
		printErrorMessage("Level 1", "render object for level 1");
	}
	
	_running = true;
}

void Level1::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void Level1::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_ESCAPE) {
				_running = false;
				
				cleanup();
				
				changeState(EXIT);
			}
			
			if (_event.key.keysym.sym == SDLK_c) {
				_running = false;
				
				cleanup();
				
				changeState(LEVEL_TWO);
			}
		}
	}
}

void Level1::update() {
	SDL_RenderPresent(_renderer);
}

void Level1::render() {
	_renderLevel1->renderLevel1Background(_renderer);
}

void Level1::cleanup() {
	delete _renderLevel1;
	_renderLevel1 = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}