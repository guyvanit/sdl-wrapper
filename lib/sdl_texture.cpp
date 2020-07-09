#include <string>
#include <SDL2_image/SDL_image.h>

#include "sdl_texture.h"

namespace SDLwrap{

    Texture::Texture(){
        tex_ = NULL;
    }

    Texture::~Texture(){
        free();
    }

    void Texture::free(){
        if(tex_!=NULL){
            SDL_DestroyTexture(tex_);
            tex_ = NULL;
        }
    }

    void Texture::loadFile(std::string fpath){
        free();

        bool success = true;
        SDL_Texture* texture = NULL;

        SDL_Surface* tempSurface = IMG_Load(fpath.c_str());
        if(tempSurface == NULL){
            success = false;
        }else{

            // creates SDL_Texture from loaded SDL_Surface
            texture = SDL_CreateTextureFromSurface(g_Renderer, loadedSurface);
            if(texture == NULL){
                success = false;
            }

        }

        // clean up surface
        SDL_FreeSurface(tempSurface);

        // TODO: build surface wrapper + use it here

    }

}
