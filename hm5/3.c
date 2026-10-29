#include <stdio.h>
#include <math.h>

int main(void) {
    // вариант 15
    int n;
    while (scanf("%d",&n) == 1 && n>0) {
        double sum = 0.0;
        for (int i = 0; i<=n;i++) {
            sum+= i/pow(2,i);
        }
        printf("sum %f \n",sum);
    }

    return 0;
}