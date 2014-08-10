//
//  Includes.h
//  Mazel
//	global include
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef Mazel_Includes_h
#define Mazel_Includes_h

// include SDL video component header files
// sub classes can also inherit these files
#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"
#include "SDL_surface.h"

// error header file
#include "SDL_error.h"

// constant window macros
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_X_POS 300
#define WINDOW_Y_POS 300

// constant macros for clicking positions
#define CLICKED_AT_XPOS _event.button.x
#define CLICKED_AT_YPOS _event.button.y

enum GameStates {
	INTRO_SCENE,
	MAIN_MENU,
	LEVEL_ONE,
	LEVEL_TWO,
	EXIT
};

#endif
