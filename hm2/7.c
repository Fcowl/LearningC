#include <stdio.h>

int main(void) {
    long double number;
    scanf("%Lf", &number);

    double db = (double)number;
    float fl = (float)number;


    printf("float: %.6f \n",fl);
    printf("double: %.6f \n",db);
    printf("LDouble: %.6Lf \n",number);

    printf("float+1: %.6f \n",fl+1);
    printf("double+1: %.6f \n",db+1);
    printf("LDouble+1: %.6Lf \n",number+1);

    /* float хранит только 7 цифр, поэтому при прибавке 1 ничего не меняется, он недостаточно точный
     * double - 15 цифр
     * lDouble - 18 */
    return 0;
}