
//
//  GameState.cpp
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
}

// need this function to access a similar function in GameManager class
void GameState::changeState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(state);
	delete gameManager;
}