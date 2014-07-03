//
//  GameManager.cpp
//  Test14
//
//  Created by Muhd Mirza on 2/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"
#include "MainMenu.h"

using namespace std;

GameManager::GameManager() {
	
}

void GameManager::changeGameState(int state) {
	switch (state) {
		case MAIN_MENU: {
			GameState *mainMenu = new MainMenu();
			mainMenu->run();
			delete mainMenu;
			break;
		}
		/*
		case LEVEL_ONE:
			break;
		case LEVEL_TWO:
			break;
		*/
		default:
			break;
	}
}