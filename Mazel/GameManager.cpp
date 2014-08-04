//
//  GameManager.cpp
//  Mazel
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"
#include "MainMenu.h"
#include "Level1.h"

using namespace std;

GameManager::GameManager() {
	
}

void GameManager::changeGameState(int state) {
	GameState *gameState = NULL;

	if (state == EXIT) {
		delete gameState;
	}
	
	switch (state) {
		case MAIN_MENU: {
			gameState = new MainMenu();
			}
			break;
		case LEVEL_ONE: {
			gameState = new Level1();
			}
			break;
		default:
			break;
	}
}