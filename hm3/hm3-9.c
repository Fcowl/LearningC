#include <locale.h>
#include <wchar.h>

int main(void) {
    setlocale(LC_ALL, "");

    wchar_t name[100];
    wscanf(L"%99ls", name);
    wprintf(L"Агент %ls авторизован в системе",name);
    return 0;
}