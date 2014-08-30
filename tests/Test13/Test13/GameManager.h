//
//  GameManager.h
//  Test13
//
//  Created by Muhd Mirza on 1/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test13__GameManager__
#define __Test13__GameManager__

#include <iostream>

using namespace std;

class GameManager {
	public:
		GameManager();
		
		void changeGameState(int state);
	
	private:
		enum state {
			MAIN_MENU
		};
};

#endif /* defined(__Test13__GameManager__) */
