//
//  RenderLevel1.h
//  Mazel
//
//  Created by Muhd Mirza on 14/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__RenderLevel1__
#define __Mazel__RenderLevel1__

#include <iostream>

#include "Includes.h"

using namespace std;

class RenderLevel1 {
	public:
		RenderLevel1();
		
		void renderLevel1Background(SDL_Renderer *level1Renderer);
		void renderLevel1Ball(SDL_Renderer *level1Renderer2, SDL_Texture *ballTexture, SDL_Rect ballRect);
		void renderLevel1Obstacle1(SDL_Renderer *level1Renderer3, SDL_Rect level1Obstacle[]);
		void renderLevel1FinishImage(SDL_Renderer *level1Renderer4, SDL_Texture *finishImageTexture, SDL_Rect finishImageRect);
	
	private:
};

#endif /* defined(__Mazel__RenderLevel1__) */
