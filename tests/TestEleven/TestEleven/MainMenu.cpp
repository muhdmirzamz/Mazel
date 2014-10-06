//
//  MainMenu.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
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
		cout << "MainMenu window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(
	_window,
	-1,
	SDL_RENDERER_PRESENTVSYNC
	);
	
	if (!_renderer) {
		cout << "MainMenu renderer failed to initialise!\n";
	}
	
	_running = true;
	
	_renderObject = new RenderObject();
	_collisionDetection = new CollisionDetection();
	
	setRectangle();
	setRectangleSpeed();
}

void MainMenu::run() {
	while (_running) {
		moveRectangle();

		event();
		update();
		render();
		
		detectRectangleCollision();
	}
}

void MainMenu::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			cleanUp();
			_running = false;
		}
		
		// for debugging purposes
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_c) {
				cleanUp();
				_running = false;
			
				_gameState->changeGameState(1);
			}
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

// rendering of background and onscreen objects
void MainMenu::render() {
	_renderObject->renderMainMenuBackground(_renderer);
	
	_renderObject->renderMainMenuSquare(_renderer, _rect1);
	_renderObject->renderMainMenuSquare(_renderer, _rect2);
	_renderObject->renderMainMenuSquare(_renderer, _rect3);
	
	// title
	_renderObject->renderMainMenuTitle(_renderer, _letterM1);
	_renderObject->renderMainMenuTitle(_renderer, _letterM2);
	_renderObject->renderMainMenuTitle(_renderer, _letterM3);
	_renderObject->renderMainMenuTitle(_renderer, _letterM4);
	_renderObject->renderMainMenuTitle(_renderer, _letterM5);
}

void MainMenu::cleanUp() {
	delete _collisionDetection;
	_collisionDetection = NULL;
	delete _renderObject;
	_renderObject = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}

void MainMenu::setRectangle() {
	_rect1.x = 10;
	_rect1.y = 10;
	_rect1.w = 20;
	_rect1.h = 20;
	
	_rect2.x = 20;
	_rect2.y = 20;
	_rect2.w = 40;
	_rect2.h = 40;
	
	_rect3.x = 5;
	_rect3.y = 5;
	_rect3.w = 50;
	_rect3.h = 50;
	
	// title
	// Letter M
	_letterM1.x = 100;
	_letterM1.y = 100;
	_letterM1.w = 20;
	_letterM1.h = 100;
	
	_letterM2.x = 120;
	_letterM2.y = 100;
	_letterM2.w = 20;
	_letterM2.h = 20;
	
	_letterM3.x = 140;
	_letterM3.y = 100;
	_letterM3.w = 20;
	_letterM3.h = 80;
	
	_letterM4.x = 160;
	_letterM4.y = 100;
	_letterM4.w = 20;
	_letterM4.h = 20;
	
	_letterM5.x = 180;
	_letterM5.y = 100;
	_letterM5.w = 20;
	_letterM5.h = 100;
}

void MainMenu::setRectangleSpeed() {
	_rect1SpeedX = 5;
	_rect1SpeedY = 5;
	
	_rect2SpeedX = 5;
	_rect2SpeedY = 5;
	
	_rect3SpeedX = 5;
}

void MainMenu::moveRectangle() {
	_rect1.x += _rect1SpeedX;
	_rect1.y += _rect1SpeedY;
	
	_rect2.x += _rect2SpeedX;
	_rect2.y += _rect2SpeedY;
	
	_rect3.x += _rect3SpeedX;
}

void MainMenu::detectRectangleCollision() {
	// _rect1
	
	// before
	// _speedX = 5;
	// _speedY = 5;
	if (_collisionDetection->didCollideWithBottomSide(_rect1, _windowHeight)) {
		// Switch _speedY to negative
		_rect1SpeedY = -5;
	}
	// after
	// _speedX = 5;
	// _speedY = -5;
	
	// before
	// _speedX = 5;
	// _speedY = -5;
	if (_collisionDetection->didCollideWithRightSide(_rect1, _windowWidth)) {
		// switch _speedX to negative
		_rect1SpeedX = -5;
	}
	// after
	// _speedX = -5;
	// _speedY = -5;
	
	// before
	// _speedX = -5;
	// _speedY = -5;
	if (_collisionDetection->didCollideWithTopSide(_rect1)) {
		// switch _speedY to positive
		_rect1SpeedY = 5;
	}
	// after
	// _speedX = -5;
	// _speedY = 5;
	
	// before
	// _speedX = -5;
	// _speedY = 5;
	if (_collisionDetection->didCollideWithLeftSide(_rect1)) {
		// switch _speedX to positive
		_rect1SpeedX = 5;
	}
	// after
	// _speedX = 5;
	// _speedY = 5;
	
	
	// _rect2
	if (_collisionDetection->didCollideWithBottomSide(_rect2, _windowHeight)) {
		// Switch _speedY to negative
		_rect2SpeedY = -5;
	}
	
	if (_collisionDetection->didCollideWithRightSide(_rect2, _windowWidth)) {
		// switch _speedX to negative
		_rect2SpeedX = -5;
	}
	
	if (_collisionDetection->didCollideWithTopSide(_rect2)) {
		// switch _speedY to positive
		_rect2SpeedY = 5;
	}
	
	if (_collisionDetection->didCollideWithLeftSide(_rect2)) {
		// switch _speedX to positive
		_rect2SpeedX = 5;
	}
	
	// _rect3
	if (_collisionDetection->didCollideWithRightSide(_rect3, _windowWidth)) {
		_rect3SpeedX = -5;
	}
	
	if (_collisionDetection->didCollideWithLeftSide(_rect3)) {
		cleanUp();
		_running = false;
	
		_gameState->changeGameState(1);
	}
}