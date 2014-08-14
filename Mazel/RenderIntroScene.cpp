//
//  Render.cpp
//  Mazel
//
//  Created by Muhd Mirza on 13/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderIntroScene.h"

using namespace std;

RenderIntroScene::RenderIntroScene() {
	
}

void RenderIntroScene::renderIntroSceneBackground(SDL_Renderer *introSceneRenderer) {
	SDL_SetRenderDrawColor(introSceneRenderer, 0, 100, 100, 0);
	SDL_RenderClear(introSceneRenderer);
}

void RenderIntroScene::renderIntroSceneContinueButton(SDL_Renderer *introsceneRenderer2, SDL_Texture *continueButtonTexture) {
	SDL_Rect continueButtonRect;

	continueButtonRect.x = 120;
	continueButtonRect.y = 150;
	continueButtonRect.w = 400;
	continueButtonRect.h = 400;
	SDL_RenderCopy(introsceneRenderer2, continueButtonTexture, NULL, &continueButtonRect);
}

void RenderIntroScene::renderIntroSceneLogo(SDL_Renderer *introsceneRenderer3, SDL_Texture *introsceneLogoTexture) {
	SDL_Rect introLogoRect;

	introLogoRect.x = 120;
	introLogoRect.y = 10;
	introLogoRect.w = 400;
	introLogoRect.h = 400;
	SDL_RenderCopy(introsceneRenderer3, introsceneLogoTexture, NULL, &introLogoRect);
}