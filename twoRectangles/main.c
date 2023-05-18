#include <SDL2/SDL.h>
#include <stdlib.h>

int main() {
    // Variables
    int quit = 0;
    int leftMouseButtonDown = 0;
    SDL_Event event;
    SDL_Rect rect1 = { 288, 208, 100, 100 };
    SDL_Rect rect2 = { 50, 50, 100, 80 };
    SDL_Rect *rectangles[2] = { &rect1, &rect2 };
    SDL_Rect *selectedRect = NULL;
    SDL_Point mousePos;
    SDL_Point clickOffset;

    // Init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDL2 Drag and Drop",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    // Handle events
    while (!quit) {
        SDL_Delay(10);
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit = 1;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (!leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT) {
                    leftMouseButtonDown = 1;

                    for (int i = 0; i < 2; i++) {
                        if (SDL_PointInRect(&mousePos, rectangles[i])) {
                            selectedRect = rectangles[i];
                            clickOffset.x = mousePos.x - rectangles[i]->x;
                            clickOffset.y = mousePos.y - rectangles[i]->y;
                            break;
                        }
                    }
                }
                break;

            case SDL_MOUSEMOTION:
                mousePos = (SDL_Point){ event.motion.x, event.motion.y };

                if (leftMouseButtonDown && selectedRect != NULL) {
                    selectedRect->x = mousePos.x - clickOffset.x;
                    selectedRect->y = mousePos.y - clickOffset.y;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                if (leftMouseButtonDown && event.button.button == SDL_BUTTON_LEFT) {
                    leftMouseButtonDown = 0;
                    selectedRect = NULL;
                }
                break;
        }

        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 2; i++) {
            if (rectangles[i] == selectedRect)
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            else
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

            SDL_RenderFillRect(renderer, rectangles[i]);
        }

        SDL_RenderPresent(renderer);
    }

    // Cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
