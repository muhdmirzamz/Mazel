//
//  MainMenu.cpp
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
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

void MainMenu::run() {
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
			
			_gameState->changeGameState(1);
		}
	}
}

void MainMenu::event() {
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
			
				_gameState->changeGameState(1);
			}
		}
	}
}

bool MainMenu::checkRightCollision(SDL_Rect testRect) {
	if (testRect.x + testRect.w >= 640) {
		return true;
	}
	
	return false;
}

bool MainMenu::checkLeftCollision(SDL_Rect testRectTwo) {
	if (testRectTwo.x <= 0) {
		return true;
	}
	
	return false;
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	renderBackground();
	renderRect();
}

void MainMenu::renderBackground() {
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

void MainMenu::renderRect() {
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
	SDL_RenderFillRect(_renderer, &_rect);
}