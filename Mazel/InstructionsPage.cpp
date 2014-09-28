//
//  InstructionsPage.cpp
//  Mazel
//
//  Created by Muhd Mirza on 12/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "InstructionsPage.h"

InstructionsPage::InstructionsPage() {
	setup();
	setupObjects();
	setupTextures();
}

void InstructionsPage::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("InstructionsPage", "Window");
	}
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("InstructionsPage", "Renderer");
	}
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void InstructionsPage::setupObjects() {
	_gui = &_guiObject;
}

void InstructionsPage::setupTextures() {
	_gui->loadImageOntoTexture("images/mazel_instructions.bmp", _renderer);
	_gui->plotGui(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void InstructionsPage::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void InstructionsPage::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
		
#if DEBUG_MODE == true
		if (EVENT_TYPE == SDL_MOUSEMOTION) {
			cout << "XPos: " << POINT_AT_XPOS << endl;
			cout << "YPos: " << POINT_AT_YPOS << endl;
		}
#endif
		if (EVENT_TYPE == SDL_MOUSEBUTTONDOWN) {
			if (POINT_AT_XPOS >= 400 && POINT_AT_XPOS <= 480) {
				if (POINT_AT_YPOS >= 20 && POINT_AT_YPOS <= 90) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, MAIN_MENU);
				}
			}
		}
	}
}

void InstructionsPage::update() {
	SDL_RenderPresent(_renderer);
}

void InstructionsPage::render() {
	_gui->render(_renderer);
}

void InstructionsPage::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}