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
	
	_renderMainMenu = new RenderMainMenu();
	if (!_renderMainMenu) {
		printErrorMessage("Main Menu", "Render pointer");
	}
	
	_running = true;
	
	_ballRect.x = 20;
	_ballRect.y = 20;
	_ballRect.w = 40;
	_ballRect.h = 40;
	
	_ballSpeedY = 5;
}

void MainMenu::run() {
	while (_running) {
		event();
		moveBall();
		checkCollision();
		update();
		render();
	}
}

void MainMenu::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			_running = false;
		
			cleanup();
			
			changeState(EXIT);
		}
		
#if DEBUG_MODE == 1
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_ESCAPE) {
				_running = false;
			
				cleanup();
				
				changeState(EXIT);
			}
		}
#endif
		
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
	_renderMainMenu->renderMainMenuBackground(_renderer);
	_renderMainMenu->renderMainMenuLogo(_renderer, _logoTexture);
	_renderMainMenu->renderMainMenuGrassBackground(_renderer, _mainMenuHalfBackgroundTexture);
	_renderMainMenu->renderMainMenuStartButton(_renderer, _startTexture);
	_renderMainMenu->renderMainMenuBall(_renderer, _ballTexture, _ballRect);
}

void MainMenu::checkCollision() {
	if (_collision->ballDidCollideWithTopOfWindow(_ballRect)) {
		_ballSpeedY = 5;
	}
	
	if (_collision->ballDidCollideWithGround(_ballRect)) {
		_ballSpeedY = -5;
	}
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
	
	delete _collision;
	_collision = NULL;
	delete _renderMainMenu;
	_renderMainMenu = NULL;
	
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}

void MainMenu::moveBall() {
	_ballRect.y += _ballSpeedY;
}