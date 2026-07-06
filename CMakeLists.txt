cmake_minimum_required(VERSION 3.20)

project(MathHunt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

add_executable(mathhunt
    src/main.cpp
    src/engine/renderwindow.cpp
    src/entities/entity.cpp
    src/utils/math.cpp
    src/managers/TextureManager.cpp
    src/engine/Game.cpp
)

target_include_directories(mathhunt PRIVATE src)

target_link_libraries(mathhunt PRIVATE
    SDL2::SDL2
    SDL2_image::SDL2_image
)
