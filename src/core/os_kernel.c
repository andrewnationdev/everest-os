#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "../../include/os_kernel.h"
#include "../../include/display.h"
#include "../../include/io.h"
#include "../../include/main_menu.h"

char curr_app[12] = "";

void boot()
{
    printf("EVEREST PHONE\n");
    init_graphics();
    io_init();
    strncpy(curr_app, "menu", sizeof(curr_app) - 1);
    curr_app[sizeof(curr_app) - 1] = '\0';
}

void watch()
{
    bool running = true;

    while (running)
    {
        // Input and output
        io_update();

        char k = io_get_keypress();

        if (k != '\0')
        {
            if (k == 'q')
                break;

            if (k == 'd'){
                strncpy(curr_app, "dialer", sizeof(curr_app) - 1);
                curr_app[sizeof(curr_app) - 1] = '\0';
            }
                

            printf("\n[EVEREST] You've pressed a key :%c", k);
        }

        //Apps

        if(strcmp(curr_app, "menu") == 0){
            display_menu();
        }

        if(strcmp(curr_app, "dialer") == 0){
            dialer_app();
        }

        usleep(100000);
    }
}

void app_init(){
    reset();
    printf("\033[5;1H");
    draw_top_UI();
}

bool is_celldata_available(){
    return false;
}