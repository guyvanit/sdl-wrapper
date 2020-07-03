#ifndef SDL
#define SDL

#include <SDL2/SDL.h>

namespace SDLwrap{

class SDL{

    public:
        SDL(Uint32 flags=SDL_INIT_VIDEO);
        ~SDL();

};

}

#endif
