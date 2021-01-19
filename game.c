#include "game.h"
#include <SDL2/SDL.h>

int initSDL()
{
    return SDL_Init(SDL_INIT_VIDEO);
}

SDL_Window *generateWindow(char name[])
{
    return SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, CELLSIZE * CELLSROW, CELLSIZE * CELLSCOLUMN, 0);
}

SDL_Renderer *generateRenderer(SDL_Window *window)
{
    return SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void updateMapLogic(int map[CELLSROW][CELLSCOLUMN])
{
    int tmpCells[CELLSROW][CELLSCOLUMN];
    for (int y = 0; y < CELLSROW; y++)
        for (int x = 0; x < CELLSCOLUMN; x++)
            tmpCells[y][x] = map[y][x];

    for (int y = 0; y < CELLSROW; y++)
        for (int x = 0; x < CELLSCOLUMN; x++)
        {
            int aliveCount = checkNeighbors(tmpCells, x, y);

            if (aliveCount == 3)
                map[y][x] = 1;
            else if (aliveCount < 2 || aliveCount > 3)
                map[y][x] = 0;
        }
}

int checkNeighbors(int map[CELLSROW][CELLSCOLUMN], int x, int y)
{
    int xCo, yCo, neighbors = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            xCo = x + j;
            yCo = y + i;

            if (xCo < 0 || yCo < 0 || xCo > CELLSCOLUMN - 1 || yCo > CELLSROW - 1)
                continue;
            if (i == 0 && j == 0)
                continue;

            neighbors += map[yCo][xCo];
        }
    }

    return neighbors;
}