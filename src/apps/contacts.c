#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

typedef struct {
    char name[20];
    char phone_number[20];
} Contact;

int contacts_app(){
    bool running = true;

    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render_contacts_app();

        usleep(50000);
    }

    return 0;
}

void render_contacts_app(){
    app_init();
    printf("--- CONTACTS---\n");
    printf("No contacts found");
    //...code goes here
    fflush(stdout);
}