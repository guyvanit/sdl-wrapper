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

        // copy constructor + copy assignment operator
        // -> do not allow copy of resources of Surface class
        Surface(const Surface& that) = delete;
        Surface& operator=(const Surface& that) = delete;

        // ways of loading into SDL_Surface
        void loadFile(std::string &fpath);

        // clean up surface
        void free();

        SDL_Surface* get_surface();

};

}

#endif
