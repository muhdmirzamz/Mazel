//
//  MainMenu.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	setup();
}

void MainMenu::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("Main Menu", "Window");
	}
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Main Menu", "Renderer");
	}
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_logoTexture = loadImageOntoTexture(_logo, "images/MazelLogo.bmp", _logoTextureRef, _renderer);
	if (!_logoTexture) {
		printErrorMessage("Main Menu", "image texture");
	}
	
	_mainMenuHalfBackgroundTexture = loadImageOntoTexture(_mainMenuHalfBackground, "images/main_menu_half_background.bmp", _mainMenuHalfBackgroundTextureRef, _renderer);
	if (!_mainMenuHalfBackgroundTexture) {
		printErrorMessage("Main Menu", "Half Background");
	}
	
	_startTexture = loadImageOntoTexture(_startImage, "images/mazelstart.bmp", _startTextureRef, _renderer);
	if (!_startTexture) {
		printErrorMessage("Main Menu", "Start image");
	}
	
	_ballTexture = loadImageOntoTexture(_ballImage, "images/ball.bmp", _ballTextureRef, _renderer);
	if (!_ballTexture) {
		printErrorMessage("Main Menu", "Ball texture");
	}
	
	_collision = new Collision();
	if (!_collision) {
		printErrorMessage("Main Menu", "Collision pointer");
	}
	
	_running = true;
	
	_ballRect.x = 20;
	_ballRect.y = 20;
	_ballRect.w = 40;
	_ballRect.h = 40;
	
	_ballSpeedX = 5;
	_ballSpeedY = 5;
}

void MainMenu::run() {
	while (_running) {
		event();
		moveBall();
		update();
		render();
		
		if (_ballRect.y < 0) {
			_ballSpeedY = 5;
		}
		
		if (_collision->ballDidCollideWithGround(_ballRect)) {
			_ballSpeedY = -5;
		}
	}
}

void MainMenu::event() {
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
		}
		
		if (_event.type == SDL_MOUSEBUTTONDOWN) {
			if (CLICKED_AT_XPOS >= 200 && CLICKED_AT_XPOS <= 400) {
				if (CLICKED_AT_YPOS >= 345 && CLICKED_AT_YPOS <= 545) {
					_running = false;
					
					cleanup();
					
					changeState(LEVEL_ONE);
				}
			}
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	// render background
	SDL_RenderClear(_renderer);
	SDL_SetRenderDrawColor(_renderer, 240, 240, 240, 0);

	// render logo
	_logoTextureRect.x = 180;
	_logoTextureRect.y = 50;
	_logoTextureRect.w = 300;
	_logoTextureRect.h = 300;
	SDL_RenderCopy(_renderer, _logoTexture, NULL, &_logoTextureRect);
	
	// render main menu ground
	_mainMenuHalfBackGroundRect.x = 0;
	_mainMenuHalfBackGroundRect.y = 280;
	_mainMenuHalfBackGroundRect.w = WINDOW_WIDTH;
	_mainMenuHalfBackGroundRect.h = 200;
	SDL_RenderCopy(_renderer, _mainMenuHalfBackgroundTexture, NULL, &_mainMenuHalfBackGroundRect);
	
	// render main menu start button
	_startRect.x = 200;
	_startRect.y = 345;
	_startRect.w = 200;
	_startRect.h = 200;
	SDL_RenderCopy(_renderer, _startTexture, NULL, &_startRect);
	
	// render ball
	SDL_RenderCopy(_renderer, _ballTexture, NULL, &_ballRect);
}

void MainMenu::cleanup() {
	SDL_DestroyTexture(_logoTexture);
	_logoTexture = NULL;
	SDL_DestroyTexture(_mainMenuHalfBackgroundTexture);
	_mainMenuHalfBackgroundTexture = NULL;
	SDL_DestroyTexture(_startTexture);
	_startTexture = NULL;
	SDL_DestroyTexture(_ballTexture);
	_ballTexture = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}

void MainMenu::moveBall() {
	_ballRect.y += _ballSpeedY;
}