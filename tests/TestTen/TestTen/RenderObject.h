//
//  RenderObject.h
//  TestTen
//	Rendering are all done here. From background to objects.
//	Take note:
//	Positioning is done in level class itself
//	Variables are also in level class itself
//
//  Created by Muhd Mirza on 8/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestTen__RenderObject__
#define __TestTen__RenderObject__

#include <iostream>

using namespace std;

class RenderObject {
	public:
		RenderObject();
		
		void renderMainMenuBackground(SDL_Renderer *rendererMainMenuBackground);
		void renderLevelOneBackground(SDL_Renderer *rendererLevelOneBackground);
	
		void renderMainMenuSquare(SDL_Renderer *rendererMainMenuSquare, SDL_Rect mainMenuSquare);
	
	private:
};

#endif /* defined(__TestTen__RenderObject__) */
