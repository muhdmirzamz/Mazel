//
//  Level2.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Level2.h"

using namespace std;

Level2::Level2() {
	setup();
}

void Level2::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("Level 2", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Level 2", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	setupObjects();
	
	_running = true;
}

void Level2::setupObjects() {
	_renderLevel2 = new RenderLevel2();
	if (!_renderLevel2) {
		printErrorMessage("Level 2", "Level 2 renderer object");
	}
}

void Level2::setupTextures() {
	
}

void Level2::setupBall() {
	
}

void Level2::setupObstacles() {
	
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
			 _running = false;
			 
			 cleanup();
		}
	}
}

void Level2::update() {
	SDL_RenderPresent(_renderer);
}

void Level2::render() {
	_renderLevel2->renderLevel2Background(_renderer);
}

void Level2::cleanup() {
	delete _renderLevel2;
	_renderLevel2 = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}