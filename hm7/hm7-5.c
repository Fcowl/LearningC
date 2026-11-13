#include <stdio.h>
#include  <time.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int d = 2; n>d; d++) {
        if (n % d == 0)
            return false;
    }
    return true;
}

bool is_prime_rec(int n, int d) {
    if (n < 2) return false;
    if (d == 1) return true;
    if (n % d == 0) return false;
    return is_prime_rec(n,d-1);
}

bool is_prime_rec_caller(int n) {
    return is_prime_rec(n,n-1);
}

int main(void) {
    // 25 проверка на простоту
    for (int i = 1; i <= 30 ; i++) {
        printf("%d - %d %d\n",i,is_prime(i),is_prime_rec_caller(i));
    }

    int n = 10000;
    printf("Отдельные замеры для наглядности n = %d: \n",n);

    clock_t start = clock();
    is_prime(n);
    printf("Время для циклического вычисления: %.7f\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    start = clock();
    is_prime_rec_caller(n);
    printf("Время для рекурсивного вычисления: %.7f \n", (double)(clock() - start) / CLOCKS_PER_SEC);
}