//
//  LevelOne.cpp
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelOne.h"

using namespace std;

LevelOne::LevelOne() {
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
	
	_rect.x = 0;
	_rect.y = 0;
	_rect.w = 100;
	_rect.h = 100;
	
	_speed = 5;
}

void LevelOne::run() {
	while (_running) {
		_rect.x += _speed;
	
		event();
		update();
		render();
		
		if (checkRightCollision(_rect)) {
			_speed = -5;
		}
		
		if (checkLeftCollision(_rect)) {
			SDL_DestroyRenderer(_renderer);
			_renderer = NULL;
			SDL_DestroyWindow(_window);
			_window = NULL;
			_running = false;
			
			_gameState->changeGameState(2);
		}
	}
}

void LevelOne::event() {
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
				
				_gameState->changeGameState(2);
			}
		}
	}
}

bool LevelOne::checkRightCollision(SDL_Rect testRect) {
	if (testRect.x + testRect.w >= 640) {
		return true;
	}
	
	return false;
}

bool LevelOne::checkLeftCollision(SDL_Rect testRectTwo) {
	if (testRectTwo.x <= 0) {
		return true;
	}
	
	return false;
}

void LevelOne::update() {
	SDL_RenderPresent(_renderer);
}

void LevelOne::render() {
	renderBackground();
	renderRectangle();
}

void LevelOne::renderBackground() {
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
	SDL_RenderClear(_renderer);
}

void LevelOne::renderRectangle() {
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(_renderer, &_rect);
}