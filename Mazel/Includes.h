//
//  Includes.h
//  Mazel
//	global include
//	game-wide macros
//
//  Created by Muhd Mirza on 3/8/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef Mazel_Includes_h
#define Mazel_Includes_h

// include SDL video component header files
#include "SDL_video.h"
#include "SDL_render.h"
#include "SDL_events.h"
#include "SDL_surface.h"
#include "SDL_error.h"

// title macros
#define GAME_TITLE "Mazel"

// constant window macros
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480
#define WINDOW_X_POS	300
#define WINDOW_Y_POS	100

// constant logo macros
#define LOGO_XPOS			(WINDOW_WIDTH / 8 + 50)
#define LOGO_YPOS			40
#define LOGO_WIDTH_HEIGHT	400

// constant macro for event type
#define EVENT_TYPE _event.type

// constant macro for key press
#define PRESSED_KEY _event.key.keysym.sym

// constant macros for mouse cursor coordinates
#define POINT_AT_XPOS _event.motion.x
#define POINT_AT_YPOS _event.motion.y

// constant macros for mouse clicking coordinates
#define CLICK_AT_XPOS _event.button.x
#define CLICK_AT_YPOS _event.button.y

/* Change to false if not debugging */
#define DEBUG_MODE false

#endif
