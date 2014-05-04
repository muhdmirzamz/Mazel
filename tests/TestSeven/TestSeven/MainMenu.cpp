//
//  MainMenu.cpp
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	_windowWidth = 640;
	_windowHeight = 480;

	_window = SDL_CreateWindow(
	"TestSeven",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	_windowWidth,
	_windowHeight,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "MainMenu window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "MainMenu renderer failed to initialise!\n";
	}
	
	_running = true;
	_gameState = new GameState();
	_textRender = new TextRender();
}

void MainMenu::run() {
	_textRender->positionLetterM();

	while (_running) {
		event();
		update();
		render();
	}
}

void MainMenu::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			freeResources();
			
			_running = false;
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	renderBackground();
	_textRender->renderLetterM(_renderer);
}

void MainMenu::renderBackground() {
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

void MainMenu::freeResources() {
	SDL_DestroyWindow(_window);
	_window = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	delete _gameState;
	delete _textRender;
}