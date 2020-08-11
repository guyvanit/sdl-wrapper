#include <iostream>

#include "SDLwrap/SDL_WRAP.h"
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

#include "test.h"

int main(){ try{

        // ------ SDL TEST ------

        SDLwrap::SDL sdl = SDLwrap::SDL();
        sdl.printVer();

        // ------ SDL_IMG TEST ------

        SDLwrap::SDL_IMG sdl_img = SDLwrap::SDL_IMG();

        // ------ WINDOW TEST ------

        SDLwrap::Window win = SDLwrap::Window();
        win.set_GLContext();
        SDL_GLContext cont = win.get_GLContext();
        std::cout << "cont: " << cont << std::endl;
        win.updateGL();

        // ------ RENDERER TEST ------

        SDLwrap::Renderer ren = SDLwrap::Renderer(win);
        ren.setDrawColor();
        ren.clear();
        ren.update();

        // ------ SURFACE TEST ------

        SDLwrap::Surface surf = SDLwrap::Surface();
        std::string fname = "test_img.jpg";
        surf.loadFile(fname);

        // ------ (MORE) SDL TEST ------

        sdl.specGL(3,3,true);
        sdl.setVSync(1);

        // ------ TEXTURE TEST ------

        SDLwrap::Texture tex = SDLwrap::Texture();
        tex.loadFile(ren, fname);

        tex.fit_window = &win;
        tex.render(ren);

    }catch(SDLwrap::Exception &e){

        std::cout << "SDL Error occured from: " << e.get_fnc() << std::endl;
        std::cout << "SDL Error: " << e.get_err() << std::endl;

    }

}
