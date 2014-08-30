//
//  GameState.cpp
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
	
}

GameState::~GameState() {
	
}

void GameState::changeGameState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeState(state);
	delete gameManager;
}