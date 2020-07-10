#include <iostream>
#include <string>
#include <SDL2_image/SDL_image.h>

#include "sdl_texture.h"
#include "sdl_surface.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

Texture::Texture(){
    tex_ = NULL;
    tex_width = 0;
    tex_height = 0;

    fit_window = NULL;
    // std::cout << "SDL Texture initialised." << std::endl;
}

Texture::~Texture(){
    free();
}

void Texture::free(){
    if(tex_!=NULL){
        SDL_DestroyTexture(tex_);
        tex_ = NULL;
        tex_width = 0;
        tex_height = 0;
    }
    std::cout << "SDL Texture freed." << std::endl;
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
    }else{

        tex_width = tempSurface.get_surface()->w;
        tex_height = tempSurface.get_surface()->h;

    }

    // stores non-NULL texture into tex_
    tex_ = texture;

    std::cout << "SDL Texture image loaded." << std::endl;
    std::cout << "tex_height: " << tex_height << ", tex_width: " << tex_width << std::endl;

}

void Texture::render(Renderer &ren, int x, int y, SDL_Rect* clip){

    // construct viewport quad
    SDL_Rect renderQuad = {x, y, tex_width, tex_height};
    if(clip != NULL){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // resize rendering quad to fit window if required
    if(fit_window!=NULL){
        float ratio = (float) renderQuad.w / (float) renderQuad.h;
        fit_window->update_size();

        if(fit_window->get_width() < renderQuad.w){
            renderQuad.w = fit_window->get_width();
            renderQuad.h = (int) (renderQuad.w/ratio);
        }

        if(fit_window->get_height() < renderQuad.h){
            renderQuad.h = fit_window->get_height();
            renderQuad.w = (int) (ratio*renderQuad.h);
        }
        // std::cout << "Render size changed: " << renderQuad.w << ", " << renderQuad.h << std::endl;
    }

    SDL_RenderCopy(ren.get_renderer(), tex_, clip, &renderQuad);
    // std::cout << "SDL Texture image rendered." << std::endl;

}

}
