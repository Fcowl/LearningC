#include <stdio.h>
#include <math.h>

double calc(double A, double B) {
    return cbrt(A*pow(B,2));
}

int main(void) {
    // вариант 25
    double a,b;

    while (scanf("%lf %lf", &a, &b) == 2) {
        printf("%.4f \n",calc(a,b));

        // something changed in 5.c
    }
}