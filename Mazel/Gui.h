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
		void plotStartImage(int startXPos, int startYPos);
		void plotInstructionsImage(int instructionsXPosition, int instructionsYPosition);
		void plotSettingsImage(int settingsXPosition, int settingsYPosition);
		
		int getX();
		int getY();
		int getW();
		int getH();
		
		void render(SDL_Renderer *guiRenderer);
		void renderGUI(SDL_Renderer *guiRenderer2, int r, int g, int b);
	
	private:
		SDL_Surface *_guiImage;
		SDL_Texture *_guiTexture;
		SDL_Rect _guiRect;
};

#endif /* defined(__Mazel__Gui__) */
