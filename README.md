# everest-os
A simulation of an embedded operating system designed for a fictional feature phone

```bash
make && ./everest
```

Keys:

```
Press the key shown in the menu to open the app
Press `b` to go back to menu from within an app
```
# Apps Structure

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