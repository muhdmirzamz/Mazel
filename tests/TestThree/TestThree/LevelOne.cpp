//
//  LevelOne.cpp
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "LevelOne.h"

using namespace std;

LevelOne::LevelOne() {
	running = true;
	
	window = SDL_CreateWindow(
	"TestThree",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	640,
	480,
	SDL_WINDOW_SHOWN);
	
	if (window == NULL) {
		cout << "Window not initialised!\n";
	}
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	if (renderer == NULL) {
		cout << "Renderer not initialised!\n";
	}
}

void LevelOne::run() {
	while (running) {
		events();
		update();
		render();
	}
}

void LevelOne::events() {
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
	}
}

void LevelOne::update() {
	SDL_RenderPresent(renderer);
}

void LevelOne::render() {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, NULL);
	SDL_RenderPresent(renderer);
}

LevelOne::~LevelOne() {
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}