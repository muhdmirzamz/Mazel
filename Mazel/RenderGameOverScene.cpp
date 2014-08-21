//
//  RenderGameOverScene.cpp
//  Mazel
//
//  Created by Muhd Mirza on 21/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "RenderGameOverScene.h"

using namespace std;

RenderGameOverScene::RenderGameOverScene() {
	
}

void RenderGameOverScene::renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer, SDL_Texture *gameOverSceneBackground) {
	SDL_SetRenderDrawColor(gameOverSceneRenderer, 100, 100, 100, 0);
	SDL_RenderClear(gameOverSceneRenderer);
	SDL_RenderCopy(gameOverSceneRenderer, gameOverSceneBackground, NULL, NULL);
}