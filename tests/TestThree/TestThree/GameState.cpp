//
//  GameState.cpp
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"

using namespace std;

GameState::GameState() {
	gameManager = new GameManager();
}

void GameState::events() {
	
}

void GameState::update() {
	
}

void GameState::render() {
	
}

void GameState::changeGameState(int state) {
	gameManager->changeState(state);
}

GameState::~GameState() {
	delete gameManager;
}