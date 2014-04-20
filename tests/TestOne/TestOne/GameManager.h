//
//  GameManager.h
//  TestOne
//
//  Created by Muhd Mirza on 19/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestOne__GameManager__
#define __TestOne__GameManager__

#include <iostream>

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
		
		int nextState;
};

#endif /* defined(__TestOne__GameManager__) */
