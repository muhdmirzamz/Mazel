//
//  GameManager.h
//  TestThree
//
//  Created by Muhd Mirza on 20/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestThree__GameManager__
#define __TestThree__GameManager__

#include <iostream>

#include "LevelOne.h"

using namespace std;

class GameManager {
	public:
		GameManager();
		
		void changeState(int state);
	
	private:
		enum states {
			LEVEL_ONE,
			LEVEL_TWO
		};
	
		LevelOne *levelOne;
};

#endif /* defined(__TestThree__GameManager__) */
