//
//  GameState.cpp
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
	
}

void GameState::changeGameState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeState(state);
	delete gameManager;
}

GameState::~GameState() {
}
