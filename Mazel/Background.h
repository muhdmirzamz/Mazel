//
//  Background.h
//  Mazel
//	Background functions for states
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Background__
#define __Mazel__Background__

#include <iostream>

#include "Includes.h"

using namespace std;

class Background {
	public:
		Background();
		
		void loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer);
		
		void plotBackground(int x, int y, int w, int h);
		
		void renderIntroSceneBackground(SDL_Renderer *introSceneRenderer);
		void renderMainMenuBackground(SDL_Renderer *mainMenuRenderer);
		void renderSettingsPageBackground(SDL_Renderer *settingsPageRenderer);
		void renderBasicLevelBackground(SDL_Renderer *basicLevelRenderer);
		void renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer);
		
		void renderImage(SDL_Renderer *imageRenderer);
	
	private:
		SDL_Surface *_backgroundImage;
		SDL_Texture *_backgroundTexture;
		SDL_Rect _backgroundRect;
};
#endif /* defined(__Mazel__Background__) */
