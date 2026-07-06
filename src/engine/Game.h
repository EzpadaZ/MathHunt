#pragma once

#include <memory>
#include <vector>

#include "engine/GameState.h"
#include "engine/RenderWindow.h"
#include "entities/Entity.h"
#include "managers/TextureManager.h"

class Game
{
public:
    Game();
    ~Game();

    bool init();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void shutdown();

    bool running;
    GameState state;

    RenderWindow window;
    std::unique_ptr<TextureManager> textures;

    std::vector<Entity> titleEntities;
    std::vector<Entity> playingEntities;
};