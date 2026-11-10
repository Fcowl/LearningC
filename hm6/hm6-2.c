#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    // 9 (Количество вхождений последовательности L"ей")
    setlocale(LC_ALL, "");
    printf("Количество вхождений последовательности L\"ей\". Введите текст\n");
    wchar_t ch;
    int counter = 0;
    while ((ch=getwchar()) != L'#' && ch != WEOF) {
        if (ch == L'е') {
            ch = getwchar();

            if (ch == L'#') continue;

            if (ch == L'й') counter++;
        }
    }
    
    printf("Количество вхождений последовательности L\"ей\": %d\n", counter);
    return 0;
}
