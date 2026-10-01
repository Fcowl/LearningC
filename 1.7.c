#include <stdio.h>

void load_mem(void) {
    printf("MEM_OK");
}
void load_CPU(void) {
    printf("CPU_OK");
}
int main(void) {
    printf("BOOT:%s|%s:END",load_mem(),load_CPU());
}