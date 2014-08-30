//
//  RenderObject.h
//  TestEleven
//
//  Created by Muhd Mirza on 18/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __TestEleven__RenderObject__
#define __TestEleven__RenderObject__

#include <iostream>

#include "SDL_render.h"

using namespace std;

class RenderObject {
	public:
		RenderObject();
		
		void renderMainMenuBackground(SDL_Renderer *rendererMainMenu);
		void renderLevel1Background(SDL_Renderer *rendererLevel1);
		void renderLevel2Background(SDL_Renderer *rendererLevel2);
		
		void renderMainMenuSquare(SDL_Renderer *rendererMainMenuSquare, SDL_Rect rect1);
		void renderMainMenuTitle(SDL_Renderer *rendererMainMenuTitle, SDL_Rect rect2);
		
		void renderLevel1PlayerRectangle(SDL_Renderer *rendererLevel1PlayerRectangle, SDL_Rect rect3);
		void renderLevel1RectangleObstacle(SDL_Renderer *rendererLevel1RectangleObstacle, SDL_Rect rect4);
	
	private:
};

#endif /* defined(__TestEleven__RenderObject__) */
