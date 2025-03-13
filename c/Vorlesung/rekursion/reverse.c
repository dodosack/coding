#include <stdio.h>

// Rekursive Funktion zur Umkehrung eines Arrays
void reverseArrayRecursive(int arr[], int start, int end) {
    if (start >= end) {
        return; // Basisfall: Stoppe die Rekursion
    }

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArrayRecursive(arr, start + 1, end - 1); // Rekursiver Aufruf
}

// Iterative Funktion zur Umkehrung eines Arrays
void reverseArrayIterative(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Ursprüngliches Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Iterative Methode
    reverseArrayIterative(arr, n);

    printf("Nach Iterativer Umkehrung: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Rekursive Methode
    reverseArrayRecursive(arr, 0, n - 1);

    printf("Nach Rekursiver Umkehrung: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
