//
//  RenderObject.h
//  Test12
//
//  Created by Muhd Mirza on 23/6/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test12__RenderObject__
#define __Test12__RenderObject__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class RenderObject {
	public:
		RenderObject();
		
		void renderMainMenuBackground(SDL_Renderer *mainMenuBackgroundRenderer);
	
	private:
};

#endif /* defined(__Test12__RenderObject__) */
