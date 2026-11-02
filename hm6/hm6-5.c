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
    int number;
    while (true) {
        printf("\nВыберите действие:\n"
               "1. dec → hex\n"
               "2. dec → oct\n"
               "3. dec → bin\n"
               "4. hex → dec\n"
               "5. Выход\n");
        char ch = getchar();
        printf("Введите число для конвертации: ");
        if (ch != '5' && scanf("%d", &number) != 1) return -1; // отличный пример ленивого вычесления
        switch (ch) {
            case '1':
                printf("%d dec -> hex: %X\n",number, number);
                break;
            case '2':
                printf("%d dec -> oct: %o\n",number, number);
                break;
            case '3':
                printf("%d dec -> bin %lld\n",number, to_binary(number));
                break;
            case '4':
                printf("%x hex→dec: %d\n",number, number);
                break;
            case '5': // Выход
                return 0;
            default:
                printf("Неверный выбор\n");
        }
    }
    return 0;
}