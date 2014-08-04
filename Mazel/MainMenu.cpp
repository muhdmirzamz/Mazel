//
//  MainMenu.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	setup();
	run();
}

void MainMenu::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("Main Menu", "Window");
	}
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Main Menu", "Renderer");
	}
	//setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_imageTexture = loadImageOntoTexture(_image, "images/MazelLogo.bmp", _imageTextureRef, _renderer);
	if (!_imageTexture) {
		printErrorMessage("Main Menu", "image texture");
	}
	
	_running = true;
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
			
			if (_event.key.keysym.sym == SDLK_c) {
				_running = false;
				
				cleanup();
				
				changeState(LEVEL_ONE);
			}
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(_renderer);
}

void MainMenu::render() {
	_imageTextureRect.x = 50;
	_imageTextureRect.y = 50;
	_imageTextureRect.w = 400;
	_imageTextureRect.h = 400;
	SDL_SetRenderDrawColor(_renderer, 240, 240, 240, 0);
	SDL_RenderClear(_renderer);
	SDL_RenderCopy(_renderer, _imageTexture, NULL, &_imageTextureRect);
			
}

void MainMenu::cleanup() {
	//SDL_FreeSurface(_icon);
	//_icon = NULL;
	SDL_DestroyTexture(_imageTexture);
	_imageTexture = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}