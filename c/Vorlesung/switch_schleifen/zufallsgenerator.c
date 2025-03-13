#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    printf("Rate mal an welche zahl ich denke?");
    int eingabe, zufallszahl;
    scanf("%d", &eingabe);
    srand(time(0));
    zufallszahl = rand() % 101;
    // printf("%d", zufallszahl);

    if (eingabe != zufallszahl)
    {
        while (zufallszahl != eingabe)
        {
            printf("falsche Zahl opfer\n");

            if (eingabe < zufallszahl)
            {
                printf("YOur input was to little dumbass!\n Try  again!");
            }
            else
            {
                printf("Your input was to big dumbass!\n Try  again!");
            }
            scanf("%d", &eingabe);
        }
    }
    else
    {
        printf("mice job your numer %d was the same i was thinking!\n", zufallszahl);
    }

    return 0;
}