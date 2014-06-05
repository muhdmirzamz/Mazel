//
//  MainMenu.h
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__MainMenu__
#define __TestEleven__MainMenu__

#include <iostream>

#include "GameState.h"
#include "RenderObject.h"
#include "CollisionDetection.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void run();
		void event();
		void update();
		void render();
		void cleanUp();
		
		void setRectangle();
		void setRectangleSpeed();
		void moveRectangle();
		void detectRectangleCollision();
		
	private:
		int _windowWidth;
		int _windowHeight;
	
		GameState *_gameState;
		
		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		RenderObject *_renderObject;
		
		SDL_Rect _rect1;
		int _rect1SpeedX;
		int _rect1SpeedY;
		
		SDL_Rect _rect2;
		int _rect2SpeedX;
		int _rect2SpeedY;
		
		SDL_Rect _rect3;
		int _rect3SpeedX;
		
		// title rectangles
		SDL_Rect _letterM1;
		SDL_Rect _letterM2;
		SDL_Rect _letterM3;
		SDL_Rect _letterM4;
		SDL_Rect _letterM5;
		
		CollisionDetection *_collisionDetection;
};

#endif /* defined(__TestEleven__MainMenu__) */
