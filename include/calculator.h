#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdbool.h>

int calc_app();

void render_calc_ui();

void perform_calculation();

void push_char(char* str, char c, int max);

void pop_char(char* str);

#endif