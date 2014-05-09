//
//  GameState.h
//  TestNine
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestNine__GameState__
#define __TestNine__GameState__

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
		
		void changeGameState(int state);
		
	private:
	
};

#endif /* defined(__TestNine__GameState__) */
