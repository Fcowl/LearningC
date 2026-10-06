#include <stdio.h>
#include <string.h>

int main(void) {
    char *name = "Sasha";
    char *group = "IV-622";
    char *hostname = "fcowl";
    // функция strlen() неправильно считает длинну если кирилица
    // поэтому все символы латинские
    printf("%s\t{%d}\n%s\t%s\t{%d}\n",
        name, (int)strlen(name),
        group,hostname, (int)strlen(group)+(int)strlen(hostname));
    return 0;
}