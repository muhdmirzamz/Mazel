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

bool Collision::ballDidCollideWithBottomOfWindow(SDL_Rect ball2) {
	if (ball2.y + ball2.h >= WINDOW_HEIGHT) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithLeftOfWindow(SDL_Rect ball3) {
	if (ball3.x <= 0) {
		return true;
	}
	
	return false;
}

bool Collision::ballDidCollideWithRightOfWindow(SDL_Rect ball4) {
	if (ball4.x + ball4.w >= WINDOW_WIDTH) {
		return true;
	}
	
	return false;
}

// basic collision with obstacles
bool Collision::ballDidCollideWithLeftOfObstacle(SDL_Rect ball6, SDL_Rect obstacle1) {
	if (ball6.y + ball6.h >= obstacle1.y && ball6.y <= obstacle1.y + obstacle1.h) {
		if (ball6.x + ball6.w >= obstacle1.x && ball6.x <= obstacle1.x) {
			return true;
		}
	}
	
	return false;
}

bool Collision::ballDidCollideWithRightOfObstacle(SDL_Rect ball7, SDL_Rect obstacle2) {
	if (ball7.y + ball7.h >= obstacle2.y && ball7.y <= obstacle2.y + obstacle2.h) {
		if (ball7.x <= obstacle2.x + obstacle2.w && ball7.x >= obstacle2.x) {
			return true;
		}
	}
	
	return false;
}

bool Collision::ballDidCollideWithTopOfObstacle(SDL_Rect ball8, SDL_Rect obstacle3) {
	if (ball8.x + ball8.w >= obstacle3.x && ball8.x <= obstacle3.x + obstacle3.w) {
		if (ball8.y + ball8.h >= obstacle3.y && ball8.y <= obstacle3.y) {
			return true;
		}
	}
	
	return false;
}

bool Collision::ballDidCollideWithBottomOfObstacle(SDL_Rect ball9, SDL_Rect obstacleArray4) {
	if (ball9.x + ball9.w >= obstacleArray4.x && ball9.x <= obstacleArray4.x + obstacleArray4.w) {
		if (ball9.y <= obstacleArray4.y + obstacleArray4.h && ball9.y >= obstacleArray4.y) {
			return true;
		}
	}
	
	return false;
}

// main menu collision
bool Collision::ballDidCollideWithGround(SDL_Rect ball5) {
	if (ball5.y >= 300) {
		return true;
	}
	
	return false;
}