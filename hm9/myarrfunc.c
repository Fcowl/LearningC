#include "myarrfunc.h"
#include <stdio.h>


void print_arr(int rows, int columns, int arr[][MAX_COLUMNS]) {
    /// prints array
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns ; c++) {
            printf("%d ", arr[r][c]);
        }
        printf("\n");
    }
}

int insert_arr(int rows, int columns, int arr[][MAX_COLUMNS]) {
    /// returns amount of successful insertions
    int input_num = 0;

    int counter = 0;
    for (int r = 0; r < rows; r++ ) {
        for (int c = 0; c < columns ; c++ ) {
            if (scanf("%d",&input_num) == 1) {
                arr[r][c] = input_num;
                counter++;
            }
        }
    }
    return counter;
}

int max(int rows, int columns, int arr[][MAX_COLUMNS]) {
    int max_s = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0 ; c < columns; c++) {
            if (arr[r][c] > max_s)
                max_s = arr[r][c];
        }
    }
    return max_s;
}

int minimal_in_row(int ROW, int columns, int arr[][MAX_COLUMNS]) {
    int min = 2147483647;
    for (int c = 0; c < columns; c++) {
        if (arr[ROW][c] < min)
            min = arr[ROW][c];
    }
    return min;
}


int avg(int ROW, int columns,int arr[][MAX_COLUMNS]) {
    int sum = 0;
    for (int c = 0; c < columns ; c++) {
       sum+=arr[ROW][c];
    }
    return sum/columns;
}

int amount_bigger_than_avg(int ROW, int columns, int arr[][MAX_COLUMNS]) {
    int counter = 0 ;
    int average = avg(ROW,columns,arr);
    for (int c = 0; c < columns; c++) {
        if (arr[ROW][c] > average)
            counter++;
    }
    return counter;
}
