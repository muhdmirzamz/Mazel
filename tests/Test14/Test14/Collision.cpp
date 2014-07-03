//
//  Collision.cpp
//  Test14
//
//  Created by Muhd Mirza on 3/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Collision.h"

using namespace std;

Collision::Collision() {
	
}

bool Collision::didCollideWithLeftSideOfWall(SDL_Rect rect1) {
	if (rect1.x <= 0) {
		return true;
	}
	
	return false;
}

bool Collision::didCollideWithRightSideOfWall(SDL_Rect rect1, int rightSideOfWall) {
	if (rect1.x + rect1.w >= rightSideOfWall) {
		return true;
	}
	
	return false;
}