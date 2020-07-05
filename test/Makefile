CXX = g++-9

# --- this makefile is used for constructing test file exectuable only ---
# OUTDIR -> directory containing the dylib file for testing

all: test

# ------------ TESTING FILES ------------

# OUTDIR = /Users/guy/Documents/CODES\ TIME/C++/dylib/lib
OUTDIR = ..

# link all the other object files to construct the executable
test: test.o $(OUTDIR)/libsdl_wrap.dylib
# 	$(CXX) -o test -L$(OUTDIR) -lsdl_wrap test.o
	$(CXX) -o test  test.o $(OUTDIR)/libsdl_wrap.dylib

# create object file for our main test file -> contains main()
test.o: test.cpp test.h
	$(CXX) -std=c++17 -Wall -c -o test.o test.cpp

# --- cleaning commands ---

clean: clean_obj clean_exe

clean_exe:
	rm test

clean_obj:
	rm *.o
