/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "engine/RenderWindow.h"
#include <iostream>


RenderWindow::RenderWindow(){
    //
    window = NULL;
    renderer = NULL;
}

void RenderWindow::crear(const char* title, int width, int height){
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    
    if(window == NULL)
        std::cout << "No se pudo iniciar la ventana, " << SDL_GetError() << std::endl;
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::cargarTextura(const char* path){
    SDL_Texture* textura = NULL;
    textura = IMG_LoadTexture(renderer, path);
    if(textura == NULL)
        std::cout << "Fallo la carga de imagen " << SDL_GetError() << std::endl;
    
    //TODO: Missing Texture return.
    return textura;
}

SDL_Renderer* RenderWindow::getRenderer() const {
	return renderer;
}

void RenderWindow::limpiarPantalla(){
    SDL_RenderClear(renderer);
}

void RenderWindow::limpiar(){
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void RenderWindow::render(Entity& entity, bool scaled){
    //Refactored.
	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	SDL_Rect dst; // Destino, donde estara dibujada la textura.
	dst.x = entity.getPos().x;
	dst.y = entity.getPos().y;

	if(scaled){
		dst.w = entity.getCurrentFrame().w * 2;
		dst.h = entity.getCurrentFrame().h  * 2;
	}
		else
	{
		dst.w = entity.getCurrentFrame().w;
		dst.h = entity.getCurrentFrame().h;
	}
	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::renderAnimated(Entity& entity, int frames, int speed, bool scaled){
    SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.w = entity.getCurrentFrame().w;
	src.h = entity.getCurrentFrame().h;

	// used for spritesheet animations (HORIZONTALLY ONLY.)
	int magic = static_cast<int>((SDL_GetTicks() / speed) % frames);
	src.x = src.w * magic;

	SDL_Rect dst; // Destino, donde estara dibujada la textura.
	dst.x = entity.getPos().x;
	dst.y = entity.getPos().y;
	if(scaled){
		dst.w = entity.getCurrentFrame().w * 2;
		dst.h = entity.getCurrentFrame().h * 2;
	}else{
		dst.w = entity.getCurrentFrame().w;
		dst.h = entity.getCurrentFrame().h;
	}

	SDL_RenderCopy(renderer, entity.getTexture(), &src, &dst);
}

void RenderWindow::renderColor(){

}

void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}
