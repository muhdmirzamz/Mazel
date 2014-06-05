//
//  GameManager.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"
#include "MainMenu.h"
#include "Level1.h"
#include "Level2.h"

using namespace std;

GameManager::GameManager() {
	
}

void GameManager::changeState(int state) {
	switch (state) {
		case MAIN_MENU: {
			GameState *mainMenu = new MainMenu();
			mainMenu->run();
			delete mainMenu;
			break;
		}
		case LEVEL_ONE: {
			GameState *level1 = new Level1();
			level1->run();
			delete level1;
			break;
		}
		case LEVEL_TWO: {
			GameState *level2 = new Level2();
			level2->run();
			delete level2;
			break;
		}
		default:
			break;
	}
}