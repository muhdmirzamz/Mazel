//
//  SettingsPage.cpp
//  Mazel
//
//  Created by Muhd Mirza on 8/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "SettingsPage.h"

SettingsPage::SettingsPage() {
	setup();
	setupObjects();
	setupTextures();
}

void SettingsPage::setup() {
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
	
	// start of difficulty settings flag as false
	_easyDifficultyChosen = false;
	_difficultDifficultyChosen = false;
	_hardDifficultyChosen = false;
}

void SettingsPage::setupObjects() {
	_background = &_backgroundObject;
	_difficulty = &_difficultyObject;
	_easyDifficulty = &_easyDifficultyObject;
	_difficultDifficulty = &_difficultDifficultyObject;
	_hardDifficulty = &_hardDifficultyObject;
}

void SettingsPage::setupTextures() {
	_difficulty->loadImageOntoTexture("images/mazel_settings_difficulty_word.bmp", _renderer);
	_difficulty->plotGui(20, 20, 80, 80);
	
	_easyDifficulty->plotGui(110, 20, 80, 70);
	_difficultDifficulty->plotGui(190, 20, 80, 70);
	_hardDifficulty->plotGui(270, 20, 80, 70);
}

void SettingsPage::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void SettingsPage::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			_gameManager->changeGameState(EXIT);
		}
		
		// clicks
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			// easyDifficulty button
			if (CLICK_AT_XPOS >= _easyDifficulty->getX() && CLICK_AT_XPOS <= _easyDifficulty->getX() + _easyDifficulty->getW()) {
				if (CLICK_AT_YPOS >= _easyDifficulty->getY() && CLICK_AT_YPOS <= _easyDifficulty->getY() + _easyDifficulty->getH()) {
					// reuse the code above to click settings off and on
					// just check the flags
					// when one flag is turned on, the rest turns off
					if (!_easyDifficultyChosen) {
						_easyDifficultyChosen = true;
						_difficultDifficultyChosen = false;
						_hardDifficultyChosen = false;
					} else {
						_easyDifficultyChosen = false;
					}
				}
			}
			
			// difficultDifficulty button
			if (CLICK_AT_XPOS >= _difficultDifficulty->getX() && CLICK_AT_XPOS <= _difficultDifficulty->getX() + _difficultDifficulty->getW()) {
				if (CLICK_AT_YPOS >= _difficultDifficulty->getY() && CLICK_AT_YPOS <= _difficultDifficulty->getY() + _difficultDifficulty->getH()) {
					if (!_difficultDifficultyChosen) {
						_difficultDifficultyChosen = true;
						_easyDifficultyChosen = false;
						_hardDifficultyChosen = false;
					} else {
						_difficultDifficultyChosen = false;
					}
				}
			}
			
			// hardDifficulty button
			if (CLICK_AT_XPOS >= _hardDifficulty->getX() && CLICK_AT_XPOS <= _hardDifficulty->getX() + _hardDifficulty->getW()) {
				if (CLICK_AT_YPOS >= _hardDifficulty->getY() && CLICK_AT_YPOS <= _hardDifficulty->getY() + _hardDifficulty->getH()) {
					if (!_hardDifficultyChosen) {
						_hardDifficultyChosen = true;
						_easyDifficultyChosen = false;
						_difficultDifficultyChosen = false;
					} else {
						_hardDifficultyChosen = false;
					}
				}
			}
		}
	}
}

void SettingsPage::update() {
	SDL_RenderPresent(_renderer);
}

void SettingsPage::render() {
	_background->renderSettingsPageBackground(_renderer);
	_difficulty->render(_renderer);
	
	// if chosen, set it lighter
	if (_easyDifficultyChosen) {
		_easyDifficulty->renderGUI(_renderer, 0, 255, 0);
	} else { // if not, set it darker
		_easyDifficulty->renderGUI(_renderer, 0, 180, 0);
	}
	
	if (_difficultDifficultyChosen) {
		_difficultDifficulty->renderGUI(_renderer, 0, 0, 255);
	} else  {
		_difficultDifficulty->renderGUI(_renderer, 0, 0, 150);
	}
	
	if (_hardDifficultyChosen) {
		_hardDifficulty->renderGUI(_renderer, 255, 0, 0);
	} else {
		_hardDifficulty->renderGUI(_renderer, 180, 0, 0);
	}
}

void SettingsPage::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}