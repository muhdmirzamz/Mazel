//
//  Render.cpp
//  Mazel
//
//  Created by Muhd Mirza on 26/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#include "Render.h"

using namespace std;

Render::Render() {
	
}

// background
void Render::renderIntroSceneBackground(SDL_Renderer *introSceneRenderer) {
	SDL_SetRenderDrawColor(introSceneRenderer, 0, 100, 100, 0);
	SDL_RenderClear(introSceneRenderer);
}

void Render::renderMainMenuBackground(SDL_Renderer *mainMenuRenderer) {
	SDL_RenderClear(mainMenuRenderer);
	SDL_SetRenderDrawColor(mainMenuRenderer, 240, 240, 240, 0);
}

void Render::renderLevelBackground(SDL_Renderer *levelRenderer) {
	SDL_SetRenderDrawColor(levelRenderer, 240, 240, 240, 0);
	SDL_RenderClear(levelRenderer);
}

void Render::renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer, SDL_Texture *gameOverSceneBackground) {
	SDL_SetRenderDrawColor(gameOverSceneRenderer, 100, 150, 100, 0);
	SDL_RenderClear(gameOverSceneRenderer);
	
	SDL_Rect background;
	background.x = (WINDOW_WIDTH / 2) - 200;
	background.y = (WINDOW_HEIGHT / 2) - 200;
	background.w = 400;
	background.h = 400;
	
	SDL_RenderCopy(gameOverSceneRenderer, gameOverSceneBackground, NULL, &background);
}

// texture
void Render::renderTexture(SDL_Renderer *textureRenderer, SDL_Texture *texture, SDL_Rect rect) {
	SDL_RenderCopy(textureRenderer, texture, NULL, &rect);
}

// obstacle rectangle
void Render::renderLevelObstacle(SDL_Renderer *levelRenderer3, SDL_Rect levelObstacle) {
	SDL_SetRenderDrawColor(levelRenderer3, 0, 0, 100, 0);
	SDL_RenderFillRect(levelRenderer3, &levelObstacle);
}