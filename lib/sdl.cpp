#include <iostream>

#include "sdl.h"
#include "sdl_exceptions.h"

/*
    Example initialisation by:

    #include "sdl.h"
    #include "sdl_exceptions.h"

    try{

        SDLwrap::SDL sdl = SDLwrap::SDL();
        // do some SDL stuff

    }catch(SDLwrap::Exception e){

        std::cout << "Error occured from " << e.get_fnc() << std::endl;
        std::cout << "SDL Error: " <, e.get_err() << std::endl;

    }

*/

namespace SDLwrap{

SDL::SDL(Uint32 flags){
    if(SDL_Init(flags)){
        throw Exception("SDL::SDL()");
    }
    std::cout << "SDL environment initialsed." << std::endl;
}

SDL::~SDL(){
    SDL_Quit();
    std::cout << "SDL environment cleaned up." << std::endl;
}

}
