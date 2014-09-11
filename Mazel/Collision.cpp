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

// basic collision with window
bool Collision::ballDidCollideWithTopOfWindow(SDL_Rect ball) {
	if (ball.y <= 0) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithWindow(SDL_Rect ball) {
	if (ball.y <= 0) {
		return true;
	}
	
	if (ball.y + ball.h >= WINDOW_HEIGHT) {
		return true;
	}
	
	if (ball.x <= 0) {
		return true;
	}
	
	if (ball.x + ball.w >= WINDOW_WIDTH) {
		return true;
	}
	
	return false;
}

// basic collision with obstacles
bool Collision::ballDidCollideWithObstacle(SDL_Rect ball2, SDL_Rect obstacle) {
	if (ball2.x + ball2.w >= obstacle.x && ball2.x <= obstacle.x + obstacle.w) {
		if (ball2.y + ball2.h >= obstacle.y && ball2.y <= obstacle.y) {
			return true;
		}
	}
	
	if (ball2.x + ball2.w >= obstacle.x && ball2.x <= obstacle.x + obstacle.w) {
		if (ball2.y <= obstacle.y + obstacle.h && ball2.y >= obstacle.y) {
			return true;
		}
	}
		
	if (ball2.y + ball2.h >= obstacle.y && ball2.y <= obstacle.y + obstacle.h) {
		if (ball2.x + ball2.w >= obstacle.x && ball2.x <= obstacle.x) {
			return true;
		}
	}
	
	if (ball2.y + ball2.h >= obstacle.y && ball2.y <= obstacle.y + obstacle.h) {
		if (ball2.x <= obstacle.x + obstacle.w && ball2.x >= obstacle.x) {
			return true;
		}
	}
	
	return false;
}

// main menu collision
bool Collision::ballDidCollideWithGround(SDL_Rect ball10) {
	if (ball10.y >= 300) {
		return true;
	}
	
	return false;
}