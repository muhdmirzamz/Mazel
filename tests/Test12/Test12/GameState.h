//
//  GameState.h
//  Test12
//	Every single level class inherits from this class
//	This class forms the base for every level class
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test12__GameState__
#define __Test12__GameState__

#include <iostream>

using namespace std;

class GameState {
	public:
		GameState();
		
		// make this an abstract class, not completely
		// every class inherits these functions except changeState(int state)
		virtual void run() = 0;
		virtual void event() = 0;
		virtual void update() = 0;
		virtual void render() = 0;
		
		// this need not be virtual
		// need to use this through at least a pointer
		void changeState(int state);
		
	private:
};

#endif /* defined(__Test12__GameState__) */
