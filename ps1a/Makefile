CC = g++
CFLAGS = -c -g -Og -Wall -Werror -ansi -pedantic
OBJ = FibLFSR.o test.o
EXE = ps1a

all: ps1a

ps1a:    $(OBJ)
	$(CC) $(OBJ) -o $(EXE) -lboost_unit_test_framework

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

FibLFSR.o: FibLFSR.cpp FibLFSR.hpp
	$(CC) $(CFLAGS) FibLFSR.cpp

clean:
	rm $(OBJ) $(EXE)
