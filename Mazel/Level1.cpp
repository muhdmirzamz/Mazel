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
	
	_collision = new Collision();
	if (!_collision) {
		printErrorMessage("Level 1", "Collision pointer");
	}
	
	_ballTexture = loadImageOntoTexture(_ballImage, "images/ball.bmp", _ballTextureRef, _renderer);
	if (!_ballTexture) {
		printErrorMessage("Level 1", "ball");
	}
	
	_running = true;
	
	_ballRect.x = 20;
	_ballRect.y = 20;
	_ballRect.w = 20;
	_ballRect.h = 20;
	
	_ballSpeedXLeft = 10;
	_ballSpeedXRight = 10;
	_ballSpeedYUp = 10;
	_ballSpeedYDown = 10;
}

void Level1::run() {
	while (_running) {
		event();
		update();
		checkCollision();
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
#if DEBUG_MODE == 1
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
#endif
			// ball controls
			if (PRESSED_KEY == SDLK_w) {
				_ballSpeedYDown = 10;
				_ballRect.y -= _ballSpeedYUp;
			}
			
			if (PRESSED_KEY == SDLK_s) {
				_ballSpeedYUp = 10;
				_ballRect.y += _ballSpeedYDown;
			}
			
			if (PRESSED_KEY == SDLK_a) {
				_ballSpeedXRight = 10;
				_ballRect.x -= _ballSpeedXLeft;
			}
			
			if (PRESSED_KEY == SDLK_d) {
				_ballSpeedXLeft = 10;
				_ballRect.x += _ballSpeedXRight;
			}
		}
	}
}

void Level1::checkCollision() {
	if (_collision->ballDidCollideWithTopOfWindow(_ballRect)) {
		_ballSpeedYUp = 0;
	}
	
	if (_collision->ballDidCollideWithBottomOfWindow(_ballRect)) {
		_ballSpeedYDown = 0;
	}
	
	if (_collision->ballDidCollideWithLeftOfWindow(_ballRect)) {
		_ballSpeedXLeft = 0;
	}
	
	if (_collision->ballDidCollideWithRightOfWindow(_ballRect)) {
		_ballSpeedXRight = 0;
	}
}

void Level1::update() {
	SDL_RenderPresent(_renderer);
}

void Level1::render() {
	_renderLevel1->renderLevel1Background(_renderer);
	_renderLevel1->renderLevel1Ball(_renderer, _ballTexture, _ballRect);
}

void Level1::cleanup() {
	delete _renderLevel1;
	_renderLevel1 = NULL;
	delete _collision;
	_collision = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}