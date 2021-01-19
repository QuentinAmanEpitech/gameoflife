#include <SDL2/SDL.h>

#ifndef DEF_GAME
#define DEF_GAME
#define CELLSIZE 15
#define CELLSROW 75
#define CELLSCOLUMN 75

int initSDL();
SDL_Window *generateWindow(char name[]);
SDL_Renderer *generateRenderer(SDL_Window *window);
void updateMapLogic(int map[CELLSROW][CELLSCOLUMN]);
int checkLine(int map[CELLSROW][CELLSCOLUMN], int x, int y);
int checkNeighbors(int map[CELLSROW][CELLSCOLUMN], int x, int y);

#endif