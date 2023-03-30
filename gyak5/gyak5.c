#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

int keypressed;
int errorCount = 0;

struct Color
{
    int red, green, blue;
};

struct Line
{
    int coordinates[2][2];
    struct Color color;
};

/*void InitSetup()
{
    srand((int)time(NULL));
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_SHOWN, &screen, &renderer);
}

void FinishOff()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(screen);
    // Quit SDL
    SDL_Quit();
    exit(0);
}
*/
void mouseFinder()
{
    int x, y;
    SDL_GetGlobalMouseState(&x, &y);
    printf("%d, %d", x, y);
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

    screen = SDL_CreateWindow("Find my mouse", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);

    SDL_Color White = {255, 255, 255};
    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

    int run = 1;
    while (run == 1)
    {
        int x,y;
    SDL_GetGlobalMouseState(&x,&y);
    printf("X: %d, Y: %d\n",x,y);
    SDL_Surface* surfaceMessage =
    TTF_RenderText_Solid(Sans, "put your text here", White);
        

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
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
int main(int argc, char const *argv[])
{
    loopThis();
    return 0;
}
