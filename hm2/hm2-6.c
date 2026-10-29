#include <stdio.h>
#include <stdint.h>
#include <math.h>


int main(void) {
    unsigned int tmp;
    uint8_t number;

    scanf("%u",&tmp);
    number = (uint8_t)tmp;

    uint8_t n1 = number+10;
    printf("ADD: %d \n",n1);

    uint8_t n2 = number*2;
    printf("MUL2: %d \n",n2);

    uint8_t n3 = (uint8_t)pow(number,2);
    printf("SQR: %d \n",n3);

    /* результат сворачивается потому что uint8 занимает 8 бит, всего хранится
     * 2**8 == 256 значений, поэтому при переполнении он "отнимает" по 256 до того момента
     * пока число станет меньше 256 */
    return 0;
}
