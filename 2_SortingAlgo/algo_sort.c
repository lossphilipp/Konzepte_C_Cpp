#pragma once

#include "algo_sort.h"

int CompareAscending(int a, int b) {
    return b - a;
}

int CompareDescending(int a, int b) {
    return a - b;
}

void BubbleSort(int arr[], int size, int (*compare)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (compare(arr[j], arr[j + 1]) < 0)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}