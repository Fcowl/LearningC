#include <stdio.h>

long long to_binary(unsigned int n) {
    long long binary = 0;
    long long place = 1;

    while (n > 0) {
        binary += (n % 2) * place;
        n /= 2;
        place *= 10;
    }

    return binary;
}

int main(void) {
    // 25 (Конвертер систем счисления: dec→hex, dec→oct, dec→bin, hex→dec, выход)
    while (true) {
        printf("\nВыберите действие:\n"
               "1. dec → hex\n"
               "2. dec → oct\n"
               "3. dec → bin\n"
               "4. hex → dec\n"
               "5. Выход\n");

        char ch;
        if (scanf(" %c", &ch) != 1) return -1;

        if (ch == '5') return 0;
        if (ch < '1' || ch > '4') {
            printf("Неверный выбор\n");
            continue;
        }

        printf("Введите число для конвертации: ");
        unsigned int number;
        if (ch == '4') {
            if (scanf("%x", &number) != 1) return -1;
        } else {
            if (scanf("%d", &number) != 1) return -1;
        }

        switch (ch) {
            case '1':
                printf("%d dec -> hex: %X\n", number, number);
                break;
            case '2':
                printf("%d dec -> oct: %o\n", number, number);
                break;
            case '3':
                printf("%d dec -> bin: %lld", number,to_binary(number));
                break;
            case '4':
                printf("%x hex -> dec: %d\n", number, number);
                break;
            default:
                return 0;
        }
    }
    return 0;
}