// hauptprogramm
#include <stdio.h>
#include <stdbool.h>
#include "mymath.h"
int main()
{
   

    int number = 0;

    printf("Geben sie eine zahl ein  (posotiv)");
    scanf("%d ", &number);

    bool ist_gerade = isEven(number);

    if (ist_gerade)
    {
        printf("Gerade");
    }
    else
    {
        printf("ungerade");
    }
    return 0;
}