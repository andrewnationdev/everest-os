#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"

#define MSG_ARRAY_MAX_LEN 200

bool running = true;

typedef struct {
    char name[20];
    char message[181];
    char date[11]; //DD/MM/YYYY
    char time[9]; //HH:MM:SS
    char status[12];
} Message;

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

    Message messages[MSG_ARRAY_MAX_LEN];

    int length = 1;

    strcpy(messages[0].name,"Steve Jobs");
    strcpy(messages[0].date, "2026/03/19");
    strcpy(messages[0].message, "Please call me back whenever u r free");
    strcpy(messages[0].status, "Missed");
    strcpy(messages[0].time, "11:43:22");

    if(length == 0) printf("You haven't received any messages\n");
    else {
        for(int c = 0; c < length; c++){
            printf("%s\n%s\n(%s-%s)\n%s\n", 
                messages[c].name, 
                messages[c].message, 
                messages[c].date, 
                messages[c].time,
                messages[c].status
            );
            printf("-------------\n");
        }
    }

    fflush(stdout);
}