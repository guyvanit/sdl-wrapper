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

void Window::get_size(int *w, int *h){
    SDL_GetWindowSize(win_, w, h);
}

void Window::set_size(int w, int h){

    // NOTE: do we need to check for w>0 and h>0 ???
    if(w>0 && h>0){
        SDL_SetWindowSize(win_, w, h);
    }

}

// ------------ OPENGL FUNCTIONS ------------

void Window::set_GLContext(){
    GLcont_ = SDL_GL_CreateContext(win_);
    if(GLcont_==NULL){
        throw Exception("Window::getGLContext()");
    }
}

SDL_GLContext Window::get_GLContext(){
    return GLcont_;
}

void Window::updateGL(){
    SDL_GL_SwapWindow(win_);
}

}
