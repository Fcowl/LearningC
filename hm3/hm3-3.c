#include <stdio.h>
#include <string.h>

int main(void) {
    char username[100];
    scanf("%99s",username);
    printf("\"%s\" \n",username);
    printf("\"%20s\" \n",username);
    printf("\"%-20s\" \n",username);
    int us_len = strlen(username)+5;
    printf("\"%*s %s %-*s\" \n", us_len, "",username, us_len,"");
    return 0;
}
