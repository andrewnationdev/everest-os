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
#include "../../include/storage.h"

#define INSTALLED_APPS 6

typedef struct {
    char name[16];
    int index;
} App;

App apps[INSTALLED_APPS];

void initialize_apps(){
    //Dialer
    strcpy(apps[0].name, "Dialer");
    apps[0].index = 0;

    //Calculator
    strcpy(apps[1].name, "Calculator");
    apps[1].index = 1;

    //Contacts
    strcpy(apps[2].name, "Contacts");
    apps[2].index = 2;

    //Messages
    strcpy(apps[3].name, "Messages");
    apps[3].index = 3;

    //Calls Register
    strcpy(apps[4].name, "Calls Register");
    apps[4].index = 0;

    //Settings
    strcpy(apps[5].name, "Settings");
    apps[5].index = 0;
}

void boot()
{
    printf("EVEREST PHONE\n");
    init_graphics();
    io_init();

    initialize_apps();
}

void watch()
{
    bool running = true;
    int choice = 0;

    while (running)
    {
        // Input and output
        io_update();

        char k = io_get_keypress();

        if (k != '\0')
        {
            if (k == 'q')
                break;

            if(k == 'w' || k == 'W')
                if(choice > 0) choice--;
        
            if(k == 's' || k == 'S')
                if(choice < 5) choice++;

            if(k == '\n')
                switch(choice){
                    case 0:
                        dialer_app();
                        break;
                    case 1:
                        calc_app();
                        break;
                    case 2:
                        contacts_app();
                        break;
                    case 3:
                        messages_app();
                        break;
                    case 4:
                        calls_register_app();
                        break;
                    case 5:
                        settings_app();
                        break;
                }

            continue;

           // printf("\n[EVEREST] You've pressed a key :%c", k);
        }

        display_menu(apps[choice].name);

        usleep(100000);
    }
}

void app_init(){
    reset();
    printf("\033[5;1H");
    draw_top_UI();
}

bool is_celldata_available(){
    bool celldata_status = false;
    return celldata_status;
}

int getBatteryLevel(){
    int battery = 100;

    return battery;
}