#include <stdio.h>
#include <stdlib.h>
#include "SDL2/SDL.h"

int keypressed;
int errorCount = 0;

typedef struct color
{
    int red, green, blue;
} Color;

typedef struct line
{
    int coordinates[2][2];
    Color color;
} Line;

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

void chatGPTCircleGen(SDL_Renderer *renderer, SDL_Event event)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(renderer, event.button.x - 10, event.button.y, event.button.x + 10, event.button.y);
    SDL_RenderDrawLine(renderer, event.button.x, event.button.y - 10, event.button.x, event.button.y + 10);
    SDL_RenderDrawLine(renderer, event.button.x - 7, event.button.y - 7, event.button.x + 7, event.button.y + 7);
    SDL_RenderDrawLine(renderer, event.button.x - 7, event.button.y + 7, event.button.x + 7, event.button.y - 7);
    SDL_RenderPresent(renderer);
}

void chatGPTRectGen(SDL_Renderer *renderer, SDL_Event event)
{
    SDL_Rect rect = {event.button.x - 20, event.button.y - 20, 40, 40};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

void chatGPTFullRectGen(SDL_Renderer *renderer, SDL_Event event)
{
    int x = event.button.x - 20;
    int y = event.button.y - 20;
    int w = 200;
    int h = 20;

    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    rect.y += h;
    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    rect.y += h;
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    rect.y += h;
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    rect.y += h;
    SDL_SetRenderDrawColor(renderer, 0, 127, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    rect.y += h;
    SDL_SetRenderDrawColor(renderer, 139, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

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
                    chatGPTFullRectGen(renderer, event);
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
int main(int argc, char const *argv[])
{
    loopThis();
    return 0;
}
