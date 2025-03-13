#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    // zufallszahl generieren und fragen
    srand(time(0));
    int eingabe;
    int zufallszahl = rand() % 101;
    printf("rate mal an welche zahl ich denke??\n");
    // zahl eingabe mit Überprüfung
    while (1)
    {
        scanf("%d", &eingabe);
        if (eingabe < 0 || eingabe > 100)
        {
            printf("Geben sie bitte eine gueltige Zahl  von  0 bis 100 ein!\n");
            continue;
        }

        else if (eingabe < zufallszahl)
        {
            printf("falschhhh!\n Probiers mit einer größeren Zahl.\n");
        }
        else if (eingabe > zufallszahl)
        {
            printf("falschhhh!\n Probiers mit einer kleineren Zahl.\n");
        }
        else
        {

            printf("Glückwunsch %d war die Zahl an die ich gedacht habe\n", zufallszahl);
            break;
        }
    }

    return 0;
}