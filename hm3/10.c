#include <locale.h>
#include <wchar.h>

int main(void) {
    setlocale(LC_ALL, "");
    wchar_t st1[100];
    wchar_t st2[100];
    wchar_t st3[100];

    wscanf(L"%ls %ls %ls", st1, st2, st3);

    wprintf(L"%-15ls|%20ls|%.5ls",st1,st2,st3);

    return 0;
}