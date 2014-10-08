//
//  GameManager.cpp
//  Mazel
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "IntroScene.h"
#include "MainMenu.h"
#include "SettingsPage.h"
#include "InstructionsPage.h"
#include "BasicLevel.h"
#include "NextLevelPage.h"
#include "GameOverScene.h"
#include "GameEndScene.h"

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
		
		case SETTINGS_PAGE: {
			SettingsPage settingsPage;
			GameState *settingsPagePointer = &settingsPage;
			settingsPagePointer->run();
			break;
		}
		
		case INSTRUCTIONS_PAGE: {
			InstructionsPage instructionsPage;
			GameState *instructionsPagePointer = &instructionsPage;
			instructionsPagePointer->run();
			break;
		}
		
		case BASIC_LEVEL: {
			BasicLevel basicLevel;
			GameState *basicLevelPointer = &basicLevel;
			basicLevelPointer->run();
			break;
		}
		
		case NEXT_LEVEL_PAGE: {
			NextLevelPage nextLevelPage;
			GameState *nextLevelPagePointer = &nextLevelPage;
			nextLevelPagePointer->run();
			break;
		}
	
		case GAME_OVER: {
			GameOverScene gameOverScene;
			GameState *gameOverScenePointer = &gameOverScene;
			gameOverScenePointer->run();
			break;
		}
		
		case GAME_END: {
			GameEndScene gameEndScene;
			GameState *gameEndScenePointer = &gameEndScene;
			gameEndScenePointer->run();
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