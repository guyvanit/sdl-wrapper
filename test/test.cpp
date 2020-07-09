#include <iostream>

#include "SDLwrap/SDL_WRAP.h"
#include "test.h"

int main(){ try{

        // initalise SDL env
        SDLwrap::SDL sdl = SDLwrap::SDL();

        //initalise SDL_IMG
        SDLwrap::SDL_IMG sdl_img = SDLwrap::SDL_IMG();

        // initalise window wrapper object
        SDLwrap::Window win = SDLwrap::Window();

        // initalise renderer wrapper object
        SDLwrap::Renderer ren = SDLwrap::Renderer(win);

        // initalise surface wrapper
        SDLwrap::Surface surf = SDLwrap::Surface();
        surf.loadFile("test_img.jpg");
        std::cout << surf.get_surface() << std::endl;

    }catch(SDLwrap::Exception &e){

        std::cout << "SDL Error occured from: " << e.get_fnc() << std::endl;
        std::cout << "SDL Error: " << e.get_err() << std::endl;

    }

}
