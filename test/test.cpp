#include <iostream>

// NOTE: <SDL2/SDL.h> alrdy included in the wrapper files
#include "../lib/SDL_WRAP.h"

#include "test.h"

int main(){ try{

        // initalise SDL env
        SDLwrap::SDL sdl = SDLwrap::SDL();

        //initalise SDL_IMG
        SDLwrap::SDL_IMG sdl_img = SDLwrap::SDL_IMG();

        // initalise window wrapper object
        SDLwrap::Window win = SDLwrap::Window();

    }catch(SDLwrap::Exception &e){

        std::cout << "SDL Error occured from: " << e.get_fnc() << std::endl;
        std::cout << "SDL Error: " << e.get_err() << std::endl;

    }

}
