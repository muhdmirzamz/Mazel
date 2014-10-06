//
//  MainMenu.cpp
//  Test14
//
//  Created by Muhd Mirza on 3/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

#include <string.h>

using namespace std;

MainMenu::MainMenu() {
	// replace the argumaent pointer with class-level pointer
	_window = setupWindow(_windowRef);
	if (!_window) {
		printError("MainMenu", "Window");
	}
	// use the class-level window pointer as argument here
	_renderer = setupRenderer(_rendererRef, _window);
	if (!_renderer) {
		printError("MainMenu", "Renderer");
	}
	
	_renderObject = new RenderObject();
	if (!_renderObject) {
		printError("MainMenu", "RenderObject");
	}
	
	// image loading
	_titleTexture = loadImage(_titleImage, _titleTextureRef, _renderer, "images/mazeltitle.bmp", 255, 255, 255); // title
	if (!_titleTexture) {
		printError("MainMenu", "Title texture");
	}
	_startTexture = loadImage(_startImage, _startTextureRef, _renderer, "images/mazelstart.bmp", 255, 255, 255); // start button
	if (!_startTexture) {
		printError("MainMenu", "Start texture");
	}
	_ballTexture = loadImage(_ballImage, _ballTextureRef, _renderer, "images/ball.bmp", 255, 255, 255); // ball
	if (!_ballTexture) {
		printError("MainMenu", "Ball texture");
	}
	
	setBall();

	
	_running = true;
}

void MainMenu::setBall() {
	displayImage(_ballRect, 10, 10, BALL_IMAGE_WIDTH, BALL_IMAGE_HEIGHT, _ballTexture, _renderer);
	
	_ballSpeedX = 5;
	_ballSpeedY = 5;
}

void MainMenu::run() {
	while (_running) {	
		event();
		moveBall();
		update();
		render();
		handleWallCollision(_ballRect, WINDOW_WIDTH, WINDOW_HEIGHT, _ballSpeedX, _ballSpeedY);
		display();
		
		cout << _ballRect.x << endl;
		cout << _ballRect.y << endl;
	}
}

void MainMenu::moveBall() {
	_ballRect.x += _ballSpeedX;
	_ballRect.y += _ballSpeedY;
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
	_renderObject->renderLevelOneBackground(_renderer);
}

void MainMenu::display() {
	// title
	displayImage(_titleRect, (WINDOW_WIDTH / 4) + (WINDOW_WIDTH / 8), WINDOW_HEIGHT / 4, TITLE_IMAGE_WIDTH, TITLE_IMAGE_HEIGHT, _titleTexture, _renderer);
	// start
	displayImage(_startRect, 230, 300, START_IMAGE_WIDTH, START_IMAGE_HEIGHT, _startTexture, _renderer);
}

void MainMenu::cleanup() {
	delete _renderObject;
	_renderObject = NULL;

	SDL_DestroyTexture(_titleTexture);
	_titleTexture = NULL;
	SDL_DestroyTexture(_startTexture);
	_startTexture = NULL;
	SDL_DestroyTexture(_ballTexture);
	_ballTexture = NULL;
	
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}

