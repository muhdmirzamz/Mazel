//
//  GameOverScene.h
//  Mazel
//
//  Created by Muhd Mirza on 21/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__GameOverScene__
#define __Mazel__GameOverScene__

#include <iostream>

#include "GameState.h"

using namespace std;

class GameOverScene: public GameState {
	public:
		GameOverScene();
		
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
		
		Render *_render; // free
		
		SDL_Surface *_gameOverBackground;
		SDL_Texture *_gameOverBackgroundTexture; // free
		SDL_Texture *_gameOverBackgroundTextureRef;
		SDL_Rect _gameOverBackgroundRect;
		
		GameManager *_gameManager;
};

#endif /* defined(__Mazel__GameOverScene__) */
