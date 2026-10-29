#include <stdio.h>
#include <math.h>
// something changed here too omg
int main(void) {
    //вариант 21
    double arr[8];
    double current_sum = 0.0;
    for (int i=0; i<8; i++) {
        arr[i] = pow(2,i-1);
    }

    printf("original array: ");
    for (int index=0; index<8; index++ ) {
        printf("%.1f ",arr[index]);
    }
    printf("\nnew array: ");
    for (int index=0; index<8; index++ ) {

        printf("%.1f ",current_sum+=arr[index]);
    }
}