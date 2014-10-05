//
//  MainMenu.cpp
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	_window = SDL_CreateWindow(
	"TestFive",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	640,
	480,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "MainMenu window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!_renderer) {
		cout << "MainMenu renderer failed to intialise!\n";
	}
	
	_running = true;
	
	_gameState = new GameState();
}

void MainMenu::run() {
	while (_running) {
		events();
		update();
		render();
	}
}

void MainMenu::events() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			SDL_DestroyRenderer(_renderer);
			_renderer = NULL;
			SDL_DestroyWindow(_window);
			_window = NULL;
		
			_running = false;
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_a) {
				SDL_DestroyRenderer(_renderer);
				_renderer = NULL;
				SDL_DestroyWindow(_window);
				_window = NULL;

				_running = false;
					
				_gameState->changeGameState(1);
			}
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	renderBackground();
	drawRectangle();
}

void MainMenu::renderBackground() {
	SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 0);
	SDL_RenderClear(_renderer);
}

void MainMenu::drawRectangle() {
	SDL_Rect rectArray[] = {
	_rect,
	_rectTwo,
	_rectThree,
	_rectFour,
	_rectFive,
	_rectSix,
	_rectSeven,
	_rectEight,
	_rectNine
	};
		
	for (int x = 0; x < 640; x += 100) {
		rectArray[0].x = x;
		rectArray[1].x = x;
		rectArray[2].x = x;
		rectArray[3].x = x;
		rectArray[4].x = x;
		rectArray[5].x = x;
		rectArray[6].x = x;
		rectArray[7].x = x;
		rectArray[8].x = x;
	}
	
	for (int y = 0; y < 480; y += 100) {
		rectArray[0].y = y;
		rectArray[1].y = y;
		rectArray[2].y = y;
		rectArray[3].y = y;
		rectArray[4].y = y;
		rectArray[5].y = y;
		rectArray[6].y = y;
		rectArray[7].y = y;
		rectArray[8].y = y;
	}
	
	for (int w = 0; w < 9; w++) {
		rectArray[0].w = 100;
		rectArray[1].w = 100;
		rectArray[2].w = 100;
		rectArray[3].w = 100;
		rectArray[4].w = 100;
		rectArray[5].w = 100;
		rectArray[6].w = 100;
		rectArray[7].w = 100;
		rectArray[8].w = 100;
	}
	
	for (int h = 0; h < 9; h++) {
		rectArray[0].y = 100;
		rectArray[1].y = 100;
		rectArray[2].y = 100;
		rectArray[3].y = 100;
		rectArray[4].y = 100;
		rectArray[5].y = 100;
		rectArray[6].y = 100;
		rectArray[7].y = 100;
		rectArray[8].y = 100;
	}
	
	SDL_SetRenderDrawColor(_renderer, 0, 0, 255, 0);
	SDL_RenderFillRects(_renderer, &rectArray[0], 9);
}