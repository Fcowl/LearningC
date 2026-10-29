#include <stdio.h>
#include <string.h>

#define string "LinuxDistro"

int main(void) {
    const char string2[] = "2026";

    printf("distro: %s \n"
           "rdate: %s \n"
           "strlen: %zu \n"
           "sizeof: %zu \n",
           string, string2, strlen(string), sizeof(string));
    // длинна строки = 11, sizeof = 12 из за \0
    return 0;
}