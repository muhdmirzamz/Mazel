//
//  GameplayModeScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameplayModeScene.h"
#include "Settings.h"

static Settings settingsObject;
static Settings *settings;

GameplayModeScene::GameplayModeScene() {
	setup();
	setupObjects();
	setupTextures();
}

void GameplayModeScene::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("GameplayModeScene", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("GameplayModeScene", "Renderer");
	}
	
	_running = true;
}

void GameplayModeScene::setupObjects() {
	settings = &settingsObject;

	_background = &_backgroundObject;
	
	_practiceMode = &_practiceModeObject;
	_levelMode = &_levelModeObject;
	_survivalMode = &_survivalModeObject;
	
	_backButton = &_backButtonObject;
}

void GameplayModeScene::setupTextures() {
	_background->loadImageOntoTexture("images/mazel_gameplay_mode_background.bmp", _renderer);
	_background->plotBackground(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	_practiceMode->loadImageOntoTexture("images/mazel_gameplay_mode_practice_mode.bmp", _renderer);
	_practiceMode->plotGui(50, WINDOW_HEIGHT / 2 + 50, 150, 150);
	_levelMode->loadImageOntoTexture("images/mazel_gameplay_mode_level_mode.bmp", _renderer);
	_levelMode->plotGui(245, WINDOW_HEIGHT / 9, 150, 150);
	_survivalMode->loadImageOntoTexture("images/mazel_gameplay_mode_survival_mode.bmp", _renderer);
	_survivalMode->plotGui(440, WINDOW_HEIGHT / 2 + 50, 150, 150);
	
	_backButton->loadImageOntoTexture("images/mazel_gameplay_mode_back_button.bmp", _renderer);
	_backButton->plotGui(550, 20, 80, 80);
}

void GameplayModeScene::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void GameplayModeScene::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
		
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			cout << "X-axis: " << POINT_AT_XPOS << endl;
		}
#endif
		
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			// if practice mode is enabled
			if (settings->isPracticeModeEnabled()) {
				// go practice mode
				if (CLICK_AT_XPOS >= _practiceMode->getX() && CLICK_AT_XPOS <= _practiceMode->getX() + _practiceMode->getY()) {
					if (CLICK_AT_YPOS >= _practiceMode->getY() && CLICK_AT_YPOS <= _practiceMode->getY() + _practiceMode->getH()) {
						_running = false;
						
						settings->didSelectPracticeMode();
						
						cleanup();
						
						changeState(_gameManager, BASIC_LEVEL_MODE);
					}
				}
			}// else player can't click the mode
			
			// go to level mode
			if (CLICK_AT_XPOS >= _levelMode->getX() && CLICK_AT_XPOS <= _levelMode->getX() + _levelMode->getW()) {
				if (CLICK_AT_YPOS >= _levelMode->getY() && CLICK_AT_YPOS <= _levelMode->getY() + _levelMode->getH()) {
					_running = false;
					
					settings->didSelectLevelMode();
					
					cleanup();
					
					changeState(_gameManager, BASIC_LEVEL_MODE);
				}
			}
			
			// go to survival mode
			if (CLICK_AT_XPOS >= _survivalMode->getX() && CLICK_AT_XPOS <= _survivalMode->getX() + _survivalMode->getY()) {
				if (CLICK_AT_YPOS >= _survivalMode->getY() && CLICK_AT_YPOS <= _survivalMode->getY() + _survivalMode->getH()) {
					_running = false;
					
					settings->didSelectSurvivalMode();
					
					cleanup();
					
					changeState(_gameManager, SURVIVAL_MODE);
				}
			}
			
			// go back to main menu
			if (CLICK_AT_XPOS >= _backButton->getX() && CLICK_AT_XPOS <= _backButton->getX() + _backButton->getW()) {
				if (CLICK_AT_YPOS >= _backButton->getY() && CLICK_AT_YPOS <= _backButton->getY() + _backButton->getH()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, MAIN_MENU);
				}
			}
		}
	}
}

void GameplayModeScene::update() {
	SDL_RenderPresent(_renderer);
}

void GameplayModeScene::render() {
	_background->renderImage(_renderer);
	
	_practiceMode->render(_renderer);
	_levelMode->render(_renderer);
	_survivalMode->render(_renderer);
	
	_backButton->render(_renderer);
}

void GameplayModeScene::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}