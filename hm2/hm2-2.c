#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    bool module_ready = n1;
    bool fault_state = n2;
    int bool_size = sizeof(bool);
    int flag_sum = module_ready+fault_state;

    printf("module_ready: %d \n",module_ready);
    printf("fault_state: %d \n",fault_state);
    printf("bool_size: %d \n",bool_size);
    printf("flag_sum: %d \n",flag_sum);
    return 0;
}