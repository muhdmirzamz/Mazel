//
//  Collision.cpp
//  Mazel
//
//  Created by Muhd Mirza on 10/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Collision.h"

using namespace std;

Collision::Collision() {
	
}

bool Collision::ballDidCollideWithTopOfWindow(SDL_Rect ball) {
	int topOfBall = ball.y;

	if (topOfBall < 0) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithBottomOfWindow(SDL_Rect ball2) {
	int ball2Height = ball2.y + ball2.h;

	if (ball2Height > WINDOW_HEIGHT) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithLeftOfWindow(SDL_Rect ball3) {
	int leftOfBall3 = ball3.x;

	if (leftOfBall3 < 0) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithRightOfWindow(SDL_Rect ball4) {
	int widthOfBall4 = ball4.x + ball4.w;
	
	if (widthOfBall4 > WINDOW_WIDTH) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithGround(SDL_Rect ball5) {
	int topOfBall5 = ball5.y;

	if (topOfBall5 >= 300) {
		return true;
	}
	
	return false;
}