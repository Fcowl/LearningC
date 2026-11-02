#include <stdio.h>

int abs(int number) {
    return number < 0 ? -number : number;
}

bool tens_l_digit(int number) {
    return number / 10 % 10 > number % 10;
}

int main(void) {
    // 15 (Числа, где цифра десятков больше цифры единиц / Наоборот)

    int number;
    int tens_bigger = 0, digits_bigger = 0;
    while (scanf("%d", &number) == 1) {

        if (number == 0) break;

        if (tens_l_digit(abs(number))) tens_bigger++;
        else digits_bigger++;
    }
    printf("Количество чисел, где цифра десятков больше цифры единиц: %d\n", tens_bigger);
    printf("Количество чисел, где цифра единиц больше цифры десятков: %d\n", digits_bigger);
    return 0;
}
