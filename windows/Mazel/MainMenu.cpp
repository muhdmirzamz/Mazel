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
	_background = &_backgroundObject;
	_grass = &_grassObject;
	_logo = &_logoObject;
	_start = &_startObject;
	_instructions = &_instructionsObject;
	_ball = &_ballObject;
}

void MainMenu::setupTextures() {
	_logo->loadImageOntoTexture("images/MazelLogo.bmp", _renderer);
	_logo->plotGui(LOGO_XPOS, LOGO_YPOS, LOGO_WIDTH_HEIGHT, LOGO_WIDTH_HEIGHT);
	
	_grass->loadImageOntoTexture("images/main_menu_half_background.bmp", _renderer);
	_grass->plotBackground(0, WINDOW_HEIGHT / 2 + 40, WINDOW_WIDTH, 200);
	
	_start->loadImageOntoTexture("images/mazelstart.bmp", _renderer);
	_start->plotStartImage(WINDOW_WIDTH / 2 - 200, WINDOW_HEIGHT - 130);
	
	_instructions->loadImageOntoTexture("images/mazel_instructions_label.bmp", _renderer);
	_instructions->plotInstructionsImage(WINDOW_WIDTH / 2, WINDOW_HEIGHT - 130);
	
	_ball->loadImageOntoTexture("images/ball.bmp", _renderer);
}

void MainMenu::setupBall() {
	_ball->plotMainMenuBall(20, 20);
	_ball->setMainMenuBallSpeed();
}

void MainMenu::run() {
	while (_running) {
		_ball->moveDown();
	
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
			
			changeState(_gameManager, EXIT);
		}
		
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_KEYDOWN) {
			if (PRESSED_KEY == SDLK_ESCAPE) {
				_running = false;
			
				cleanup();
				
				changeState(_gameManager, EXIT);
			}
		}
#endif
		// continue to game
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= _start->getX() && CLICK_AT_XPOS <= (_start->getX() + _start->getW())) {
				if (CLICK_AT_YPOS >= _start->getY() && CLICK_AT_YPOS <= (_start->getY() + _start->getH())) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, BASIC_LEVEL);
				}
			}
		}
		
		// continue to instructions page
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= _instructions->getX() && CLICK_AT_XPOS <= _instructions->getX() + _instructions->getW()) {
				if (CLICK_AT_YPOS >= _instructions->getY() && CLICK_AT_YPOS <= _instructions->getY() + _instructions->getH()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, INSTRUCTIONS_PAGE);
				}
			}
		}
	}
}

void MainMenu::checkCollision() {
	if (_ball->ballDidCollideWithTopOfWindow(_ball)) {
		_ball->setMainMenuBallSpeed();
	}
	
	if (_ball->ballDidCollideWithGround(_ball)) {
		_ball->setMainMenuBallSpeedReversed();
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	_background->renderMainMenuBackground(_renderer);
	_logo->render(_renderer);
	_grass->renderImage(_renderer);
	_start->render(_renderer);
	_instructions->render(_renderer);
	_ball->render(_renderer);
}

void MainMenu::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}