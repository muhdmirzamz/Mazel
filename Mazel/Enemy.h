//
//  Enemy.h
//  Mazel
//	Enemies
//
//  Created by Muhd Mirza on 23/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Enemy__
#define __Mazel__Enemy__

#include <iostream>
#include "Obstacle.h"

using namespace std;

class Enemy {
	public:
		Enemy();
	
		void plotEnemy(int x, int y);
		
		void setSpeedX();
		void setSpeedY();
		
		void setSpeedXReversed();
		void setSpeedYReversed();
		
		int getX();
		int getY();
		int getW();
		int getH();
		
		void moveHorizontally();
		void moveVertically();
		
		bool enemyDidCollideWithObstacle(Enemy *enemy, Obstacle *obstacle);
		bool enemyDidCollideWithWindow(Enemy *enemy2);
		
		void renderEnemy(SDL_Renderer *renderer);
		
	private:
		SDL_Rect _enemyRect;
		
		int _speedX;
		int _speedY;
};

#endif /* defined(__Mazel__Enemy__) */
