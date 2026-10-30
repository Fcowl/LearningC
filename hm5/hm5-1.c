#include <stdio.h>

long double power(long long base, int exp) {
    long double res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

int main(void) {
    // вариант 15
    int iteration = 1;

    for (float x = -3.0; x <= 3.0; x++) {
        printf("n %d: x: %.4f y: %.4f \n",iteration, x, power(x,2)-4);
        iteration++;
    }
    return 0;
}