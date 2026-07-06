#include "managers/TextureManager.h"
#include <iostream>
#include <SDL2/SDL_image.h>


TextureManager::TextureManager(SDL_Renderer* renderer)
    : renderer(renderer)
{
}

TextureManager::~TextureManager()
{
    clear();
}

void TextureManager::clear()
{
    for (auto& pair : textures)
    {
        SDL_DestroyTexture(pair.second);
    }

    textures.clear();
}

bool TextureManager::load(const std::string& name, const std::string& path){
    if (textures.find(name) != textures.end()){
        return true;
    }

    SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());

    if (texture == nullptr){
        std::cout << "No se pudo cargar " << path << ": "<< IMG_GetError() << "\n";
        return false;
    }

    textures[name] = texture;
    return true;
}

SDL_Texture* TextureManager::get(const std::string& name) const {
    auto texture = textures.find(name);

    if (texture == textures.end()){
        return nullptr;
    }

    return texture->second;
}