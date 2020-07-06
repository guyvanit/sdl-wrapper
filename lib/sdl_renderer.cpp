#include <iostream>

#include "sdl_render.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

Renderer::Renderer(Window& window, int index, Uint32 flags){
    ren_ = SDL_CreateRenderer(window, index, flags);
    if(ren_==NULL){
        throw Exception("Renderer::Renderer()");
    }
    std::cout << "SDL Renderer initalised." << std::endl;
}

Renderer::~Renderer(){
    if(ren_!=NULL){
        SDL_DestroyRenderer(ren_);
        std::cout << "SDL Renderer destroyed." << std::endl;
    }
}

}
