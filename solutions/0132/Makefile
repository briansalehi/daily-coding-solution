CC := g++
CPPFLAGS := -Wall -Wextra -pedantic -g3 -Og -std=c++20 -I.
LDFLAGS := -lgtest

.PHONY: all default clean

all default: test

clean:
	rm -f *.o test tags

tags:
	ctags *.cpp *.hpp

test: test.o

test.o: hitcounter.hpp
