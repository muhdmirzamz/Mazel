//
//  GameManager.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
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

// create a GameState pointer and point it to level class
void GameManager::changeGameState(int state) {
	switch (state) {
		case MAIN_MENU: {
			GameState *mainMenu = new MainMenu();
			mainMenu->run();
			delete mainMenu;
		}
		break;
		default:
			break;
	}
}