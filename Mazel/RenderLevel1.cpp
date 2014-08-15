//
//  RenderLevel1.cpp
//  Mazel
//
//  Created by Muhd Mirza on 14/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderLevel1.h"

using namespace std;

RenderLevel1::RenderLevel1() {
	
}

void RenderLevel1::renderLevel1Background(SDL_Renderer *level1Renderer) {
	SDL_SetRenderDrawColor(level1Renderer, 240, 240, 240, 0);
	SDL_RenderClear(level1Renderer);
}

void RenderLevel1::renderLevel1Ball(SDL_Renderer *level1Renderer2, SDL_Texture *ballTexture, SDL_Rect ballRect) {
	SDL_RenderCopy(level1Renderer2, ballTexture, NULL, &ballRect);
}