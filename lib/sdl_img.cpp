#include <iostream>

#include "sdl_img.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

SDL_IMG::SDL_IMG(int flags){
    int init = IMG_Init(flags);
    if((init&flags) == flags){
        throw Exception("SDL_IMG::SDL_IMG()");
    }
    std::cout << "SDL_IMG initalisation successful." << std::endl;
}

SDL_IMG::~SDL_IMG(){
    IMG_Quit();
    std::cout << "SDL_IMG environment cleaned up successfully." << std::endl;
}

}
