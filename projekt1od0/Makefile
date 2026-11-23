CC = gcc
CFLAGS = -std=c90 -Wall -Wextra -pedantic
TARGET = kalkulator
OBJS = main.o matrix.o matrix_io.o

all: $(TARGET)

$(TARGET): $(OBJS)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c matrix.h matrix_io.h
$(CC) $(CFLAGS) -c main.c

matrix.o: matrix.c matrix.h
$(CC) $(CFLAGS) -c matrix.c

matrix_io.o: matrix_io.c matrix_io.h matrix.h
$(CC) $(CFLAGS) -c matrix_io.c

clean:
rm -f $(OBJS) $(TARGET)
