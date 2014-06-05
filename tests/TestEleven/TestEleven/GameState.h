//
//  GameState.h
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__GameState__
#define __TestEleven__GameState__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
		
		virtual void run() = 0;
		virtual void event() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		virtual void cleanUp() = 0;
		
		void changeGameState(int state);
		
	private:
};

#endif /* defined(__TestEleven__GameState__) */
