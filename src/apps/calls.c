#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

typedef struct {
    char name[20];
    char phone_number[20];
    char date[10]; //DD/MM/YYYY
    char time[8]; //HH:MM:SS
} CallRegister;

int calls_register_app(){
    bool running = true;

    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render_calls_app();

        usleep(50000);
    }

    return 0;
}

void render_calls_app(){
    app_init();
    printf("--- CALLS REGISTER ---\n");
    printf("You haven't received any calls\n");
    //...code goes here
    fflush(stdout);
}