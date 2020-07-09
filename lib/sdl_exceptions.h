#ifndef SDL_EXS_H
#define SDL_EXS_H

#include <string>
#include <stdexcept>

namespace SDLwrap{

class Exception : public std::runtime_error {

    // stores error message from SDL_Error()
    std::string sdl_err_;
    // stores which function causes the exception to be thrown
    std::string fnc_;

    std::string make_msg(std::string fnc, std::string err);

    public:
        // constructor + (default) destructor?
        Exception(std::string f);

        // getters -> would storing as char[] use less memory/better?
        std::string get_err();
        std::string get_fnc();

};

}

#endif
