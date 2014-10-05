//
//  GameManager.h
//  TestEight
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEight__GameManager__
#define __TestEight__GameManager__

#include <iostream>

using namespace std;

class GameManager {
	public:
		GameManager();
		
		void changeState(int state);
		
	private:
		enum state {
			MAIN_MENU,
			LEVEL_ONE,
			LEVEL_TWO
		};
};

#endif /* defined(__TestEight__GameManager__) */
