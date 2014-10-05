//
//  Ball.h
//  Mazel
//	Ball functions for state classes
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Ball__
#define __Mazel__Ball__

#include <iostream>

#include "Includes.h"
#include "Obstacle.h"
#include "Enemy.h"

using namespace std;

class Ball {
	public:
		Ball();
		
		void loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer);
		void plotBall(int x, int y);
		void plotMainMenuBall(int xPos, int yPos);
		
		void setBallSpeed();
		void setBallSpeedXLeft();
		void setBallSpeedXRight();
		void setBallSpeedYUp();
		void setBallSpeedYDown();
		
		// specifically for main menu
		void setMainMenuBallSpeed();
		void setMainMenuBallSpeedReversed();
		
		int getX();
		int getY();
		int getW();
		int getH();
		
		int getSpeedXLeft();
		int getSpeedXRight();
		int getSpeedYUp();
		int getSpeedYDown();
		
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		
		// collision
		bool ballDidCollideWithTopOfWindow(Ball *ball);
		bool ballDidCollideWithWindow(Ball *ball2);
		bool ballDidCollideWithObstacle(Ball *ball3, Obstacle *obstacle);
		bool ballDidCollideWithEnemy(Ball *ball4, Enemy *enemy);
		bool ballDidCollideWithGround(Ball *ball5); // bouncing ball collide with ground
		
		void render(SDL_Renderer *renderer2);
	
	private:
		SDL_Surface *_ballImage;
		SDL_Texture *_ballTexture;
		SDL_Rect _ballRect;
		
		int _ballSpeedXLeft;
		int _ballSpeedXRight;
		int _ballSpeedYUp;
		int _ballSpeedYDown;
};
#endif /* defined(__Mazel__Ball__) */
