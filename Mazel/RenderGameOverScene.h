//
//  RenderGameOverScene.h
//  Mazel
//
//  Created by Muhd Mirza on 21/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__RenderGameOverScene__
#define __Mazel__RenderGameOverScene__

#include <iostream>

#include "Includes.h"

using namespace std;

class RenderGameOverScene {
	public:
		RenderGameOverScene();
		
		void renderGameOverSceneBackground(SDL_Renderer *gameOverSceneRenderer, SDL_Texture *gameOverSceneBackground);
	
	private:
};

#endif /* defined(__Mazel__RenderGameOverScene__) */
