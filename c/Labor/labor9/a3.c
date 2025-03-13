#include <stdio.h>
#include <stdlib.h>

// Funktion zur Sortierung des Arrays (Bubble Sort)
void sort_array(int *array, int size);

int main() {
    int size;

    // Einlesen der Anzahl der zu sortierenden Zahlen
    
     scanf("%d", &size);
    

    // Dynamischer Speicher für das Array
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        
        return EXIT_FAILURE;
    }

    // Einlesen der Zahlen (die erste Zahl wurde bereits verwendet)
   
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Sortiere das Array
    sort_array(array, size);

    // Ausgabe der sortierten Zahlen
   
    for (int i = 0; i < size; i++) {
        printf("%2d:%4d", i + 1, array[i]);
    }

    // Speicher freigeben
    free(array);
    return EXIT_SUCCESS;
}

// Funktion zur Sortierung des Arrays (Bubble Sort)
void sort_array(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {//vergleicht immer alle benachbarten elemente und auscht das gröserer bis es am ende ist 
        //bei jede, durchlauf wird das nächstgröste an die letzte stelle minus i gesetzt bis fertig sortierrt 
            if (array[j] > array[j + 1]) {
                // Werte tauschen
                int temp = array[j];//zwischenspeichern 
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }// sonst nichts 
    }
}
