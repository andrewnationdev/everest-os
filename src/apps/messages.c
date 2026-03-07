#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"

bool running = true;

int messages_app(){
    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render();

        usleep(50000);
    }

    return 0;
}

void render(){
    app_init();
    printf("--- MESSAGES ---\n");
    printf("No messages found");
    fflush(stdout);
}