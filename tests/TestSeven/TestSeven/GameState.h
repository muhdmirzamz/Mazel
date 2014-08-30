//
//  GameState.h
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSeven__GameState__
#define __TestSeven__GameState__

#include <iostream>

#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"

#include "TextRender.h"

class GameState {
	public:
		GameState();
		
		virtual void event();
		virtual void update();
		virtual void render();
		
		void changeGameState(int state);
		
	private:
	
};

#endif /* defined(__TestSeven__GameState__) */
