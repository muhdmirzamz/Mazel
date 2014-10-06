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
	
		// set all speed values to ensure no arbitrary values are set
		// be very careful with the logic bugs here
		void setSpeedX();
		void setSpeedXBounce();
		void setSpeedY();
		void setSpeedYBounce();
		
		int getX();
		int getY();
		int getW();
		int getH();
	
		int getSpeedX();
		int getSpeedY();
		
		void moveHorizontally();
		void moveVertically();
	
		void bounceBack();
		
		bool enemyDidCollideWithObstacle(Enemy *enemy, Obstacle *obstacle);
		bool enemyDidCollideWithWindow(Enemy *enemy2);
		
		void renderEnemy(SDL_Renderer *renderer);
		
	private:
		SDL_Rect _enemyRect;
	
		// two speed axis but each with two speed values
		// normal speed and bouncing speed
		int _speedX;
		int _speedY;
};

#endif /* defined(__Mazel__Enemy__) */
