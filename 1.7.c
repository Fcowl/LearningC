#include <stdio.h>

void load_mem(void) {
    printf("MEM_OK");
}

void load_CPU(void) {
    printf("CPU_OK");
}

int main(void) {
    printf("BOOT:");
    load_mem();
    printf("|");
    load_CPU();
    printf(":END");
    return 0;
}