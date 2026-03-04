#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../include/io.h"
#include "../include/os_kernel.h"
#include "../include/display.h"

int main() {
    bool running = true;
    printf("\033[2J");

    //Takes care of booting
    boot();

    sleep(5);

    while(running){
        //Input and output
        io_update();

        char k = io_get_keypress();

        if(k != '\0') {
            if (k == 'q') break;

            printf("\n[EVEREST] You've pressed a key :%c", k);
        }

        //Main user interface
        printf("\033[H");
        draw_top_UI();
        printf("\033[5;1H");
        printf("--- MAIN MENU ---\n");
        printf("1. Messages\n");
        printf("2. Contacts\n");
        printf("0. Power Off\n");
        usleep(100000);
    }

    return 0;
}
