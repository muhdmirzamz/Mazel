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
#include "Collision.h"

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
	
		// inherited functions to override
		void setup();
		void run();
		void event();
		void update();
		void render();
		void cleanup();
		
		void moveBall();
		
	private:
		SDL_Window *_window; // free
		SDL_Window *_windowRef;
		SDL_Renderer *_renderer; // free
		SDL_Renderer *_rendererRef;
		SDL_Event _event;
		
		Collision *_collision; // free
		
		bool _running;
		
		SDL_Surface *_icon;
		
		SDL_Surface *_logo;
		SDL_Texture *_logoTexture; // free
		SDL_Texture *_logoTextureRef;
		SDL_Rect _logoTextureRect;
		
		SDL_Surface *_mainMenuHalfBackground;
		SDL_Texture *_mainMenuHalfBackgroundTexture; // free
		SDL_Texture *_mainMenuHalfBackgroundTextureRef;
		SDL_Rect _mainMenuHalfBackGroundRect;
		
		SDL_Surface *_ballImage;
		SDL_Texture *_ballTexture; // free
		SDL_Texture *_ballTextureRef;
		SDL_Rect _ballRect;
		int _ballSpeedX;
		int _ballSpeedY;
		
		SDL_Surface *_startImage;
		SDL_Texture *_startTexture; // free
		SDL_Texture *_startTextureRef;
		SDL_Rect _startRect;
};

#endif /* defined(__Mazel__MainMenu__) */
