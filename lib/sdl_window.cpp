#include <iostream>

#include "sdl_window.h"
#include "sdl_exceptions.h"

namespace SDLwrap{

Window::Window(const std::string &title, int x, int y, int w, int h, Uint32 flags){

    // initalise SDL Window object and test for NULL
    win_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
    if(win_==NULL){
        throw Exception("Window::Window()");
    }
    std::cout << "SDL Window initalisation successful." << std::endl;

}

Window::~Window(){
    if(win_!=NULL){
        SDL_DestroyWindow(win_);
    }
    std::cout << "SDL Window destroyed successfully." << std::endl;
}

SDL_Window* Window::get_window(){
    return win_;
}

}
