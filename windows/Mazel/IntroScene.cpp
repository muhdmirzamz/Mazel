//
//  IntroScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 6/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "IntroScene.h"

using namespace std;

IntroScene::IntroScene() {
	setup();
	setupObjects();
	setupTextures();
}

void IntroScene::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("IntroScene", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("IntroScene", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void IntroScene::setupObjects() {
	_background = &backgroundObject;
	_introLogo = &_introLogoObject;
	_continueButton = &_continueButtonObject;
}

void IntroScene::setupTextures() {
	_introLogo->loadImageOntoTexture("images/mazeltitle.bmp", _renderer);
	_introLogo->plotGui(LOGO_XPOS, LOGO_YPOS, LOGO_WIDTH_HEIGHT, LOGO_WIDTH_HEIGHT);
	
	_continueButton->loadImageOntoTexture("images/intro_scene_continue_button.bmp", _renderer);
	_continueButton->plotGui(WINDOW_WIDTH / 4 + 20, 280, 300, 300);
}

void IntroScene::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void IntroScene::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}

#if DEBUG_MODE == true
		if (_event.type == SDL_KEYDOWN) {
			if (PRESSED_KEY == SDLK_ESCAPE) {
				_running = false;
				
				cleanup();
				
				changeState(_gameManager, EXIT);
			}
		}
#endif
		
		// click screen to continue to main menu
		if (_event.type == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= 0 && CLICK_AT_XPOS <= WINDOW_WIDTH) {
				if (CLICK_AT_YPOS >= 0 && CLICK_AT_YPOS <= WINDOW_HEIGHT) {
					_running = false;
					
					cleanup();
				
					changeState(_gameManager, MAIN_MENU);
				}
			}
		}
	}
}

void IntroScene::update() {
	SDL_RenderPresent(_renderer);
}

void IntroScene::render() {
	_background->renderIntroSceneBackground(_renderer);
	_introLogo->render(_renderer);
	_continueButton->render(_renderer);
}

void IntroScene::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}