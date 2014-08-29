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
	_render = new Render();
	if (!_render) {
		printErrorMessage("Intro Scene", "Render");
	}
}

void IntroScene::setupTextures() {
	_continueButtonTexture = loadImageOntoTexture(_continueButton, "images/intro_scene_continue_button.bmp", _continueButtonTextureRef, _renderer);
	if (!_continueButtonTexture) {
		printErrorMessage("IntroScene", "Continue button");
	}
	
	_introLogoTexture = loadImageOntoTexture(_introLogo, "images/mazeltitle.bmp", _introLogoTextureRef, _renderer);
	if (!_introLogoTexture) {
		printErrorMessage("IntroScene", "Intro logo");
	}
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
			
			changeState(EXIT);
		}

#if DEBUG_MODE == true
		if (_event.type == SDL_KEYDOWN) {
			if (PRESSED_KEY == SDLK_ESCAPE) {
				_running = false;
				
				cleanup();
				
				changeState(EXIT);
			}
		}
#endif
		
		// click screen to continue to main menu
		if (_event.type == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= 0 && CLICK_AT_XPOS <= WINDOW_WIDTH) {
				if (CLICK_AT_YPOS >= 0 && CLICK_AT_YPOS <= WINDOW_HEIGHT) {
					_running = false;
					
					cleanup();
				
					changeState(MAIN_MENU);
				}
			}
		}
	}
}

void IntroScene::update() {
	SDL_RenderPresent(_renderer);
}

void IntroScene::render() {
	_render->renderIntroSceneBackground(_renderer);
	_render->renderIntroSceneLogo(_renderer, _introLogoTexture);
	_render->renderIntroSceneContinueButton(_renderer, _continueButtonTexture);
}

void IntroScene::cleanup() {
	SDL_DestroyTexture(_introLogoTexture);
	_introLogoTexture = NULL;
	SDL_DestroyTexture(_continueButtonTexture);
	_continueButtonTexture = NULL;
	
	delete _render;
	_render = NULL;
	
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}