#include "../../include/logs.h"
#include <string.h>

void report(char flag[10], char message[180]){
    printf("\n[%s] %s\n", flag, message);
}