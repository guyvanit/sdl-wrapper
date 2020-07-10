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

    // set window size attributes
    win_width = w;
    win_height = h;

    // std::cout << "SDL Window initalised." << std::endl;

}

Window::~Window(){
    if(win_!=NULL){
        SDL_DestroyWindow(win_);
        // std::cout << "SDL Window destroyed." << std::endl;
    }
}

SDL_Window* Window::get_window(){
    return win_;
}

// ------------ WRAPPED FUNCTIONS ------------

void Window::update_size(){
    SDL_GetWindowSize(win_, &win_width, &win_height);
}

int Window::get_width(){
    return win_width;
}

int Window::get_height(){
    return win_height;
}

void Window::set_size(int w, int h){

    // NOTE: do we need to check for w>0 and h>0 ???
    if(w>0 && h>0){
        SDL_SetWindowSize(win_, w, h);
        win_width = w;
        win_height = h;
    }

}

// ------------------------------------------

}
