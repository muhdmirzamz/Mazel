//
//  LevelTwo.h
//  TestNine
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestNine__LevelTwo__
#define __TestNine__LevelTwo__

#include <iostream>

#include "GameState.h"

using namespace std;

class LevelTwo: public GameState {
public:
	LevelTwo();
	
	void run();
	void event();
	void update();
	void render();
	
private:
};

#endif /* defined(__TestNine__LevelTwo__) */
