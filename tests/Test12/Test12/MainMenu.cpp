//
//  MainMenu.cpp
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	_window = _gameState->setupWindow("Main Menu", "Window");
	_renderer = _gameState->setupRenderer(_window, "Main Menu", "Renderer");
	
	_gameState->setRunning(_running);
	
	_renderObject = new RenderObject();
	
	if (!_renderObject) {
		cout << "Main Menu render object failed to initialise!\n";
	}
}

void MainMenu::run() {
	while (_running) {
		event();
		update();
		render();
	}
}

void MainMenu::event() {
	while (SDL_PollEvent(&_event) != 0) {
		while (_event.type == SDL_QUIT) {
			cleanup();
		
			_running = false;
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	_renderObject->renderMainMenuBackground(_renderer);
}

void MainMenu::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}