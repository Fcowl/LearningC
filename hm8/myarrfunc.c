#include "myarrfunc.h"
#include <stdio.h>

void print_arr(int arr[], int size) {
    /// prints array
    printf("array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insert_arr(int arr[], int size) {
    /// returns amount of successful insertions
    int num = 0;
    int i = 0;
    for (; i < size && (scanf("%d",&num) == 1); i++ ) {
        arr[i] = num;
    }
    return i;
}

int last_positive(int arr[],int size) {
    /// returns index of last positive number and -1 if there is no positive numbers
    for (int i = size-1; i >= 0; i--) {
        if (arr[i] > 0) return i;
    }
    return -1;
}

int distance_between_eq(int arr[], int size) {
    /// returns distance between equal numbres in the array and -1 if no equal numbers
    for (int i = 0; i < size ; i++) {
        for (int ii = i+1; ii < size; ii++) {
            if (arr[i] == arr[ii]) return ii-i-1;
        }
    }
    return -1;
}

int get_average(int arr[], int size) {
    /// get avarege of array (not available in main)
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum+=arr[i];
    }
    return sum/size;
}

int count_n_lower_then_average(int arr[],int size) {
    /// returns amount of numbers lower then array average
    int counter = 0;
    double average = get_average(arr,size);

    for (int i = 0; i < size ; i++) {
        if (arr[i] < average ) counter++;
    }
    return counter;
}