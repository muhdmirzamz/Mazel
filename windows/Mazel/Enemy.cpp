//
//  Enemy.cpp
//  Mazel
//
//  Created by Muhd Mirza on 23/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Enemy.h"

static const int ENEMY_WIDTH = 20;
static const int ENEMY_HEIGHT = 20;
static const int ENEMY_SPEED = 3;
static const int ENEMY_SPEED_ZERO = 0;

Enemy::Enemy() {
	
}

void Enemy::plotEnemy(int x, int y) {
	_enemyRect.x = x;
	_enemyRect.y = y;
	_enemyRect.w = ENEMY_WIDTH;
	_enemyRect.h = ENEMY_HEIGHT;
}

void Enemy::setSpeedXLeft() {
	_speedXLeft = ENEMY_SPEED;
	_speedXRight = ENEMY_SPEED_ZERO;
	_speedYUp = ENEMY_SPEED_ZERO;
	_speedYDown = ENEMY_SPEED_ZERO;
}

void Enemy::setSpeedXRight() {
	_speedXRight = ENEMY_SPEED;
	_speedXLeft = ENEMY_SPEED_ZERO;
	_speedYUp = ENEMY_SPEED_ZERO;
	_speedYDown = ENEMY_SPEED_ZERO;
}

void Enemy::setSpeedYUp() {
	_speedYUp = ENEMY_SPEED;
	_speedYDown = ENEMY_SPEED_ZERO;
	_speedXRight = ENEMY_SPEED_ZERO;
	_speedXLeft = ENEMY_SPEED_ZERO;
}

void Enemy::setSpeedYDown() {
	_speedYDown = ENEMY_SPEED;
	_speedYUp = ENEMY_SPEED_ZERO;
	_speedXRight = ENEMY_SPEED_ZERO;
	_speedXLeft = ENEMY_SPEED_ZERO;
}

int Enemy::getX() {
	return _enemyRect.x;
}

int Enemy::getY() {
	return _enemyRect.y;
}

int Enemy::getW() {
	return _enemyRect.w;
}

int Enemy::getH() {
	return _enemyRect.h;
}

int Enemy::getSpeedXRight() {
	return _speedXRight;
}

int Enemy::getSpeedXLeft() {
	return _speedXLeft;
}

int Enemy::getSpeedYUp() {
	return _speedYUp;
}

int Enemy::getSpeedYDown() {
	return _speedYDown;
}

void Enemy::moveHorizontally() {
	if (_speedXRight == ENEMY_SPEED) {
		_enemyRect.x += _speedXRight;
	}
	
	if (_speedXLeft == ENEMY_SPEED) {
		_enemyRect.x -= _speedXLeft;
	}
}

void Enemy::moveVertically() {
	if (_speedYUp == ENEMY_SPEED) {
		_enemyRect.y -= _speedYUp;
	}
	
	if (_speedYDown == ENEMY_SPEED) {
		_enemyRect.y += _speedYDown;
	}
}

void Enemy::bounceBack() {
	// use else if
	// using only if statements will cause the value to reset back to before function
	if (_speedXRight == ENEMY_SPEED) {
		setSpeedXLeft();
	} else if (_speedXLeft == ENEMY_SPEED) {
		setSpeedXRight();
	}
	
	if (_speedYUp == ENEMY_SPEED) {
		setSpeedYDown();
	} else if (_speedYDown == ENEMY_SPEED) {
		setSpeedYUp();
	}
}

bool Enemy::enemyDidCollideWithObstacle(Enemy *enemy, Obstacle *obstacle) {
	if (enemy->getX() + enemy->getW() >= obstacle->getX() && enemy->getX() <= obstacle->getX() + obstacle->getW()) {
		if (enemy->getY() + enemy->getH() >= obstacle->getY() && enemy->getY() <= obstacle->getY()) {
			return true;
		}
	}
	
	if (enemy->getX() + enemy->getW() >= obstacle->getX() && enemy->getX() <= obstacle->getX() + obstacle->getW()) {
		if (enemy->getY() <= obstacle->getY() + obstacle->getH() && enemy->getY() >= obstacle->getY()) {
			return true;
		}
	}
	
	if (enemy->getY() + enemy->getH() >= obstacle->getY() && enemy->getY() <= obstacle->getY() + obstacle->getH()) {
		if (enemy->getX() + enemy->getW() >= obstacle->getX() && enemy->getX() <= obstacle->getX()) {
			return true;
		}
	}
	
	if (enemy->getY() + enemy->getH() >= obstacle->getY() && enemy->getY() <= obstacle->getY() + obstacle->getH()) {
		if (enemy->getX() <= obstacle->getX() + obstacle->getW() && enemy->getX() >= obstacle->getX()) {
			return true;
		}
	}
	
	return false;
}

bool Enemy::enemyDidCollideWithWindow(Enemy *enemy2) {
	if (enemy2->getY() <= 0) {
		return true;
	}
	
	if (enemy2->getY() + enemy2->getH() >= WINDOW_HEIGHT) {
		return true;
	}
	
	if (enemy2->getX() <= 0) {
		return true;
	}
	
	if (enemy2->getX() + enemy2->getW() >= WINDOW_WIDTH) {
		return true;
	}
	
	return false;
}

void Enemy::renderEnemy(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(renderer, &_enemyRect);
}