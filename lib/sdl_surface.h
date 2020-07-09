#ifndef SDL_SURFACE_H
#define SDL_SURFACE_H

#include <string>
#include <SDL2/SDL.h>

namespace SDLwrap{

    class Surface{

        SDL_Surface* surf_;

        public:
            Surface();
            ~Surface();

            // ways of loading into SDL_Surface
            void loadFile(std::string fpath);

            // clean up surface
            void free();

    };

}

#endif
