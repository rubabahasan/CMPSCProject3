CC=gcc
CFLAGS=-I.
TARGET=simulator.out
DEPS = simulator.h gll.h fileIO.h dataStructures.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): simulator.o gll.o fileIO.o 
	$(CC) -o $(TARGET) simulator.o gll.o fileIO.o

.PHONY: clean

clean:
	rm -f *.o *.out $(TARGET)
