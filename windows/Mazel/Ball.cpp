//
//  Ball.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Ball.h"

static const int MAIN_MENU_BALL_WIDTH = 40;
static const int MAIN_MENU_BALL_HEIGHT = 40;

static const int BASIC_LEVEL_BALL_WIDTH = 20;
static const int BASIC_LEVEL_BALL_HEIGHT = 20;

static const int BASIC_LEVEL_BALL_SPEED = 10;

Ball::Ball() {
	
}

void Ball::loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer) {
	// load image
	_ballImage = SDL_LoadBMP(filePathOfImage.c_str());
	
	// get rid of white background
	// comment out for debugging
	SDL_SetColorKey(_ballImage, SDL_TRUE, SDL_MapRGB(_ballImage->format, 255, 255, 255));
	
	_ballTexture = SDL_CreateTextureFromSurface(renderer, _ballImage);
	if (!_ballTexture) {
		cout << "Failed to create texture from surface\n";
	}
	
	// remember to free surface
	SDL_FreeSurface(_ballImage);
	_ballImage = NULL;
}

void Ball::plotBall(int x, int y) {
	_ballRect.x = x;
	_ballRect.y = y;
	_ballRect.w = BASIC_LEVEL_BALL_WIDTH;
	_ballRect.h = BASIC_LEVEL_BALL_HEIGHT;
}

void Ball::plotMainMenuBall(int xPos, int yPos) {
	_ballRect.x = xPos;
	_ballRect.y = yPos;
	_ballRect.w = MAIN_MENU_BALL_WIDTH;
	_ballRect.h = MAIN_MENU_BALL_HEIGHT;
}

void Ball::setBallSpeed() {
	_ballSpeedXLeft = BASIC_LEVEL_BALL_SPEED;
	_ballSpeedXRight = BASIC_LEVEL_BALL_SPEED;
	_ballSpeedYUp = BASIC_LEVEL_BALL_SPEED;
	_ballSpeedYDown = BASIC_LEVEL_BALL_SPEED;
}

void Ball::setBallSpeedXLeft() {
	_ballSpeedXLeft = BASIC_LEVEL_BALL_SPEED;
}

void Ball::setBallSpeedXRight() {
	_ballSpeedXRight = BASIC_LEVEL_BALL_SPEED;
}

void Ball::setBallSpeedYUp() {
	_ballSpeedYUp = BASIC_LEVEL_BALL_SPEED;
}

void Ball::setBallSpeedYDown() {
	_ballSpeedYDown = BASIC_LEVEL_BALL_SPEED;
}

void Ball::setMainMenuBallSpeed() {
	_ballSpeedYDown = 5;
}

void Ball::setMainMenuBallSpeedReversed() {
	_ballSpeedYDown = -5;
}

int Ball::getX() {
	return _ballRect.x;
}

int Ball::getY() {
	return _ballRect.y;
}

int Ball::getW() {
	return _ballRect.w;
}

int Ball::getH() {
	return _ballRect.h;
}

#if DEBUG_MODE == true
int Ball::getSpeedXLeft() {
	return _ballSpeedXLeft;
}

int Ball::getSpeedXRight() {
	return _ballSpeedXRight;
}

int Ball::getSpeedYUp() {
	return _ballSpeedYUp;
}

int Ball::getSpeedYDown() {
	return _ballSpeedYDown;
}
#endif

void Ball::moveLeft() {
	_ballRect.x -= _ballSpeedXLeft;
}

void Ball::moveRight() {
	_ballRect.x += _ballSpeedXRight;
}

void Ball::moveUp() {
	_ballRect.y -= _ballSpeedYUp;
}

void Ball::moveDown() {
	_ballRect.y += _ballSpeedYDown;
}

// basic collision with window
bool Ball::ballDidCollideWithTopOfWindow(Ball *ball) {
	if (ball->getY() <= 0) {
		return true;
	}
	
	return false;
}

bool Ball::ballDidCollideWithWindow(Ball *ball2) {
	if (ball2->getY() <= 0) {
		return true;
	}
	
	if (ball2->getY() + ball2->getH() >= WINDOW_HEIGHT) {
		return true;
	}
	
	if (ball2->getX() <= 0) {
		return true;
	}
	
	if (ball2->getX() + ball2->getW() >= WINDOW_WIDTH) {
		return true;
	}
	
	return false;
}

// basic collision with obstacles
bool Ball::ballDidCollideWithObstacle(Ball *ball3, Obstacle *obstacle) {
	if (ball3->getX() + ball3->getW() >= obstacle->getX() && ball3->getX() <= obstacle->getX() + obstacle->getW()) {
		if (ball3->getY() + ball3->getH() >= obstacle->getY() && ball3->getY() <= obstacle->getY()) {
			return true;
		}
	}
	
	if (ball3->getX() + ball3->getW() >= obstacle->getX() && ball3->getX() <= obstacle->getX() + obstacle->getW()) {
		if (ball3->getY() <= obstacle->getY() + obstacle->getH() && ball3->getY() >= obstacle->getY()) {
			return true;
		}
	}
	
	if (ball3->getY() + ball3->getH() >= obstacle->getY() && ball3->getY() <= obstacle->getY() + obstacle->getH()) {
		if (ball3->getX() + ball3->getW() >= obstacle->getX() && ball3->getX() <= obstacle->getX()) {
			return true;
		}
	}
	
	if (ball3->getY() + ball3->getH() >= obstacle->getY() && ball3->getY() <= obstacle->getY() + obstacle->getH()) {
		if (ball3->getX() <= obstacle->getX() + obstacle->getW() && ball3->getX() >= obstacle->getX()) {
			return true;
		}
	}
	
	return false;
}

bool Ball::ballDidCollideWithEnemy(Ball *ball4, Enemy *enemy) {
	if (ball4->getX() + ball4->getW() >= enemy->getX() && ball4->getX() <= enemy->getX() + enemy->getW()) {
		if (ball4->getY() + ball4->getH() >= enemy->getY() && ball4->getY() <= enemy->getY()) {
			return true;
		}
	}
	
	if (ball4->getX() + ball4->getW() >= enemy->getX() && ball4->getX() <= enemy->getX() + enemy->getW()) {
		if (ball4->getY() <= enemy->getY() + enemy->getH() && ball4->getY() >= enemy->getY()) {
			return true;
		}
	}
	
	if (ball4->getY() + ball4->getH() >= enemy->getY() && ball4->getY() <= enemy->getY() + enemy->getH()) {
		if (ball4->getX() + ball4->getW() >= enemy->getX() && ball4->getX() <= enemy->getX()) {
			return true;
		}
	}
	
	if (ball4->getY() + ball4->getH() >= enemy->getY() && ball4->getY() <= enemy->getY() + enemy->getH()) {
		if (ball4->getX() <= enemy->getX() + enemy->getW() && ball4->getX() >= enemy->getX()) {
			return true;
		}
	}
	
	return false;
}

// main menu collision
bool Ball::ballDidCollideWithGround(Ball *ball5) {
	if (ball5->getY() >= 300) {
		return true;
	}
	
	return false;
}

void Ball::render(SDL_Renderer *renderer2) {
	SDL_SetRenderDrawColor(renderer2, 255, 0, 0, 0);
	SDL_RenderCopy(renderer2, _ballTexture, NULL, &_ballRect);
}