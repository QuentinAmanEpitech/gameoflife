#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "game.h"
#include "map.h"

int main(int argc, char const *argv[])
{
    if (initSDL() == -1)
        goto Quit;

    SDL_Event event;
    int map[CELLSROW][CELLSCOLUMN] = {0};

    SDL_Window *pWindow = generateWindow("Game of Life");
    if (!pWindow)
        goto Quit;

    SDL_Renderer *pRenderer = generateRenderer(pWindow);
    if (!pRenderer)
        goto Quit;

    int playGame = 1, pause = 1;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;
    double refreshRate = 0;

    refreshRender(pRenderer, map);

    while (playGame == 1)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                playGame = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    map[(int)(event.button.y / CELLSIZE)][(int)(event.button.x / CELLSIZE)] = 1;
                else
                    map[(int)(event.button.y / CELLSIZE)][(int)(event.button.x / CELLSIZE)] = 0;
                refreshRender(pRenderer, map);
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE)
                    pause = !pause;
                break;
            }
        }
        LAST = NOW;
        NOW = SDL_GetPerformanceCounter();
        refreshRate += (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

        if (refreshRate >= 100 && pause != 1)
        {
            refreshRate = 0;
            updateMapLogic(map);
            refreshRender(pRenderer, map);
        }
    }

Quit:
    if (!pRenderer)
        SDL_DestroyRenderer(pRenderer);
    if (!pWindow)
        SDL_DestroyWindow(pWindow);
    SDL_Quit();
    return EXIT_SUCCESS;
}