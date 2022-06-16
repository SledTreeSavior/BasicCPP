LFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CFLAGS = -Wall -Werror -ansi -pedantic -std=c++17
CC = g++
EXE = NBody

all: NBody

NBody: NBody.o Universe.o main.o
	$(CC) NBody.o Universe.o main.o -o NBody $(LFLAGS)

main.o: main.cpp NBody.hpp Universe.hpp
	$(CC) -c main.cpp NBody.cpp Universe.cpp $(CFLAGS)

NBody.o: NBody.cpp NBody.hpp
	$(CC) -c NBody.cpp $(CFLAGS)

Universe.o: Universe.cpp Universe.hpp
	$(CC) -c Universe.cpp $(CFLAGS)

clean:
	\rm *.o NBody
