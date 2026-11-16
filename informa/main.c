#include <stdio.h>

#define CPU_INFO_SIZE 8
#define  MEM_SIZE 256

int main(void) {

    /*
     * cpu_state[0] - счетчик команд (pc)
     * cpu_state[1] - аккумулятор (acc), хранит текущий результат
     * cpu_state[2] - регистр команд (ir), хранит текущий опкод
     * cpu_state[3] - вектор прерываний (адрес обработчика ошибок)
     * cpu_state[4] - флаг остановки (0 = работает, 1 = остановлен)
     * cpu_state[5] - код последней ошибки (0 = нет ошибки)
     * cpu_state[6] - резерв для будущих расширений
     * cpu_state[7] - резерв для будущих расширений
     */

    int cpu_state[CPU_INFO_SIZE] = {0};
    int memory[MEM_SIZE] = {0};

    FILE *f = fopen("program_test.txt","r");

    if (f == NULL) return -1;

    int i = 0;
    while (i<MEM_SIZE && fscanf(f,"%d",&memory[i]) == 1) // считывание информации с файла в память
        i++;

    fclose(f);

    //printf("%d\n",i);
    //print_arr(memory,MEM_SIZE);
    cpu_state[0] = 1;
    cpu_state[3] = memory[0];
    
    int operand_addr = 0;
    int operand_val = 0;
    while (cpu_state[4] == 0) {
        
        operand_addr = memory[cpu_state[0]];
        operand_val = memory[cpu_state[0]+1];
        if (cpu_state[0] < 0 || cpu_state[0] > 256) {
            // обработка если номер команды out of bounce
            cpu_state[5] = 1;
            cpu_state[0] = cpu_state[3];
            continue;
        }
        
        if (cpu_state[2] != 0 && (operand_addr < 0 || operand_addr >= MEM_SIZE)) {
            // обработка если адрес out of bounce 
            cpu_state[5] = 2;
            cpu_state[0] = cpu_state[3];
            continue;
        }
        
        cpu_state[2] = operand_addr; // opcode = memory[pc]
        

        switch (cpu_state[2]) {
            case 1:
                // загрузить в cpu_state[1] значение из памяти по адресу
                cpu_state[1] = memory[operand_val]; // i wanna die bru
                cpu_state[0]+=2;
                break;

            case 2:
                // прибавить к cpu_state[1] значение из памяти
                cpu_state[1] += memory[operand_val];
                cpu_state[0]+=2;
                break;

            case 3:
                // вычесть от cpu_state[1] значение из памяти
                cpu_state[1] -= memory[operand_val];
                cpu_state[0]+=2;
                break;

            case 4:
                // jump
                cpu_state[0] = operand_addr;
                break;
            
            case 5:
                // jump if zero
                if (cpu_state[0] == 0) {
                    cpu_state[1] = operand_addr;
                } else {
                    cpu_state[1] +=2;
                }
                break;
                
            case 0:
                cpu_state[4] = 1; // остановка
                break;

            default:
                printf("unknown upcode ");
                cpu_state[5] = 3;
                cpu_state[0] = cpu_state[3];
                continue;
        }
        printf("[PC=%03d] command: %d | operand (adress): %d value %d) | ACC: %d\n",
               cpu_state[0],  operand_addr, operand_val, memory[operand_val], cpu_state[1]);
                // pc, opcode, operand_addr, operand_val, cpu_state[1]);
    }

    printf("result: %d",cpu_state[1]);
    return 0;
}
