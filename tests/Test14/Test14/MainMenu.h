//
//  MainMenu.h
//  Test14
//
//  Created by Muhd Mirza on 3/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test14__MainMenu__
#define __Test14__MainMenu__

#include <iostream>

#include "GameState.h"
#include "RenderObject.h"
#include "Collision.h"

#define TITLE_IMAGE_WIDTH 150
#define TITLE_IMAGE_HEIGHT 150

#define START_IMAGE_WIDTH 150
#define START_IMAGE_HEIGHT 150

#define BALL_IMAGE_WIDTH 30
#define BALL_IMAGE_HEIGHT 30

using namespace std;

class MainMenu: public GameState {
	public:
		MainMenu();
		
		void setBall();
		
		void run();
		void moveBall();
		void event();
		void update();
		void render();
		void display();
		void cleanup();
		
	private:
		SDL_Window *_windowRef;
		SDL_Window *_window;
		SDL_Surface *_windowSurface;
		
		SDL_Renderer *_rendererRef;
		SDL_Renderer *_renderer;
		
		SDL_Event _event;
		
		bool _running;
		
		RenderObject *_renderObject;
		Collision *_collision;
		
		// title
		SDL_Surface *_titleImage;
		SDL_Texture *_titleTexture;
		SDL_Texture *_titleTextureRef;
		SDL_Rect _titleRect;
		
		// start button
		SDL_Surface *_startImage;
		SDL_Texture *_startTexture;
		SDL_Texture *_startTextureRef;
		SDL_Rect _startRect;
		
		// ball
		SDL_Surface *_ballImage;
		SDL_Texture *_ballTexture;
		SDL_Texture *_ballTextureRef;
		SDL_Rect _ballRect;
		
		int _ballSpeedX;
		int _ballSpeedY;
};

#endif /* defined(__Test14__MainMenu__) */
