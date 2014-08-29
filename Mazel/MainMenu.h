//
//  MainMenu.h
//  Mazel
//	Game Main Menu
//
//  Created by Muhd Mirza on 31/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__MainMenu__
#define __Mazel__MainMenu__

#include <iostream>

#include "GameState.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
	
		void setup();
		void setupObjects();
		void setupTextures();
		void setupBall();
		
		void run();
		
		void event();
		void checkCollision();
		
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
		
		Collision *_collision; // free
		Render *_render; // free
		
		SDL_Surface *_logo;
		SDL_Texture *_logoTexture; // free
		SDL_Texture *_logoTextureRef;
		
		SDL_Surface *_mainMenuHalfBackground;
		SDL_Texture *_mainMenuHalfBackgroundTexture; // free
		SDL_Texture *_mainMenuHalfBackgroundTextureRef;
		
		SDL_Surface *_ballImage;
		SDL_Texture *_ballTexture; // free
		SDL_Texture *_ballTextureRef;
		SDL_Rect _ballRect;
		int _ballSpeedY;
		
		SDL_Surface *_startImage;
		SDL_Texture *_startTexture; // free
		SDL_Texture *_startTextureRef;
};

#endif /* defined(__Mazel__MainMenu__) */
