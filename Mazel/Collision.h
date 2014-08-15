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
		
		// basic collision with window
		bool ballDidCollideWithTopOfWindow(SDL_Rect ball);
		bool ballDidCollideWithBottomOfWindow(SDL_Rect ball2);
		bool ballDidCollideWithLeftOfWindow(SDL_Rect ball3);
		bool ballDidCollideWithRightOfWindow(SDL_Rect ball4);
		
		// main menu collision
		bool ballDidCollideWithGround(SDL_Rect ball5); // bouncing ball collide with ground
		
	private:
};

#endif /* defined(__Mazel__Collision__) */
