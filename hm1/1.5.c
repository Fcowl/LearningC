#include <stdio.h>
#include <math.h>

int main(void) {
    const int reactor_core = 12;
    printf("[%d, ",reactor_core);
    printf("%d, ",reactor_core*2);
    printf("%d]\n",(int)pow(reactor_core,2));
    return 0;
}
