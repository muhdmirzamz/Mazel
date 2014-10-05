//
//  GameState.cpp
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
	
}

GameState::~GameState() {
}

SDL_Window* GameState::initWindow(SDL_Window *window) {
	window = SDL_CreateWindow(
	  GAME_TITLE,
	  WINDOW_X_POS,
	  WINDOW_Y_POS,
	  WINDOW_WIDTH,
	  WINDOW_HEIGHT,
	  SDL_WINDOW_SHOWN
	);
	
	if (!window) {
		cout << "Window failed to initialise!\n";
	}
	
	return window;
}

SDL_Renderer* GameState::initRenderer(SDL_Window *window2, SDL_Renderer *renderer) {
	renderer = SDL_CreateRenderer(window2, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!renderer) {
		cout << "Renderer failed to initialise!\n";
	}
	
	return renderer;
}

void GameState::setIcon(SDL_Window *window3, SDL_Surface *icon, const string filePathOfIcon) {
	icon = SDL_LoadBMP(filePathOfIcon.c_str());
	if (!icon) {
		cout << "Window icon failed to initialise!\n";
	}

	SDL_SetWindowIcon(window3, icon);
}

void GameState::setup() {
	
}

void GameState::setupObjects() {
	
}

void GameState::setupTextures() {
	
}

void GameState::setupBall() {
	
}

void GameState::setupFinishRect() {
	
}

void GameState::setupObstaclesAndEnemies() {
	
}

void GameState::run() {
	
}

void GameState::event() {
	
}

void GameState::moveEnemy() {
	
}

void GameState::checkBallAndWindowCollision() {
	
}

void GameState::checkBallAndObstacleCollision() {
	
}

void GameState::checkBallAndFinishRectangleCollision() {
	
}

void GameState::checkBallAndEnemiesCollision() {
	
}

void GameState::checkEnemiesAndWindowCollision() {
	
}

void GameState::checkEnemiesAndObstacleCollision() {
	
}

void GameState::update() {
	
}

void GameState::render() {
	
}

void GameState::cleanup() {
	
}

void GameState::changeState(GameManager *gameManager, int state) {
	gameManager->changeGameState(state);
}



