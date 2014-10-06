//
//  GameState.h
//  Test14
//
//  Created by Muhd Mirza on 2/7/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Test14__GameState__
#define __Test14__GameState__

#include <iostream>

#include "SDL_video.h"
#include "SDL_surface.h"
#include "SDL_render.h"
#include "SDL_events.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace std;

class GameState {
	public:
		GameState();
		virtual ~GameState();
		
		void printError(string level, string comp);
		
		virtual SDL_Window* setupWindow(SDL_Window *window);
		virtual SDL_Renderer* setupRenderer(SDL_Renderer *renderer, SDL_Window *window2);
		
		virtual void run() = 0;
		virtual void event();
		virtual void update();
		virtual void render();
		virtual void display();
		virtual void handleWallCollision(SDL_Rect rect1, int windowWidth, int windowHeight, int speedX, int speedY);
		virtual void cleanup();
		
		virtual SDL_Texture* loadImage(SDL_Surface *image, SDL_Texture *imageTexture, SDL_Renderer *renderer, const string path, int r, int g, int b);
		virtual void displayImage(SDL_Rect imageRect, int x, int y, int imageWidth, int imageHeight, SDL_Texture *imageTexture2, SDL_Renderer *renderer2);
	
		void changeState(int state);
				
	private:
};

#endif /* defined(__Test14__GameState__) */
