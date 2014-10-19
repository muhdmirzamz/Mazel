//
//  SurvivalMode.h
//  Mazel
//
//  Created by Muhd Mirza on 14/10/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__SurvivalMode__
#define __Mazel__SurvivalMode__

#include <iostream>

#include "GameState.h"

using namespace std;

class SurvivalMode: public GameState {
	public:
		SurvivalMode();
	
		void setup();
		void setupObjects();
		void setupTextures();
		void setupBall();
		void setupEnemies();
	
		void run();
		
		void event();
	
		void moveEnemy();
	
		void checkBallAndWindowCollision();
		void checkBallAndEnemiesCollision();
		void checkEnemiesAndWindowCollision();
	
		void update();
		void render();
		
		void cleanup();
	
	private:
		Background _backgroundObject;
		Background *_background;
	
		Ball _ballObject;
		Ball *_ball;
	
		Enemy _enemy1Object;
		Enemy *_enemy1;
};

#endif /* defined(__Mazel__SurvivalMode__) */
