#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

typedef struct {
    char option_name[12];
    char status[4]; //ON or OFF
} Setting;

int settings_app(){
    bool running = true;
    int choice = 0;

    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        if(k == 'w' || k == 'W')
            if(choice > 0) choice--;
        
        if(k == 's' || k == 'S')
            if(choice < 3) choice++;

        render_settings_app(choice);

        usleep(50000);
    }

    return 0;
}

void render_settings_app(int choice){
    app_init();

    printf("--- SETTINGS ---\n");
    
    switch(choice){
        case 1:
            printf("SOUND          [ON]\n");
            break;
        case 2:
            printf("AIRPLANE MODE  [OFF]\n");
            break;
        case 3:
            printf("EverestOS v.0.0.1 Pre-Alpha\n");
            printf("All rights reserved\n");
            break;
        default:
            printf("Invalid selection\n");
    }
    fflush(stdout);
}