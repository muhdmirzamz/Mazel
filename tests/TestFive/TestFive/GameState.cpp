//
//  GameState.cpp
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
}

void GameState::events() {
	
}

void GameState::update() {
	
}

void GameState::render() {
	
}

void GameState::changeGameState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeState(state);
	delete gameManager;
}