#include <stdio.h>

int main(void) {
    const int n1 = 10;
    const int n2 = 010;
    const int n3 = 0x10;

    printf("dec 10: %d \n",n1);
    printf("oct 10: %d \n",n2);
    printf("hex 10: %d \n\n",n3);

    printf("int \n");
    printf("10 10u 10LL 10ULL\n");
    printf("%d  %d   %d    %d \n\n" ,
        (int)sizeof(10),(int)sizeof(10u),(int)sizeof(10LL),(int)sizeof(10ULL));

    printf("float \n");
    printf("0.1f 0.1 0.1L \n");
    printf("%d    %d   %d\n\n",
        (int)sizeof(0.1f),(int)sizeof(0.1),(int)sizeof(0.1L));
    printf("0.1f == 0.1 : %d\n", 0.1f == 0.1);

    char letter = 'A';
    printf("char: %d %d %d \n", letter, '\x41', '\101');
    printf("char_lit_var_str: %d %d %d \n",
        (int)sizeof('A'),(int)sizeof(letter),(int)sizeof("A"));

    return 0;
}