//
//  Includes.h
//  Mazel
//	global include
//	all macros and enums
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
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define WINDOW_X_POS 300
#define WINDOW_Y_POS 300

// constant main menu ball macros
#define MAIN_MENU_BALL_XPOS 20
#define MAIN_MENU_BALL_YPOS 20
#define MAIN_MENU_BALL_WIDTH 40
#define MAIN_MENU_BALL_HEIGHT 40
#define MAIN_MENU_BALL_SPEEDY 5

// constant main menu start image macros
#define BEGIN_OF_START_IMAGE 200
#define END_OF_START_IMAGE 400
#define TOP_OF_START_IMAGE 345
#define BOTTOM_OF_START_IMAGE 545

// constant basic level ball macros
#define BASIC_LEVEL_BALL_WIDTH 20
#define BASIC_LEVEL_BALL_HEIGHT 20
#define BASIC_LEVEL_BALL_SPEED 10

// constant basic level finish rectangle macros
#define BASIC_LEVEL_FINISH_RECT_WIDTH 50
#define BASIC_LEVEL_FINISH_RECT_HEIGHT 80

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

/*
 Currently, there are two ways to exit the game
 Apply this macro to the escape key and 'c' key
 for easy debugging
 Change to false if not debugging
 */
#define DEBUG_MODE true

#endif
