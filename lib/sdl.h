#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>

namespace SDLwrap{

class SDL{

    public:
        SDL(Uint32 flags=SDL_INIT_VIDEO);
        ~SDL();

        // print SDL version
        void printVer();

};

}

#endif
