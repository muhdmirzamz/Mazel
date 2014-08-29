//
//  Render.h
//  Mazel
//	All the rendering here
//
//  Created by Muhd Mirza on 26/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Render__
#define __Mazel__Render__

#include <iostream>

#include "Includes.h"

using namespace std;

class Render {
	public:
		Render();
		
		// intro scene
		void renderIntroSceneBackground(SDL_Renderer *introSceneRenderer);
		void renderIntroSceneContinueButton(SDL_Renderer *introsceneRenderer2, SDL_Texture *continueButtonTexture);
		void renderIntroSceneLogo(SDL_Renderer *introsceneRenderer3, SDL_Texture *introsceneLogoTexture);
	
		// main menu
		void renderMainMenuBackground(SDL_Renderer *mainMenuRenderer);
		void renderMainMenuLogo(SDL_Renderer *mainMenuRenderer2, SDL_Texture *logoTexture);
		void renderMainMenuGrassBackground(SDL_Renderer *mainMenuRenderer3, SDL_Texture *grassBackgroundTexture);
		void renderMainMenuStartButton(SDL_Renderer *mainMenuRenderer4, SDL_Texture *startButton);
		void renderMainMenuBall(SDL_Renderer *mainMenuRenderer5, SDL_Texture *ballTexture, SDL_Rect ballRect); // ball rect needs to be passed in
		
		// levels
		void renderLevelBackground(SDL_Renderer *levelRenderer);
		void renderLevelBall(SDL_Renderer *levelRenderer2, SDL_Texture *ballTexture, SDL_Rect ballRect);
		void renderLevelObstacle(SDL_Renderer *levelRenderer3, SDL_Rect levelObstacle);
		void renderLevelFinishImage(SDL_Renderer *levelRenderer4, SDL_Texture *finishImageTexture, SDL_Rect finishImageRect);
		
		// game over scene
		void renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer, SDL_Texture *gameOverSceneBackground);
		
	private:
};

#endif /* defined(__Mazel__Render__) */
