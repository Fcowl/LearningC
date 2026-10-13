#include <stdio.h>
#include <string.h>

int main(void) {
    char string[] = "\x48\x65\x6C\x6C\x6F\t\x57\x6F\x72\x6C\x64\n"; // \t значит знак табуляции
    // в шестандцетеричной форме символы означают отдельные буквы по юникод таблице
    size_t string_len = strlen(string)-1; //без учета \n
    size_t string_size = sizeof(string)-1; //без учета \n
    
    printf("%s \n",string);
    printf("string_len: %zu \n",string_len);
    printf("sting_size: %zu \n",string_size);

}
