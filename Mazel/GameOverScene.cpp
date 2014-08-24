//
//  GameOverScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 21/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameOverScene.h"

using namespace std;

GameOverScene::GameOverScene() {
	setup();
}

void GameOverScene::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("GameOverScene", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("GameOverScene", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	setupObjects();
	setupTextures();
	
	_running = true;
}

void GameOverScene::setupObjects() {
	_renderGameOverScene = new RenderGameOverScene();
	if (!_renderGameOverScene) {
		printErrorMessage("GameOverScene", "render object");
	}
}

void GameOverScene::setupTextures() {
	_gameOverBackgroundTexture = loadImageOntoTexture(_gameOverBackground, "images/gameover.bmp", _gameOverBackgroundTextureRef, _renderer);
	if (!_gameOverBackgroundTexture) {
		printErrorMessage("GameOverScene", "background texture");
	}
}

void GameOverScene::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void GameOverScene::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
#if DEBUG_MODE == 1
		// tracks mouse coordinates
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			cout << "X-axis: " << POINT_AT_XPOS << endl;
			cout << "Y-axis: " << POINT_AT_YPOS << endl;
		}
#endif
		/*
			Coordinates:
			X: 147 260
			Y: 255 287
		*/
		// x-axis
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= 147 && CLICK_AT_XPOS <= 260) {
				// y-axis
				if (CLICK_AT_YPOS >= 255 && CLICK_AT_YPOS <= 287) {
					_running = false;
					
					cleanup();
					
					changeState(LEVEL_ONE);
				}
			}
		}
	}
}

void GameOverScene::update() {
	SDL_RenderPresent(_renderer);
}

void GameOverScene::render() {
	_renderGameOverScene->renderGameOverSceneBackground(_renderer, _gameOverBackgroundTexture);
}

void GameOverScene::cleanup() {
	SDL_DestroyTexture(_gameOverBackgroundTexture);
	_gameOverBackgroundTexture = NULL;
	
	delete _renderGameOverScene;
	_renderGameOverScene = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}