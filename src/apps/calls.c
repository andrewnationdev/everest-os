#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

#define CALLS_MAX_LEN 200

typedef struct {
    char name[20];
    char phone_number[20];
    char date[11]; //DD/MM/YYYY
    char time[9]; //HH:MM:SS
    char status[12];
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

    CallRegister calls[CALLS_MAX_LEN];

    int length = 1;

    //To be removed later and loaded from storage

    strcpy(calls[0].name,"Steve Jobs");
    strcpy(calls[0].date, "2026/03/19");
    strcpy(calls[0].phone_number, "+1334212229");
    strcpy(calls[0].status, "Missed");
    strcpy(calls[0].time, "11:43:22");

    if(length == 0) printf("You haven't received any calls\n");
    else {
        for(int c = 0; c < length; c++){
            printf("%s\n%s\n(%s-%s)\n%s\n", 
                calls[c].name, 
                calls[c].phone_number, 
                calls[c].date, 
                calls[c].time,
                calls[c].status
            );
            printf("-------------\n");
        }
    }

    fflush(stdout);
}