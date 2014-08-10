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

bool Collision::ballDidCollideWithGround(SDL_Rect ball1) {
	if (ball1.y >= 300) {
		return true;
	}
	
	return false;
}