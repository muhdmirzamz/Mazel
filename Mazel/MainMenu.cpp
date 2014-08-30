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
	setupObjects();
	setupTextures();
	setupBall();
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
	
	_running = true;
}

void MainMenu::setupObjects() {
	_collision = new Collision();
	if (!_collision) {
		printErrorMessage("Main Menu", "Collision pointer");
	}
	
	_render = new Render();
	if (!_render) {
		printErrorMessage("Main Menu", "Render pointer");
	}
}

void MainMenu::setupTextures() {
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
}

void MainMenu::setupBall() {
	_ballRect.x = MAIN_MENU_BALL_XPOS;
	_ballRect.y = MAIN_MENU_BALL_YPOS;
	_ballRect.w = MAIN_MENU_BALL_WIDTH;
	_ballRect.h = MAIN_MENU_BALL_HEIGHT;
	
	_ballSpeedY = MAIN_MENU_BALL_SPEEDY;
}

void MainMenu::run() {
	while (_running) {
		_ballRect.y += _ballSpeedY;
	
		event();
		checkCollision();
		update();
		render();
	}
}

void MainMenu::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
		
			cleanup();
			
			changeState(EXIT);
		}
		
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_KEYDOWN) {
			if (PRESSED_KEY == SDLK_ESCAPE) {
				_running = false;
			
				cleanup();
				
				changeState(EXIT);
			}
		}
#endif
		
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= BEGIN_OF_START_IMAGE && CLICK_AT_XPOS <= END_OF_START_IMAGE) {
				if (CLICK_AT_YPOS >= TOP_OF_START_IMAGE && CLICK_AT_YPOS <= BOTTOM_OF_START_IMAGE) {
					_running = false;
					
					cleanup();
					
					changeState(BASIC_LEVEL);
				}
			}
		}
	}
}

void MainMenu::checkCollision() {
	if (_collision->ballDidCollideWithTopOfWindow(_ballRect)) {
		_ballSpeedY = 5;
	}
	
	if (_collision->ballDidCollideWithGround(_ballRect)) {
		_ballSpeedY = -5;
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	_render->renderMainMenuBackground(_renderer);
	_render->renderMainMenuLogo(_renderer, _logoTexture);
	_render->renderMainMenuGrassBackground(_renderer, _mainMenuHalfBackgroundTexture);
	_render->renderMainMenuStartButton(_renderer, _startTexture);
	_render->renderMainMenuBall(_renderer, _ballTexture, _ballRect);
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
	delete _render;
	_render = NULL;
	
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}