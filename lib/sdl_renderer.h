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

        // copy constructor + copy assignment operator
        // -> do not allow copy of resources of Renderer class
        Renderer(const Renderer& that) = delete;
        Renderer& operator=(const Renderer& that) = delete;

        // -- wrapped SDL_Renderer functions --

        // wraps SDL_SetRenderDrawColor()
        void setDrawColor(Uint8 r=0xFF, Uint8 g=0xFF, Uint8 b=0xFF, Uint8 a=0xFF);
        // wraps SDL_RenderClear()
        void clear();
        // wraps SDL_RenderPresent()
        void update();

        // getter for SDL renderer
        SDL_Renderer* get_renderer();

};

}

#endif
