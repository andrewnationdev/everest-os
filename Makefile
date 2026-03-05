CC = gcc
CFLAGS = -I./include
SRC = src/main.c src/core/os_kernel.c src/apps/main_menu.c src/apps/dialer.c src/drivers/io.c src/drivers/display.c
OBJ = $(SRC:.c=.o)
TARGET = everest

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(SRC:.c=.o) $(TARGET)
