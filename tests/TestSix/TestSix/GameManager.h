//
//  GameManager.h
//  TestSix
//
//  Created by Muhd Mirza on 1/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSix__GameManager__
#define __TestSix__GameManager__

#include <iostream>

using namespace std;

class GameManager {
	public:
		GameManager();
		
		void changeState(int state);
		
	private:
		enum states {
			MAIN_MENU,
			LEVEL_ONE,
			LEVEL_TWO
		};
};

#endif /* defined(__TestSix__GameManager__) */
