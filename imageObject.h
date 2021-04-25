#ifndef IMAGEOBJECT_H_INCLUDED
#define IMAGEOBJECT_H_INCLUDED

#include "commonFunc.h"
class imageObject
{
public:
    imageObject();
    ~imageObject();
    void setRect(const int& x, const int& y) {rect_.x=x;rect_.y=y;}
    SDL_Rect getRect()const{return rect_;}
    SDL_Texture* getObject() const {return p_object_;}

    void loadImg(std::string path, SDL_Renderer* screen);

    void render(SDL_Renderer* des,int xp1, int yp1,int wp1, int hp1, const SDL_Rect* clip=NULL);
    void Free();

protected:
    SDL_Texture* p_object_;
    SDL_Rect rect_;
};

#endif // IMAGEOBJECT_H_INCLUDED
