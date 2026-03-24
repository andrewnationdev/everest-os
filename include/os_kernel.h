#ifndef OS_KERNEL_H
#define OS_KERNEL_H

#include <stdbool.h>

void boot();

void watch();

void app_init();

void initialize_apps();

bool is_celldata_available();

int getBatteryLevel();

#endif
