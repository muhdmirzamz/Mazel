//
//  GameState.h
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestThree__GameState__
#define __TestThree__GameState__

#include <iostream>

#include "GameManager.h"

using namespace std;

class GameState {
	public:
		GameState();
		~GameState();
		
		virtual void events();
		virtual void update();
		virtual void render();
		
		void changeGameState(int state);
	
	private:
		GameManager *gameManager;
};

#endif /* defined(__TestThree__GameState__) */
