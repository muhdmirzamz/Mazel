//
//  RenderMainMenu.h
//  Mazel
//	handles rendering in main menu
//
//  Created by Muhd Mirza on 13/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

/*
	arguments passed here are mostly renderers and textures,
	Rectangles are declared in functions
 
	Surfaces and textures are declared in level classes
 */

#ifndef __Mazel__RenderMainMenu__
#define __Mazel__RenderMainMenu__

#include <iostream>

#include "Includes.h"

using namespace std;

class RenderMainMenu {
	public:
		RenderMainMenu();
		
		void renderMainMenuBackground(SDL_Renderer *mainMenuRenderer);
		void renderMainMenuLogo(SDL_Renderer *mainMenuRenderer2, SDL_Texture *logoTexture);
		void renderMainMenuGrassBackground(SDL_Renderer *mainMenuRenderer3, SDL_Texture *grassBackgroundTexture);
		void renderMainMenuStartButton(SDL_Renderer *mainMenuRenderer4, SDL_Texture *startButton);
		void renderMainMenuBall(SDL_Renderer *mainMenuRenderer5, SDL_Texture *ballTexture, SDL_Rect ballRect); // ball rect needs to be passed in
	
	private:
};

#endif /* defined(__Mazel__RenderMainMenu__) */
