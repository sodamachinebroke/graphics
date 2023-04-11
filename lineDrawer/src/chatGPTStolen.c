#include "chatGPTStolen.h"
#include "SDL2/SDL.h"

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

void chatGPTGayRectGen(SDL_Renderer *renderer, SDL_Event event)
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