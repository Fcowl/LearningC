
#include <stdio.h>

void sort(int *a, int *b, int *c) {
    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
}

int main(void) {
    //21 Отсортировать три переменные по возрастанию
    int x = 12, y = 15, z = 10;

    printf("%d %d %d \n",x, y, z);
    sort(&x,&y,&z);
    printf("%d %d %d \n",x, y, z);

    return 0;
}