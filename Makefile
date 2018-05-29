# From https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
# Options https://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
# The compiler: g++ for C++ program
CC = gcc
CXX = g++

# compiler flags:
#  -g 		adds debugging information to the executable file
#  -Wall	turns on most, but not all, compiler warnings
#  -Wextra	enables some extra warning flags that are not enabled by -Wall.
#  -lm		include the math library
CFLAGS = -g -Wall -Wextra -std=c99
CXXFLAGS = -g -Wall -Wextra -std=c++11
FILES = ./test

all: $(FILES)

test: test.cpp
	$(CXX) $(CXXFLAGS) -o test test.cpp -lm

clean:
	rm -f $(FILES) *.o *~ 