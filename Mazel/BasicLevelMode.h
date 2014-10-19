//
//  BasicLevel.h
//  Mazel
//	the game's first basic level
//
//  Created by Muhd Mirza on 26/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__BasicLevel__
#define __Mazel__BasicLevel__

#include <iostream>

#include "GameState.h"

using namespace std;

class BasicLevelMode: public GameState {
	public:
		BasicLevelMode();
		
		void setup();
		void setupObjects();
		void setupTextures();
		void setupBall();
		void setupFinishRect();
		void setupEnemies();
		void setupObstaclesAndEnemies();
		
		void run();
		
		void event();
		void moveEnemy();
		void checkBallAndWindowCollision();
		void checkBallAndObstacleCollision();
		void checkBallAndFinishRectangleCollision();
		void checkBallAndEnemiesCollision();
		void checkEnemiesAndWindowCollision();
		void checkEnemiesAndObstacleCollision();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		Background _backgroundObject;
		Background *_background;
		
		Ball _ballObject;
		Ball *_ball;
	
		Obstacle _obstacle1Object;
		Obstacle *_obstacle1;
		Obstacle _obstacle2Object;
		Obstacle *_obstacle2;
		Obstacle _obstacle3Object;
		Obstacle *_obstacle3;
		Obstacle _obstacle4Object;
		Obstacle *_obstacle4;
		Obstacle _obstacle5Object;
		Obstacle *_obstacle5;
		
		Obstacle _finishImageObject;
		Obstacle *_finishImage;
	
		Enemy _enemy1Object;
		Enemy *_enemy1;
		
		Enemy _enemy2Object;
		Enemy *_enemy2;
		
		Enemy _enemy3Object;
		Enemy *_enemy3;
};

#endif /* defined(__Mazel__BasicLevel__) */
