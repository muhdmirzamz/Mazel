//
//  GameManager.h
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__GameManager__
#define __TestEleven__GameManager__

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

#endif /* defined(__TestEleven__GameManager__) */
