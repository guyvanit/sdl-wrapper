#ifndef SDL_IMG_H
#define SDL_IMG_H

#include <SDL2_image/SDL_image.h>

namespace SDLwrap{

class SDL_IMG{

    public:
        SDL_IMG(int flags=IMG_INIT_JPG);
        ~SDL_IMG();

};

}

#endif
