#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include <SDL2/SDL.h>
#include "sdl_renderer.h"

namespace SDLwrap{

class Texture{

    SDL_Texture* tex_;
    int tex_width;
    int tex_height;

    public:
        Texture();
        ~Texture();

        // ways of loading texture into SDL_Texture
        void loadFile(Renderer &ren, std::string &fpath);
        void loadText(std::string &text);

        // clean up texture
        void free();

};

}

#endif
