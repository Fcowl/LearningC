#include <stdio.h>

#define MULTIPLYER 1000
int main(void) {
    printf("вариант №%d \n",(111260324 % 30)+1); // 15

    int volume;
    printf("Введите объем в мл для конвертации: ");
    while (scanf("%d", &volume) == 1 && volume>=1) {
        printf("Объем мл: %d, л: %d.%d \n",
            volume,volume/MULTIPLYER,volume%MULTIPLYER);
    }
    return 0;
}