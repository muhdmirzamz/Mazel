//
//  BasicLevel.cpp
//  Mazel
//
//  Created by Muhd Mirza on 26/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "BasicLevel.h"

using namespace std;

/* 
	need something that can increase level count
	- without resetting on every constructor call,
	- stay private to the class
	- and initialise with value 1
	only way is to declare a static global variable
	cant use a private variable as value cannot be set straight away
*/
static int levelCount = 1; // change to level number for easy debugging

BasicLevel::BasicLevel() {
#if DEBUG_MODE == true
	cout << "Level count: " << levelCount << endl;
#endif

	setup();
	setupObjects();
	setupTextures();
	setupFinishRect();
	setupBall();
	setupObstacles();
}

void BasicLevel::setup() {
	_window = initWindow(_windowRef);
	if (!_window) {
		printErrorMessage("Level 1", "Window");
	}
	
	_renderer = initRenderer(_window, _rendererRef);
	if (!_renderer) {
		printErrorMessage("Level 1", "Renderer");
	}
	
	setIcon(_window, _icon, "images/MazelLogo.bmp");
	
	_running = true;
}

void BasicLevel::setupObjects() {
	_render = new Render();
	if (!_render) {
		printErrorMessage("Level 1", "render object for level 1");
	}
	
	_collision = new Collision();
	if (!_collision) {
		printErrorMessage("Level 1", "Collision pointer");
	}
}

void BasicLevel::setupTextures() {
	_ballTexture = loadImageOntoTexture(_ballImage, "images/ball.bmp", _ballTextureRef, _renderer);
	if (!_ballTexture) {
		printErrorMessage("Level 1", "ball");
	}
	
	_finishImageTexture = loadImageOntoTexture(_finishImage, "images/finish.bmp", _finishImageTextureRef, _renderer);
	if (!_finishImageTexture) {
		printErrorMessage("Level 1 ", "Finish image");
	}
}

void BasicLevel::setupBall() {
	_ballRect.x = 30;
	_ballRect.y = 30;
	_ballRect.w = BASIC_LEVEL_BALL_WIDTH;
	_ballRect.h = BASIC_LEVEL_BALL_HEIGHT;
	
	_ballSpeedXLeft = BASIC_LEVEL_BALL_SPEED;
	_ballSpeedXRight = BASIC_LEVEL_BALL_SPEED;
	_ballSpeedYUp = BASIC_LEVEL_BALL_SPEED;
	_ballSpeedYDown = BASIC_LEVEL_BALL_SPEED;
}

void BasicLevel::setupFinishRect() {
	if (levelCount <= 5) {
		_finishImageRect.x = 550;
		_finishImageRect.y = 380;
		_finishImageRect.w = BASIC_LEVEL_FINISH_RECT_WIDTH;
		_finishImageRect.h = BASIC_LEVEL_FINISH_RECT_HEIGHT;
#if DEBUG_MODE == true
		cout << "Finish image x pos: " << _finishImageRect.x << endl;
#endif
	}
}

// pretty much level design right here
void BasicLevel::setupObstacles() {
	// level 1
	if (levelCount == 1) {
		_obstacle1 = plotImage(540, 0, 100, 250);
		_obstacle2 = plotImage(100, 0, 100, 200);
		_obstacle3 = plotImage(0, 300, 100, 100);
		_obstacle4 = plotImage(0, 400, 300, 100);
		_obstacle5 = plotImage(300, 200, 100, 500);
		/*
		_obstacle1.x = 540;
		_obstacle1.y = 0;
		_obstacle1.w = 100;
		_obstacle1.h = 250;
		
		_obstacle2.x = 100;
		_obstacle2.y = 0;
		_obstacle2.w = 100;
		_obstacle2.h = 200;
		
		_obstacle3.x = 0;
		_obstacle3.y = 300;
		_obstacle3.w = 100;
		_obstacle3.h = 100;
		
		_obstacle4.x = 0;
		_obstacle4.y = 400;
		_obstacle4.w = 300;
		_obstacle4.h = 100;
		
		_obstacle5.x = 300;
		_obstacle5.y = 200;
		_obstacle5.w = 100;
		_obstacle5.h = 500;
		*/
	}
	
	// level 2
	if (levelCount == 2) {
		_obstacle1 = plotImage(0, 100, 200, 50);
		_obstacle2 = plotImage(400, 0, 240, 200);
		_obstacle3 = plotImage(0, 200, 300, 50);
		_obstacle4 = plotImage(200, 300, 440, 50);
		_obstacle5 = plotImage(400, 400, 50, 80);
		/*
		_obstacle1.x = 0;
		_obstacle1.y = 100;
		_obstacle1.w = 200;
		_obstacle1.h = 50;
		
		_obstacle2.x = 400;
		_obstacle2.y = 0;
		_obstacle2.w = 240;
		_obstacle2.h = 200;
		
		_obstacle3.x = 0;
		_obstacle3.y = 200;
		_obstacle3.w = 300;
		_obstacle3.h = 50;
		
		_obstacle4.x = 200;
		_obstacle4.y = 300;
		_obstacle4.w = 440;
		_obstacle4.h = 50;
		
		_obstacle5.x = 400;
		_obstacle5.y = 400;
		_obstacle5.w = 50;
		_obstacle5.h = 80;
		*/
	}
	
	// level 3
	if (levelCount == 3) {
		_obstacle1 = plotImage(0, 100, 200, 50);
		_obstacle2 = plotImage(400, 0, 50, 300);
		_obstacle3 = plotImage(60, 300, 390, 50);
		_obstacle4 = plotImage(500, 200, 40, 280);
		_obstacle5 = plotImage(590, 280, 50, 50);
		/*
		_obstacle1.x = 0;
		_obstacle1.y = 100;
		_obstacle1.w = 200;
		_obstacle1.h = 50;
		
		_obstacle2.x = 400;
		_obstacle2.y = 0;
		_obstacle2.w = 50;
		_obstacle2.h = 300;
		
		_obstacle3.x = 60;
		_obstacle3.y = 300;
		_obstacle3.w = 390;
		_obstacle3.h = 50;
		
		_obstacle4.x = 500;
		_obstacle4.y = 200;
		_obstacle4.w = 40;
		_obstacle4.h = 280;
		
		_obstacle5.x = 590;
		_obstacle5.y = 280;
		_obstacle5.w = 50;
		_obstacle5.h = 50;
		*/
	}
	
	// level 4
	if (levelCount == 4) {
		_obstacle1 = plotImage(100, 0, 540, 200);
		_obstacle2 = plotImage(0, 250, 200, 230);
		_obstacle3 = plotImage(270, 200, 370, 80);
		_obstacle4 = plotImage(200, 330, 200, 150);
		_obstacle5 = plotImage(450, 280, 190, 90);
		/*
		_obstacle1.x = 100;
		_obstacle1.y = 0;
		_obstacle1.w = 540;
		_obstacle1.h = 200;
		
		_obstacle2.x = 0;
		_obstacle2.y = 250;
		_obstacle2.w = 200;
		_obstacle2.h = 230;
		
		_obstacle3.x = 270;
		_obstacle3.y = 200;
		_obstacle3.w = 370;
		_obstacle3.h = 80;
		
		_obstacle4.x = 200;
		_obstacle4.y = 330;
		_obstacle4.w = 200;
		_obstacle4.h = 150;
		
		_obstacle5.x = 450;
		_obstacle5.y = 280;
		_obstacle5.w = 190;
		_obstacle5.h = 90;
		*/
	}
}

void BasicLevel::run() {
	while (_running) {
		event();
		update();
		checkCollision();
		render();
	}
}

void BasicLevel::event() {
	while (SDL_PollEvent(&_event) != 0) {
		if (EVENT_TYPE == SDL_QUIT) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, EXIT);
		}
		
		if (EVENT_TYPE == SDL_KEYDOWN) {
#if DEBUG_MODE == true
			if (PRESSED_KEY == SDLK_ESCAPE) {
				_running = false;
				
				cleanup();
				
				changeState(_gameManager, EXIT);
			}
			
			if (PRESSED_KEY == SDLK_c) {
				_running = false;
				
				cleanup();
				
				changeState(_gameManager, BASIC_LEVEL);
			}
#endif
			// ball controls
			if (PRESSED_KEY == SDLK_w) {
				_ballSpeedYDown = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedXRight = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedXLeft = BASIC_LEVEL_BALL_SPEED;
				
				_ballRect.y -= _ballSpeedYUp;
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_s) {
				_ballSpeedYUp = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedXRight = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedXLeft  = BASIC_LEVEL_BALL_SPEED;
				
				_ballRect.y += _ballSpeedYDown;
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_a) {
				_ballSpeedXRight = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedYUp = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedYDown = BASIC_LEVEL_BALL_SPEED;
				
				_ballRect.x -= _ballSpeedXLeft;
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ballSpeedYUp << endl;
				cout << "BallSpeedYDown: " << _ballSpeedYDown << endl;
				cout << "BallSpeedXLeft: " << _ballSpeedXLeft << endl;
				cout << "BallSpeedXRight: " << _ballSpeedXRight << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_d) {
				_ballSpeedXLeft = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedYUp = BASIC_LEVEL_BALL_SPEED;
				_ballSpeedYDown = BASIC_LEVEL_BALL_SPEED;
				
				_ballRect.x += _ballSpeedXRight;
#if DEBUG_MODE == true
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

void BasicLevel::checkCollision() {
	// wall collision
	if (_collision->ballDidCollideWithWindow(_ballRect)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	// obstacle collision
	if (_collision->ballDidCollideWithObstacle(_ballRect, _obstacle1)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_collision->ballDidCollideWithObstacle(_ballRect, _obstacle2)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_collision->ballDidCollideWithObstacle(_ballRect, _obstacle3)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_collision->ballDidCollideWithObstacle(_ballRect, _obstacle4)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_collision->ballDidCollideWithObstacle(_ballRect, _obstacle5)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	
	// finish rectangle collision
	if (_collision->ballDidCollideWithObstacle(_ballRect, _finishImageRect)) {
		levelCount++; // go to next level
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, BASIC_LEVEL);
	}
}

void BasicLevel::update() {
	SDL_RenderPresent(_renderer);
}

void BasicLevel::render() {
	_render->renderLevelBackground(_renderer);
	_render->renderTexture(_renderer, _ballTexture, _ballRect);
	
	_render->renderLevelObstacle(_renderer, _obstacle1);
	_render->renderLevelObstacle(_renderer, _obstacle2);
	_render->renderLevelObstacle(_renderer, _obstacle3);
	_render->renderLevelObstacle(_renderer, _obstacle4);
	_render->renderLevelObstacle(_renderer, _obstacle5);
	
	_render->renderTexture(_renderer, _finishImageTexture, _finishImageRect);
}

void BasicLevel::cleanup() {
	delete _render;
	_render = NULL;
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