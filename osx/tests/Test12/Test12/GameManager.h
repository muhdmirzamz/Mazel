//
//  GameManager.h
//  Test12
//	Stores program states and helps switch between them
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test12__GameManager__
#define __Test12__GameManager__

#include <iostream>

using namespace std;

class GameManager {
	public:
		GameManager();
		
		// switch game states
		void changeGameState(int state);
		
	private:
		// store all states in an enum
		enum state {
			MAIN_MENU,
			LEVEL_ONE,
		};
};

#endif /* defined(__Test12__GameManager__) */
