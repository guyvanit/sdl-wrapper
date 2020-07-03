#include "test.h"

// NOTE: <SDL2/SDL.h> alrdy included in the wrapper files
#include "../lib/sdl.h"
#include "../lib/sdl_window.h"

int main(){

    // initalise SDL env
    SDLwrap::SDL sdl = SDLwrap::SDL();

    // initalise window wrapper object
    SDLwrap::Window win = SDLwrap::Window();

}
