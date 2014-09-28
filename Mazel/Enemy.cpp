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
static const int ENEMY_SPEED_REVERSED = -3;

Enemy::Enemy() {
	
}

void Enemy::plotEnemy(int x, int y) {
	_enemyRect.x = x;
	_enemyRect.y = y;
	_enemyRect.w = ENEMY_WIDTH;
	_enemyRect.h = ENEMY_HEIGHT;
}

void Enemy::setSpeedX() {
	_speedX = ENEMY_SPEED;
}

void Enemy::setSpeedY() {
	_speedY = ENEMY_SPEED;
}

void Enemy::setSpeedXReversed() {
	_speedX = ENEMY_SPEED_REVERSED;
}

void Enemy::setSpeedYReversed() {
	_speedY = ENEMY_SPEED_REVERSED;
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

void Enemy::moveHorizontally() {
	_enemyRect.x += _speedX;
}

void Enemy::moveVertically() {
	_enemyRect.y += _speedY;
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