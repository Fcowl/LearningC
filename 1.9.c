#include <stdio.h>

void phase_2(void) {
    printf("BETA ");
}

void phase_1(void) {
    printf("ALPHA ");
    phase_2();
    printf("GAMMA ");
}

int main(void) {
    printf("START ");
    phase_1();
    printf("END");
    return 0;
}