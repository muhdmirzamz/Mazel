//
//  SettingsPage.cpp
//  Mazel
//
//  Created by Muhd Mirza on 8/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Settings.h"

// sets all the flags' initial values first
// flags will be "saved" as settings
// and will be the same each time player goes into settings

static bool easyDifficultyChosen = true;
static bool difficultDifficultyChosen = false;
static bool hardDifficultyChosen = false;

static int playerLivesOnEasyDifficulty = 5;
static int playerLivesOnDifficultDifficulty = 3;
static int playerLivesOnHardDifficulty = 1;

static bool enablePracticeMode = false;
static bool disablePracticeMode = true;

static bool enableEnemy = true;
static bool disableEnemy = false;

static bool levelModeSelected = false;
static bool practiceModeSelected = false;
static bool survivalModeSelected = false;

Settings::Settings() {
	setup();
	setupObjects();
	setupTextures();
}

void Settings::setup() {
	_window = initWindow(_window);
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Main Menu", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void Settings::setupObjects() {
	_background = &_backgroundObject;
	
	_difficulty = &_difficultyObject;
	_difficultyGuide = &_difficultyGuideObject;
	
	_easyDifficulty = &_easyDifficultyObject;
	_difficultDifficulty = &_difficultDifficultyObject;
	_hardDifficulty = &_hardDifficultyObject;
	
	_practiceModeToggle = &_practiceModeToggleObject;
	_enablePracticeMode = &_enablePracticeModeObject;
	_disablePracticeMode = &_disablePracticeModeObject;
	
	_enableEnemyInPracticeMode = &_enableEnemyInPracticeModeObject;
	
	_enableEnemy = &_enableEnemyObject;
	_disableEnemy = &_disableEnemyObject;
	
	_backButton = &_backButtonObject;
}

void Settings::setupTextures() {
	_difficulty->loadImageOntoTexture("images/mazel_settings_difficulty_word.bmp", _renderer);
	_difficulty->plotGui(20, 15, 80, 80);
	_difficultyGuide->loadImageOntoTexture("images/mazel_settings_difficulty_guide.bmp", _renderer);
	_difficultyGuide->plotGui(110, 80, 200, 80);
	
	_easyDifficulty->plotGui(110, 15, 80, 70);
	_difficultDifficulty->plotGui(190, 15, 80, 70);
	_hardDifficulty->plotGui(270, 15, 80, 70);
	
	_practiceModeToggle->loadImageOntoTexture("images/mazel_settings_enable_practice_mode.bmp", _renderer);
	_practiceModeToggle->plotGui(10, 200, 100, 80);
	_disablePracticeMode->plotGui(195, 200, 80, 80);
	_enablePracticeMode->plotGui(115, 200, 80, 80);
	
	_enableEnemyInPracticeMode->loadImageOntoTexture("images/mazel_settings_practice_mode_enable_enemy.bmp", _renderer);
	_enableEnemyInPracticeMode->plotGui(10, 300, 100, 80);
	_disableEnemy->plotGui(117, 300, 80, 80);
	_enableEnemy->plotGui(197, 300, 80, 80);
	
	_backButton->loadImageOntoTexture("images/mazel_settings_back.bmp", _renderer);
	_backButton->plotGui(500, 15, 80, 80);
}

void Settings::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void Settings::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			_gameManager->changeGameState(EXIT);
		}
		
		// clicks
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			// back button
			if (CLICK_AT_XPOS >= _backButton->getX() && CLICK_AT_XPOS <= _backButton->getX() + _backButton->getW()) {
				if (CLICK_AT_YPOS >= _backButton->getY() && CLICK_AT_YPOS <= _backButton->getY() + _backButton->getH()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, MAIN_MENU);
				}
			}
		
			// easyDifficulty button
			if (CLICK_AT_XPOS >= _easyDifficulty->getX() && CLICK_AT_XPOS <= _easyDifficulty->getX() + _easyDifficulty->getW()) {
				if (CLICK_AT_YPOS >= _easyDifficulty->getY() && CLICK_AT_YPOS <= _easyDifficulty->getY() + _easyDifficulty->getH()) {
					// reuse the code above to click settings off and on
					// just check the flags
					// when one flag is turned on, the rest turns off
					if (!easyDifficultyChosen) {
						easyDifficultyChosen = true;
						difficultDifficultyChosen = false;
						hardDifficultyChosen = false;
					} else {
						// makes sure there's always a difficulty chosen
						if (!difficultDifficultyChosen && !hardDifficultyChosen) {
							// keep current difficulty if the other two is not set
							easyDifficultyChosen = true;
						} else {
							easyDifficultyChosen = false;
						}
					}
				}
			}
			
			// difficultDifficulty button
			if (CLICK_AT_XPOS >= _difficultDifficulty->getX() && CLICK_AT_XPOS <= _difficultDifficulty->getX() + _difficultDifficulty->getW()) {
				if (CLICK_AT_YPOS >= _difficultDifficulty->getY() && CLICK_AT_YPOS <= _difficultDifficulty->getY() + _difficultDifficulty->getH()) {
					if (!difficultDifficultyChosen) {
						difficultDifficultyChosen = true;
						easyDifficultyChosen = false;
						hardDifficultyChosen = false;
					} else {
						if (!easyDifficultyChosen && !hardDifficultyChosen) {
							difficultDifficultyChosen = true;
						} else {
							difficultDifficultyChosen = false;
						}
					}
				}
			}
			
			// hardDifficulty button
			if (CLICK_AT_XPOS >= _hardDifficulty->getX() && CLICK_AT_XPOS <= _hardDifficulty->getX() + _hardDifficulty->getW()) {
				if (CLICK_AT_YPOS >= _hardDifficulty->getY() && CLICK_AT_YPOS <= _hardDifficulty->getY() + _hardDifficulty->getH()) {
					if (!hardDifficultyChosen) {
						hardDifficultyChosen = true;
						easyDifficultyChosen = false;
						difficultDifficultyChosen = false;
					} else {
						if (!easyDifficultyChosen && !difficultDifficultyChosen) {
							hardDifficultyChosen = true;
						} else {
							hardDifficultyChosen = false;
						}
					}
				}
			}
			
			// disable practice mode
			if (CLICK_AT_XPOS >= _enablePracticeMode->getX() && CLICK_AT_XPOS <= _enablePracticeMode->getX() + _enablePracticeMode->getW()) {
				if (CLICK_AT_YPOS >= _enablePracticeMode->getY() && CLICK_AT_YPOS <= _enablePracticeMode->getY() + _enablePracticeMode->getH()) {
					if (!disablePracticeMode) {
						disablePracticeMode = true;
						enablePracticeMode = false;
					}
				}
			}
			
			// enable practice mode
			if (CLICK_AT_XPOS >= _disablePracticeMode->getX() && CLICK_AT_XPOS <= _disablePracticeMode->getX() + _disablePracticeMode->getW()) {
				if (CLICK_AT_YPOS >= _disablePracticeMode->getY() && CLICK_AT_YPOS <= _disablePracticeMode->getY() + _disablePracticeMode->getH()) {
					if (!enablePracticeMode) {
						disablePracticeMode = false;
						enablePracticeMode = true;
					}
				}
			}
			
			// disable enemy
			if (CLICK_AT_XPOS >= _enableEnemy->getX() && CLICK_AT_XPOS <= _enableEnemy->getX() + _enableEnemy->getW()) {
				if (CLICK_AT_YPOS >= _enableEnemy->getY() && CLICK_AT_YPOS <= _enableEnemy->getY() + _enableEnemy->getH()) {
					// if the other button is not chosen, choose it
					// and disable the current button
					if (!disableEnemy) {
						disableEnemy = true;
						enableEnemy = false;
					}
				}
			}
			
			// enable enemy
			if (CLICK_AT_XPOS >= _disableEnemy->getX() && CLICK_AT_XPOS <= _disableEnemy->getX() + _disableEnemy->getW()) {
				if (CLICK_AT_YPOS >= _disableEnemy->getY() && CLICK_AT_YPOS <= _disableEnemy->getY() + _disableEnemy->getH()) {
					if (!enableEnemy) {
						enableEnemy = true;
						disableEnemy = false;
					}
				}
			}
		}
	}
}

int Settings::getLives() {
	if (easyDifficultyChosen == true) {
		return playerLivesOnEasyDifficulty;
	}
	
	if (difficultDifficultyChosen == true) {
		return playerLivesOnDifficultDifficulty;
	}
	
	if (hardDifficultyChosen == true) {
		return playerLivesOnHardDifficulty;
	}
	
	return 0;
}

int Settings::chosenDifficulty() {
	if (easyDifficultyChosen == true) {
		return EASY;
	}
	
	if (difficultDifficultyChosen == true) {
		return DIFFICULT;
	}
	
	if (hardDifficultyChosen == true) {
		return HARD;
	}
	
	return 0;
}

void Settings::decrementLives() {
	// decrement lives based on difficulty chosen
	if (easyDifficultyChosen == true) {
		playerLivesOnEasyDifficulty--;
	}
	
	if (difficultDifficultyChosen == true) {
		playerLivesOnDifficultDifficulty--;
	}
	
	if (hardDifficultyChosen == true) {
		playerLivesOnHardDifficulty--;
	}
}

bool Settings::isPlayerDeadInEasyDifficulty() {
	if (playerLivesOnEasyDifficulty > 1) {
		return true;
	}
	
	return false;
}

bool Settings::isPlayerDeadInDifficultDifficulty() {
	if (playerLivesOnDifficultDifficulty > 1) {
		return true;
	}
	
	return false;
}

bool Settings::isPlayerDeadInHardDifficulty() {
	if (playerLivesOnHardDifficulty > 0) {
		return true;
	}
	
	return false;
}

bool Settings::isPracticeModeEnabled() {
	if (enablePracticeMode) {
		return true;
	}
	
	if (disablePracticeMode) {
		return false;
	}
	
	return false;
}

bool Settings::doEnemyExists() {
	if (enableEnemy) {
		return false;
	}
	
	if (disableEnemy) {
		return true;
	}
	
	return true;
}

void Settings::didSelectLevelMode() {
	levelModeSelected = true;
}

void Settings::didSelectPracticeMode() {
	practiceModeSelected = true;
}

void Settings::didSelectSurvivalMode() {
	survivalModeSelected = true;
}

int Settings::selectedMode() {
	if (levelModeSelected) {
		return LEVEL_MODE;
	}
	
	if (practiceModeSelected) {
		return PRACTICE_MODE;
	}
	
	if (survivalModeSelected) {
		return SURVIVAL;
	}
	
	return 0;
}

void Settings::update() {
	SDL_RenderPresent(_renderer);
}

void Settings::render() {
	_background->renderSettingsPageBackground(_renderer);

	_difficulty->render(_renderer);
	_difficultyGuide->render(_renderer);
	
	// if chosen, set it lighter
	if (easyDifficultyChosen) {
		_easyDifficulty->renderGUI(_renderer, 0, 255, 0);
	} else { // if not, set it darker
		_easyDifficulty->renderGUI(_renderer, 0, 140, 0);
	}
	
	if (difficultDifficultyChosen) {
		_difficultDifficulty->renderGUI(_renderer, 0, 0, 255);
	} else  {
		_difficultDifficulty->renderGUI(_renderer, 0, 0, 110);
	}
	
	if (hardDifficultyChosen) {
		_hardDifficulty->renderGUI(_renderer, 255, 0, 0);
	} else {
		_hardDifficulty->renderGUI(_renderer, 180, 0, 0);
	}
	
	_practiceModeToggle->render(_renderer);
	
	if (disablePracticeMode) {
		_disablePracticeMode->renderGUI(_renderer, 255, 0, 0);
	} else {
		_disablePracticeMode->renderGUI(_renderer, 140, 0, 0);
	}
	
	// only enable the option to not have enemies if practice mode is enabled
	if (enablePracticeMode) {
		_enablePracticeMode->renderGUI(_renderer, 0, 255, 0);
		
		_enableEnemyInPracticeMode->render(_renderer);
	
		if (enableEnemy == true) {
			_enableEnemy->renderGUI(_renderer, 255, 0, 0);
		} else {
			_enableEnemy->renderGUI(_renderer, 140, 0, 0);
		}
		
		if (disableEnemy == true) {
			_disableEnemy->renderGUI(_renderer, 0, 255, 0);
		} else {
			_disableEnemy->renderGUI(_renderer, 0, 100, 0);
		}
	} else {
		_enablePracticeMode->renderGUI(_renderer, 0, 100, 0);
	}
	
	_backButton->render(_renderer);
}

void Settings::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}