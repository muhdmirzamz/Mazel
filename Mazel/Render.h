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
		
		// background
		void renderIntroSceneBackground(SDL_Renderer *introSceneRenderer);
		void renderMainMenuBackground(SDL_Renderer *mainMenuRenderer);
		void renderLevelBackground(SDL_Renderer *levelRenderer);
		void renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer, SDL_Texture *gameOverSceneBackground);
		
		// texture
		void renderTexture(SDL_Renderer *textureRenderer, SDL_Texture *texture, SDL_Rect rect);
		
		// obstacle rectangles
		void renderLevelObstacle(SDL_Renderer *levelRenderer3, SDL_Rect levelObstacle);
		
	private:
};

#endif /* defined(__Mazel__Render__) */
