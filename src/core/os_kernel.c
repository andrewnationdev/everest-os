#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include "../../include/os_kernel.h"
#include "../../include/display.h"
#include "../../include/io.h"
#include "../../include/main_menu.h"
#include "../../include/messages.h"
#include "../../include/calculator.h"
#include "../../include/calls.h"
#include "../../include/contacts.h"
#include "../../include/settings.h"
#include "../../include/logs.h"

char curr_app[12] = "";
int app_return_val = 1;

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
                continue;
            }

            if (k == 'c'){
                strncpy(curr_app, "calc", sizeof(curr_app) - 1);
                curr_app[sizeof(curr_app) - 1] = '\0';
                continue;
            }
                
            if (k == 'm'){
                strncpy(curr_app, "msg", sizeof(curr_app) - 1);
                curr_app[sizeof(curr_app) - 1] = '\0';
                continue;
            }

            if (k == 'r'){
                strncpy(curr_app, "callsreg", sizeof(curr_app) - 1);
                curr_app[sizeof(curr_app) - 1] = '\0';
                continue;
            }

            if (k == 'k'){
                strncpy(curr_app, "contacts", sizeof(curr_app) - 1);
                curr_app[sizeof(curr_app) - 1] = '\0';
                continue;
            }

            if (k == 's'){
                strncpy(curr_app, "settings", sizeof(curr_app) - 1);
                curr_app[sizeof(curr_app) - 1] = '\0';
                continue;
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

        if(strcmp(curr_app, "msg") == 0){
            messages_app();
        }

        if(strcmp(curr_app, "calc") == 0){
            calc_app();
        }

        if(strcmp(curr_app, "callsreg") == 0){
            calls_register_app();
        }

        if(strcmp(curr_app, "settings") == 0){
            settings_app();
        }

        if(strcmp(curr_app, "contacts") == 0){
            contacts_app();
        }

        strncpy(curr_app, "menu", sizeof(curr_app) - 1);
        curr_app[sizeof(curr_app) - 1] = '\0';

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