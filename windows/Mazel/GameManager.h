//
//  GameManager.h
//  Mazel
//	In charge of changing states and levels
//
//  Created by Muhd Mirza on 3/8/14.
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
};

#endif /* defined(__Mazel__GameManager__) */
