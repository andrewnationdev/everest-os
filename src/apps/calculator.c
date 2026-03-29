#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/calculator.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

char buffer_a[16];
char buffer_b[16];
int current_field = 0; 
char active_op = ' ';
float calc_result = 0.0f;
bool has_result = false;

void push_char(char* str, char c, int max) {
    int len = strlen(str);
    if (len + 1 < max) {
        str[len] = c;
        str[len + 1] = '\0';
    }
}

void pop_char(char* str) {
    int len = strlen(str);
    if (len > 0) {
        str[len - 1] = '\0';
    }
}

void perform_calculation() {
    float val_a = atof(buffer_a);
    float val_b = atof(buffer_b);

    switch (active_op) {
        case '+': calc_result = val_a + val_b; break;
        case '-': calc_result = val_a - val_b; break;
        case '*': calc_result = val_a * val_b; break;
        case '/': 
            if (val_b != 0) calc_result = val_a / val_b;
            else calc_result = 0; 
            break;
    }
    has_result = true;
}

void render_calc_ui() {
    app_init();
    printf("--- CALCULATOR ---\n\n");
    
    printf("A: %s %s\n", buffer_a, (current_field == 0 ? "<" : ""));
    printf("Op:    %c\n", active_op);
    printf("B: %s %s\n", buffer_b, (current_field == 1 ? "<" : ""));
    
    printf("\n--------------------------\n");
    if (has_result) {
        printf("RESULT: %.2f\n", calc_result);
    } else {
        printf("RESULT: ---\n");
    }
    printf("--------------------------\n");
}

int calc_app() {
    bool running = true;
    strcpy(buffer_a, "");
    strcpy(buffer_b, "");
    current_field = 0;
    active_op = ' ';
    has_result = false;

    while (running) {
        io_update();
        char k = io_get_keypress();

        if (k == 'b' || k == 'B') {
            running = false;
            break;
        }

        if ((k >= '0' && k <= '9') || k == '.') {
            if (current_field == 0) push_char(buffer_a, k, 15);
            else push_char(buffer_b, k, 15);
        }

        if (k == 127 || k == 8) { //Backspace
            if (current_field == 0) pop_char(buffer_a);
            else pop_char(buffer_b);
        }

        if (k == '+' || k == '-' || k == '*' || k == '/') {
            active_op = k;
        }

        if (k == '\n' || k == '\r') { //Enter
            if (current_field == 0) {
                current_field = 1;
            } else {
                perform_calculation();
            }
        }

        if (k == 'c' || k == 'C') {
            strcpy(buffer_a, "");
            strcpy(buffer_b, "");
            current_field = 0;
            active_op = ' ';
            has_result = false;
        }

        render_calc_ui();
        usleep(50000);
        fflush(stdout);
    }

    return 0;
}