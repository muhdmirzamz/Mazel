//
//  GameState.h
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSix__GameState__
#define __TestSix__GameState__

#include <iostream>

using namespace std;

class GameState {
	public:
		GameState();
		
		virtual void event();
		virtual void update();
		virtual void render();
		
		void changeGameState(int state);
	
	private:
	
};

#endif /* defined(__TestSix__GameState__) */
