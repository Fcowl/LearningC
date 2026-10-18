#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

// Структура для хранения результатов
typedef struct {
    int core_id;
    double operations_per_second;
    double time_taken;
} benchmark_result;

// Глобальные переменные для синхронизации
int num_cores = 0;
benchmark_result *results = NULL;

// Функция для бенчмарка одного ядра
void* cpu_benchmark_core(void* arg) {
    int core_id = *(int*)arg;
    clock_t start, end;
    double total_operations = 0;

    // Засекаем время
    start = clock();

    // Выполняем многочисленные операции
    for (int i = 0; i < 100000000; i++) {
        // Простая математическая операция
        double result = sqrt(i) + log(i + 1);
        total_operations += 1;
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    double ops_per_second = total_operations / time_taken;

    // Сохраняем результаты
    results[core_id].core_id = core_id;
    results[core_id].operations_per_second = ops_per_second;
    results[core_id].time_taken = time_taken;

    printf("Ядро %d: %.2f операций/сек\n", core_id, ops_per_second);

    return NULL;
}

// Функция параллельного бенчмарка
void cpu_benchmark_parallel() {
    pthread_t* threads = NULL;
    int* core_ids = NULL;

    printf("Запуск бенчмарка на всех ядрах...\n");

    // Получаем количество ядер
    num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    printf("Обнаружено ядер: %d\n", num_cores);

    // Выделяем память для результатов
    results = (benchmark_result*)malloc(num_cores * sizeof(benchmark_result));

    // Создаем потоки для каждого ядра
    threads = (pthread_t*)malloc(num_cores * sizeof(pthread_t));
    core_ids = (int*)malloc(num_cores * sizeof(int));

    // Создаем потоки
    for (int i = 0; i < num_cores; i++) {
        core_ids[i] = i;
        pthread_create(&threads[i], NULL, cpu_benchmark_core, &core_ids[i]);
    }

    // Ожидаем завершения потоков
    for (int i = 0; i < num_cores; i++) {
        pthread_join(threads[i], NULL);
    }

    // Выводим результаты
    double total_ops = 0;
    printf("\nРезультаты бенчмарка:\n");
    for (int i = 0; i < num_cores; i++) {
        printf("Ядро %d: %.2f операций/сек\n",
               results[i].core_1d, results[i].operations_per_second);
        total_ops += results[i].operations_per_second;
    }

    double avg_ops = total_ops / num_cores;
    printf("\nСредняя производительность: %.2f операций/сек\n", avg_ops);
    printf("Общая производительность: %.2f операций/сек\n", total_ops);

    // Очищаем память
    free(results);
    free(threads);
    free(core_ids);
}

// Функция одиночного бенчмарка
void cpu_benchmark_single() {
    clock_t start, end;
    double total_operations = 0;

    printf("Запуск одиночного бенчмарка...\n");

    // Засекаем время
    start = clock();

    // Выполняем многочисленные операции
    for (int i = 0; i < 100000000; i++) {
        double result = sqrt(i) + log(i + 1);
        total_operations += 1;
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    double ops_per_second = total_operations / time_taken;

    printf("Одиночное ядро: %.2f операций/сек\n", ops_per_second);
}

int main() {
    setlocale(LC_ALL,"");
    printf("Бенчмарк процессора на всех ядрах\n");

    // Параллельный бенчмарк
    cpu_benchmark_parallel();

    // Одиночный бенчмарк
    cpu_benchmark_single();

    return 0;
}
