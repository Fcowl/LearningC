#include <stdio.h>

#define MULTIPLYER 1000
int main(void) {
    printf("вариант №%d \n",(111260324 % 30)+1); // 15

    int volume;
    scanf("%d",&volume);
    while (volume>=1) {
        printf("Объем мл: %d, л: %d.%d \n",volume,volume/MULTIPLYER,volume%MULTIPLYER);
        scanf("%d",&volume);
    }
    
    return 0;
}