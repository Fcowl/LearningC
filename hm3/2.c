#include <stdio.h>
#include <string.h>

int main(void) {
    char word1[15];
    char word2[15];
    scanf("%s %s",word1,word2);
    printf("%s-%s \ntotal len: %zu",word1,word2,strlen(word1)+strlen(word2));

    return 0;
}
