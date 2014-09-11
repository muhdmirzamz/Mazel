//
//  GameManager.cpp
//  Mazel
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "IntroScene.h"
#include "MainMenu.h"
#include "BasicLevel.h"
#include "GameOverScene.h"

using namespace std;

GameManager::GameManager() {

}

void GameManager::changeGameState(int state) {
	switch (state) {
		case INTRO_SCENE: {
			IntroScene introScene;
			GameState *introScenePointer = &introScene;
			introScenePointer->run();
			break;
		}
		
		case MAIN_MENU: {
			MainMenu mainMenu;
			GameState *mainMenuPointer = &mainMenu;
			mainMenuPointer->run();
			break;
		}
		
		case BASIC_LEVEL: {
			BasicLevel basicLevel;
			GameState *basicLevelPointer = &basicLevel;
			basicLevelPointer->run();
			break;
		}
	
		case GAME_OVER: {
			GameOverScene gameOverScene;
			GameState *gameOverScenePointer = &gameOverScene;
			gameOverScenePointer->run();
			break;
		}
		
		case EXIT: {
			cout << "Exiting game...\n";
			break;
		}
		
		default:
			break;
	}
}