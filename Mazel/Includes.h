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

enum GameStates {
	MAIN_MENU,
	LEVEL_ONE,
	LEVEL_TWO,
	EXIT
};

#endif
