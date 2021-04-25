#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED
#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Event g_event;

//screen
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 650;
//const int SCREEN_BPP = 32;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;


#endif // COMMONFUNC_H_INCLUDED
