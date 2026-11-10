#include <stdio.h>

long double power(double base, int exp) {
    long double res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}
int main(void) {
    // 15 куб суммы
    double a,b;
    while ((scanf("%lf %lf",&a,&b) == 2))
        printf("%.4Lf\n",power(a+b,3));

    return 0;
}
