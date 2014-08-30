//
//  GameState.h
//  TestFive
//
//  Created by Muhd Mirza on 28/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestFive__GameState__
#define __TestFive__GameState__

#include <iostream>

using namespace std;

class GameState {
	public:
		GameState();
		
		virtual void events();
		virtual void update();
		virtual void render();
		
		void changeGameState(int state);
		
	private:
};

#endif /* defined(__TestFive__GameState__) */
