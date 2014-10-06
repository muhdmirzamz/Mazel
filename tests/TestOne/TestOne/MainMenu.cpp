//
//  MainMenu.cpp
//  TestOne
//
//  Created by Muhd Mirza on 19/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include <iostream>

#include "SDL_video.h"
#include "SDL_events.h"

#include "MainMenu.h"
#include "GameManager.h"

using namespace std;

MainMenu::MainMenu() {
	window = SDL_CreateWindow (
		"TestOne",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);
	
	if (window == NULL) {
		cout << "Window failed to be created\n";
	}
	
	mainSurface = SDL_GetWindowSurface(window);
}

void MainMenu::run() {
	running = true;
	
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
	}
}

void MainMenu::update() {
	SDL_UpdateWindowSurface
}

void MainMenu::render() {
	
}