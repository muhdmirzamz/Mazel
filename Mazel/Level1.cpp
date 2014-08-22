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
	
	srand((int)time(NULL));
	
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

void Level1::setupObstacles() {
	_level1Obstacles[0] = _obstacle1;
	_level1Obstacles[1] = _obstacle2;
	
	for (int i = 0; i <= 2; i++) {
		_level1Obstacles[i].x = rand() % 640;
		_level1Obstacles[i].y = rand() % 480;
		_level1Obstacles[i].w = 40;
		_level1Obstacles[i].h = 40;
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
	if (_collision->ballDidCollideWithTopOfWindow(_ballRect)) {
		_ballSpeedYUp = 0;
	}
	
	if (_collision->ballDidCollideWithBottomOfWindow(_ballRect)) {
		_ballSpeedYDown = 0;
	}
	
	if (_collision->ballDidCollideWithLeftOfWindow(_ballRect)) {
		_ballSpeedXLeft = 0;
	}
	
	if (_collision->ballDidCollideWithRightOfWindow(_ballRect)) {
		_ballSpeedXRight = 0;
	}
	
	// loop through array to check collision
	for (int i = 0; i <= 2; i++) {
		if (_collision->ballDidCollideWithTopOfObstacle(_ballRect, _level1Obstacles[i])) {
			//_ballSpeedYDown = 0;
			_running = false;
			
			cleanup();
			
			changeState(GAME_OVER);
		}

		if (_collision->ballDidCollideWithBottomOfObstacle(_ballRect, _level1Obstacles[i])) {
			_ballSpeedYUp = 0;
		}
		
		
		if (_collision->ballDidCollideWithLeftOfObstacle(_ballRect, _level1Obstacles[i])) {
			_ballSpeedXRight = 0;
		}
		
		if (_collision->ballDidCollideWithRightOfObstacle(_ballRect, _level1Obstacles[i])) {
			_ballSpeedXLeft = 0;
		}
	}
}

void Level1::update() {
	SDL_RenderPresent(_renderer);
}

void Level1::render() {
	_renderLevel1->renderLevel1Background(_renderer);
	_renderLevel1->renderLevel1Ball(_renderer, _ballTexture, _ballRect);
	_renderLevel1->renderLevel1Obstacle1(_renderer, _level1Obstacles);
}

void Level1::cleanup() {
	delete _renderLevel1;
	_renderLevel1 = NULL;
	delete _collision;
	_collision = NULL;

	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}