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
	SDL_SetRenderDrawColor(gameOverSceneRenderer, 100, 150, 100, 0);
	SDL_RenderClear(gameOverSceneRenderer);
	
	SDL_Rect background;
	background.x = (WINDOW_WIDTH / 2) - 200;
	background.y = (WINDOW_HEIGHT / 2) - 200;
	background.w = 400;
	background.h = 400;
	
	SDL_RenderCopy(gameOverSceneRenderer, gameOverSceneBackground, NULL, &background);
}