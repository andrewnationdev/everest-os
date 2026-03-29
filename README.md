# everest-os
A simulation of an embedded operating system designed for a fictional feature phone

```bash
make && ./everest
```

Keys:

```
Press `b` to go back to menu from within an app
Press `t` to toggle settings
Press `w` to go up and `s` to go down
Press `q` in the main menu to power off
Press `ENTER` to select items in the main menu
Press `c` for backspace in dialer app
Press `e` to call a number in dialer app
```
# Apps Structure

You can build your own apps by using this structure.

```c
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "../../include/dialer.h"
#include "../../include/display.h"
#include "../../include/os_kernel.h"
#include "../../include/io.h"

int my_app(){
    bool running = true;

    while(running){
        io_update();
        char k = io_get_keypress();

        if(k == 'b' || k == 'B'){
            running = false;
            break;
        }

        render_app();

        usleep(50000);
    }

    return 0;
}

void render_app(){
    app_init();
    printf("--- APP TITLE ---\n");
    //...code goes here
    fflush(stdout);
}
```

# TASKS