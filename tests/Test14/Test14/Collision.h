//
//  Collision.h
//  Test14
//
//  Created by Muhd Mirza on 3/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test14__Collision__
#define __Test14__Collision__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class Collision {
	public:
		Collision();
	
		bool didCollideWithLeftSideOfWall(SDL_Rect rect1);
		bool didCollideWithRightSideOfWall(SDL_Rect rect1, int rightSideOfWall);
	
	private:
};

#endif /* defined(__Test14__Collision__) */
