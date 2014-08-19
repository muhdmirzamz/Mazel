//
//  Level1.h
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Level1__
#define __Mazel__Level1__

#include <iostream>

#include "GameState.h"

using namespace std;

class Level1: public GameState {
	public:
		Level1();
		
		void setup();
		void setupObjects();
		void setupTextures();
		void setupBall();
		void setupObstacles();
		
		void run();
		
		void event();
		void checkCollision();
		
		void update();
		void render();
		
		void cleanup();
		
	private:
		SDL_Window *_window; // free
		SDL_Window *_windowRef;
		SDL_Renderer *_renderer; // free
		SDL_Renderer *_rendererRef;
		SDL_Event _event;
		
		bool _running;
		
		SDL_Surface *_icon;
		
		RenderLevel1 *_renderLevel1; // free
		Collision *_collision; // free
		
		SDL_Surface *_ballImage;
		SDL_Texture *_ballTexture; // free
		SDL_Texture *_ballTextureRef;
		SDL_Rect _ballRect;
		int _ballSpeedXLeft;
		int _ballSpeedXRight;
		int _ballSpeedYUp;
		int _ballSpeedYDown;
		
		SDL_Rect _level1Obstacles[2];
		SDL_Rect _obstacle1;
		SDL_Rect _obstacle2;
};

#endif /* defined(__Mazel__Level1__) */
