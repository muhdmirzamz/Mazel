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

// intro scene
void Render::renderIntroSceneBackground(SDL_Renderer *introSceneRenderer) {
	SDL_SetRenderDrawColor(introSceneRenderer, 0, 100, 100, 0);
	SDL_RenderClear(introSceneRenderer);
}

void Render::renderIntroSceneContinueButton(SDL_Renderer *introsceneRenderer2, SDL_Texture *continueButtonTexture) {
	SDL_Rect continueButtonRect;
	
	continueButtonRect.x = 120;
	continueButtonRect.y = 150;
	continueButtonRect.w = 400;
	continueButtonRect.h = 400;
	SDL_RenderCopy(introsceneRenderer2, continueButtonTexture, NULL, &continueButtonRect);
}

void Render::renderIntroSceneLogo(SDL_Renderer *introsceneRenderer3, SDL_Texture *introsceneLogoTexture) {
	SDL_Rect introLogoRect;
	
	introLogoRect.x = 120;
	introLogoRect.y = 10;
	introLogoRect.w = 400;
	introLogoRect.h = 400;
	SDL_RenderCopy(introsceneRenderer3, introsceneLogoTexture, NULL, &introLogoRect);
}

// main menu
void Render::renderMainMenuBackground(SDL_Renderer *mainMenuRenderer) {
	SDL_RenderClear(mainMenuRenderer);
	SDL_SetRenderDrawColor(mainMenuRenderer, 240, 240, 240, 0);
}

void Render::renderMainMenuLogo(SDL_Renderer *mainMenuRenderer2, SDL_Texture *logoTexture) {
	SDL_Rect logoTextureRect;
	
	logoTextureRect.x = 180;
	logoTextureRect.y = 50;
	logoTextureRect.w = 300;
	logoTextureRect.h = 300;
	SDL_RenderCopy(mainMenuRenderer2, logoTexture, NULL, &logoTextureRect);
}

void Render::renderMainMenuGrassBackground(SDL_Renderer *mainMenuRenderer3, SDL_Texture *grassBackgroundTexture) {
	SDL_Rect mainMenuHalfBackGroundRect;
	
	mainMenuHalfBackGroundRect.x = 0;
	mainMenuHalfBackGroundRect.y = 280;
	mainMenuHalfBackGroundRect.w = WINDOW_WIDTH;
	mainMenuHalfBackGroundRect.h = 200;
	SDL_RenderCopy(mainMenuRenderer3, grassBackgroundTexture, NULL, &mainMenuHalfBackGroundRect);
}

void Render::renderMainMenuStartButton(SDL_Renderer *mainMenuRenderer4, SDL_Texture *startButton) {
	SDL_Rect startRect;
	
	startRect.x = 200;
	startRect.y = 345;
	startRect.w = 200;
	startRect.h = 200;
	SDL_RenderCopy(mainMenuRenderer4, startButton, NULL, &startRect);
}

void Render::renderMainMenuBall(SDL_Renderer *mainMenuRenderer5, SDL_Texture *ballTexture, SDL_Rect ballRect) {
	SDL_RenderCopy(mainMenuRenderer5, ballTexture, NULL, &ballRect);
}

// levels
void Render::renderLevelBackground(SDL_Renderer *levelRenderer) {
	SDL_SetRenderDrawColor(levelRenderer, 240, 240, 240, 0);
	SDL_RenderClear(levelRenderer);
}

void Render::renderLevelBall(SDL_Renderer *levelRenderer2, SDL_Texture *ballTexture, SDL_Rect ballRect) {
	SDL_RenderCopy(levelRenderer2, ballTexture, NULL, &ballRect);
}

void Render::renderLevelObstacle(SDL_Renderer *levelRenderer3, SDL_Rect levelObstacle) {
	SDL_SetRenderDrawColor(levelRenderer3, 0, 0, 100, 0);
	SDL_RenderFillRect(levelRenderer3, &levelObstacle);
}

void Render::renderLevelFinishImage(SDL_Renderer *levelRenderer4, SDL_Texture *finishImageTexture, SDL_Rect finishImageRect) {
	SDL_RenderCopy(levelRenderer4, finishImageTexture, NULL, &finishImageRect);
}

// game over scene
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