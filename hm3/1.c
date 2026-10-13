#include <stdio.h>
#include <string.h>

int main(void) {
    //char string[20] = "СибГУТИ";
    char string[20] = "SibSUTIS";

    printf("sizeof: %zu \n"
           "strlen: %zu \n"
           "free_bytes: %zu \n",
           sizeof(string),strlen(string),sizeof(string)-strlen(string)-1);
    /* -1 ещё потому что символ конца строки
    * sizeof возвращет количество байт которое занимает переменная
    * strlen возвращает длинну строки
    * srtlen возвращает неправильную длинну строки для киррилицы,
    * потому что она хранится в юникод, кадждый символ занимает 2 байта
    */
    return 0;
}
