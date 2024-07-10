#include "headers/header.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* bunnyTexture = NULL;
SDL_Texture* mazeTexture = NULL;
SDL_Texture* wallTexture = NULL;
Bunny bunny = {100.0f, 100.0f};

int initSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	window = SDL_CreateWindow("Bunny Maze", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) {
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return 0;
	}
return 1;
}

SDL_Texture* loadTexture(const char* path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path);
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! IMG_Error: %s\n", path, IMG_GetError());
		} else {
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			SDL_FreeSurface(loadedSurface);
		}
	return newTexture;
}

void handleInput(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_UP: bunny.y -= 5.0f; break;
            case SDLK_DOWN: bunny.y += 5.0f; break;
            case SDLK_LEFT: bunny.x -= 5.0f; break;
            case SDLK_RIGHT: bunny.x += 5.0f; break;
        }
    }
}

void renderGame() {
    SDL_RenderClear(renderer);

    SDL_Rect mazeRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(renderer, mazeTexture, NULL, &mazeRect);

    SDL_Rect wallRect = {BLOCK_SIZE * 2, BLOCK_SIZE * 2, BLOCK_SIZE, BLOCK_SIZE};
    SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);

    SDL_Rect destRect = { (int)bunny.x, (int)bunny.y, BLOCK_SIZE, BLOCK_SIZE };
    SDL_RenderCopy(renderer, bunnyTexture, NULL, &destRect);

    SDL_RenderPresent(renderer);
}

void cleanup() {
    SDL_DestroyTexture(bunnyTexture);
    SDL_DestroyTexture(mazeTexture);
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* args[]) {
    if (!initSDL()) {
        printf("Failed to initialize!\n");
        return -1;
    }
    bunnyTexture = loadTexture("images/bunny.png");
    if (bunnyTexture == NULL) {
        printf("Failed to load bunny texture!\n");
        return -1;
    }

    mazeTexture = loadTexture("images/maze.png");
    if (mazeTexture == NULL) {
        printf("Failed to load maze texture!\n");
        return -1;
    }

    wallTexture = loadTexture("images/wall.png");
    if (wallTexture == NULL) {
        printf("Failed to load wall texture!\n");
        return -1;
    }

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else {
                handleInput(e);
            }
        }

        renderGame();
    }

    cleanup();
    return 0;
}
