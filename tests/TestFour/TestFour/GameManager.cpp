//
//  GameManager.cpp
//  TestFour
//
//  Created by Muhd Mirza on 24/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "MainMenu.h"
#include "LevelOne.h"

using namespace std;

GameManager::GameManager() {
	
}

void GameManager::changeState(int state) {
	switch (state) {
		case MAIN_MENU: {
			MainMenu *mainMenu = new MainMenu();
			mainMenu->run();
			delete mainMenu;
			break;
		}
		case LEVEL_ONE: {
			LevelOne *levelOne = new LevelOne();
			levelOne->run();
			delete levelOne;
		}
		default:
			break;
	}
}