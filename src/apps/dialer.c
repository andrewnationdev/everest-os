#include <stdio.h>
#include <unistd.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"

char phone_number[18];

//TO BE REBUILT FROM SCRATCH WITH THE NEW LOGIC
void dialer_app(){
    reset();
    printf("\033[5;1H");
    draw_top_UI();
    printf("Enter a number: \n");
    scanf("%17s", phone_number);
    dial(phone_number);
    fflush(stdout);
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