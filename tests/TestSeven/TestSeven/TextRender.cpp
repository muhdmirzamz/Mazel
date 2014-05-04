//
//  TextRender.cpp
//  TestSeven
//
//  Created by Muhd Mirza on 4/5/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "TextRender.h"

using namespace std;

TextRender::TextRender() {
	
}

void TextRender::positionLetterM() {
	_mLeftPillar.x = 10;
	_mLeftPillar.y = 10;
	_mLeftPillar.w = 20;
	_mLeftPillar.h = 200;
}

void TextRender::renderLetterM(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderFillRect(renderer, &_mLeftPillar);
}