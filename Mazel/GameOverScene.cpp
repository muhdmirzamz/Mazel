//
//  GameOverScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 21/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameOverScene.h"
#include "SettingsPage.h"

// this set of gui class constants stay here
// since there's no specific mapping of the "GO" word
static const int START_OF_RETRY_BUTTON = 150;
static const int END_OF_RETRY_BUTTON = (START_OF_RETRY_BUTTON + 120);
static const int START_OF_MAIN_MENU_BUTTON = 290;
static const int END_OF_MAIN_MENU_BUTTON = (START_OF_MAIN_MENU_BUTTON + 210);
static const int TOP_OF_BUTTON = 260;
static const int BOTTOM_OF_BUTTON = (TOP_OF_BUTTON + 40);

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
	_background = &_backgroundObject;
	_image = &_imageObject;
}

void GameOverScene::setupTextures() {
	_image->loadImageOntoTexture("images/gameover.bmp", _renderer);
	_image->plotGui(WINDOW_WIDTH / 8 + 50, 50, 400, 400);
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
			
			changeState(_gameManager, EXIT);
		}
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			cout << "X axis: " << POINT_AT_XPOS << endl;
			cout << "X axis: " << POINT_AT_XPOS << endl;
		}
#endif
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_YPOS >= TOP_OF_BUTTON && CLICK_AT_YPOS <= BOTTOM_OF_BUTTON) {
				// retry button
				if (CLICK_AT_XPOS >= START_OF_RETRY_BUTTON && CLICK_AT_XPOS <= END_OF_RETRY_BUTTON) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, BASIC_LEVEL);
				}
				
				// main menu button
				if (CLICK_AT_XPOS >= START_OF_MAIN_MENU_BUTTON && CLICK_AT_XPOS <= END_OF_MAIN_MENU_BUTTON) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, MAIN_MENU);
				}
			}
		}
	}
}

void GameOverScene::update() {
	SDL_RenderPresent(_renderer);
}

void GameOverScene::render() {
	_background->renderGameOverSceneBackground(_renderer);
	_image->render(_renderer);
}

void GameOverScene::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}