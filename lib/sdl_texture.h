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

    // used for switching between intial rendering
    // bool init_render_;

    // function for resetting class variables
    void reset_var();

    public:
        Texture();
        ~Texture();

        // ways of loading texture into SDL_Texture
        void loadFile(Renderer &ren, std::string &fpath);
        void loadText(std::string &text);

        // rendering function
        void render(Renderer &ren, int x=0, int y=0, SDL_Rect* clip=NULL);

        // clean up texture
        void free();

        // getters of vars
        int get_width();
        int get_height();

        // ------------ VARIABLES ------------

        // var indicating window to fit image with
        Window* fit_window;

        // -- flags --

        // bool indc. the rendering to be at the center of window
        bool FLAG_RENDER_CENTER;
        // indc. image to be scaled automatically to fit to window
        bool FLAG_SCALE_IMG;

};

}

#endif
