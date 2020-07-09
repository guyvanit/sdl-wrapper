#include <SDL2_image/SDL_image.h>

#include "sdl_surface.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

    Surface::Surface(){
        surf_ = NULL;
    }

    Surface::~Surface(){
        free();
    }

    void Surface::loadFile(std::string fpath){
        surf_ = IMG_Load(fpath.c_str());
        if(surf_==NULL){
            throw Exception("Surface::loadFile");
        }
    }

    void Surface::free(){
        if(surf_!=NULL){
             SDL_FreeSurface(surf_);
             surf_=NULL;
        }
    }

}
