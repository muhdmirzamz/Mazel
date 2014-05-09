//
//  GameManager.h
//  TestNine
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestNine__GameManager__
#define __TestNine__GameManager__

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


#endif /* defined(__TestNine__GameManager__) */
