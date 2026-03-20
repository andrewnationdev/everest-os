#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

#define NAME_LEN 20
#define PHONE_NUM_LEN 20
#define CONTACTS_MAX_LEN 200

typedef struct {
    char name[NAME_LEN];
    char phone_number[PHONE_NUM_LEN];
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

    Contact contacts[CONTACTS_MAX_LEN];

    //I will consider we have 2 contacts for now
    int length = 2;

    printf("--- CONTACTS---\n");

    /*I will save contacts manually for now, but we will soon
    retrieve them from storage*/

    strcpy(contacts[0].name,"Juliano K");
    strcpy(contacts[0].phone_number,"5542987654321");
    
    strcpy(contacts[1].name, "Adriano F");
    strcpy(contacts[1].phone_number, "9123456123");

    if(length == 0) printf("No contacts found");
    else {
        for(int c = 0; c < length; c++){
            printf("%s\n%s\n", contacts[c].name, contacts[c].phone_number );
            printf("-------------\n");
        }
    }
    fflush(stdout);
}