#ifndef IO_H
#define IO_H

#include <stdbool.h>

#define BUFFER_SIZE 16

typedef struct {
    char data[BUFFER_SIZE];
    int head;
    int tail;
    int count;
} KeyBuffer;

//Initialize INPUT/OUTPUT
void io_init();

//Reads a key without blocking the execution
char io_get_keypress();

//Listen to IO
void io_update();

int _kbhit();

#endif