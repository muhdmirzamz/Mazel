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

void RenderLevel1::renderLevel1Obstacle1(SDL_Renderer *level1Renderer3, SDL_Rect level1Obstacle[]) {
	SDL_SetRenderDrawColor(level1Renderer3, 0, 0, 100, 0);
	SDL_RenderFillRects(level1Renderer3, &level1Obstacle[0], 16);
}

void RenderLevel1::renderLevel1FinishImage(SDL_Renderer *level1Renderer4, SDL_Texture *finishImageTexture, SDL_Rect finishImageRect) {
	SDL_RenderCopy(level1Renderer4, finishImageTexture, NULL, &finishImageRect);
}