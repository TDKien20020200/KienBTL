#ifndef BASEOBJECT_H_INCLUDED
#define BASEOBJECT_H_INCLUDED
#include "commonFunc.h"

class baseObject
{
public:
    baseObject();
    ~baseObject();
    void setRect(const int& x, const int& y) {rect_.x=x;rect_.y=y;}
    SDL_Rect getRect()const{return rect_;}
    SDL_Texture* getObject() const {return p_object_;}

    bool loadImg(std::string path, SDL_Renderer* screen);
    void render(SDL_Renderer* des, const SDL_Rect* clip=NULL);
    void Free();

protected:
    SDL_Texture* p_object_;
    SDL_Rect rect_;
};



#endif // BASEOBJECT_H_INCLUDED
