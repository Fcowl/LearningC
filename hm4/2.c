#include <stdint.h>
#include <stdio.h>

int main(void) {
    printf("вариант №%d \n",((111260324 + 0+7) % 30)+1); // 22

    uint16_t w;
    uint16_t h;
    scanf("%hu %hu", &w, &h);

    printf("%llu \n", (unsigned long long)(2 * (w + h)));
    printf("%zu %zu",sizeof(uint16_t),sizeof(unsigned long long));
    return 0;
}