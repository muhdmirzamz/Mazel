//
//  GameManager.cpp
//  Mazel
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameManager.h"
#include "GameState.h"
#include "IntroScene.h"
#include "MainMenu.h"
#include "Level1.h"

using namespace std;

GameManager::GameManager() {
	
}

void GameManager::changeGameState(int state) {
	GameState *gameState = NULL; // use one pointer to rotate all levels

	if (state == EXIT) {
		delete gameState;
	}
	
	switch (state) {
		case INTRO_SCENE: {
			gameState = new IntroScene();
			gameState->run();
			break;
		}
		case MAIN_MENU: {
			gameState = new MainMenu();
			gameState->run();
			break;
		}
		case LEVEL_ONE: {
			gameState = new Level1();
			gameState->run();
			break;
		}
		default:
			break;
	}
}