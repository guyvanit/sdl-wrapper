#include <iostream>

// NOTE: <SDL2/SDL.h> alrdy included in the wrapper files
#include "../lib/sdl.h"
#include "../lib/sdl_exceptions.h"
#include "../lib/sdl_window.h"

#include "test.h"

int main(){ try{

        // initalise SDL env
        SDLwrap::SDL sdl = SDLwrap::SDL();

        // initalise window wrapper object
        SDLwrap::Window win = SDLwrap::Window();

    }catch(SDLwrap::Exception &e){

        std::cout << "SDL Error occured from: " << e.get_fnc() << std::endl;
        std::cout << "SDL Error: " << e.get_err() << std::endl;

    }

}
