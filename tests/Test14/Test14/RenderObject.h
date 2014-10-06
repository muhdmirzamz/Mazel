//
//  RenderObject.h
//  Test14
//
//  Created by Muhd Mirza on 3/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test14__RenderObject__
#define __Test14__RenderObject__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class RenderObject {
	public:
		RenderObject();
		
		void renderLevelOneBackground(SDL_Renderer *levelOneBackground);
	
	private:
};

#endif /* defined(__Test14__RenderObject__) */
