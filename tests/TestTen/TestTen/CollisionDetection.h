//
//  CollisionDetection.h
//  TestTen
//
//  Created by Muhd Mirza on 9/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__CollisionDetection__
#define __TestTen__CollisionDetection__

#include <iostream>

#include "SDL_Render.h"

using namespace std;

class CollisionDetection {
	public:
		CollisionDetection();
		
		bool collidedWithRightSide(SDL_Rect mainMenuSquare, int mainMenuWidth);
		bool collidedWithLeftSide(SDL_Rect mainMenuSquareTwo);
		
	private:
};

#endif /* defined(__TestTen__CollisionDetection__) */
