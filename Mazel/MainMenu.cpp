//
//  MainMenu.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"
#include "Settings.h"

using namespace std;

static Settings settingsObject;
static Settings *settings;

MainMenu::MainMenu() {
	settings = &settingsObject;
	
	setup();
	setupObjects();
	setupTextures();
	setupBall();
}

void MainMenu::setup() {
	_window = initWindow(_windowRef);
	
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
	_instructions = &_instructionsObject;
	_start = &_startObject;
	_settings = &_settingsObject;
	_ball = &_ballObject;
}

void MainMenu::setupTextures() {
	_logo->loadImageOntoTexture("images/MazelLogo.bmp", _renderer);
	_logo->plotGui(LOGO_XPOS, LOGO_YPOS, LOGO_WIDTH_HEIGHT, LOGO_WIDTH_HEIGHT);
	_grass->loadImageOntoTexture("images/main_menu_half_background.bmp", _renderer);
	_grass->plotBackground(0, WINDOW_HEIGHT / 2 + 40, WINDOW_WIDTH, 200);
	_instructions->loadImageOntoTexture("images/mazel_instructions_label.bmp", _renderer);
	_instructions->plotInstructionsImage(WINDOW_WIDTH / 10, WINDOW_HEIGHT - 130);
	_start->loadImageOntoTexture("images/mazelstart.bmp", _renderer);
	_start->plotStartImage(WINDOW_WIDTH / 2 - 80, WINDOW_HEIGHT - 130);
	_settings->loadImageOntoTexture("images/mazel_settings.bmp", _renderer);
	_settings->plotGui(WINDOW_WIDTH / 2 + 100, WINDOW_HEIGHT - 135, 150, 150);
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
		
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			// continue to instructions page
			if (CLICK_AT_XPOS >= _instructions->getX() && CLICK_AT_XPOS <= _instructions->getX() + _instructions->getW()) {
				if (CLICK_AT_YPOS >= _instructions->getY() && CLICK_AT_YPOS <= _instructions->getY() + _instructions->getH()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, INSTRUCTIONS);
				}
			}
			
			// continue to gameplay mode scene
			if (CLICK_AT_XPOS >= _start->getX() && CLICK_AT_XPOS <= _start->getX() + _start->getW()) {
				if (CLICK_AT_YPOS >= _start->getY() && CLICK_AT_YPOS <= _start->getY() + _start->getH()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAMEPLAY_MODE_SCENE);
				}
			}
			
			// continue to settings
			if (CLICK_AT_XPOS >= _settings->getX() && CLICK_AT_XPOS <= _settings->getX() + _settings->getW()) {
				if (CLICK_AT_YPOS >= _settings->getY() && CLICK_AT_YPOS <= _settings->getY() + _settings->getH()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, SETTINGS);
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
	_instructions->render(_renderer);
	_start->render(_renderer);
	_settings->render(_renderer);
	_ball->render(_renderer);
}

void MainMenu::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}