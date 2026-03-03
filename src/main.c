#include <stdio.h>
#include <unistd.h>
#include "../include/os_kernel.h"
#include "../include/display.h"

int main() {
    printf("\033[2J"); // Limpa a tela no início
    boot();
    sleep(5);
    draw_top_UI();
    printf("\n\n--- FEATURE PHONE OS ---\n");
    printf("Pressione Enter para sair...\n");
    getchar();
    return 0;
}
