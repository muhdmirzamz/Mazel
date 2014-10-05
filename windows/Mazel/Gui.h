//
//  Gui.h
//  Mazel
//	GUI for state classes
//
//  Created by Muhd Mirza on 14/9/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef __Mazel__Gui__
#define __Mazel__Gui__

#include <iostream>

#include "Includes.h"

using namespace std;

class Gui {
	public:
		Gui();
		
		void loadImageOntoTexture(string filePathOfImage, SDL_Renderer *renderer);
		
		void plotGui(int x, int y, int w, int h);
		void plotStartImage(int xPos, int yPos);
		void plotInstructionsImage(int xPosition, int yPosition);
		
		int getX();
		int getY();
		int getW();
		int getH();
		
		void render(SDL_Renderer *guiRenderer);
	
	private:
		SDL_Surface *_guiImage;
		SDL_Texture *_guiTexture;
		SDL_Rect _guiRect;
};

#endif /* defined(__Mazel__Gui__) */
