#include "imageObject.h"
#include <bits/stdc++.h>
imageObject::imageObject()
{
    p_object_=NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}
imageObject::~imageObject()
{
    Free();
}
void imageObject::loadImg(std::string path,SDL_Renderer* renderer)
{
    SDL_Texture* new_texture = NULL;
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    if (load_surface != NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(renderer, load_surface);
        if (new_texture != NULL)
        {
            rect_.w = load_surface->w;
            rect_.h = load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
    p_object_ = new_texture;
}

void imageObject::render(SDL_Renderer* des, int xp1, int yp1,int wp1, int hp1,const SDL_Rect* clip)
{
    rect_.x = xp1;
    rect_.y = yp1;
    rect_.w = wp1;
    rect_.h = hp1;

    SDL_Rect renderquad = {rect_.x,rect_.y,rect_.w,rect_.h};
    SDL_RenderCopy(des, p_object_, clip, &renderquad);
}

void imageObject::Free()
{
    if (p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}


