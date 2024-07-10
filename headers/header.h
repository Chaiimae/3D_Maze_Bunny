#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BLOCK_SIZE 64

typedef struct {
    float x, y;
} Bunny;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Texture* bunnyTexture;
extern Bunny bunny;

int initSDL();
SDL_Texture* loadTexture(const char* path);
void handleInput(SDL_Event event);
void renderGame();
void cleanup();

#endif
