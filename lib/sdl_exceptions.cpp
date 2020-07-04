#include <SDL2/SDL.h>
#include "sdl_exceptions.h"

namespace SDLwrap{

std::string Exception::make_msg(std:: string fnc, std::string err){
    return "SDL Error at " + fnc + " : " + err;
}

Exception::Exception(std::string f)
    : std::runtime_error(make_msg(f, SDL_GetError())){
    fnc_ = f;
    sdl_err_ = SDL_GetError();
}

std::string Exception::get_err(){
    return sdl_err_;
}

std::string Exception::get_fnc(){
    return fnc_;
}

}
