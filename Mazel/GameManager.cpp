//
//  GameManager.cpp
//  Mazel
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "IntroScene.h"
#include "Instructions.h"
#include "MainMenu.h"
#include "Settings.h"
#include "GameplayModeScene.h"
#include "BasicLevelMode.h"
#include "SurvivalMode.h"
#include "NextLevelScene.h"
#include "GameOverScene.h"
#include "GameOverOneLifeScene.h"
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
		
		case INSTRUCTIONS: {
			Instructions instructions;
			GameState *instructionsPointer = &instructions;
			instructionsPointer->run();
			break;
		}
		
		case MAIN_MENU: {
			MainMenu mainMenu;
			GameState *mainMenuPointer = &mainMenu;
			mainMenuPointer->run();
			break;
		}
		
		case SETTINGS: {
			Settings settings;
			GameState *settingsPointer = &settings;
			settingsPointer->run();
			break;
		}
		
		case GAMEPLAY_MODE_SCENE: {
			GameplayModeScene gameplayModeScene;
			GameState *gameplayModeScenePointer = &gameplayModeScene;
			gameplayModeScenePointer->run();
			break;
		}
		
		case BASIC_LEVEL_MODE: {
			BasicLevelMode basicLevelMode;
			GameState *basicLevelModePointer = &basicLevelMode;
			basicLevelModePointer->run();
			break;
		}
		
		case SURVIVAL_MODE: {
			SurvivalMode survivalMode;
			GameState *survivalModePointer = &survivalMode;
			survivalModePointer->run();
			break;
		}
		
		case NEXT_LEVEL_SCENE: {
			NextLevelScene nextLevelScene;
			GameState *nextLevelScenePointer = &nextLevelScene;
			nextLevelScenePointer->run();
			break;
		}
	
		case GAME_OVER_SCENE: {
			GameOverScene gameOverScene;
			GameState *gameOverScenePointer = &gameOverScene;
			gameOverScenePointer->run();
			break;
		}
		
		case GAME_OVER_ONE_LIFE_SCENE: {
			GameOverOneLifeScene gameOverOneLifeScene;
			GameState *gameOverOneLifeScenePointer = &gameOverOneLifeScene;
			gameOverOneLifeScenePointer->run();
			break;
		}
		
		case GAME_END_SCENE: {
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