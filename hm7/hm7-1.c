#include <stdio.h>


bool isdigit_my(char ch) {
    return (ch >= '0') && (ch <= '9')? true:false;
}

int main(void) {
    // 15  Заменить все цифры на символ '?'
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isdigit_my(ch))
            putchar('?');
        else
            putchar(ch);
    }
    return 0;
}