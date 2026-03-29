#include <stdio.h>
#include <unistd.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"

char phone_number[18];

void pop_string(char* str) {
    int len = strlen(str);
    if (len > 0) {
        str[len - 1] = '\0';
    }
}

void push_string(char* str, char c, int max) {
    int len = strlen(str);
    
    if (len + 1 < max) {
        str[len] = c;
        str[len + 1] = '\0';
    }
}

//TO BE REBUILT FROM SCRATCH WITH THE NEW LOGIC
void dialer_app(){
    bool running = true;

    strcpy(phone_number, "");

    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        if(k == 'c' || k == 'C'){
            pop_string(phone_number);
        }

        if(k >= '0' && k <= '9'){
            push_string(phone_number, k, 17);
        }

        if(k == 'e' || k == 'E'){
            dial(phone_number);
        }

        app_init();
        printf("Enter a number: \n");
        printf("%s\n", phone_number);

        usleep(50000);
        fflush(stdout);
    }
}

void dial(char number[]){
    if(!is_celldata_available()){
        printf("Cannot dial this number\nService not found");
        fflush(stdout);
        usleep(1000000);
    } else {
        printf("Dialing...");
        usleep(1000000);
    }

    return;
}