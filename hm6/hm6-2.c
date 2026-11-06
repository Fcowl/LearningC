#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    // 9 (Количество вхождений последовательности L"ей")
    setlocale(LC_ALL, "");
    printf("Количество вхождений последовательности L\"ей\"\n");
    wchar_t ch;
    int counter = 0;
    while ((ch=getwchar()) != L'#')
        if (ch == L'е')
            if ((ch=getwchar()) == L'й')
                counter++;
    
    printf("Количество вхождений последовательности L\"ей\": %d\n", counter);
    return 0;
}
