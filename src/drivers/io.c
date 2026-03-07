#include <stdio.h>
#include "../include/io.h"
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

static KeyBuffer input_buffer;

int _kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void io_init() {
    input_buffer.head = 0;
    input_buffer.tail = 0;
    input_buffer.count = 0;
}

void io_update() {
    if(_kbhit()){
        char key = getch();

        if(input_buffer.count < BUFFER_SIZE) {
            input_buffer.data[input_buffer.tail] = key;
            input_buffer.tail = (input_buffer.tail + 1) % BUFFER_SIZE;
            input_buffer.count++;
        }
    }
}

char io_get_keypress() {
    if(input_buffer.count == 0) {
        return '\0';
    }

    char key = input_buffer.data[input_buffer.head];
    input_buffer.head = (input_buffer.head + 1) % BUFFER_SIZE;
    input_buffer.count--;

    return key;
}

int getch(){
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}