#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, "");

    const char st1[] = "Рузкий текст";
    const wchar_t st2[] = L"Рузкий текст";

    printf("char (st1)-> sizeof: %zu bytes, strlen: %zu chars \n",sizeof(st1), strlen(st1));
    printf("wchar_t (st2)-> sizeof: %zu bytes, wcslen: %zu chars",sizeof(st2), wcslen(st2));

    return 0;
}