//
//  GameManager.cpp
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "MainMenu.h"
#include "LevelOne.h"
#include "LevelTwo.h"

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
			break;
		}
		case LEVEL_TWO: {
			break;
		}
		default:
			break;
	}
}