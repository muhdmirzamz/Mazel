//
//  MainMenu.cpp
//  Test13
//
//  Created by Muhd Mirza on 1/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	setup(&_window, &_renderer, _running);
}

void MainMenu::run() {
	while (_running) {
		event(_event, _running);
		update(&_renderer);
		render();
	}
}

void MainMenu::render() {
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
	SDL_RenderClear(_renderer);
}