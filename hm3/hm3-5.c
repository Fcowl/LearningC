#include <ctype.h>
#include <stdio.h>

int main(void) {
    char ch;
    scanf("%c", &ch);

    printf("dec: %d \n", ch);
    printf("hex: %x \n", ch);
    printf("oct: %o \n", ch);
    printf("upper: %c \n",toupper(ch));
    printf("next: %c \n",ch+1);
    printf("prev: %c \n",ch-1);
    return 0;
}