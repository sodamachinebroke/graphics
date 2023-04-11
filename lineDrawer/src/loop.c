#include "loop.h"
#include <stdbool.h>

void drawLine(SDL_Renderer *renderer, int x1, int x2, int y1, int y2)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

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

    int x1, x2, y1, y2;

    int run = 1;
    while (run == 1)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    x1 = event.button.x;
                    y1 = event.button.y;
                }

                break;

            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                    x2 = event.button.x;
                    y2 = event.button.y;

                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
                SDL_RenderPresent(renderer);
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