//
//  MainMenu.cpp
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
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
	_speed = 5;
	
	_renderObject = new RenderObject();
	_collisionDetection = new CollisionDetection();
}

void MainMenu::positionSquare() {
	_square.x = 10;
	_square.y = 10;
	_square.w = 100;
	_square.h = 100;
}

void MainMenu::run() {
	positionSquare();
	
	while (_running) {
		_square.x += _speed;
	
		event();
		update();
		render();
		
		if (_collisionDetection->collidedWithRightSide(_square, _windowWidth)) {
			_speed = -5;
		}
		
		if (_collisionDetection->collidedWithLeftSide(_square)) {
			cleanUp();
			
			_running = false;
			
			_gameState->changeGameState(1);
		}
	}
}

void MainMenu::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			cleanUp();
		
			_running = false;
		}
		
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

void MainMenu::render() {
	_renderObject->renderMainMenuBackground(_renderer);
	_renderObject->renderMainMenuSquare(_renderer, _square);
}

void MainMenu::cleanUp() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
	delete _renderObject;
	_renderObject = NULL;
	delete _collisionDetection;
	_collisionDetection = NULL;
}