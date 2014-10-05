//
//  GameManager.h
//  Test14
//
//  Created by Muhd Mirza on 2/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test14__GameManager__
#define __Test14__GameManager__

#include <iostream>

using namespace std;

class GameManager {
	public:
		GameManager();
		
		void changeGameState(int state);
	
	private:
		enum states {
			MAIN_MENU,
			LEVEL_ONE,
			LEVEL_TWO
		};
};

#endif /* defined(__Test14__GameManager__) */
