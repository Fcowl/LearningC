#include "myarrfunc.h"
#include <stdio.h>


void print_arr(int rows, int columns, int arr[][MAX_COLUMNS]) {
    /// prints array

    int (*row)[MAX_COLUMNS] = arr;

    // with each step i move pointer to the next number in the array

    for (int r = 0; r < rows; r++, row++) {
        int *p = *row; // pointer to first number in row
        for (int c = 0; c < columns ; c++, p++) {
            printf("%d ", *p);
        }
        printf("\n");
    }
}

int insert_arr(int rows, int columns, int arr[][MAX_COLUMNS]) {
    /// returns amount of successful insertions
    int input_num = 0;

    int counter = 0;
    int (*row)[MAX_COLUMNS] = arr;

    for (int r = 0; r < rows; r++, row++) {
        int *p = *row; // pointer to first number in row
        for (int c = 0; c < columns ; c++, p++) {
            if (scanf("%d", &input_num) == 1) {
                *p = input_num;
                counter++;
            }
        }
    }
    return counter;
}

int max(int rows, int columns, int arr[][MAX_COLUMNS]) {
    if (rows <= 0 || columns <= 0)
        return 0;

    int max_s = **arr; // first element, reached through pointers
    int (*row)[MAX_COLUMNS] = arr;

    for (int r = 0; r < rows; r++, row++) {
        int *p = *row; // pointer to first number in row
        for (int c = 0; c < columns ; c++, p++) {
            if (*p > max_s)
                max_s = *p;
        }
    }
    return max_s;
}

int minimal_in_row(int ROW, int columns, int arr[][MAX_COLUMNS]) {
    int min = 2147483647;
    int *p = *(arr + ROW); // pointer to first number in the needed row

    for (int c = 0; c < columns; c++, p++) {
        if (*p < min)
            min = *p;
    }
    return min;
}


int avg(int ROW, int columns, int arr[][MAX_COLUMNS]) {
    int sum = 0;
    int *p = *(arr + ROW); // pointer to first number in the needed row

    for (int c = 0; c < columns ; c++, p++) {
       sum += *p;
    }
    return sum / columns;
}

int amount_bigger_than_avg(int ROW, int columns, int arr[][MAX_COLUMNS]) {
    int counter = 0 ;
    int average = avg(ROW, columns, arr);
    int *p = *(arr + ROW); // pointer to first number in the needed row

    for (int c = 0; c < columns; c++, p++) {
        if (*p > average)
            counter++;
    }
    return counter;
}
