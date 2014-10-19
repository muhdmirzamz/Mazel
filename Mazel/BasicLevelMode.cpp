//
//  BasicLevel.cpp
//  Mazel
//
//  Created by Muhd Mirza on 26/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "BasicLevelMode.h"
#include "Settings.h"

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

// use this to check the player's difficulty selection
static Settings settingsObject;
static Settings *settings;

BasicLevelMode::BasicLevelMode() {
#if DEBUG_MODE == true
	cout << "Level count: " << levelCount << endl;
	cout << "Lives: " << settings->getLives() << endl;
#endif

	setup();
	setupObjects();
	setupTextures();
	setupBall();
	setupFinishRect();
	setupObstaclesAndEnemies();
}

void BasicLevelMode::setup() {
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

void BasicLevelMode::setupObjects() {
	settings = &settingsObject;

	_background = &_backgroundObject;
	
	_ball = &_ballObject;
	
	_obstacle1 = &_obstacle1Object;
	_obstacle2 = &_obstacle2Object;
	_obstacle3 = &_obstacle3Object;
	_obstacle4 = &_obstacle4Object;
	_obstacle5 = &_obstacle5Object;
	
	// if in practice mode
	if (settings->selectedMode() == PRACTICE_MODE) {
		// initialise enemies if they exist
		if (settings->doEnemyExists()) {
			_enemy1 = &_enemy1Object;
			_enemy2 = &_enemy2Object;
			_enemy3 = &_enemy3Object;
		} // if practice mode is enabled, but enemies do not exist, do not initialise, AKA do nothing
	}
	
	// if in level mode
	if (settings->selectedMode() == LEVEL_MODE) {
		_enemy1 = &_enemy1Object;
		_enemy2 = &_enemy2Object;
		_enemy3 = &_enemy3Object;
	}
	
	_finishImage = &_finishImageObject;
}

void BasicLevelMode::setupTextures() {
	_ball->loadImageOntoTexture("images/ball.bmp", _renderer);
	_finishImage->loadImageOntoTexture("images/finish.bmp", _renderer);
}

void BasicLevelMode::setupBall() {
	_ball->plotBall(30, 30);
	_ball->setBallSpeed();
}

void BasicLevelMode::setupFinishRect() {
	if (levelCount <= 5) {
		_finishImage->plotFinishRect(550, 380);
	}
}

// pretty much level design right here
void BasicLevelMode::setupObstaclesAndEnemies() {
	if (levelCount == 1) {
		_obstacle1->plotObstacle(540, 0, 100, 250);
		_obstacle2->plotObstacle(100, 0, 100, 200);
		_obstacle3->plotObstacle(0, 300, 100, 100);
		_obstacle4->plotObstacle(0, 400, 300, 100);
		_obstacle5->plotObstacle(300, 200, 100, 500);
		
		if (settings->selectedMode() == PRACTICE_MODE) {
			if (settings->doEnemyExists()) {
				_enemy1->plotEnemy(0, 210);
				_enemy1->setSpeedX();
// check if enemy speed values were actually set
#if DEBUG_MODE == true
				cout << "SpeedX: " << _enemy1->getSpeedX() << endl;
				cout << "SpeedY: " << _enemy1->getSpeedY() << endl;
#endif
				_enemy2->plotEnemy(210, 170);
				_enemy2->setSpeedX();
				_enemy3->plotEnemy(400, 260);
				_enemy3->setSpeedX();
			}
		}
		
		 if (settings->selectedMode() == LEVEL_MODE) {
			_enemy1->plotEnemy(0, 210);
			_enemy1->setSpeedX();
			_enemy2->plotEnemy(210, 170);
			_enemy2->setSpeedX();
			_enemy3->plotEnemy(400, 260);
			_enemy3->setSpeedX();
		}
	}
	
	if (levelCount == 2) {
		_obstacle1->plotObstacle(0, 100, 200, 50);
		_obstacle2->plotObstacle(400, 0, 240, 200);
		_obstacle3->plotObstacle(0, 200, 300, 50);
		_obstacle4->plotObstacle(200, 300, 440, 50);
		_obstacle5->plotObstacle(400, 400, 50, 80);
		
		if (settings->selectedMode() == PRACTICE_MODE) {
			if (settings->doEnemyExists()) {
				_enemy1->plotEnemy(310, 0);
				_enemy1->setSpeedY();
				_enemy2->plotEnemy(170, 250);
				_enemy2->setSpeedY();
				_enemy3->plotEnemy(370, 350);
				_enemy3->setSpeedY();
			}
		}
		
		 if (settings->selectedMode() == LEVEL_MODE) {
			_enemy1->plotEnemy(310, 0);
			_enemy1->setSpeedY();
			_enemy2->plotEnemy(170, 250);
			_enemy2->setSpeedY();
			_enemy3->plotEnemy(370, 350);
			_enemy3->setSpeedY();
		}
	}
	
	if (levelCount == 3) {
		_obstacle1->plotObstacle(0, 100, 200, 50);
		_obstacle2->plotObstacle(400, 0, 50, 300);
		_obstacle3->plotObstacle(60, 300, 390, 50);
		_obstacle4->plotObstacle(500, 200, 40, 280);
		_obstacle5->plotObstacle(590, 280, 50, 50);

		if (settings->selectedMode() == PRACTICE_MODE) {
			if (settings->doEnemyExists()) {
				_enemy1->plotEnemy(220, 0);
				_enemy1->setSpeedY();
				_enemy2->plotEnemy(510, 165);
				_enemy2->setSpeedX();
				_enemy3->plotEnemy(0, 365);
				_enemy3->setSpeedX();
			}
		}
		
		if (settings->selectedMode() == LEVEL_MODE){
			_enemy1->plotEnemy(220, 0);
			_enemy1->setSpeedY();
			_enemy2->plotEnemy(510, 165);
			_enemy2->setSpeedX();
			_enemy3->plotEnemy(0, 365);
			_enemy3->setSpeedX();
		}
	}
	
	if (levelCount == 4) {
		_obstacle1->plotObstacle(200, 0, 540, 200);
		_obstacle2->plotObstacle(0, 250, 200, 230);
		_obstacle3->plotObstacle(300, 200, 370, 80);
		_obstacle4->plotObstacle(200, 380, 200, 150);
		_obstacle5->plotObstacle(500, 280, 190, 90);
		
		if (settings->selectedMode() == PRACTICE_MODE) {
			if (settings->doEnemyExists()) {
				_enemy1->plotEnemy(250, 200);
				_enemy1->setSpeedY();
				_enemy2->plotEnemy(430, 280);
				_enemy2->setSpeedY();
				_enemy3->plotEnemy(0, 170);
				_enemy3->setSpeedX();
			}
		}
		
		if (settings->selectedMode() == LEVEL_MODE){
			_enemy1->plotEnemy(250, 200);
			_enemy1->setSpeedY();
			_enemy2->plotEnemy(430, 280);
			_enemy2->setSpeedY();
			_enemy3->plotEnemy(0, 170);
			_enemy3->setSpeedX();
		}
	}
	
	if (levelCount == 5) {
		_obstacle1->plotObstacle(100, 0, 250, 400);
		_obstacle2->plotObstacle(0, 150, 50, 50);
		_obstacle3->plotObstacle(0, 300, 60, 80);
		_obstacle4->plotObstacle(350, 0, 300, 300);
		_obstacle5->plotObstacle(450, 350, 50, 130);
		
		if (settings->selectedMode() == PRACTICE_MODE) {
			if (settings->doEnemyExists()) {
				_enemy1->plotEnemy(420, 300);
				_enemy1->setSpeedY();
				_enemy2->plotEnemy(355, 300);
				_enemy2->setSpeedY();
				_enemy3->plotEnemy(0, 405);
				_enemy3->setSpeedX();
			}
		}
		
		if (settings->selectedMode() == LEVEL_MODE){
			_enemy1->plotEnemy(420, 300);
			_enemy1->setSpeedY();
			_enemy2->plotEnemy(355, 300);
			_enemy2->setSpeedY();
			_enemy3->plotEnemy(0, 405);
			_enemy3->setSpeedX();
		}
	}
}

void BasicLevelMode::run() {
	while (_running) {
		event();
		
		// if practice mode is enabled
		if (settings->selectedMode() == PRACTICE_MODE) {
			// if enemies exist, move enemy
			if (settings->doEnemyExists()) {
				moveEnemy();
			} // do nothing
		}
		
		if (settings->selectedMode() == LEVEL_MODE){
			moveEnemy();
		}

		checkBallAndWindowCollision();
		checkBallAndObstacleCollision();
		checkBallAndFinishRectangleCollision();
		
		// if practice mode is enabled
		if (settings->selectedMode() == PRACTICE_MODE) {
			// if enemies exist, enable these functions
			if (settings->doEnemyExists()) {
				checkBallAndEnemiesCollision();
				checkEnemiesAndWindowCollision();
				checkEnemiesAndObstacleCollision();
			} // if practice mode is enabled, and enemies do not exist, do nothing
		}
		
		if (settings->selectedMode() == LEVEL_MODE){ // if practice mode is not enabled, AKA level mode, enable these functions
			checkBallAndEnemiesCollision();
			checkEnemiesAndWindowCollision();
			checkEnemiesAndObstacleCollision();
		}
		
		update();
		render();
	}
}

void BasicLevelMode::event() {
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
				
				changeState(_gameManager, NEXT_LEVEL_SCENE);
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

void BasicLevelMode::moveEnemy() {
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

void BasicLevelMode::checkBallAndWindowCollision() {
	if (_ball->ballDidCollideWithWindow(_ball)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
	
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
				
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}
	}
}

void BasicLevelMode::checkBallAndObstacleCollision() {
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle1)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}
	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle2)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}

	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle3)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}

	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle4)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}

	}
	
	if (_ball->ballDidCollideWithObstacle(_ball, _obstacle5)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}

	}
}

void BasicLevelMode::checkBallAndFinishRectangleCollision() {
	if (_ball->ballDidCollideWithObstacle(_ball, _finishImage)) {
		// if player finishes level 5
		if (levelCount == 5) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_END_SCENE);
		} else {
			levelCount++; // increment level flag
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, NEXT_LEVEL_SCENE);
		}
	}
}

void BasicLevelMode::checkBallAndEnemiesCollision() {
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy1)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}

	}
	
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy2)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}

	}
	
	if (_ball->ballDidCollideWithEnemy(_ball, _enemy3)) {
		if (settings->selectedMode() == PRACTICE_MODE) {
			_running = false;
			
			cleanup();
			
			changeState(_gameManager, GAME_OVER_SCENE);
		}
		
		if (settings->selectedMode() == LEVEL_MODE) {
			if (settings->chosenDifficulty() == EASY) {
				if (settings->isPlayerDeadInEasyDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == DIFFICULT) {
				if (settings->isPlayerDeadInDifficultDifficulty()) {
					settings->decrementLives();
					
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_SCENE);
				} else {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
			
			if (settings->chosenDifficulty() == HARD) {
				if (settings->isPlayerDeadInHardDifficulty()) {
					_running = false;
					
					cleanup();
					
					changeState(_gameManager, GAME_OVER_ONE_LIFE_SCENE);
				}
			}
		}
	}
}

void BasicLevelMode::checkEnemiesAndWindowCollision() {
	if (_enemy1->enemyDidCollideWithWindow(_enemy1)) {
		_enemy1->bounceBack();
		
// debug output to check if enemy did hit the window
#if DEBUG_MODE == true
		cout << "SpeedX: " << _enemy1->getSpeedX() << endl;
		cout << "SpeedY: " << _enemy1->getSpeedY() << endl;
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

void BasicLevelMode::checkEnemiesAndObstacleCollision() {
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
}

void BasicLevelMode::update() {
	SDL_RenderPresent(_renderer);
}

void BasicLevelMode::render() {
	_background->renderBasicLevelBackground(_renderer);
	_ball->render(_renderer);
	
	_obstacle1->render(_renderer);
	_obstacle2->render(_renderer);
	_obstacle3->render(_renderer);
	_obstacle4->render(_renderer);
	_obstacle5->render(_renderer);
	
	_finishImage->renderImage(_renderer);
	
	// if practice mode is enabled
	if (settings->selectedMode() == PRACTICE_MODE) {
		// if enemies exist, render them
		if (settings->doEnemyExists()) {
			_enemy1->renderEnemy(_renderer);
			_enemy2->renderEnemy(_renderer);
			_enemy3->renderEnemy(_renderer);
		} // practice mode without enemies
	}
	
	if (settings->selectedMode() == LEVEL_MODE){ // level mode
		_enemy1->renderEnemy(_renderer);
		_enemy2->renderEnemy(_renderer);
		_enemy3->renderEnemy(_renderer);
	}
}

void BasicLevelMode::cleanup() {
	SDL_DestroyRenderer(_renderer);
	_renderer = NULL;
	SDL_DestroyWindow(_window);
	_window = NULL;
}