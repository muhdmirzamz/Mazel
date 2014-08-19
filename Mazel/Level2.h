//
//  Level2.h
//  Mazel
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Level2__
#define __Mazel__Level2__

#include <iostream>

#include "GameState.h"

using namespace std;

class Level2: public GameState {
	public:
		Level2();
		
		void setup();
		void setupObjects();
		void setupTextures();
		void setupBall();
		void setupObstacles();
		
		void run();
		
		void event();
		
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
		
		RenderLevel2 *_renderLevel2; // free
};

#endif /* defined(__Mazel__Level2__) */
