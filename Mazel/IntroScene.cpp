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
	
	_renderIntroScene = new RenderIntroScene();
	if (!_renderIntroScene) {
		printErrorMessage("Intro Scene", "Render");
	}
	
	_continueButtonTexture = loadImageOntoTexture(_continueButton, "images/intro_scene_continue_button.bmp", _continueButtonTextureRef, _renderer);
	if (!_continueButtonTexture) {
		printErrorMessage("IntroScene", "Continue button");
	}
	
	_introLogoTexture = loadImageOntoTexture(_introLogo, "images/mazeltitle.bmp", _introLogoTextureRef, _renderer);
	if (!_introLogoTexture) {
		printErrorMessage("IntroScene", "Intro logo");
	}
	
	_running = true;
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
		if (_event.type == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_ESCAPE) {
				_running = false;
				
				cleanup();
				
				changeState(EXIT);
			}
		}
		
		// click screen to continue to main menu
		if (_event.type == SDL_MOUSEBUTTONDOWN) {
			if (CLICKED_AT_XPOS >= 0 && CLICKED_AT_XPOS <= WINDOW_WIDTH) {
				if (CLICKED_AT_YPOS >= 0 && CLICKED_AT_YPOS <= WINDOW_HEIGHT) {
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
	_renderIntroScene->renderIntroSceneBackground(_renderer);
	_renderIntroScene->renderIntroSceneLogo(_renderer, _introLogoTexture);
	_renderIntroScene->renderIntroSceneContinueButton(_renderer, _continueButtonTexture);
}

void IntroScene::cleanup() {
	SDL_DestroyTexture(_introLogoTexture);
	_introLogoTexture = NULL;
	SDL_DestroyTexture(_continueButtonTexture);
	_continueButtonTexture = NULL;
	
	delete _renderIntroScene;
	_renderIntroScene = NULL;
	
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}