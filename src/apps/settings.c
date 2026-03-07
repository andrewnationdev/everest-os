#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

int settings_app(){
    bool running = true;

    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render_settings_app();

        usleep(50000);
    }

    return 0;
}

void render_settings_app(){
    app_init();
    printf("--- SETTINGS ---\n");
    //...code goes here
    fflush(stdout);
}