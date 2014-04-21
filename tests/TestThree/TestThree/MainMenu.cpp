//
//  MainMenu.cpp
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	running = true;
	gameState = new GameState();
	
	window = SDL_CreateWindow(
		"TestThree",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);
	
	if (window == NULL) {
		cout << "Window failed to initialise!\n";
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (renderer == NULL) {
		cout << "Renderer failed to initialise!\n";
	}
}

void MainMenu::run() {
	while (running) {
		events();
		update();
		render();
	}
}

void MainMenu::events() {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_KP_1) {
				gameState->changeGameState(1);
			}
		}
	}
}

void MainMenu::update() {
	SDL_RenderPresent(renderer);
}

void MainMenu::render() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, NULL);
	SDL_RenderClear(renderer);
}

MainMenu::~MainMenu() {
	delete gameState;
	gameState = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}