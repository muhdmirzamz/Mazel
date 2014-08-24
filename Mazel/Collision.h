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
		
		// a standardised function to check for all sides of window
		bool ballDidCollideWithWindow(SDL_Rect ball5);
		
		// basic collision with obstacles
		bool ballDidCollideWithLeftOfObstacle(SDL_Rect ball6, SDL_Rect obstacle1);
		bool ballDidCollideWithRightOfObstacle(SDL_Rect ball7, SDL_Rect obstacle2);
		bool ballDidCollideWithTopOfObstacle(SDL_Rect ball8, SDL_Rect obstacle3);
		bool ballDidCollideWithBottomOfObstacle(SDL_Rect ball9, SDL_Rect obstacle4);
		
		// a standardised function to check for all sides of obstacles
		bool ballDidCollideWithObstacle(SDL_Rect ball10, SDL_Rect obstacle5);
		
		// main menu collision
		bool ballDidCollideWithGround(SDL_Rect ball10); // bouncing ball collide with ground
		
	private:
};

#endif /* defined(__Mazel__Collision__) */
