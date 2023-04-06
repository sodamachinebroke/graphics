#include "loop.h"

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
                    chatGPTGayRectGen(renderer, event);
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