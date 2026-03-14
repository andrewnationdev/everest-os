#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/calculator.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

int calc_app(){
    bool running = true;
    
    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render_calc();

        usleep(50000);
    }

    return 0;
}

void render_calc(){
    app_init();

    float x, y, result;

    printf("--- CALCULATOR ---\n");
    printf("First number: ");
    scanf("%f", &x);
    printf("Second number: ");
    scanf("%f", &y);

    if(x || x == 0.0){
        if(y || y == 0.0){
            printf("--- Operations ---\n");
            printf("1-Sum\n2-Divide\n3--Multiply\n4-Subtract\n0-Delete\n9-Exit\n> ");

            int op;

            scanf("%d", &op);

            switch(op){
                case 1: //Sum
                    result = x + y;
                    break;
                case 2: //Divide
                    if(y == 0.0) return; //Division by zero
                    result = x / y;
                    break;
                case 3: // Multiply
                    result = x * y;
                    break;
                case 4: //Subtract
                    result = x - y;
                    break;
                case 9:
                    return;
                    break;
                default:
                    x = 0.0;
                    y = 0.0;
                    result = 0.0;
                    break;
            }

            printf("Result: %f\n", result);
        }
    }

    usleep(5000000);

    fflush(stdout);
}