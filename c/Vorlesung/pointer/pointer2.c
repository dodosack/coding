#include <stdio.h>

// Funktion erwartet einen Pointer auf ein Array und die Länge
void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("Element %d: %d\n", i, array[i]);  // Zugriff mit array[i]
    }
}

int main() {
    int numbers[] = {4, 6, 9, 5};  // Ein Array mit 4 Elementen
    printArray(numbers, 4);        // Übergabe des Arrays an die Funktion
    return 0;
}
