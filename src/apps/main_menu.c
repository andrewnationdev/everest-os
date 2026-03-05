#include <stdio.h>
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/main_menu.h"

void display_menu() {
    app_init();
    printf("--- MAIN MENU ---\n");
    printf("1. Messages\n");
    printf("2. Contacts\n");
    printf("0. Power Off\n");
    fflush(stdout);
}