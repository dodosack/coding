#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int size;
    printf("Gib die Größe deiner Arrays an bzw wie viele zufallszahlen wills du?\n");
    scanf("%d", &size);
    int *array_random = (int *)malloc(size * sizeof(int));
    if (array_random == NULL)
    {
        return 1;
        /* code */
    }

    srand(time(0)); // seed auf aktualle zeit
    for (int i = 0; i < size; i++)
    {
        int zufallszahl = rand()% 101;
        array_random[i] = zufallszahl;
        printf("%d\t", array_random[i]);
    }
    free(array_random);
    return 0;
}