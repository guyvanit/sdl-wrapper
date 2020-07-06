# sdl-wrapper
Simple wrapper for SDL resources in C++, for managed initalisation and cleaning up for the resources.
This is mainly for use with sdl-gallery.

## Building dynamic library (for MAC OS)
1. Run "make" in cloned directory -> get libsdl_wrap.dylib in directory
2. Run "setup" -> move libsdl_wrap.dylib to /usr/local/lib and headers to /usr/local/include
3. Link to this library by using options in g++: -L/usr/local/lib -lsdl_wrap -I/usr/local/include

## Dependencies?:
- g++-9
- SDL2.0
- SDL_Img (Optional?)

NOTE: this readme is horrible and details regarding dependencies + install/buiding instructions are
        badly-written without details -> will fix this repo to be better maintained some time later

## TODO:
- Add other wrappers for future use (e.g. SDL_Renderer / SDL_Texture)
- Fix README + Makefile etc. about library instructions
- Cross-platform library building? (e.g. CMake)
