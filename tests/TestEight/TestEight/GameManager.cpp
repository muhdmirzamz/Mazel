//
//  GameManager.cpp
//  TestEight
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"
#include "MainMenu.h"
#include "LevelOne.h"
#include "LevelTwo.h"

using namespace std;

GameManager::GameManager() {
}

void GameManager::changeState(int state) {
	switch (state) {
		case MAIN_MENU:
			GameState *mainMenu = new MainMenu();
			mainMenu->run();
			
			break;
		case LEVEL_ONE:
			break;
		case LEVEL_TWO:
			break;
		default:
			break;
	}
}