LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++14
CC = g++
EXE = tree

all: tree

tree: PTree.o main.o
	$(CC) PTree.o main.o -o tree $(LFLAGS)

main.o: main.cpp PTree.hpp
	$(CC) -c main.cpp PTree.cpp $(CFLAGS)

PTree.o: PTree.cpp PTree.hpp
	$(CC) -c PTree.cpp $(CFLAGS)

clean:
	\rm *.o tree




