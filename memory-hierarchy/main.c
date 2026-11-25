#include <stdio.h>
#include <string.h>

#define L3 12*1024*1024 // kb
#define L2 7*1024*1024 // kb
#define L1 320*1024 // kb

char memory[65536] = {};
char data[256 * 1024] = {};
char CPU[50];

int convert_to_int(char);
int convert_to_char(int);
void clear();
int get_value();
void print_int(int);
int num_sum(int);
int encode(int);

int main(void) {

    printf("incert cpu name: ");
    if (scanf("%s",CPU) != 1) return -1;
    clear();


    //setbuf(stdin, NULL); //  не работает
    //int num = get_value();
    //int sum = num_sum(num);
    //print_int(sum);

    //print_int(num_sum(get_value()));
    printf("\n");
}

int convert_to_int(char ch) {
    return ch-48;
}
int convert_to_char(int ch) {
    return ch+48;
}

int get_value() {
    int ch;
    int sign = 1;
    int value = 0;
    ch = getchar();

    if (ch == '-') {
        sign = -1;
        ch = getchar();
    }

    while (ch != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
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

int num_sum(int number) {
    int sum = 0;
    for (int i = 0; i <= number; i++) {
        sum += i;
        memory[i % 65536] = i % 256;
        data[i % (256*1024)] = (sum + i) % 256;
    }
    return sum;
}

int int_to_arr(int n) {
    char arr[20];

    for (int i = 0; i < 20; i++) {
        
    }
}


int encode(int num) {
    for (int i = 0; i <= strlen(CPU);i++) {
        putchar((int)CPU[i]);
    }
}