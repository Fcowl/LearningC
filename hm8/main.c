//compile gcc main.c myarrfunc.c -o main && ./main
#include <stdio.h>
#include <stdlib.h>

#include "myarrfunc.h"

#define ARR_MAX_SIZE 100

void print_prompt();
void clear();

int main(void) {
    // №4 - 8 15 26
    int choice;

    int arr_size = 0;
    int arr[ARR_MAX_SIZE] = {};

    printf("Choose operation \n"
        "a (1): set array size \n"
        "b (2): fill array \n"
        "c (3): print array \n"
        "d (4): find index of last positive element \n"
        "e (5): find distance between equal values \n"
        "f (6): count number of values < then average \n"
        "g (7): exit \n");

    while ((choice = getchar()) != EOF) {

        clear();

        switch (choice) {
            case '1':
            case 'a':
                printf("Ender a desired array size: ");

                int new_size;

                if (scanf("%9d",&new_size) != 1) {
                    printf("Enter correct value \n");
                    clear();
                    break;
                }
                clear();


                if (new_size <= 0 || new_size > ARR_MAX_SIZE) {
                    printf("size must be in range 1-%d\n",ARR_MAX_SIZE);
                    break;
                }
                arr_size = new_size;
                printf("set array to size = %d: successfully\n",arr_size);
                //print_arr(arr,arr_size);
                break;

            case '2':
            case 'b':
                if (arr_size == 0) {
                    printf("initialize array first\n");
                    break;
                }

                printf("insert %d values into array\n",arr_size);
                int value = insert_arr(arr,arr_size);
                if (value == arr_size) {
                    printf("insertion successful\n");
                } else {
                    printf("not all numbers inserted\n");
                }
                clear();
                break;

            case '3':
            case 'c':
                if (arr_size == 0) {
                    printf("initialize array first\n");
                    break;
                }

                printf("arr: ");
                print_arr(arr,arr_size);
                break;

            case '4':
            case 'd':
                if (arr_size == 0) {
                    printf("initialize array first\n");
                    break;
                }
                int index = last_positive(arr,arr_size);
                if (index == -1) {
                    printf("no positive numbers in array\n");
                    break;
                }

                printf("index of last positive element: %d \n",index);
                break;

            case '5':
            case 'e':
                if (arr_size == 0) {
                    printf("initialize array first\n");
                    break;
                }
                int distance = distance_between_eq(arr,arr_size);

                if (distance == -1) {
                    printf("no equal numbers found \n");
                    break;
                }

                printf("distance between equal numbers = %d \n",distance);
                break;

            case '6':
            case 'f':
                if (arr_size == 0) {
                    printf("initialize array first\n");
                    break;
                }
                printf("amount of values lower then array average: %d \n",count_n_lower_then_average(arr,arr_size));
                break;

            case '7':
            case 'g':
                printf("end (case g)\n");
                return 0;

            default:
                printf("unknown option\n");
                break;

        }
        print_prompt();
    }
    printf("end (EOF) \n");
    return 0;
}


void print_prompt() {
    //printf("\nenter to go to next iteration\n");
    //clear(); // getchar();
    printf("\nChoose operation \n"
           "a (1): set array size \n"
           "b (2): fill array \n"
           "c (3): print array \n"
           "d (4): find index of last positive element \n"
           "e (5): find distance between equal values \n"
           "f (6): count number of values < then average \n"
           "g (7): exit \n");
}

void clear() {
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
}
