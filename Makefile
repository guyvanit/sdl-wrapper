CXX = g++-9

INDIR = lib
BINDIR = bin

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks -fPIC
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

# --- this makefile is used to construct the .dylib file ---

all: wrap_lib

# ------------ SHARED LIBRARY CONSTRUCTION ------------

# construct shared library -> uses ".dylib" for MAC OS
# we use "-dynamiclib" instead of "-shared" (for OS X?)
wrap_lib: sdl.o sdl_img.o sdl_ex.o sdl_win.o
	$(CXX) $(LDFLAGS) $(LD2FLAG) -dynamiclib -o libsdl_wrap.dylib $(BINDIR)/*.o

# create object file for SDL initalisation wrapper
sdl.o: $(INDIR)/sdl.cpp $(INDIR)/sdl.h
	$(CXX) $(CXXFLAGS) -c -o $(BINDIR)/sdl.o $(INDIR)/sdl.cpp

# create object file for SDL_IMG initalisation wrapper
sdl_img.o: $(INDIR)/sdl_img.cpp $(INDIR)/sdl_img.h
	$(CXX) $(CXXFLAGS) -c -o $(BINDIR)/sdl_img.o $(INDIR)/sdl_img.cpp

# create object file for SDL exceptions
sdl_ex.o: $(INDIR)/sdl_exceptions.cpp $(INDIR)/sdl_exceptions.h
	$(CXX) $(CXXFLAGS) -c -o $(BINDIR)/sdl_ex.o $(INDIR)/sdl_exceptions.cpp

# create object file for SDL widow wrapper
sdl_win.o: $(INDIR)/sdl_window.cpp $(INDIR)/sdl_window.h
	$(CXX) $(CXXFLAGS) -c -o $(BINDIR)/sdl_win.o $(INDIR)/sdl_window.cpp

# --- moving / setting-up commands ---

setup: lib_copy h_copy

lib_copy: libsdl_wrap.dylib
	cp libsdl_wrap.dylib /usr/local/lib

h_copy:
	mkdir -p /usr/local/include/SDLwrap
	cd lib && cp *.h /usr/local/include/SDLwrap

# --- cleaning commands ---

clean: clean_lib clean_obj

clean_lib:
	rm libsdl_wrap.dylib

clean_obj:
	rm $(BINDIR)/*.o

clean_installed:
	rm /usr/local/lib/libsdl_wrap.dylib
	rm -r /usr/local/include/SDL-wrap
