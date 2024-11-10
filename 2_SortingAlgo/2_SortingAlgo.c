#include "algo_sort.h"
#include <stdio.h>

static void PrintArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

static void PrintNumber(int value) {
    printf("%d ", value);
}

static void for_each(int arr[], int size, void (*func)(int)) {
    for (int i = 0; i < size; i++) {
        func(arr[i]);
    }
}

int main()
{
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    PrintArray(arr, n);
    for_each(arr, n, PrintNumber);

    BubbleSort(arr, n, CompareAscending);

    printf("Sorted array: \n");
    PrintArray(arr, n);

    return 0;
}