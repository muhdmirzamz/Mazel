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
#if DEBUG_MODE == true
	static int levelCount = 1; // change to level number for easy debugging
#else 
	static int levelCount = 1; // start in level 1
#endif

BasicLevel::BasicLevel() {
#if DEBUG_MODE == true
	cout << "Level count: " << levelCount << endl;
#endif

	setup();
	setupObjects();
	setupTextures();
	setupBall();
	setupFinishRect();
	setupObstaclesAndEnemies();
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
	_background = &_backgroundObject;
	
	_ball = &_ballObject;
	
	_obstacle1 = &_obstacle1Object;
	_obstacle2 = &_obstacle2Object;
	_obstacle3 = &_obstacle3Object;
	_obstacle4 = &_obstacle4Object;
	_obstacle5 = &_obstacle5Object;
	
	_enemy1 = &_enemy1Object;
	_enemy2 = &_enemy2Object;
	_enemy3 = &_enemy3Object;
	
	_finishImage = &_finishImageObject;
}

void BasicLevel::setupTextures() {
	_ball->loadImageOntoTexture("images/ball.bmp", _renderer);
	_finishImage->loadImageOntoTexture("images/finish.bmp", _renderer);
}

void BasicLevel::setupBall() {
	_ball->plotBall(30, 30);
	_ball->setBallSpeed();
}

void BasicLevel::setupFinishRect() {
	if (levelCount <= 5) {
		_finishImage->plotFinishRect(550, 380);
	}
}

// pretty much level design right here
void BasicLevel::setupObstaclesAndEnemies() {
	if (levelCount == 1) {
		_obstacle1->plotObstacle(540, 0, 100, 250);
		_obstacle2->plotObstacle(100, 0, 100, 200);
		_obstacle3->plotObstacle(0, 300, 100, 100);
		_obstacle4->plotObstacle(0, 400, 300, 100);
		_obstacle5->plotObstacle(300, 200, 100, 500);
		
		_enemy1->plotEnemy(0, 210);
		_enemy1->setSpeedX();
// check if enemy speed values were actually set
#if DEBUG_MODE == true
		cout << "SpeedXRight: " << _enemy1->getSpeedXRight() << endl;
		cout << "SpeedXLeft: " << _enemy1->getSpeedXLeft() << endl;
		cout << "SpeedYup: " << _enemy1->getSpeedYUp() << endl;
		cout << "SpeedYDown: " << _enemy1->getSpeedYDown() << endl;
#endif
		
		_enemy2->plotEnemy(210, 170);
		_enemy2->setSpeedX();
		_enemy3->plotEnemy(400, 260);
		_enemy3->setSpeedX();
	}
	
	if (levelCount == 2) {
		_obstacle1->plotObstacle(0, 100, 200, 50);
		_obstacle2->plotObstacle(400, 0, 240, 200);
		_obstacle3->plotObstacle(0, 200, 300, 50);
		_obstacle4->plotObstacle(200, 300, 440, 50);
		_obstacle5->plotObstacle(400, 400, 50, 80);
		
		_enemy1->plotEnemy(310, 0);
		_enemy1->setSpeedY();
		_enemy2->plotEnemy(170, 250);
		_enemy2->setSpeedY();
		_enemy3->plotEnemy(370, 350);
		_enemy3->setSpeedY();
	}
	
	if (levelCount == 3) {
		_obstacle1->plotObstacle(0, 100, 200, 50);
		_obstacle2->plotObstacle(400, 0, 50, 300);
		_obstacle3->plotObstacle(60, 300, 390, 50);
		_obstacle4->plotObstacle(500, 200, 40, 280);
		_obstacle5->plotObstacle(590, 280, 50, 50);

		_enemy1->plotEnemy(220, 0);
		_enemy1->setSpeedY();
		_enemy2->plotEnemy(510, 165);
		_enemy2->setSpeedX();
		_enemy3->plotEnemy(0, 365);
		_enemy3->setSpeedX();
	}
	
	if (levelCount == 4) {
		_obstacle1->plotObstacle(200, 0, 540, 200);
		_obstacle2->plotObstacle(0, 250, 200, 230);
		_obstacle3->plotObstacle(300, 200, 370, 80);
		_obstacle4->plotObstacle(200, 380, 200, 150);
		_obstacle5->plotObstacle(500, 280, 190, 90);
		
		_enemy1->plotEnemy(250, 200);
		_enemy1->setSpeedY();
		_enemy2->plotEnemy(430, 280);
		_enemy2->setSpeedY();
		_enemy3->plotEnemy(0, 170);
		_enemy3->setSpeedX();
	}
	
	if (levelCount == 5) {
		_obstacle1->plotObstacle(100, 0, 250, 400);
		_obstacle2->plotObstacle(0, 150, 50, 50);
		_obstacle3->plotObstacle(0, 300, 60, 80);
		_obstacle4->plotObstacle(350, 0, 300, 300);
		_obstacle5->plotObstacle(450, 350, 50, 130);
		
		_enemy1->plotEnemy(420, 300);
		_enemy1->setSpeedY();
		_enemy2->plotEnemy(355, 300);
		_enemy2->setSpeedY();
		_enemy3->plotEnemy(0, 405);
		_enemy3->setSpeedX();
	}
}

void BasicLevel::run() {
	while (_running) {
		event();
		moveEnemy();

		checkBallAndWindowCollision();
		checkBallAndObstacleCollision();
		checkBallAndFinishRectangleCollision();
		checkBallAndEnemiesCollision();
		checkEnemiesAndWindowCollision();
		checkEnemiesAndObstacleCollision();
		
		update();
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
				levelCount++;
				_running = false;
				
				cleanup();
				
				changeState(_gameManager, NEXT_LEVEL_PAGE);
			}
#endif
			// ball controls
			if (PRESSED_KEY == SDLK_UP) {
				_ball->setBallSpeedYDown();
				_ball->setBallSpeedXRight();
				_ball->setBallSpeedXLeft();
				
				_ball->moveUp();
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ball->getSpeedYUp() << endl;
				cout << "BallSpeedYDown: " << _ball->getSpeedYDown() << endl;
				cout << "BallSpeedXLeft: " << _ball->getSpeedXLeft() << endl;
				cout << "BallSpeedXRight: " << _ball->getSpeedXRight() << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_DOWN) {
				_ball->setBallSpeedYUp();
				_ball->setBallSpeedXRight();
				_ball->setBallSpeedXLeft();
				
				_ball->moveDown();
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ball->getSpeedYUp() << endl;
				cout << "BallSpeedYDown: " << _ball->getSpeedYDown() << endl;
				cout << "BallSpeedXLeft: " << _ball->getSpeedXLeft() << endl;
				cout << "BallSpeedXRight: " << _ball->getSpeedXRight() << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_LEFT) {
				_ball->setBallSpeedXRight();
				_ball->setBallSpeedYUp();
				_ball->setBallSpeedYDown();
				
				_ball->moveLeft();
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ball->getSpeedYUp() << endl;
				cout << "BallSpeedYDown: " << _ball->getSpeedYDown() << endl;
				cout << "BallSpeedXLeft: " << _ball->getSpeedXLeft() << endl;
				cout << "BallSpeedXRight: " << _ball->getSpeedXRight() << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
			
			if (PRESSED_KEY == SDLK_RIGHT) {
				_ball->setBallSpeedXLeft();
				_ball->setBallSpeedYUp();
				_ball->setBallSpeedYDown();
				
				_ball->moveRight();
#if DEBUG_MODE == true
				cout << "BallSpeedYUp: " << _ball->getSpeedYUp() << endl;
				cout << "BallSpeedYDown: " << _ball->getSpeedYDown() << endl;
				cout << "BallSpeedXLeft: " << _ball->getSpeedXLeft() << endl;
				cout << "BallSpeedXRight: " << _ball->getSpeedXRight() << endl;
				
				cout << endl;
				cout << endl;
#endif
			}
		}
	}
}

void BasicLevel::moveEnemy() {
	if (levelCount == 1) {
		_enemy1->moveHorizontally();
		_enemy2->moveHorizontally();
		_enemy3->moveHorizontally();
	}
	
	if (levelCount == 2) {
		_enemy1->moveVertically();
		_enemy2->moveVertically();
		_enemy3->moveVertically();
	}

	if (levelCount == 3) {
		_enemy1->moveVertically();
		_enemy2->moveHorizontally();
		_enemy3->moveHorizontally();
	}
	
	if (levelCount == 4) {
		_enemy1->moveVertically();
		_enemy2->moveVertically();
		_enemy3->moveHorizontally();
	}
	
	if (levelCount == 5) {
		_enemy1->moveVertically();
		_enemy2->moveVertically();
		_enemy3->moveHorizontally();
	}
}

void BasicLevel::checkBallAndWindowCollision() {
	if (_ball->ballDidCollideWithWindow(_ball)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
}

void BasicLevel::checkBallAndObstacleCollision() {
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle1)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle2)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle3)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle4)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle5)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
}

void BasicLevel::checkBallAndFinishRectangleCollision() {
	if (_ball->ballDidCollideWithObstacle(_ball, _finishImage)) {
		// if game is over
		if (levelCount == 5) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_END);
		} else {
			levelCount++; // increment level flag
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, NEXT_LEVEL_PAGE);
		}
	}
}

void BasicLevel::checkBallAndEnemiesCollision() {
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy1)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy2)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
	
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy3)) {
		levelCount = 1; // go back to level 1
		_running = false;
		
		cleanup();
		
		changeState(_gameManager, GAME_OVER);
	}
}

void BasicLevel::checkEnemiesAndWindowCollision() {
	if (_enemy1->enemyDidCollideWithWindow(_enemy1)) {
		_enemy1->bounceBack();
		
// debug output to check if enemy did hit the window
#if DEBUG_MODE == true
		cout << "Enemy hit\n";
#endif
	}
	
	if (_enemy2->enemyDidCollideWithWindow(_enemy2)) {
		_enemy2->bounceBack();
	}
	
	if (_enemy3->enemyDidCollideWithWindow(_enemy3)) {
		_enemy3->bounceBack();
	}
}

void BasicLevel::checkEnemiesAndObstacleCollision() {
	// _enemy1
	if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle1)) {
		_enemy1->bounceBack();
	}
	
	if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle2)) {
		_enemy1->bounceBack();
	}
	
	if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle3)) {
		_enemy1->bounceBack();
	}
	
	if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle4)) {
		_enemy1->bounceBack();
	}
	
	if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle5)) {
		_enemy1->bounceBack();
	}
	
	// _enemy2
	if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle1)) {
		_enemy2->bounceBack();
	}
	
	if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle2)) {
		_enemy2->bounceBack();
	}
	
	if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle3)) {
		_enemy2->bounceBack();
	}
	
	if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle4)) {
		_enemy2->bounceBack();
	}
	
	if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle5)) {
		_enemy2->bounceBack();
	}
	
	// _enemy3
	if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle1)) {
		_enemy3->bounceBack();
	}
	
	if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle2)) {
		_enemy3->bounceBack();
	}
	
	if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle3)) {
		_enemy3->bounceBack();
	}
	
	if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle4)) {
		_enemy3->bounceBack();
	}
	
	if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle5)) {
		_enemy3->bounceBack();
	}
	
	/*
	if (levelCount == 1) {
		if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle5)) {
			_enemy1->setSpeedXReversed();
		}
		
		if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle1)) {
			_enemy2->setSpeedXReversed();
		}
		
		if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle2)) {
			_enemy2->setSpeedX();
		}
		
		if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle5)) {
			_enemy3->setSpeedX();
		}
	}
	
	if (levelCount == 2) {
		if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle4)) {
			_enemy1->setSpeedYReversed();
		}
		
		if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle3)) {
			_enemy2->setSpeedY();
		}
		
		if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle5)) {
			_enemy3->setSpeedY();
		}
		
		if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle4)) {
			_enemy3->setSpeedY();
		}
	}
	
	if (levelCount == 3) {
		if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle3)) {
			_enemy1->setSpeedYReversed();
		}
		
		if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle2)) {
			_enemy2->setSpeedX();
		}
		
		if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle4)) {
			_enemy3->setSpeedXReversed();
		}
	}
	
	if (levelCount == 4) {
		if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle1)) {
			_enemy1->setSpeedY();
		}
		
		if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle4)) {
			_enemy1->setSpeedYReversed();
		}
	
		if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle3)) {
			_enemy2->setSpeedY();
		}
		
		if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle1)) {
			_enemy3->setSpeedXReversed();
		}
	}
	
	if (levelCount == 5) {
		if (_enemy1->enemyDidCollideWithObstacle(_enemy1, _obstacle1)) {
			_enemy1->setSpeedX();
		}
		
		if (_enemy2->enemyDidCollideWithObstacle(_enemy2, _obstacle4)) {
			_enemy2->setSpeedY();
		}
		
		if (_enemy3->enemyDidCollideWithObstacle(_enemy3, _obstacle5)) {
			_enemy3->setSpeedXReversed();
		}
	}
	*/
}

void BasicLevel::update() {
	SDL_RenderPresent(_renderer);
}

void BasicLevel::render() {
	_background->renderBasicLevelBackground(_renderer);
	_ball->render(_renderer);
	
	_obstacle1->render(_renderer);
	_obstacle2->render(_renderer);
	_obstacle3->render(_renderer);
	_obstacle4->render(_renderer);
	_obstacle5->render(_renderer);
	
	_finishImage->renderImage(_renderer);
	
	_enemy1->renderEnemy(_renderer);
	_enemy2->renderEnemy(_renderer);
	_enemy3->renderEnemy(_renderer);
}

void BasicLevel::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}