//
//  Level1.h
//  TestEleven
//
//  Created by Muhd Mirza on 25/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__Level1__
#define __TestEleven__Level1__

#include <iostream>

#include "GameState.h"
#include "RenderObject.h"
#include "CollisionDetection.h"

using namespace std;

class Level1: public GameState {
	public:
		Level1();
		
		void run();
		void event();
		void update();
		void render();
		void cleanUp();
		
		void setPlayerRectangle();
		void setRectangleObstacle();
			
	private:
		int _windowHeight;
		int _windowWidth;
		
		GameState *_gameState;

		SDL_Window *_window;
		SDL_Renderer *_renderer;
		SDL_Event _event;
		
		bool _running;
		
		RenderObject *_renderObject;
		
		SDL_Rect _playerRectangle;
		int _playerRectangleSpeed;
		SDL_Rect _rectangleObstacle1;
		int _rectangleObstacle1RandomNum;
		SDL_Rect _rectangleObstacle2;
		int _rectangleObstacle2RandomNum;
		SDL_Rect _rectangleObstacle3;
		int _rectangleObstacle3RandomNum;
		SDL_Rect _rectangleObstacle4;
		int _rectangleObstacle4RandomNum;
		SDL_Rect _rectangleObstacle5;
		int _rectangleObstacle5RandomNum;
		SDL_Rect _rectangleObstacle6;
		int _rectangleObstacle6RandomNum;


		
		CollisionDetection *_collisionDetection;
};

#endif /* defined(__TestEleven__Level1__) */
