#ifndef SDL_RENDERER_H
#define SDL_RENDERER_H

#include <SDL2/SDL.h>
#include "sdl_window.h"

namespace SDLwrap{

class Renderer{

    SDL_Renderer* ren_;

    public:
        Renderer(Window &window, int index=-1, Uint32 flags=SDL_RENDERER_ACCELERATED);
        ~Renderer();

        // getter for SDL renderer
        SDL_Renderer* get_renderer();

};

}

#endif
