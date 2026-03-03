CC = gcc
CFLAGS = -I./include
SRC = src/main.c src/core/os_kernel.c src/drivers/display.c
OBJ = $(SRC:.c=.o)
TARGET = feature_phone

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f $(SRC:.c=.o) $(TARGET)
