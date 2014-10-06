//
//  Obstacle.h
//  Mazel
//	Ball functions for state classes
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Obstacle__
#define __Mazel__Obstacle__

#include <iostream>

#include "Includes.h"

using namespace std;

class Obstacle {
	public:
		Obstacle();
		
		void loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer);
		void plotObstacle(int x, int y, int w, int h);
		void plotFinishRect(int xPos, int yPos);
		
		int getX();
		int getY();
		int getW();
		int getH();
		
		void render(SDL_Renderer *obstacleRenderer);
		void renderImage(SDL_Renderer *obstacleImageRenderer); // used for finish rectangle
	
	private:
		SDL_Surface *_obstacleImage;
		SDL_Texture *_obstacleTexture;
		SDL_Rect _obstacleRect;
};

#endif /* defined(__Mazel__Obstacle__) */
