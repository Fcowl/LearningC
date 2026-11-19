#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 256

// Индексы массива cpu_state через макросы (без enum)
#define REG_PC   0
#define REG_ACC  1
#define REG_IR   2
#define REG_IVEC 3
#define REG_HALT 4
#define REG_ERR  5

// Коды операций (опкоды)
#define OP_HALT 0
#define OP_LOAD 1
#define OP_ADD  2
#define OP_SUB  3

int main(void) {
    int cpu_state[8] = {0};
    int memory[MEM_SIZE] = {0};

    // Чтение программы из текстового файла
    FILE *file = fopen("program_test.txt", "r");
    if (!file) {
        perror("Не удалось открыть файл program.txt");
        return 1;
    }

    int addr = 0;
    int value;
    while (fscanf(file, "%d", &value) == 1 && addr < MEM_SIZE) {
        memory[addr++] = value;
    }
    fclose(file);

    // Ячейка memory[0] — вектор прерываний
    cpu_state[REG_IVEC] = memory[0];

    // Старт программы с ячейки 1
    cpu_state[REG_PC] = 1;

    // Главный цикл выполнения
    while (cpu_state[REG_HALT] == 0) {
        int pc = cpu_state[REG_PC];

        // Проверка выхода PC за границы памяти
        if (pc < 0 || pc >= MEM_SIZE) {
            cpu_state[REG_ERR] = 1;
            cpu_state[REG_PC] = cpu_state[REG_IVEC];
            continue;
        }

        int opcode = memory[pc];
        cpu_state[REG_IR] = opcode; // Сохраняем опкод в регистр команд

        // Команда 0 — стоп
        if (opcode == OP_HALT) {
            printf("[PC=%03d] Команда: 0 (СТОП) | ACC: %d\n", pc, cpu_state[REG_ACC]);
            cpu_state[REG_HALT] = 1;
            break;
        }

        // Проверяем, есть ли ячейка для операнда
        if (pc + 1 >= MEM_SIZE) {
            cpu_state[REG_ERR] = 1;
            cpu_state[REG_PC] = cpu_state[REG_IVEC];
            continue;
        }

        int operand_addr = memory[pc + 1];

        // Проверка выхода адреса операнда за границы памяти
        if (operand_addr < 0 || operand_addr >= MEM_SIZE) {
            printf("[PC=%03d] Ошибка: выход за границы по адресу %d\n", pc, operand_addr);
            cpu_state[REG_ERR] = 1;
            cpu_state[REG_PC] = cpu_state[REG_IVEC];
            continue;
        }

        int operand_val = memory[operand_addr];

        // Замена цепочки if-else на switch-case
        switch (opcode) {
            case OP_LOAD:
                cpu_state[REG_ACC] = operand_val;
                cpu_state[REG_PC] += 2;
                break;

            case OP_ADD:
                cpu_state[REG_ACC] += operand_val;
                cpu_state[REG_PC] += 2;
                break;

            case OP_SUB:
                cpu_state[REG_ACC] -= operand_val;
                cpu_state[REG_PC] += 2;
                break;

            default:
                // Неизвестная команда -> прерывание
                printf("[PC=%03d] Ошибка: неизвестный опкод %d\n", pc, opcode);
                cpu_state[REG_ERR] = 2;
                cpu_state[REG_PC] = cpu_state[REG_IVEC];
                continue;
        }

        // Вывод информации о выполненной команде и аккумуляторе
        printf("[PC=%03d] Команда: %d | Операнд (адр): %d (знач: %d) | ACC: %d\n",
               pc, opcode, operand_addr, operand_val, cpu_state[REG_ACC]);
    }

    printf("Выполнение завершено. Итоговый ACC = %d\n", cpu_state[REG_ACC]);
    return 0;
}