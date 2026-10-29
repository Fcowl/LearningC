#include <stdio.h>
#include <math.h>

int main(void) {
    // вариант 15
    int iteration = 1;

    for (float x = -3.0; x <= 3.0; x++) {
        printf("n %d: x: %.4f y: %.4f \n",iteration, x, pow(x,2)-4);
        iteration++;
    }
    return 0;
}