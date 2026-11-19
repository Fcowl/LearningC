#include <stdio.h>
#include <stdlib.h>

#include "myarrfunc.h"

void print_prompt();
void clear();

int main(void) {
    // №4 - 8 15 26
    char choice;

    int arr_size;
    int *arr = NULL;

    printf("Choose operation \n"
           "a: set array size \n"
           "b: fill array \n"
           "c: print array \n"
           "d: find index of last positive element \n"
           "e: find distance between equal values \n"
           "f: count number of values < then average \n"
           "g: exit \n");

    while ((choice=getchar()) != EOF) {

        clear();

        switch (choice) {
            case 'a':
                printf("Ender a desired array size: ");

                if (scanf("%d",&arr_size) != 1) {
                    printf("Enter correct value \n");
                    break;
                }

                clear();

                if (arr_size <= 0) {
                    printf("size cannot be 0 or lower\n");
                    break;
                }

                if (arr != NULL) {
                    arr = NULL;
                    free(arr);
                }

                arr = malloc(arr_size * sizeof(int));
                printf("set array to size = %d successfully\n",arr_size);
                //print_arr(arr,arr_size);
                break;

            case 'b':
                printf("insert values into array\n"); // todo eof abort
                int value = insert_arr(arr,arr_size);
                if (value == arr_size) {
                    printf("insertion successful\n");
                } else {
                    printf("not all numbers inserted\n");
                }
                clear();
                break;

            case 'c':
                if (arr == NULL) {
                    printf("initialize array first\n");
                    break;
                }

                printf("arr: ");
                print_arr(arr,arr_size);
                break;

            case 'd':
                if (arr == NULL) {
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

            case 'e':
                if (arr == NULL) {
                    printf("initialize array first\n");
                    break;
                }
                int distance = distance_between_eq(arr,arr_size);

                if (distance == -1) {
                    printf("no eq numbers found \n");
                    break;
                }

                printf("distance between eq numbers = %d \n",distance);
                break;

            case 'f':
                if (arr == NULL) {
                    printf("initialize array first\n");
                    break;
                }
                printf("amount of values lower then array average: %d \n",count_n_lower_then_average(arr,arr_size));
                break;

            case 'g':
                printf("end (case g)\n");
                return 0;

            default:
                printf("unknown\n");
                break;

        }
        print_prompt();
    }
    printf("end\n");
    return 0;
}


void print_prompt() {
    printf("\nenter to go to next iteration\n");
    clear(); // getchar();c
    printf("\nChoose operation \n"
           "a: set array size \n"
           "b: fill array \n"
           "c: print array \n"
           "d: find index of last positive element \n"
           "e: find distance between equal values \n"
           "f: count number of values < then average \n"
           "g: exit \n");
}

void clear() {
    while (getchar() != '\n');
}
