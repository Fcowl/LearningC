//compile gcc main.c myarrfunc.c -o main && ./main < input.txt > output.txt
#include <stdio.h>
#include "myarrfunc.h"

#define MAX_ROWS 100
#define MAX_COLUMNS 100

void print_prompt(bool);
void clear();

int main(void) {
    // №4 - 1 12 27
    int choice;

    int arr_rows = 0;
    int arr_columns = 0;
    int arr[MAX_ROWS][MAX_COLUMNS] = {};

    print_prompt(1);
    while ((choice = getchar()) != EOF) {

        clear();

        switch (choice) {
            case '1':
            case 'a': // initialize
                printf("Ender a desired amount of ROWS (max=%d): ",MAX_ROWS);

                int new_size;

                if (scanf("%9d",&new_size) != 1) {
                    printf("Enter correct value \n");
                    clear();
                    break;
                }
                clear();

                if (new_size <= 0 || new_size > MAX_ROWS) {
                    printf("size must be in range 1-%d\n",MAX_ROWS);
                    break;
                }
                arr_rows = new_size;

                printf("Ender a desired amount of COLUMNS (max=%d): ",MAX_COLUMNS);

                if (scanf("%9d",&new_size) != 1) {
                    printf("Enter correct value \n");
                    clear();
                    break;
                }
                clear();

                if (new_size <= 0 || new_size > MAX_COLUMNS) {
                    printf("size must be in range 1-%d\n",MAX_COLUMNS);
                    break;
                }
                arr_columns = new_size;

                printf("set array to size = [%d][%d]: successfully\n",arr_rows,arr_columns);
                break;

            case '2':
            case 'b': // fill arr
                if (arr_rows == 0) {
                    printf("initialize array first\n");
                    break;
                }

                printf("insert %d values into array (%d rows, %d columns)\n",
                    arr_rows*arr_columns,arr_rows,arr_columns);

                if (insert_arr(arr_rows, arr_columns, arr) == arr_columns*arr_rows) {
                    printf("insertion successful\n");
                } else {
                    printf("not all numbers inserted\n");
                }
                clear();
                break;

            case '3':
            case 'c': // print arr
                if (arr_rows == 0) {
                    printf("initialize array first\n");
                    break;
                }

                printf("array: \n");
                print_arr(arr_rows,arr_columns,arr);
                break;

            case '4':
            case 'd': // max number
                if (arr_rows == 0) {
                    printf("initialize array first\n");
                    break;
                }
                printf("max number in arr: %d \n",max(arr_rows, arr_columns, arr));
                break;

            case '5':
            case 'e': // minimal in each row
                if (arr_rows == 0) {
                    printf("initialize array first\n");
                    break;
                }
                printf("minimal number in each row: \n");

                for (int row = 0; row<arr_rows; row++) {
                    printf("%d : %d\n",row+1,minimal_in_row(row,arr_columns,arr));
                }

                break;

            case '6':
            case 'f': // amount of numbers > then avg in row
                if (arr_rows == 0) {
                    printf("initialize array first\n");
                    break;
                }
                printf("amount of \"numbers > then avg in row\" : \n");

                for (int row = 0; row<arr_rows; row++) {
                    printf("%d : %d\n",row+1,amount_bigger_than_avg(row,arr_columns,arr));
                }

                break;

            case '7':
            case 'g':
                printf("end (case g)\n");
                return 0;

            default:
                printf("unknown option\n");
                break;

        }
        print_prompt(0);
    }
    printf("end (EOF) \n");
    return 0;
}


void print_prompt(bool n) {
    //printf("\nenter to go to next iteration\n");
    //clear(); // getchar();
    if (n) {
        printf("Choose operation \n");
    } else {
        printf("\nChoose operation \n");
    }
    printf(""
           "a (1): set array size \n"
           "b (2): fill array \n"
           "c (3): print array \n"
           "d (4): print max number in array\n"
           "e (5): minimal in each row \n"
           "f (6): amount of \"numbers > then avg in row\" \n"
           "g (7): exit \n");
}

void clear() {
    int c;
    while ((c=getchar()) != '\n' && c != EOF);
}
