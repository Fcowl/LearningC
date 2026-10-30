#include <stdio.h>

long double power(long long base, int exp) {
    long double res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

double cbrt_m(double x) {
    double guess = x / 3.0;
    double l_guess = guess;

    do {
        l_guess = guess;
        guess = (2.0 * guess + x / (guess * guess)) / 3.0;
    } while ((guess > l_guess ? guess - l_guess : l_guess - guess) > 0.0001);

    return guess;
}

double calc(double A, double B) {
    return cbrt_m(A*power(B,2));
}

int main(void) {
    // вариант 25
    double a,b;

    while (scanf("%lf %lf", &a, &b) == 2) {
        printf("%.4f \n",calc(a,b));
    }
}