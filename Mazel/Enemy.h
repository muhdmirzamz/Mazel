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
	
		void setSpeedXLeftZero();
		void setSpeedXRightZero();
		void setSpeedYUpZero();
		void setSpeedYDownZero();
	
		void setSpeedXLeft();
		void setSpeedXRight();
		void setSpeedYUp();
		void setSpeedYDown();
		
		int getX();
		int getY();
		int getW();
		int getH();
	
		int getSpeedX();
		int getSpeedY();
	
		int getSpeedXLeft();
		int getSpeedXRight();
		int getSpeedYUp();
		int getSpeedYDown();
	
		void moveHorizontally();
		void moveVertically();
		void moveInAllDirections();
	
		void moveHorizontallyOnFourAxis();
		void moveVerticallyOnFourAxis();
	
		void bounceBack();
		
		bool enemyDidCollideWithObstacle(Enemy *enemy, Obstacle *obstacle);
		bool enemyDidCollideWithWindow(Enemy *enemy2);
	
		bool enemyDidCollideWithTopOfWindow();
		bool enemyDidCollideWithBottomOfWindow();
		bool enemyDidCollideWithLeftOfWindow();
		bool enemyDidCollideWithRightOfWindow();
	
		void renderEnemy(SDL_Renderer *renderer);
		
	private:
		SDL_Rect _enemyRect;
	
		// two speed axis but each with two speed values
		// normal speed and bouncing speed
		// for level mode
		int _speedX;
		int _speedY;
	
		// for survival mode
		int _speedXLeft;
		int _speedXRight;
		int _speedYUp;
		int _speedYDown;
};

#endif /* defined(__Mazel__Enemy__) */
