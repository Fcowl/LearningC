
#define CPU "210H"

#define L3 12*1024*1024 // kb
#define L2 7*1024*1024 // kb
#define L1 320*1024
#include <stdio.h>

int convert_to_int(char);
void clear();
int get_value();
void print_int(int);

int main(void) {

    char memory[65536] = {};
    char data[256 * 1024] = {};

    setbuf(stdin, NULL); // ниче не рабо
    int num = get_value();
    //printf("%d\n",num);

    int sum = 0;
    for (int i = 0; i <= num; i++) {
        sum += i;
        memory[i % 65536] = i % 256;
        data[i % (256*1024)] = (sum + i) % 256;
    }
    print_int(sum);
    printf("\n");
}

int convert_to_int(char ch) {
    return ch-48;
}

int get_value() {
    char ch;
    int sign = 1;
    int value = 0;
    ch = getchar();

    if (ch == '-') {
        sign = -1;
        ch = getchar();
    }

    while (ch != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9' && ch !=0) {
            value = value * 10 + convert_to_int(ch);
        }
        ch = getchar();
    }
    return sign * value;
}

void clear() {
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
}

void print_int(int num) {
    if (num < 0) {
        putchar('-');
        // Работаем с отрицательными числами напрямую, чтобы не переполнить INT_MIN
        if (num / 10 != 0) {
            print_int(-(num / 10));
        }
        putchar(-(num % 10) + '0');
        return;
    }

    if (num / 10 != 0) {
        print_int(num / 10);
    }
    putchar((num % 10) + '0');
}
