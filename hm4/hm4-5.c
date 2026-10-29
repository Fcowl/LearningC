#include <stdio.h>

double hr_to_day(double h) {
    const int h_in_day = 24;
    return h / h_in_day;

}
int main(void) {
    printf("вариант №%d \n",((111260324 + 0+23) % 30)+1); //8

    double value;
    printf("Введите количество часов для конвертации в дни: ");
    while (scanf("%lf", &value) == 1) {
        printf("Результат в днях: %.2f \n",hr_to_day(value));

    }
    return 0;
}