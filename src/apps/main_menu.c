#include <stdio.h>
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/main_menu.h"

void display_menu(char app_title[16]) {
    app_init();
    printf("--- MAIN MENU ---\n");
    printf("\n\n   < %s >", app_title);
    fflush(stdout);
}