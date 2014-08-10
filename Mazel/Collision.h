//
//  Collision.h
//  Mazel
//	checks for collision
//
//  Created by Muhd Mirza on 10/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Collision__
#define __Mazel__Collision__

#include <iostream>

#include "Includes.h"

using namespace std;

class Collision {
	public:
		Collision();
		
		// main menu collision
		bool ballDidCollideWithGround(SDL_Rect ball1); // bouncing ball collide with ground
		
	private:
};

#endif /* defined(__Mazel__Collision__) */
