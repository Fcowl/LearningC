#include <stdio.h>

int main(void) {
    //вариант 9
    const int HEIGHT = 5;
    for (int n_lines = 0; n_lines<=HEIGHT; n_lines++) {

        for (int l = 0; l<HEIGHT && (n_lines==0 || n_lines==HEIGHT-1);l++) {
            printf("=");
        }
        printf("\n");

        for (int l = 0; l<1 && n_lines <= HEIGHT-3;l++) {
            printf("=");

        }

        for (int l=0; l<=HEIGHT-3 && n_lines <= HEIGHT-3;l++) {
            printf(" ");
        }

        for (int l=0; l<1 && l<=HEIGHT-2 && n_lines <= HEIGHT-3;l++) {
            printf("=");
        }
    }
    return 0;
}