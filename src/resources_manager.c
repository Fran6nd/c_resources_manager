#include "resources_manager.h"

void resources_init()
{
    resources_manager.images = NULL;
    resources_manager.images_counter = 0;
}
void resources_free()
{
    int i;
    for (i = 0; i < resources_manager.images_counter; i++)
    {
        if (resources_manager.images[i] != NULL)
            SDL_DestroyTexture(resources_manager.images[i]);
    }
    free(resources_manager.images);
    resources_manager.images_counter = 0;
}
void resources_free_image(int id)
{
    if (id < resources_manager.images_counter)
        if (resources_manager.images[id] != NULL)
            SDL_DestroyTexture(resources_manager.images[id]);
}
int resources_load_image(SDL_Renderer *r, char *path, int color_key)
{
    SDL_Surface *img = SDL_LoadBMP(path);
    if (color_key != -1)
        SDL_SetColorKey(img, 1, color_key);
    resources_manager.images_counter++;
    if (resources_manager.images_counter == 1)
    {
        resources_manager.images = malloc(sizeof(SDL_Texture *));
    }
    else
    {
        resources_manager.images = realloc(resources_manager.images, sizeof(SDL_Texture *) * resources_manager.images_counter);
    }
    resources_manager.images[resources_manager.images_counter - 1] = SDL_CreateTextureFromSurface(r, img);
    SDL_FreeSurface(img);
    return resources_manager.images_counter - 1;
}
SDL_Texture *resources_get_image(int id)
{
    return resources_manager.images[id];
}