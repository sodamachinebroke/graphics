#include "loop.h"
#include <stdbool.h>

void loopThis()
{
    int error_code;
    SDL_Window *screen = NULL;
    SDL_Renderer *renderer;
    SDL_Event event;
    int i;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0)
    {
        printf("Initialization error: %s\n", SDL_GetError());
    }

    screen = SDL_CreateWindow("Draw me some gay stuff", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    int x1, x2, y1, y2;
    int coords[2][2];
    int clicked = 0;

    int run = 1;
    while (run == 1)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
            case SDL_MOUSEBUTTONDOWN:
                if (clicked % 2 == 0)
                {
                    coords[0][0] = event.button.x;
                    coords[0][1] = event.button.y;
                    clicked++;
                }
                else if (clicked % 2 == 1)
                {
                    coords[1][0] = event.button.x;
                    coords[1][1] = event.button.y;
                    clicked++;
                    SDL_RenderDrawLine(renderer, coords[0][0], coords[0][1], coords[1][0], coords[1][1]);
                    SDL_RenderPresent(renderer);
                }

                break;
            case SDL_SCANCODE_Q:
                run = 0;
                break;
            case SDL_QUIT:
                run = 0;
                break;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    SDL_Quit();
}