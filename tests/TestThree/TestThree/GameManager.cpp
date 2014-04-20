//
//  GameManager.cpp
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	
}

void GameManager::changeState(int state) {
	switch (state) {
		case LEVEL_ONE:
			levelOne = new LevelOne();
			levelOne->run();
			break;
		case LEVEL_TWO:
			break;
		default:
			break;
	}
}