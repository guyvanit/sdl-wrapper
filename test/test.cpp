#include <iostream>

#include "SDLwrap/SDL_WRAP.h"
#include "test.h"

int main(){ try{

        // test SDL env
        SDLwrap::SDL sdl = SDLwrap::SDL();

        //test SDL_IMG
        SDLwrap::SDL_IMG sdl_img = SDLwrap::SDL_IMG();

        // test window wrapper object
        SDLwrap::Window win = SDLwrap::Window();

        // test renderer wrapper object
        SDLwrap::Renderer ren = SDLwrap::Renderer(win);
        ren.setDrawColor();
        ren.clear();
        ren.update();

        // test surface wrapper
        SDLwrap::Surface surf = SDLwrap::Surface();
        std::string fname = "test_img.jpg";
        surf.loadFile(fname);
        // std::cout << surf.get_surface() << std::endl;

        // test texture wrapper
        SDLwrap::Texture tex = SDLwrap::Texture();
        tex.loadFile(ren, fname);

        // test texture rendering
        tex.fit_window = &win;
        std::cout << tex.fit_window << std::endl;
        // std::cout << win.get_width() << " : " << win.get_height() << std::endl;
        tex.render(ren);

    }catch(SDLwrap::Exception &e){

        std::cout << "SDL Error occured from: " << e.get_fnc() << std::endl;
        std::cout << "SDL Error: " << e.get_err() << std::endl;

    }

}
