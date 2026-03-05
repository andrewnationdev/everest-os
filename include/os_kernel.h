#ifndef OS_KERNEL_H
#define OS_KERNEL_H

#include <stdbool.h>

void boot();

void watch();

void app_init();

bool is_celldata_available();

#endif
