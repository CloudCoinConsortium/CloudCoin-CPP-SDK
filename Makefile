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

test: test.cpp bank_keys.o bank_total.o
	$(CXX) $(CXXFLAGS) -o test test.cpp bank_keys.o bank_total.o -lm

bank_keys.o: bank_keys.h bank_keys.cpp
	$(CXX) $(CXXFLAGS) -c bank_keys.cpp

bank_total.o: bank_total.h bank_total.cpp
	$(CXX) $(CXXFLAGS) -c bank_total.cpp

clean:
	rm -f $(FILES) *.o *~ 