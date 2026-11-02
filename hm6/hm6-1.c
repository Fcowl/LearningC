#include <stdio.h>
#include <ctype.h>

int main(void) {
    // 15 (Количество управляющих символов (используя iscntrl)) 111260324
    char ch;
    int cntrl_counter = 0;
    while ((ch=getchar()) != '#') {
        if (iscntrl(ch)) cntrl_counter++;
    }
    printf("Количество управляющих символов: %d\n", cntrl_counter);

    return 0;
}