CC = gcc
CFLAGS = -I./include
SRC = src/main.c src/core/os_kernel.c src/core/logs.c src/drivers/storage.c src/apps/contacts.c src/apps/settings.c src/apps/calls.c src/apps/calculator.c src/apps/messages.c src/apps/main_menu.c src/apps/dialer.c src/drivers/io.c src/drivers/display.c
OBJ = $(SRC:.c=.o)
TARGET = everest

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(SRC:.c=.o) $(TARGET)