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
	if (ball.y < 0) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithBottomOfWindow(SDL_Rect ball2) {
	if (ball2.y + ball2.h > WINDOW_HEIGHT) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithLeftOfWindow(SDL_Rect ball3) {
	if (ball3.x < 0) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithRightOfWindow(SDL_Rect ball4) {
	if (ball4.x + ball4.w > WINDOW_WIDTH) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithGround(SDL_Rect ball5) {
	if (ball5.y >= 300) {
		return true;
	}
	
	return false;
}