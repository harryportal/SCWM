CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = filemanip_app

all: $(TARGET)

$(TARGET): main.o filemanip.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o filemanip.o

main.o: main.c filemanip.h
	$(CC) $(CFLAGS) -c main.c

filemanip.o: filemanip.c filemanip.h
	$(CC) $(CFLAGS) -c filemanip.c

clean:
	rm -f *.o $(TARGET)