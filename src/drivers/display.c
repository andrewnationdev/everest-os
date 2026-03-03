#include <stdio.h>
#include <time.h>
#include "../../include/display.h"

void draw_top_UI() {
    time_t rawtime;
    struct tm *info;
    char buffer[10];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 10, "%H:%M", info);

    printf("\033[H\033[7m"); 
    printf(" [I] NO SERVICE       %s ", buffer);
    printf("\033[0m\n");
}
