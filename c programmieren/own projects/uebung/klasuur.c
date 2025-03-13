#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum_iterativ(int arr[], int size);

int sum_recursiv(int arr[], int size);

int main()
{

    int size;
    printf("Wie viele Ganzzahlen möchten sie einscannen und summierern?\n");
    scanf("%d", &size);
    int *arr_dynam = (int *)malloc(size * sizeof(int)); // erstellen des array und reservieren des speichers im heap
    assert(arr_dynam != NULL);

    for (int i = 0; i < size; i++)                      // einscanne der werteim arry
    {
        printf("Bitte gib deine %d. Zahl ein\n", i + 1);
        scanf("%d", &arr_dynam[i]);
    }
    int sum_iter = sum_iterativ(arr_dynam, size);
    int sum_rec = sum_recursiv(arr_dynam, size);

    printf("Summe Iterativ = %d und recursiv = %d\n", sum_iter, sum_rec);
    free(arr_dynam);
    arr_dynam = NULL;
    return 0;
}
int sum_iterativ(int arr[], int size){

    int ergebnis = 0;

    for (int i = 0; i < size; i++)
    {
        ergebnis += arr[i];
    }

    return ergebnis;
};

int sum_recursiv(int arr[], int size){

    if (size == 0)
    {
        return 0;
    }

    return arr[size - 1] + sum_recursiv(arr, size - 1);
};
