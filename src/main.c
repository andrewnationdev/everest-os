#include <stdio.h>
#include <unistd.h>
#include "../include/os_kernel.h"

int main() {
    printf("\033[2J");

    //Takes care of booting
    boot();
    sleep(5);
    watch();

    return 0;
}
