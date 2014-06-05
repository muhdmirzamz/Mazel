//
//  CollisionDetection.h
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__CollisionDetection__
#define __TestEleven__CollisionDetection__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class CollisionDetection {
	public:
		CollisionDetection();
		
		bool didCollideWithRightSide(SDL_Rect obstacle1, int windowWidth1);
		bool didCollideWithLeftSide(SDL_Rect obstacle2);
		bool didCollideWithTopSide(SDL_Rect obstacle3);
		bool didCollideWithBottomSide(SDL_Rect obstacle4, int windowHeight1);
		
		bool didCollideWithLevel1Obstacle(SDL_Rect obstacle5, SDL_Rect playerRect1);
		
	private:
};

#endif /* defined(__TestEleven__CollisionDetection__) */
