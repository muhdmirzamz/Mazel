//
//  Level1.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Level1.h"

using namespace std;

Level1::Level1() {
	setup();
}

void Level1::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("Level 1", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Level 1", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	setupObjects();
	setupTextures();
	
	srand((int) time(NULL));
	
	setupFinishRect();
	setupBall();
	setupObstacles();

	_running = true;
}

void Level1::setupObjects() {
	_renderLevel1 = new RenderLevel1();
	if (!_renderLevel1) {
		printErrorMessage("Level 1", "render object for level 1");
	}
	
	_collision = new Collision();
	if (!_collision) {
		printErrorMessage("Level 1", "Collision pointer");
	}
}

void Level1::setupTextures() {
	_ballTexture = loadImageOntoTexture(_ballImage, "images/ball.bmp", _ballTextureRef, _renderer);
	if (!_ballTexture) {
		printErrorMessage("Level 1", "ball");
	}
	
	_finishImageTexture = loadImageOntoTexture(_finishImage, "images/finish.bmp", _finishImageTextureRef, _renderer);
	if (!_finishImageTexture) {
		printErrorMessage("Level 1 ", "Finish image");
	}
}

void Level1::setupBall() {
	_ballRect.x = rand() % 50;
	_ballRect.y = rand() % 50;
	_ballRect.w = 20;
	_ballRect.h = 20;
	
	_ballSpeedXLeft = 10;
	_ballSpeedXRight = 10;
	_ballSpeedYUp = 10;
	_ballSpeedYDown = 10;
}

void Level1::setupFinishRect() {
	/*
		take rand() % 100
		You get a range from 0 - 100
		max is 99(take it down a notch)
		
		Window width is 640
		We want the rectange to spawn between range of 600 - 640(?)
		Make use of max to get a number less than 640
		
		Workaround/Solution is to add a number to 99 to make it less than 640
		Consider rectangle width too
		
		0 - 100
		99 + ___ = <(640 - rectangle width)
		
		491 perhaps?
	*/
	_finishImageRect.x = rand() % 100 + 491;
	_finishImageRect.y = rand() % 100 + 301; // same math concept applies to y-axis
	_finishImageRect.w = 50;
	_finishImageRect.h = 80;
#if DEBUG_MODE == 1
	cout << _finishImageRect.x << endl;
#endif
}

void Level1::setupObstacles() {
	_level1Obstacles[0] = _obstacle1;
	_level1Obstacles[1] = _obstacle2;
	_level1Obstacles[2] = _obstacle3;
	_level1Obstacles[3] = _obstacle4;
	_level1Obstacles[4] = _obstacle5;
	_level1Obstacles[5] = _obstacle6;
	_level1Obstacles[6] = _obstacle7;
	_level1Obstacles[7] = _obstacle8;
	_level1Obstacles[8] = _obstacle9;
	_level1Obstacles[9] = _obstacle10;
	_level1Obstacles[10] = _obstacle11;
	_level1Obstacles[11] = _obstacle12;
	_level1Obstacles[12] = _obstacle13;
	_level1Obstacles[13] = _obstacle14;
	_level1Obstacles[14] = _obstacle15;
	_level1Obstacles[15] = _obstacle16;
	
	for (int i = 0; i <= 16; i++) {
		_level1Obstacles[i].x = 50 + rand() % 640;
		_level1Obstacles[i].y = 50 + rand() % 480;
		_level1Obstacles[i].w = 80;
		_level1Obstacles[i].h = 50;
	}
}

void Level1::run() {
	while (_running) {
		event();
		update();
		checkCollision();
		render();
	}
}

void Level1::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(EXIT);
		}
		
		if (EVENT_TYPE == SDL_KEYDOWN) {
#if DEBUG_MODE == 1
			if (PRESSED_KEY == SDLK_ESCAPE) {
				_running = false;
				
				cleanup();
				
				changeState(EXIT);
			}

			if (PRESSED_KEY == SDLK_c) {
				_running = false;
				
				cleanup();
				
				changeState(LEVEL_TWO);
			}
#endif
			// ball controls
			if (PRESSED_KEY == SDLK_w) {
				_ballSpeedYDown = 10;
				_ballSpeedXRight = 10;
				_ballSpeedXLeft = 10;
				
				_ballRect.y -= _ballSpeedYUp;
#if DEBUG_MODE == 1
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_s) {
				_ballSpeedYUp = 10;
				_ballSpeedXRight = 10;
				_ballSpeedXLeft  = 10;
				
				_ballRect.y += _ballSpeedYDown;
#if DEBUG_MODE == 1
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_a) {
				_ballSpeedXRight = 10;
				_ballSpeedYUp = 10;
				_ballSpeedYDown = 10;
				
				_ballRect.x -= _ballSpeedXLeft;
#if DEBUG_MODE == 1
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_d) {
				_ballSpeedXLeft = 10;
				_ballSpeedYUp = 10;
				_ballSpeedYDown = 10;
				
				_ballRect.x += _ballSpeedXRight;
#if DEBUG_MODE == 1
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
		}
	}
}

void Level1::checkCollision() {
	// wall collision
	if (_collision->ballDidCollideWithWindow(_ballRect)) {
		_running = false;
		
		cleanup();
		
		changeState(GAME_OVER);
	}
	
	// obstacle collision
	// NOTE: arrays start with 0, so watch out for the middle number
	//		 make sure no overflows happen
	for (int i = 0; i <= 16; i++) {
		if (_collision->ballDidCollideWithObstacle(_ballRect, _level1Obstacles[i])) {
			_running = false;
			
			cleanup();
			
			changeState(GAME_OVER);
		}
	}
	
	// collision with finish rectangle
	if (_collision->ballDidCollideWithObstacle(_ballRect, _finishImageRect)) {
		_running = false;
		
		cleanup();
		
		changeState(LEVEL_TWO);
	}
}

void Level1::update() {
	SDL_RenderPresent(_renderer);
}

void Level1::render() {
	_renderLevel1->renderLevel1Background(_renderer);
	_renderLevel1->renderLevel1Ball(_renderer, _ballTexture, _ballRect);
	_renderLevel1->renderLevel1Obstacle1(_renderer, _level1Obstacles);
	_renderLevel1->renderLevel1FinishImage(_renderer, _finishImageTexture, _finishImageRect);
}

void Level1::cleanup() {
	delete _renderLevel1;
	_renderLevel1 = NULL;
	delete _collision;
	_collision = NULL;
	
	SDL_DestroyTexture(_ballTexture);
	_ballTexture = NULL;
	SDL_DestroyTexture(_finishImageTexture);
	_finishImageTexture = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}