#include <stdio.h>

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

bool is_prime_caller(int n) {
    return is_prime_rec(n,n-1);
}

int main(void) {
    // 25 проверка на простоту
    for (int i = 1; i < 30 ; i++) {
        printf("%d - %d ",i,is_prime(i));
        printf("%d \n",is_prime_caller(i));
    }
}