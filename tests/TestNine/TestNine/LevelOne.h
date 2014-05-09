//
//  LevelOne.h
//  TestNine
//
//  Created by Muhd Mirza on 5/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestNine__LevelOne__
#define __TestNine__LevelOne__

#include <iostream>

#include "GameState.h"

using namespace std;

class LevelOne: public GameState {
public:
	LevelOne();
	
	void run();
	void event();
	void update();
	void render();
	
private:
};

#endif /* defined(__TestNine__LevelOne__) */
