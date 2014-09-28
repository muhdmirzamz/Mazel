//
//  NextLevelPage.cpp
//  Mazel
//
//  Created by Muhd Mirza on 13/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "NextLevelPage.h"

// this set of gui class constants stay here
// since there's no specific mapping of the "GO" word
static const int START_OF_GO = 240;
static const int END_OF_GO = START_OF_GO + 150;
static const int TOP_OF_GO = 290;
static const int BOTTOM_OF_GO = TOP_OF_GO + 140;

NextLevelPage::NextLevelPage() {
	setup();
	setupObjects();
	setupTextures();
}

void NextLevelPage::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("NextLevelPage", "_window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("NextLevelPage", "_renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void NextLevelPage::setupObjects() {
	_gui = &_guiObject;
}

void NextLevelPage::setupTextures() {
	_gui->loadImageOntoTexture("images/mazel_next_level.bmp", _renderer);
	_gui->plotGui(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void NextLevelPage::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void NextLevelPage::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			cout << "X axis: " << POINT_AT_XPOS << endl;
			cout << "Y axis: " << POINT_AT_YPOS << endl;
		}
		
		if (EVENT_TYPE == SDL_KEYDOWN) {
			if (PRESSED_KEY == SDLK_c) {
				_running = false;
				
				cleanup();
				
				changeState(_gameManager, BASIC_LEVEL);
			}
		}
#endif

		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (CLICK_AT_XPOS >= START_OF_GO && CLICK_AT_XPOS <= END_OF_GO) {
				if (CLICK_AT_YPOS >= TOP_OF_GO && CLICK_AT_YPOS <= BOTTOM_OF_GO) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, BASIC_LEVEL);
				}
			}
		}
	}
}

void NextLevelPage::update() {
	SDL_RenderPresent(_renderer);
}

void NextLevelPage::render() {
	_gui->render(_renderer);
}

void NextLevelPage::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}