//
//  IntroScene.h
//  Mazel
//	A simple intro scene before going to the main menu
//
//  Created by Muhd Mirza on 6/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__IntroScene__
#define __Mazel__IntroScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class IntroScene: public GameState {
	public:
		IntroScene();
		
		void setup();
		void setupObjects();
		void setupTextures();
		
		void run();
		
		void event();
		
		void update();
		void render();
		
		void cleanup();
	
	private:
		SDL_Window *_window; // free
		SDL_Window *_windowRef;
		SDL_Renderer *_renderer; // free
		SDL_Renderer *_rendererRef;
		SDL_Event _event;
		
		bool _running;
		
		SDL_Surface *_icon;
		
		RenderIntroScene *_renderIntroScene; // free
		
		// logo
		SDL_Surface *_introLogo;
		SDL_Texture *_introLogoTexture; // free
		SDL_Texture *_introLogoTextureRef;
		
		// continue button
		SDL_Surface *_continueButton;
		SDL_Texture *_continueButtonTexture; // free
		SDL_Texture *_continueButtonTextureRef;
};

#endif /* defined(__Mazel__IntroScene__) */
