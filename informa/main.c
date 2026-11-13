#include <stdio.h>

#define CPU_INFO_SIZE 8
#define  MEM_SIZE 256

void print_arr(int arr[], int size) {
    printf("Массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(void) {
    int cpu_state[CPU_INFO_SIZE] = {0};
    int memory[MEM_SIZE] = {0};

    FILE *f = fopen("program.txt","r");

    if (f == NULL) return -1;

    int i = 0;
    while (i<MEM_SIZE && fscanf(f,"%d",&memory[i]) == 1)
        i++;

    fclose(f);

    printf("%d\n",i);
    print_arr(memory,MEM_SIZE);
    //while (cpu_state[4] == 0)
}
