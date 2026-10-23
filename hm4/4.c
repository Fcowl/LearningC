#include <stdio.h>
#include <math.h>

int main(void) {
    printf("вариант №%d \n",((111260324 + 0+19) % 30)+1); //4

    int limit; // n
    printf("Введите лимит для вычисления суммы степеней: ");
    scanf("%d",&limit);
    double total=0;
    int counter=0;

    while (counter<limit) {
        counter++;
        total += pow(counter,counter);
    }
    printf("%.0f",total);
    return 0;
}