//
//  Render.h
//  Mazel
//	handles all the rendering in intro scene
//
//  Created by Muhd Mirza on 13/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

/*
	arguments passed here are mostly renderers and textures,
	Rectangles are declared in functions
	
	Surfaces and textures are declared in level classes
*/

#ifndef __Mazel__Render__
#define __Mazel__Render__

#include <iostream>

#include "Includes.h"

using namespace std;

class RenderIntroScene {
	public:
		RenderIntroScene();

		void renderIntroSceneBackground(SDL_Renderer *introSceneRenderer);
		void renderIntroSceneContinueButton(SDL_Renderer *introsceneRenderer2, SDL_Texture *continueButtonTexture);
		void renderIntroSceneLogo(SDL_Renderer *introsceneRenderer3, SDL_Texture *introsceneLogoTexture);
	
	private:
};

#endif /* defined(__Mazel__Render__) */
