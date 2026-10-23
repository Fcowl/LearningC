#include <stdio.h>

int main(void) {
    printf("вариант №%d \n",((111260324 + 0+13) % 30)+1); //28

    double counter = 0;
    int repeats;
    printf("Введите значение для вычисления последовательности: ");
    scanf("%d",&repeats);
    while (counter<repeats) {
        printf("%.0f ",++counter*1024);
        // i++ сначала считает, потом увеличивает
        // ++i сначала увеличивает потом считает
    }
    
    return 0;
}