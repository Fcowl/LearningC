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
    return 0;
}