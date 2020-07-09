#ifndef SDL_TEXTURE_H
#define SDL_TEXTURE_H

#include <SDL2/SDL.h>

namespace SDLwrap{

    class Texture{

        SDL_Texture* tex_;

        public:
            Texture();
            ~Texture();

            // ways of loading texture into SDL_Texture
            void loadFile(std::string fpath);
            void loadText(std::string text);

            // clean up texture
            void free();

    };

}

#endif
