#include <stdio.h>
#include "../../include/os_kernel.h"
#include "../../include/display.h"
#include "../../include/io.h"

void boot() {
    printf("EVEREST PHONE\n");
    init_graphics();
    io_init();
}
