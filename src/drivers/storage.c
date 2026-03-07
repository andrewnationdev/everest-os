#include "../../include/storage.h"
#include <stdio.h>

int fswrite(char filename[20], char data[2048]){
    FILE *file = fopen(filename, "ab");

    if(file == NULL){
        return 0;
    }

    fwrite(&data, sizeof(char), 2048, file);
    fclose(file);
}

int fsopen(char filename[20]){
    FILE *file = fopen(filename, "rb");

    char f_data[2048];

    if(file == NULL){
        return 0;
    }

    fread(f_data, 2048, 1, file);
    fclose(file);
    return 1;
}