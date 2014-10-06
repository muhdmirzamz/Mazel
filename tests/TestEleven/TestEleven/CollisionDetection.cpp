//
//  CollisionDetection.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "CollisionDetection.h"

using namespace std;

CollisionDetection::CollisionDetection() {
	
}

bool CollisionDetection::didCollideWithRightSide(SDL_Rect obstacle1, int windowWidth) {
	if (obstacle1.x + obstacle1.w >= windowWidth) {
		return true;
	}

	return false; 
}

bool CollisionDetection::didCollideWithLeftSide(SDL_Rect obstacle2) {
	if (obstacle2.x <= 0) {
		return true;
	}

	return false;
}

bool CollisionDetection::didCollideWithTopSide(SDL_Rect obstacle3) {
	if (obstacle3.y <= 0) {
		return true;
	}

	return false;
}

bool CollisionDetection::didCollideWithBottomSide(SDL_Rect obstacle4, int windowHeight1) {
	if (obstacle4.y + obstacle4.h >= windowHeight1) {
		return true;
	}

	return false;
}

bool CollisionDetection::didCollideWithLevel1Obstacle(SDL_Rect obstacle5, SDL_Rect playerRect1) {
	int obstacleLeftSide = obstacle5.x;
	int obstacleTopSide = obstacle5.y;
	
	int playerRectRightSide = playerRect1.x + playerRect1.w;
	int playerRectBottomSide = playerRect1.y + playerRect1.h;
	
	int obstacleRightSide = obstacle5.x + obstacle5.w;
	int obstacleBottomSide = obstacle5.y + obstacle5.h;
	
	int playerRectLeftSide = playerRect1.x;
	int playerRectTopSide = playerRect1.y;

	if (playerRectRightSide >= obstacleLeftSide && playerRectLeftSide <= obstacleRightSide) {
		if (playerRectBottomSide >= obstacleTopSide && playerRectTopSide <= obstacleBottomSide) {
			return true;
		}
	}
	 
	return false;
}