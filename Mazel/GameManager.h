//
//  GameManager.h
//  Mazel
//	this class is in charge of handling the switching
//	of game states
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameManager__
#define __Mazel__GameManager__

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

#endif /* defined(__Mazel__GameManager__) */
