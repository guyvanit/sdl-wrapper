#include <iostream>
#include <SDL2_image/SDL_image.h>

#include "sdl_surface.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

Surface::Surface(){
    surf_ = NULL;
    std::cout << "SDL Surface initalised." << std::endl;
}

Surface::~Surface(){
    free();
}

void Surface::loadFile(std::string fpath){
    surf_ = IMG_Load(fpath.c_str());
    if(surf_==NULL){
        throw Exception("Surface::loadFile");
    }
    std::cout << "SDL_Surface image loaded." << std::endl;
}

void Surface::free(){
    if(surf_!=NULL){
         SDL_FreeSurface(surf_);
         surf_=NULL;
    }
    std::cout << "SDL Surface freed." << std::endl;
}

SDL_Surface* Surface::get_surface(){
    return surf_;
}

}
