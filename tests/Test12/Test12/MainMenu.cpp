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
	/*
	_window = SDL_CreateWindow(
	"Test12",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		_gameState->showErrorMessage("MainMenu", "Window");
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		_gameState->showErrorMessage("MainMenu", "Renderer");
	}
	
	_renderObject = new RenderObject();
	
	if (!_renderObject) {
		_gameState->showErrorMessage("Main Menu", "RenderObject");
	}
	
	_running = true;
	*/
	
	if (_gameState->setupWindow(_window) == false) {
		_gameState->showErrorMessage("MainMenu", "Window");
	}
	
	if (!(_gameState->setupRenderer(_renderer, _window))) {
		_gameState->showErrorMessage("MainMenu", "Renderer");
	}
	
	_renderObject = new RenderObject();
	
	if (!_renderObject) {
		_gameState->showErrorMessage("Main Menu", "RenderObject");
	}
	
	_gameState->setRunning(_running);
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
		if (_event.type == SDL_QUIT) {
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
	delete _renderObject;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}