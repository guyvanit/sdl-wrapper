CXX = g++-9
LIBDIR = ../lib

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: test

# link all the other object files to construct the executable
test: test.o sdl.o sdl_ex.o sdl_win.o sdl_img.o
	$(CXX) $(LDFLAGS) $(LD2FLAG) -o test test.o sdl.o sdl_ex.o sdl_win.o sdl_img.o
# 	rm *.o

# create object file for our main test file -> contains main()
test.o: test.cpp test.h
	$(CXX) $(CXXFLAGS) -c -o test.o test.cpp

# create object file for SDL initalisation wrapper
sdl.o: $(LIBDIR)/sdl.cpp $(LIBDIR)/sdl.h
	$(CXX) $(CXXFLAGS) -c -o sdl.o $(LIBDIR)/sdl.cpp

# create object file for SDL_IMG initalisation wrapper
sdl_img.o: $(LIBDIR)/sdl_img.cpp $(LIBDIR)/sdl_img.h
	$(CXX) $(CXXFLAGS) -c -o sdl_img.o $(LIBDIR)/sdl_img.cpp

# create object file for SDL exceptions
sdl_ex.o: $(LIBDIR)/sdl_exceptions.cpp $(LIBDIR)/sdl_exceptions.h
	$(CXX) $(CXXFLAGS) -c -o sdl_ex.o $(LIBDIR)/sdl_exceptions.cpp

# create object file for SDL widow wrapper
sdl_win.o: $(LIBDIR)/sdl_window.cpp $(LIBDIR)/sdl_window.h
	$(CXX) $(CXXFLAGS) -c -o sdl_win.o $(LIBDIR)/sdl_window.cpp

# --- cleaning commands ---

clean: clean_exe clean_obj

clean_exe:
	rm test

clean_obj:
	rm *.o
