/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "entities/Entity.h"

const int DEFAULT_SIZE = 50; // el nombre explica que es esto.

Entity::Entity(Vector2f p_pos, SDL_Texture* p_texture)
:pos(p_pos), texture(p_texture){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = DEFAULT_SIZE;
    currentFrame.h = DEFAULT_SIZE;
}

Entity::Entity(Vector2f p_pos, SDL_Texture* p_texture, int p_sizew, int p_sizeh)
:pos(p_pos),texture(p_texture){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = p_sizew;
    currentFrame.h = p_sizeh;
}

SDL_Texture* Entity::getTexture(){
    return texture;
}

SDL_Rect Entity::getCurrentFrame(){
    return currentFrame;
}

void Entity::setX(float px){
    pos.x = px;
}

void Entity::setY(float py){
    pos.y = py;
}

void Entity::setPos(Vector2f p_pos){
    pos = p_pos;
}
