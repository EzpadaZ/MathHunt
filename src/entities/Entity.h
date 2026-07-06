/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.h
 * Author: Jorge
 *
 * Created on October 6, 2020, 3:38 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "utils/Math.h"

class Entity{
public:
    Entity(Vector2f p_pos, SDL_Texture* p_texture);
    Entity(Vector2f p_pos, SDL_Texture* p_texture, int p_sizew, int p_sizeh);
    void setTexture(SDL_Texture* p_texture);
    SDL_Texture* getTexture();
    SDL_Rect getCurrentFrame();
    Vector2f& getPos(){
        return pos;
    }
    void setX(float px);
    void setY(float py);
    void setPos(Vector2f p_pos);
private:
    Vector2f pos;
    SDL_Rect currentFrame;
    SDL_Texture* texture;
};


#endif /* ENTITY_H */

