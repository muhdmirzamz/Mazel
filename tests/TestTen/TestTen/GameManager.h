//
//  GameManager.h
//  TestTen
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__GameManager__
#define __TestTen__GameManager__

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

#endif /* defined(__TestTen__GameManager__) */
