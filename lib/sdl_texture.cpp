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

    // -- set default value for vars + flags

    fit_window = NULL;
    FLAG_RENDER_CENTER = false;
    FLAG_SCALE_IMG = false;
    FLAG_SCALE_WINDOW = false;

    // std::cout << "SDL Texture initialised." << std::endl;
}

Texture::~Texture(){
    free();
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

    std::cout << "SDL Texture image: " << fpath << " loaded." << std::endl;
    std::cout << "tex_height: " << tex_height << ", tex_width: " << tex_width << std::endl;

}

void Texture::render(Renderer &ren, int x, int y, SDL_Rect* clip){

    // construct viewport quad
    SDL_Rect renderQuad = {x, y, tex_width, tex_height};
    if(clip != NULL){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // if window to fit is given
    if(fit_window!=NULL){

        // obtain window width + height
        int win_w;
        int win_h;
        fit_window->get_size(&win_w, &win_h);

        float ratio = (float) renderQuad.w / (float) renderQuad.h;

        // if flag given to scale iamge to window
        if(FLAG_SCALE_IMG){

            // resize rendering quad to fit window if required (maintains texture ratio)

            if(win_w < renderQuad.w){
                renderQuad.w = win_w;
                renderQuad.h = (int) (renderQuad.w/ratio);
            }

            if(win_h < renderQuad.h){
                renderQuad.h = win_h;
                renderQuad.w = (int) (ratio*renderQuad.h);
            }
            // std::cout << "Render size changed: " << renderQuad.w << ", " << renderQuad.h << std::endl;

        }

        // if flag to center rendering is given
        if(FLAG_RENDER_CENTER){
            renderQuad.x = (win_w/2) - (renderQuad.w/2);
            renderQuad.y = (win_h/2) - (renderQuad.h/2);
        }

    }

    SDL_RenderCopy(ren.get_renderer(), tex_, clip, &renderQuad);
    // std::cout << "SDL Texture image rendered." << std::endl;

}

void Texture::free(){
    if(tex_!=NULL){
        SDL_DestroyTexture(tex_);
        tex_ = NULL;
        tex_width = 0;
        tex_height = 0;
    }
    // std::cout << "SDL Texture freed." << std::endl;
}

int Texture::get_width(){
    return tex_width;
}

int Texture::get_height(){
    return tex_height;
}

}
