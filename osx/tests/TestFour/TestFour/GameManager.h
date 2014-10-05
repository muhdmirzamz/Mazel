//
//  GameManager.h
//  TestFour
//
//  Created by Muhd Mirza on 24/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestFour__GameManager__
#define __TestFour__GameManager__

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
		};
	
};

#endif /* defined(__TestFour__GameManager__) */
