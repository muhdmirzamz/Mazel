//
//  MainMenu.cpp
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "MainMenu.h"

using namespace std;

MainMenu::MainMenu() {
	_window = getWindow();
	_renderer = getRenderer();
	_event = getEvent();
	_running = getRunningVar();
	
	setupWindow(_window);
	setupRenderer(_renderer, _window);
	setRunning(_running);
}

void MainMenu::run() {
	while (_running) {
		event();
		update();
		MainMenu::render();
	}
}

void MainMenu::render() {
	SDL_SetRenderDrawColor(_renderer, 0, 255, 0, 0);
	SDL_RenderClear(_renderer);
}