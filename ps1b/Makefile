LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++11
CC = g++
EXE = PhotoMagic

all: PhotoMagic

PhotoMagic: FibLFSR.o PhotoMagic.o
	$(CC) FibLFSR.o PhotoMagic.o -o PhotoMagic $(LFLAGS)

FibLFSR.o: FibLFSR.cpp FibLFSR.hpp
	$(CC) -c FibLFSR.cpp $(CFLAGS)

PhotoMagic.o: PhotoMagic.cpp FibLFSR.hpp
	$(CC) -c  PhotoMagic.cpp FibLFSR.cpp $(CFLAGS)

clean:
	\rm *.o PhotoMagic

