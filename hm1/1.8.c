#include <stdio.h>

void pulse(void) {
    printf("@");
}
int main(void) {
    pulse();
    printf("\n");
    pulse();
    pulse();
    printf("\n");
    pulse();
    pulse();
    pulse();
    printf("\n");
    return 0;
}