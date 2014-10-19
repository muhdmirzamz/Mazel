//
//  SurvivalMode.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "SurvivalMode.h"

SurvivalMode::SurvivalMode() {
	setup();
	setupObjects();
	setupTextures();
	setupBall();
	setupEnemies();
}

void SurvivalMode::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("SurvivalMode", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("SurvivalMode", "Renderer");
	}
	
	_running = true;
}

void SurvivalMode::setupObjects() {
	_background = &_backgroundObject;
	
	_ball = &_ballObject;
	
	_enemy1 = &_enemy1Object;
}

void SurvivalMode::setupTextures() {
	_background->plotBackground(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	_ball->loadImageOntoTexture("images/ball.bmp", _renderer);
	_ball->plotBall(100, 100);
	
	_enemy1->plotEnemy(200, 200);
}

void SurvivalMode::setupBall() {
	_ball->setBallSpeed();
#if DEBUG_MODE == true
	cout << "ball speed x left: " << _ball->getSpeedXLeft() << endl;
	cout << "ball speed x right: " << _ball->getSpeedXRight() << endl;
	cout << "ball speed y up: " << _ball->getSpeedYUp() << endl;
	cout << "ball speed y down: " << _ball->getSpeedYDown() << endl;
#endif
}

void SurvivalMode::setupEnemies() {
	_enemy1->setSpeedXRight();
	_enemy1->setSpeedYDown();
	_enemy1->setSpeedXLeftZero();
	_enemy1->setSpeedYUpZero();
}

void SurvivalMode::run() {
	while (_running) {
		event();
		moveEnemy();
		
		checkBallAndWindowCollision();
		checkBallAndEnemiesCollision();
		checkEnemiesAndWindowCollision();
		
		update();
		render();
	}
}

void SurvivalMode::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
		
		if (EVENT_TYPE == SDL_KEYDOWN) {
			if (PRESSED_KEY == SDLK_UP) {
				_ball->moveUp();
			}
			
			if (PRESSED_KEY == SDLK_DOWN) {
				_ball->moveDown();
			}
			
			if (PRESSED_KEY == SDLK_LEFT) {
				_ball->moveLeft();
			}
			
			if (PRESSED_KEY == SDLK_RIGHT) {
				_ball->moveRight();
			}
		}
	}
}

void SurvivalMode::moveEnemy() {
	_enemy1->moveHorizontallyOnFourAxis();
	_enemy1->moveVerticallyOnFourAxis();
}

void SurvivalMode::checkBallAndWindowCollision() {
	if (_ball->ballDidCollideWithWindow(_ball)) {
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER_SCENE);
	}
}

void SurvivalMode::checkBallAndEnemiesCollision() {
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy1)) {
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER_SCENE);
	}
}

void SurvivalMode::checkEnemiesAndWindowCollision() {
	if (_enemy1->enemyDidCollideWithTopOfWindow()) {
		if (_enemy1->getSpeedXLeft() == 0) {
			_enemy1->setSpeedYUpZero();
			_enemy1->setSpeedYDown();
			_enemy1->setSpeedXRight();
			_enemy1->setSpeedXLeftZero();
		}
		
		if (_enemy1->getSpeedXRight() == 0) {
			_enemy1->setSpeedYUpZero();
			_enemy1->setSpeedYDown();
			_enemy1->setSpeedXLeft();
			_enemy1->setSpeedXRightZero();
		}
	}
	
	if (_enemy1->enemyDidCollideWithBottomOfWindow()) {
		if (_enemy1->getSpeedXLeft() == 0) {
			_enemy1->setSpeedYUp();
			_enemy1->setSpeedYDownZero();
			_enemy1->setSpeedXRight();
			_enemy1->setSpeedXLeftZero();
		}
		
		if (_enemy1->getSpeedXRight() == 0) {
			_enemy1->setSpeedYUp();
			_enemy1->setSpeedYDownZero();
			_enemy1->setSpeedXLeft();
			_enemy1->setSpeedXRightZero();
		}
	}
	
	if (_enemy1->enemyDidCollideWithLeftOfWindow()) {
		if (_enemy1->getSpeedYDown() == 0) {
			_enemy1->setSpeedYUp();
			_enemy1->setSpeedYDownZero();
			_enemy1->setSpeedXRight();
			_enemy1->setSpeedXLeftZero();
		}
		
		if (_enemy1->getSpeedYUp() == 0) {
			_enemy1->setSpeedYDown();
			_enemy1->setSpeedYUpZero();
			_enemy1->setSpeedXRight();
			_enemy1->setSpeedXLeftZero();
		}
	}
	
	if (_enemy1->enemyDidCollideWithRightOfWindow()) {
		if (_enemy1->getSpeedYUp() == 0) {
			_enemy1->setSpeedYDown();
			_enemy1->setSpeedYUpZero();
			_enemy1->setSpeedXRightZero();
			_enemy1->setSpeedXLeft();
		}
		
		if (_enemy1->getSpeedYDown() == 0) {
			_enemy1->setSpeedYUp();
			_enemy1->setSpeedYDownZero();
			_enemy1->setSpeedXRightZero();
			_enemy1->setSpeedXLeft();
		}
	}
}

void SurvivalMode::update() {
	SDL_RenderPresent(_renderer);
}

void SurvivalMode::render() {
	_background->renderSurvivalModeBackground(_renderer);
	
	_ball->render(_renderer);
	
	_enemy1->renderEnemy(_renderer);
}

void SurvivalMode::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}