//
//  GameState.h
//  TestOne
//
//  Created by Muhd Mirza on 19/4/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestOne__GameState__
#define __TestOne__GameState__

#include <iostream>

class GameState {
	public:
		GameState();
		
		virtual void events();
		virtual void update();
		virtual void render();
	
	private:
};

#endif /* defined(__TestOne__GameState__) */
