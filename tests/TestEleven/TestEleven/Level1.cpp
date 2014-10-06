//
//  Level1.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 25/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <cstdlib>
#include <ctime>

#include "Level1.h"

using namespace std;

Level1::Level1() {
	_windowHeight = 480;
	_windowWidth = 640;
	
	_window = SDL_CreateWindow(
	"Test 11",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	_windowWidth,
	_windowHeight,
	SDL_WINDOW_SHOWN
	);
	
	if (!_window) {
		cout << "Level1 window failed to initialise!\n";
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC);
		
	if (!_renderer) {
		cout << "Level1 renderer failed to initialise!\n";
	}
	
	_running = true;
	
	_renderObject = new RenderObject();
	
	_playerRectangleSpeed = 15;
	
	_collisionDetection = new CollisionDetection();
	
	setPlayerRectangle();
	setRectangleObstacle();
}

void Level1::run() {
	while (_running) {
		event();
		update();
		render();
		
		if (_collisionDetection->didCollideWithLevel1Obstacle(_rectangleObstacle1, _playerRectangle)) {
			cleanUp();
			_running = false;
		}
		
		if (_collisionDetection->didCollideWithLevel1Obstacle(_rectangleObstacle2, _playerRectangle)) {
			cleanUp();
			_running = false;
		}
		
		if (_collisionDetection->didCollideWithLevel1Obstacle(_rectangleObstacle3, _playerRectangle)) {
			cleanUp();
			_running = false;
		}

		if (_collisionDetection->didCollideWithLevel1Obstacle(_rectangleObstacle4, _playerRectangle)) {
			cleanUp();
			_running = false;
		}

		if (_collisionDetection->didCollideWithLevel1Obstacle(_rectangleObstacle5, _playerRectangle)) {
			cleanUp();
			_running = false;
		}

		if (_collisionDetection->didCollideWithLevel1Obstacle(_rectangleObstacle6, _playerRectangle)) {
			cleanUp();
			_running = false;
		}

	}
}

void Level1::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (_event.type == SDL_QUIT) {
			cleanUp();
			_running = false;
		}
		
		// for debugging
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_c) {
				cleanUp();
				_running = false;
				
				_gameState->changeGameState(2);
			}
		}
		
		if (_event.type == SDL_KEYDOWN) {
			if (_event.key.keysym.sym == SDLK_a) {
				_playerRectangle.x -= _playerRectangleSpeed;
			}

			if (_event.key.keysym.sym == SDLK_d) {
				_playerRectangle.x += _playerRectangleSpeed;
			}

			if (_event.key.keysym.sym == SDLK_s) {
				_playerRectangle.y += _playerRectangleSpeed;
			}
			
			if (_event.key.keysym.sym == SDLK_w) {
				_playerRectangle.y -= _playerRectangleSpeed;
			}
		}
	}
}

void Level1::update() {
	SDL_RenderPresent(_renderer);
}

void Level1::render() {
	_renderObject->renderLevel1Background(_renderer);
	_renderObject->renderLevel1PlayerRectangle(_renderer, _playerRectangle);
	_renderObject->renderLevel1RectangleObstacle(_renderer, _rectangleObstacle1);
	_renderObject->renderLevel1RectangleObstacle(_renderer, _rectangleObstacle2);
	_renderObject->renderLevel1RectangleObstacle(_renderer, _rectangleObstacle3);
	_renderObject->renderLevel1RectangleObstacle(_renderer, _rectangleObstacle4);
	_renderObject->renderLevel1RectangleObstacle(_renderer, _rectangleObstacle5);
	_renderObject->renderLevel1RectangleObstacle(_renderer, _rectangleObstacle6);
}

void Level1::cleanUp() {
	delete _collisionDetection;
	_collisionDetection = NULL;
	delete _renderObject;
	_renderObject = NULL;
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}

void Level1::setPlayerRectangle() {
	_playerRectangle.x = 10;
	_playerRectangle.y = 10;
	_playerRectangle.w = 10;
	_playerRectangle.h = 10;
}

void Level1::setRectangleObstacle() {
	srand((int) time(0));
	_rectangleObstacle1RandomNum = rand() % 640 + 50;
	
	_rectangleObstacle1.x = _rectangleObstacle1RandomNum;
	_rectangleObstacle1.y = 100;
	_rectangleObstacle1.w = 50;
	_rectangleObstacle1.h = 80;
	
	srand((int) time(0));
	_rectangleObstacle2RandomNum = rand() % 640 + 50;
	
	_rectangleObstacle2.x = _rectangleObstacle2RandomNum;
	_rectangleObstacle2.y = 200;
	_rectangleObstacle2.w = 60;
	_rectangleObstacle2.h = 80;
	
	srand((int) time(0));
	_rectangleObstacle3RandomNum = rand() % 640 + 50;
	
	_rectangleObstacle3.x = _rectangleObstacle3RandomNum;
	_rectangleObstacle3.y = 10;
	_rectangleObstacle3.w = 100;
	_rectangleObstacle3.h = 80;
	
	srand((int) time(0));
	_rectangleObstacle2RandomNum = rand() % 640 + 50;
	
	_rectangleObstacle4.x = _rectangleObstacle4RandomNum;
	_rectangleObstacle4.y = 50;
	_rectangleObstacle4.w = 200;
	_rectangleObstacle4.h = 100;
	
	srand((int) time(0));
	_rectangleObstacle5RandomNum = rand() % 640 + 50;
	
	_rectangleObstacle5.x = _rectangleObstacle5RandomNum;
	_rectangleObstacle5.y = 50;
	_rectangleObstacle5.w = 200;
	_rectangleObstacle5.h = 100;

	srand((int) time(0));
	_rectangleObstacle6RandomNum = rand() % 640 + 50;
	
	_rectangleObstacle6.x = _rectangleObstacle6RandomNum;
	_rectangleObstacle6.y = 50;
	_rectangleObstacle6.w = 200;
	_rectangleObstacle6.h = 100;

}