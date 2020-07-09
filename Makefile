CXX = g++-9

INDIR = lib
BINDIR = bin

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks -fPIC
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAGS = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

# --- this makefile is used to construct the .dylib file ---

all: wrap_lib

# ------------ SHARED LIBRARY CONSTRUCTION ------------

# var containing all object files needed to build library
_OBJS = sdl.o sdl_img.o sdl_exceptions.o sdl_window.o sdl_renderer.o sdl_surface.o
OBJS = $(patsubst %,$(BINDIR)/%,$(_OBJS))

# construct shared library -> uses ".dylib" for MAC OS
# we use "-dynamiclib" instead of "-shared" (for OS X?)
wrap_lib: $(OBJS)
	$(CXX) $(LDFLAGS) $(LD2FLAGS) -dynamiclib -o libsdl_wrap.dylib $(BINDIR)/*.o

# construct respective object files
$(BINDIR)/%.o: $(INDIR)/%.cpp $(INDIR)/%.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# --- moving / setting-up commands ---

setup: lib_copy h_copy

lib_copy: libsdl_wrap.dylib
	cp libsdl_wrap.dylib /usr/local/lib

h_copy:
	mkdir -p /usr/local/include/SDLwrap
	cd lib && cp *.h /usr/local/include/SDLwrap

clean_setup:
	rm /usr/local/lib/libsdl_wrap.dylib ; rm -r /usr/local/include/SDLwrap

# --- cleaning commands ---

clean: clean_obj clean_lib

clean_lib:
	rm libsdl_wrap.dylib

clean_obj:
	rm $(BINDIR)/*.o
