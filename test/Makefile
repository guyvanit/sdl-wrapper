CXX = g++-9

CXXFLAGS = -std=c++17 -Wall -F /Library/Frameworks
LDFLAGS = -framework SDL2 -I /Library/Frameworks/SDL2.framework/Headers
LD2FLAG = -framework SDL2_image -I /Library/Frameworks/SDL2_image.framework/Headers

all: test

test: test.o
	$(CXX) $(LDFLAGS) $(LD2FLAG) -o test test.o

test.o: test.cpp test.h
	$(CXX) $(CXXFLAGS) -c -o test.o test.cpp

clean:
	rm test.o test
