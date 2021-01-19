#include <SDL2/SDL.h>
#include "game.h"

#ifndef DEF_MAP
#define DEF_MAP

void refreshRender(SDL_Renderer *renderer, int map[CELLSROW][CELLSCOLUMN]);

#endif