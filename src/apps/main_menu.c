#include <stdio.h>
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/main_menu.h"

void display_menu() {
    app_init();
    printf("--- MAIN MENU ---\n");
    printf("r. Call History\n");
    printf("d. Dialer\n");
    printf("m. Messages\n");
    printf("c. Calculator\n");
    printf("s. Settings\n");
    printf("k. Contacts\n");
    printf("q. Power Off\n");
    fflush(stdout);
}