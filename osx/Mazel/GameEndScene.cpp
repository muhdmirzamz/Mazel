//
//  GameEndScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 16/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameEndScene.h"

GameEndScene::GameEndScene() {
	setup();
	setupObjects();
	setupTextures();
}

void GameEndScene::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("GameEndScene", "Window");
	}
	
	_renderer = initRenderer(_window, _renderer);
	if (!_renderer) {
		printErrorMessage("GameEndScene", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void GameEndScene::setupObjects() {
	_background = &_backgroundObject;
	_backgroundImage = &_backgroundImageObject;
}

void GameEndScene::setupTextures() {
	_background->loadImageOntoTexture("images/mazel_congratz_background.bmp", _renderer);
	_background->plotBackground(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	_backgroundImage->loadImageOntoTexture("images/mazel_congratz.bmp", _renderer);
	_backgroundImage->plotGui(100, 10, 400, 400);
}

void GameEndScene::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void GameEndScene::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
	}
}

void GameEndScene::update() {
	SDL_RenderPresent(_renderer);
}

void GameEndScene::render() {
	_background->renderImage(_renderer);
	_backgroundImage->render(_renderer);
}

void GameEndScene::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}