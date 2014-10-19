//
//  GameOverOneLifeScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 12/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameOverOneLifeScene.h"

GameOverOneLifeScene::GameOverOneLifeScene() {
	setup();
	setupObjects();
	setupTextures();
}

void GameOverOneLifeScene::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("GameOverOneLifeScene", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("GameOverOneLifeScene", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void GameOverOneLifeScene::setupObjects() {
	_background = &_backgroundObject;
	_gameOverImage = &_gameOverImageObject;
}

void GameOverOneLifeScene::setupTextures() {
	_gameOverImage->loadImageOntoTexture("images/gameoveronelife.bmp", _renderer);
	_gameOverImage->plotGui(120, 50, 400, 400);
}

void GameOverOneLifeScene::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void GameOverOneLifeScene::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
		
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			// 130 - 500
			cout << "X axis: " << POINT_AT_XPOS << endl;
			
			// 290 - 390
			cout << "Y axis: " << POINT_AT_YPOS << endl;
		}
#endif

		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (POINT_AT_XPOS >= 130 && POINT_AT_XPOS <= 500) {
				if (POINT_AT_YPOS >= 290 && POINT_AT_YPOS <= 390) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, MAIN_MENU);
				}
			}
		}
	}
}

void GameOverOneLifeScene::update() {
	SDL_RenderPresent(_renderer);
}

void GameOverOneLifeScene::render() {
	_background->renderGameOverOneLifeSceneBackground(_renderer);
	_gameOverImage->render(_renderer);
}

void GameOverOneLifeScene::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}