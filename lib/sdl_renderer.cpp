#include <iostream>

#include "sdl_renderer.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

Renderer::Renderer(Window &window, int index, Uint32 flags){
    ren_ = SDL_CreateRenderer(window.get_window(), index, flags);
    if(ren_==NULL){
        throw Exception("Renderer::Renderer()");
    }
    // std::cout << "SDL Renderer initalised." << std::endl;
}

Renderer::~Renderer(){
    if(ren_!=NULL){
        SDL_DestroyRenderer(ren_);
        // std::cout << "SDL Renderer destroyed." << std::endl;
    }
}

// ------------ WRAPPED FUNCTIONS ------------

void Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a){
    SDL_SetRenderDrawColor(ren_, r, g, b, a);
}

void Renderer::clear(){
    SDL_RenderClear(ren_);
}

void Renderer::update(){
    SDL_RenderPresent(ren_);
}

// ---------------------------------------

SDL_Renderer* Renderer::get_renderer(){
    return ren_;
}

}
