#include <stdio.h>

int main(void) {
    // 21 (1/ГБ до 10ГБ, 0.8/ГБ от 10 до 60ГБ, 0.5/ГБ свыше)
    double num;
    if (scanf("%lf",&num) != 1) return -1;

    if (num <= 10) {
        printf("1 %.4f",1/num);
    } else if (num >= 10 && num <= 60) {
        printf("2 %.4f",0.8/num);
    } else if (num > 60) {
        printf("3 %.4f",0.5/num);
    }

    return 0;
}