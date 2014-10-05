//
//  TextRender.h
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestSeven__TextRender__
#define __TestSeven__TextRender__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class TextRender {
	public:
		TextRender();
		
		void positionLetterM();
		void renderLetterM(SDL_Renderer *renderer);
	
	private:
		SDL_Rect _mLeftPillar;
	
};

#endif /* defined(__TestSeven__TextRender__) */
