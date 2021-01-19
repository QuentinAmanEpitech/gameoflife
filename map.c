#include "game.h"
#include "map.h"
#include <SDL2/SDL.h>

void refreshRender(SDL_Renderer *renderer, int map[CELLSROW][CELLSCOLUMN])
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_Rect rect;

    for (int i = 0; i < CELLSROW; i++)
    {
        for (int j = 0; j < CELLSCOLUMN; j++)
        {
            if (map[i][j] == 1)
            {
                rect.h = CELLSIZE;
                rect.w = CELLSIZE;
                rect.x = j * CELLSIZE;
                rect.y = i * CELLSIZE;

                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    SDL_RenderPresent(renderer);
}