//
//  MainMenu.h
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__MainMenu__
#define __TestTen__MainMenu__

#include <iostream>

#include "GameState.h"
#include "RenderObject.h"
#include "CollisionDetection.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void positionSquare();
		
		void run();
		void event();
		void update();
		void render();
		void cleanUp();
	
	private:
		int _windowWidth;
		int _windowHeight;
	
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		GameState *_gameState;
		RenderObject *_renderObject;
		CollisionDetection *_collisionDetection;
		
		SDL_Rect _square;
		int _speed;
};

#endif /* defined(__TestTen__MainMenu__) */
