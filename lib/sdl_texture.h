#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include <SDL2/SDL.h>
#include "sdl_renderer.h"
#include "sdl_window.h"

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

        // rendering function
        void render(Renderer &ren, int x=0, int y=0, SDL_Rect* clip=NULL);
        // fit image size to size of window
        void fitWindow(Window &win);

        // clean up texture
        void free();

        // var indicating window to fit image to
        Window* fit_window;

};

}

#endif
