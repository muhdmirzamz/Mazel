//
//  GameState.h
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__GameState__
#define __TestTen__GameState__

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

#endif /* defined(__TestTen__GameState__) */
