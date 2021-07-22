#include <stdio.h>

void bai1(int *a, int* b) {
    *a += *b;
    *b = *a - *b;
    *a = *a - *b;
}

void bai2(int* arr) {
    for (int i=0; i<10; i++) printf("%d ", arr[i]);
}

void bai3(int* arr, int n, int* max, int* min) {
    *max = arr[0]; *min = arr[0];
    for (int i=0; i<n; i++) {
        if (*max < arr[i]) *max = arr[i];
        if (*min < arr[i]) *min = arr[i];
    }
} 

void bai4(int* arr, int n) {
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (arr[i] > arr[j]) {
                bai1(&arr[i], &arr[j]);
            }
        }
    }
}