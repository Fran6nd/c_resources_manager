#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL2/SDL.h>

typedef struct ResourcesManager ResourcesManager;

struct ResourcesManager
{
    SDL_Texture **images;
    int images_counter;
};

ResourcesManager resources_manager;

void resources_init();
void resources_free();
void resources_free_image(int id);
int resources_load_image(SDL_Renderer *, char *, int);
SDL_Texture *resources_get_image(int id);

#endif