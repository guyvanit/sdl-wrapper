#include <iostream>
#include <string>
#include <SDL2_image/SDL_image.h>

#include "sdl_texture.h"
#include "sdl_surface.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

Texture::Texture(){
    tex_ = NULL;
    // std::cout << "SDL Texture initialised." << std::endl;
}

Texture::~Texture(){
    free();
}

void Texture::free(){
    if(tex_!=NULL){
        SDL_DestroyTexture(tex_);
        tex_ = NULL;
    }
    // std::cout << "SDL Texture freed." << std::endl;
}

void Texture::loadFile(Renderer &ren, std::string &fpath){

    // free up old texture first
    free();

    // intialise texture and surface to be converted
    SDL_Texture* texture = NULL;
    Surface tempSurface = Surface();
    tempSurface.loadFile(fpath);

    // creates SDL_Texture from loaded SDL_Surface
    texture = SDL_CreateTextureFromSurface(ren.get_renderer(), tempSurface.get_surface());
    if(texture == NULL){
        throw Exception("Texture::loadFile()");
    }

    // stores non-NULL texture into tex_
    tex_ = texture;
    // std::cout << "SDL Texture image loaded." << std::endl;

}

}
