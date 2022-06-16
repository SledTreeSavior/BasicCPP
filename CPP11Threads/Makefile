CC = g++
CFLAGS = -c -g -Og -std=c++11
OBJ = ThreadPCCV.o
DEPS = 
LIBS = -pthread
EXE = a.out

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) $(EXE)
