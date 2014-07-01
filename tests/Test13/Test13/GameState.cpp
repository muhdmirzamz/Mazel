//
//  GameState.cpp
//  Test13
//
//  Created by Muhd Mirza on 1/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "GameState.h"
#include "GameManager.h"

using namespace std;

GameState::GameState() {
	
}

GameState::~GameState() {
}

void GameState::setup(SDL_Window **window, SDL_Renderer **renderer, bool running) {
	*window = SDL_CreateWindow(
	"test13",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	WINDOW_WIDTH,
	WINDOW_HEIGHT,
	SDL_WINDOW_SHOWN
	);
	
	if (!window) {
		cout << "Window failed to initialise!\n";
	}
	
	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (!renderer) {
		cout << "Renderer failed to intialise!\n";
	}
	
	running = true;
}

void GameState::event(SDL_Event event, bool runningVar) {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			runningVar = false;
		}
	}
}

void GameState::update(SDL_Renderer **renderer2) {
	SDL_RenderPresent(*renderer2);
}

void GameState::render() {
	
}

void GameState::changeState(int state) {
	GameManager *gameManager = new GameManager();
	gameManager->changeGameState(state);
	delete gameManager;
}