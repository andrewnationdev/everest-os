#include <stdio.h>
#include <time.h>
#include "../../include/display.h"
#include "../../include/logs.h"
#include "../../include/os_kernel.h"

void draw_top_UI() {
    time_t rawtime;
    struct tm *info;
    char buffer[10];
    time(&rawtime);
    info = localtime(&rawtime);
    strftime(buffer, 10, "%H:%M", info);

    printf("\033[H\033[7m"); 
    printf(" [%d\%] NO SERVICE       %s ", getBatteryLevel() , buffer);
    printf("\033[0m\n");
}

void init_graphics(){
    reset();
    report("START", "Initializing Graphics");
    printf("%s%s%s", BG_BLUE, FG_WHITE, CLR_SCREEN);
    report("OK", "Initializing Graphics");
}

void reset(){
    printf("\033[H\033[J");
}