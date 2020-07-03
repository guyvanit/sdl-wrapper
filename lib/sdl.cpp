#include <iostream>

#include "sdl.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

SDL::SDL(Uint32 flags){
    if(SDL_Init(flags)){
        throw Exception("SDL::SDL()");
    }
    std::cout << "SDL initalisation successful." << std::endl;
}

SDL::~SDL(){
    SDL_Quit();
    std::cout << "SDL environment cleaned up successfully." << std::endl;
}

}
