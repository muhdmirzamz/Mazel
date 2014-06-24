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
	if (_gameState->setupWindow()) {
		_gameState->showErrorMessage("MainMenu", "Window");
	}
	
	if (_gameState->setupRenderer()) {
		_gameState->showErrorMessage("MainMenu", "Renderer");
	}
	
	_gameState->startRunning();
}

void MainMenu::run() {
	
}

void MainMenu::event() {
	
}

void MainMenu::update() {
	
}

void MainMenu::render() {
	
}