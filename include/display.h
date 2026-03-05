#ifndef DISPLAY_H
#define DISPLAY_H

#define CLR_SCREEN "\033[2J"
#define RESET    "\033[0m"
#define BG_BLUE  "\033[44m"
#define FG_WHITE "\033[37m"
#define HOME     "\033[H"

void draw_top_UI();

void init_graphics();

void reset();

#endif
