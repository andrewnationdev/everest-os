#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/calculator.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

int calc_app(){
    bool running = true;
    
    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render_calc();

        usleep(50000);
    }

    return 0;
}

void render_calc(){
    app_init();
    printf("--- CALCULATOR ---\n");
    //...code goes here
    fflush(stdout);
}