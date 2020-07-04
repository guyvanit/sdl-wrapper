# sdl-wrapper
Simple wrapper for SDL resources in C++, for better initalisation and cleaning up

## Current WIP:
- Construct shared library for sdl-wrapper
- Test using the library in test.cpp

## Plan/TODO:
0. --- implement SDL_Exception wrapper with runtime_error intheritance ---
1. Set up proper Makefile (and will be tedious but pls keep it up to date)
2. Set up some test files
3. Continue adding on other wrappers:
    - SDL_IMG Initalisation
    - SDL_Renderer
    - SDL_Texture

## EXTRA Plans:
- Turn into shared library (.so/.dylib) file??
- Automated cross-platform library building -> cmake?
