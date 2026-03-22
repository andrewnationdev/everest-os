#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

#define SETTINGS_ITEMS 4

typedef struct {
    char option_name[18];
    char status[4]; //ON or OFF
} Setting;

Setting settings[SETTINGS_ITEMS];

void load_settings(){
    strcpy(settings[0].option_name, "SOUND");
    strcpy(settings[0].status, "ON");
    strcpy(settings[1].option_name, "AIRPLANE MODE");
    strcpy(settings[1].status, "ON");
    strcpy(settings[2].option_name, "CELLULLAR DATA");
    strcpy(settings[2].status, "ON");
    strcpy(settings[3].option_name, "BATTERY SAVE");
    strcpy(settings[3].status, "ON");
}

void toggle_settings(char key[18]){
    for(int i = 0; i < SETTINGS_ITEMS; i++){
        if(settings[i].option_name == key){
            if(strcmp(settings[i].status, "ON") == 0)
                strcpy(settings[i].status, "OFF");
            else if(strcmp(settings[i].status, "OFF") == 0)
                strcpy(settings[i].status, "ON");
        }
    }
}

int settings_app(){
    bool running = true;
    int choice = 0;

    load_settings();

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
            if(choice < 4) choice++;

        if(k == 't' || k == 'T')
            toggle_settings(settings[choice].option_name);

        render_settings_app(choice);

        usleep(50000);
    }

    return 0;
}

void render_settings_app(int choice){
    app_init();

    printf("--- SETTINGS ---\n");
    
    switch(choice){
        case 0:
            printf("%s          [%s]\n", 
                settings[0].option_name, 
                settings[0].status
            );
            break;
        case 1:
            printf("%s  [%s]\n", 
                settings[1].option_name, 
                settings[1].status
            );
            break;
        case 2:
            printf("%s [%s]\n", 
                settings[2].option_name, 
                settings[2].status
            );
            break;
        case 3:
            printf("%s   [%s]\n", 
                settings[3].option_name, 
                settings[3].status
            );
            break;
        case 4:
            printf("EverestOS v.0.0.1 Pre-Alpha\n");
            printf("All rights reserved\n");
            break;
        default:
            printf("Invalid selection\n");
    }
    fflush(stdout);
}