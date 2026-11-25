#define CPU "210H"

#define L3 12*1024*1024 // kb
#define L2 7*1024*1024 // kb
#define L1 320*1024 // kb

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(__unix__)
#include <termios.h>
#include <unistd.h>
#endif

int convert_to_int(char);
void clear(void);
int get_value(void);
void print_int(int);
int read_char(void);

#if defined(__unix__)
static struct termios old_tio;
static int raw_enabled = 0;

static void restore_terminal(void) {
    if (raw_enabled) {
        tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
    }
}

static void enable_raw_terminal(void) {
    struct termios t;

    if (tcgetattr(STDIN_FILENO, &old_tio) != 0) {
        return;
    }

    t = old_tio;
    t.c_lflag &= ~(ICANON | ECHO);
    t.c_cc[VMIN] = 1;
    t.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &t) == 0) {
        raw_enabled = 1;
        atexit(restore_terminal);
    }
}
#endif

/*
 * Без аргументов: буферизованный ввод (setvbuf с _IOLBF) и обычный
 * cooked-терминал — считанные символы видны только после Enter.
 *
 * С флагом -b: -b означает "без буфера" -> setbuf(stdin, NULL) плюс
 * termios без ICANON/ECHO — программа читает и печатает каждый символ
 * сразу, Enter нужен только чтобы закончить ввод числа.
 */
int main(int argc, char **argv) {
    char memory[65536] = {};
    char data[256 * 1024] = {};
    int unbuffered = (argc > 1 && argv[1] != NULL && strcmp(argv[1], "-b") == 0);

    if (unbuffered) {
        setbuf(stdin, NULL);
#if defined(__unix__)
        enable_raw_terminal();
#endif
    } else {
        static char input_buffer[BUFSIZ];
        setvbuf(stdin, input_buffer, _IOLBF, sizeof input_buffer);
    }

    int num = get_value();

    int sum = 0;
    for (int i = 0; i <= num; i++) {
        sum += i;
        memory[i % 65536] = i % 256;
        data[i % (256*1024)] = (sum + i) % 256;
    }
    print_int(sum);
    printf("\n");

    return 0;
}

/* Читает один символ и сразу показывает момент чтения. */
int read_char(void) {
    int ch = getchar();

    if (ch != EOF) {
        if (ch == '\n') {
            printf("[\\n]\n");
        } else {
            printf("[%c]", ch);
        }
        fflush(stdout);
    }
    return ch;
}

int convert_to_int(char ch) {
    return ch - 48;
}

int get_value(void) {
    int ch = read_char();
    int sign = 1;
    int value = 0;

    if (ch == '-') {
        sign = -1;
        ch = read_char();
    }

    while (ch != EOF && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            value = value * 10 + convert_to_int(ch);
        }
        ch = read_char();
    }
    return sign * value;
}

void clear(void) {
    int c;
    while ((c = read_char()) != '\n' && c != EOF) {
        /* discard */
    }
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
