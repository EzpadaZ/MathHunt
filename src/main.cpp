/* 
 * File:   main.cpp
 * Author: Jorge
 *
 * Created on October 5, 2020, 11:45 AM
 */


#include <iostream>

#include "engine/RenderWindow.h"
#include "managers/TextureManager.h"
#include "engine/GameState.h"

RenderWindow window;
bool gameRunning = true;
GameState gameState = GameState::Title;

bool init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        std::cout << "Failed SDL2 Init, "<< SDL_GetError() << std::endl;
        return false;
    }
        
    if(!IMG_Init(IMG_INIT_PNG)){
        std::cout << "SDL2Image failed init "<< SDL_GetError() << std::endl;
        return false;
    }
    
    SDL_ShowCursor(SDL_DISABLE); // adios cursor.
    window.crear("MathHunt - C++ Engine Test", 1280,720);
    return true;
}

void gameLoop(Entity& debugEntity){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                gameRunning = false;
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_RETURN && gameState == GameState::Title){
                    gameState = GameState::Playing;
                }
                break;
        }
    }
    
    window.limpiarPantalla();
    
    window.renderAnimated(debugEntity,8,100,true);
    window.display();
}


int main(int argc, char** argv) {
    if (!init())
    {
        std::cout << "No se pudo iniciar MathHunt.\n";
        return 1;
    }

    TextureManager textures(window.getRenderer());

    if (!textures.load("debug", "images/debug.png")) return 1;
    if (!textures.load("stage", "images/stage.png")) return 1;

    Entity debugEntity(
        Vector2f((1280 / 2) - 64, (720 / 2) - 64),
        textures.get("debug"),
        64,
        64
    );

    Entity stageEntity(
        Vector2f(0, 0),
        textures.get("stage"),
        1280,
        769
    );

    // Main File
    while(gameRunning)
    {
        gameLoop(debugEntity);
        SDL_Delay(16);
    }

    textures.clear();
    window.limpiar();
    IMG_Quit();
    SDL_Quit();
    return 0;
}

