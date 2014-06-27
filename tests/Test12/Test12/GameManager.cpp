//
//  GameManager.cpp
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"
// include all level files here to avoid multiple including
#include "MainMenu.h"
#include "Level1.h"

using namespace std;

GameManager::GameManager() {
}

void GameManager::changeGameState(int state) {
	switch (state) {
		case MAIN_MENU: {
			// use a gamestate pointer for a MainMenu object
			// polymorphism is used here
			GameState *mainMenu = new MainMenu();
			mainMenu->run();
			delete mainMenu;
			break;
		}
		/*
		case LEVEL_ONE: {
			// use a gamestate pointer for a level1 object
			GameState *level1 = new Level1();
			level1->run();
			delete level1;
			break;
		}
		*/
		default:
			break;
	}
}