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
	setupObjects();
	setupTextures();
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
	
	_running = true;
}

void GameOverScene::setupObjects() {
	_render = new Render();
	if (!_render) {
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
#if DEBUG_MODE == true
		// tracks mouse coordinates
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			cout << "X-axis: " << POINT_AT_XPOS << endl;
			cout << "Y-axis: " << POINT_AT_YPOS << endl;
		}
#endif
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			// clicked retry
			if (CLICK_AT_XPOS >= 147 && CLICK_AT_XPOS <= 260) {
				if (CLICK_AT_YPOS >= 255 && CLICK_AT_YPOS <= 287) {
					_running = false;
					
					cleanup();
					
					changeState(BASIC_LEVEL);
				}
			}
			
			// clicked main menu
			if (CLICK_AT_XPOS >= 288 && CLICK_AT_XPOS <= 488) {
				if (CLICK_AT_YPOS >= 258 && CLICK_AT_YPOS <= 289) {
					_running = false;
					
					cleanup();
					
					changeState(MAIN_MENU);
				}
			}
		}
	}
}

void GameOverScene::update() {
	SDL_RenderPresent(_renderer);
}

void GameOverScene::render() {
	_render->renderGameOverSceneBackground(_renderer, _gameOverBackgroundTexture);
}

void GameOverScene::cleanup() {
	SDL_DestroyTexture(_gameOverBackgroundTexture);
	_gameOverBackgroundTexture = NULL;
	
	delete _render;
	_render = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}