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
    int n;
    while (scanf("%d",&n) == 1 && n>0) {
        double sum = 0.0;
        for (int i = 0; i<=n;i++) {
            sum+= i/power(2,i);
        }
        printf("sum %f \n",sum);
    }

    return 0;
}