#include <stdio.h>

#define CPU_INFO_SIZE 8
#define MEM_SIZE 256

int main(void) {
    int cpu_state[CPU_INFO_SIZE] = {0};
    int memory[MEM_SIZE] = {0};

    FILE *f = fopen("program_test.txt", "r");
    if (f == NULL) {
        perror("Не удалось открыть файл");
        return -1;
    }

    int i = 0;
    while (i < MEM_SIZE && fscanf(f, "%d", &memory[i]) == 1)
        i++;

    fclose(f);

    // Инициализация по принципам фон Неймана
    cpu_state[0] = 1;         // PC указывает на первую команду
    memory[0] = 12;           // Пример адреса обработчика прерываний в memory[0] (если в файле не задан)
    cpu_state[3] = memory[0]; // Вектор прерываний
    
    while (cpu_state[4] == 0) {
        int pc = cpu_state[0];

        // 1. Проверка выхода PC за границы памяти
        if (pc < 0 || pc >= MEM_SIZE) {
            cpu_state[5] = 1;         // Код ошибки
            cpu_state[0] = cpu_state[3]; // Переход на обработчик прерываний
            continue;
        }

        int opcode = memory[pc];
        int operand_val = (pc + 1 < MEM_SIZE) ? memory[pc + 1] : 0;
        
        cpu_state[2] = opcode; // Сохраняем опкод в регистр команд (IR)

        // 2. Проверка выхода адреса операнда за границы памяти (для команд, которым нужен операнд)
        if (opcode >= 1 && opcode <= 3) {
            if (operand_val < 0 || operand_val >= MEM_SIZE) {
                cpu_state[5] = 2;
                cpu_state[0] = cpu_state[3];
                continue;
            }
        }

        // 3. Декодирование и выполнение команд
        switch (opcode) {
            case 1: // LOAD: загрузить в аккумулятор значение из памяти по адресу operand_val
                cpu_state[1] = memory[operand_val];
                cpu_state[0] += 2;
                break;

            case 2: // ADD: прибавить к аккумулятору
                cpu_state[1] += memory[operand_val];
                cpu_state[0] += 2;
                break;

            case 3: // SUB: вычесть из аккумулятора
                cpu_state[1] -= memory[operand_val];
                cpu_state[0] += 2;
                break;

            case 4: // JUMP: безусловный переход на адрес opcode (в вашей логике opcode хранит целевой адрес)
                cpu_state[0] = operand_val; // или operand_val в зависимости от того, как у вас устроен формат файла для JUMP
                break;
            
            case 5: // JUMP IF ZERO: если аккумулятор == 0, прыжок
                if (cpu_state[1] == 0) {
                    cpu_state[0] = operand_val; 
                } else {
                    cpu_state[0] += 2;
                }
                break;
                
            case 0: // HALT: остановка
                cpu_state[4] = 1;
                break;

            default:
                printf("unknown opcode: %d\n", opcode);
                cpu_state[5] = 3;
                cpu_state[0] = cpu_state[3];
                continue;
        }

        // Безопасный вывод (проверяем, что operand_val в пределах памяти перед обращением к memory[])
        int val_to_print = (operand_val >= 0 && operand_val < MEM_SIZE) ? memory[operand_val] : -1;
        printf("[PC=%03d] command: %d | operand_val: %d (value: %d) | ACC: %d\n",
               pc, opcode, operand_val, val_to_print, cpu_state[1]);
    }

    printf("result (ACC): %d\n", cpu_state[1]);
    return 0;
}