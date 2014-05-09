//
//  CollisionDetection.cpp
//  TestTen
//
//  Created by Muhd Mirza on 9/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "CollisionDetection.h"

using namespace std;

CollisionDetection::CollisionDetection() {
	
}

bool CollisionDetection::collidedWithRightSide(SDL_Rect mainMenuSquare, int mainMenuWidth) {
	if (mainMenuSquare.x + mainMenuSquare.w >= mainMenuWidth) {
		return true;
	}
	
	return false;
}

bool CollisionDetection::collidedWithLeftSide(SDL_Rect mainMenuSquareTwo) {
	if (mainMenuSquareTwo.x <= 0) {
		return true;
	}
	
	return false;
}