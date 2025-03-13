#include <stdio.h>
#include <stdlib.h> // für malloc/free
#include<time.h>
 int main()
{
    //size für 
    int size = 0;
    printf("Wie viele zahlen sollen wir generieren\n");
    scanf("%d", &size);

    int *array = (int*)malloc(size *sizeof(size));// eratmal voi pointer casten zu int* dann 4 mal sizeint speicher reservieren


if (array == NULL)
{
    printf("Fehler Mrk\n");
    return 1;  // geht wei  wir ja NULL haben und keinen speicher freigegebn haben 
}

srand(time(NULL));

for (int  i = 0; i < size; i++)
{
    array[i] = rand() % 100; //zahlen  0-99 
}

printf("Deine zahlen lauten\n");
for (int i = 0; i < size; i++)
{
    printf("%d  ", array[i]);
}
printf("\n");

free(array);
array = NULL;
return 0;
}