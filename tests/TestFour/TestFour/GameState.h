//
//  GameState.h
//  TestFour
//
//  Created by Muhd Mirza on 24/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestFour__GameState__
#define __TestFour__GameState__

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

#endif /* defined(__TestFour__GameState__) */
