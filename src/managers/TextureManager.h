#pragma once

#include <string>
#include <unordered_map>

#include <SDL2/SDL.h>

class TextureManager {
    public:
        explicit TextureManager(SDL_Renderer* renderer);
        ~TextureManager();

        bool load(const std::string& name, const std::string& path);

        SDL_Texture* get(const std::string& name) const;

        void clear();
    
    private:
        SDL_Renderer* renderer;
        std::unordered_map<std::string, SDL_Texture*> textures;
};