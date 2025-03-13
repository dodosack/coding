#include <stdio.h>

int main()
{
    int kleinbuchstaben_zaehler = 0;
    char eingabe[40];

    // eingabe und lesen der zeichenkette
    scanf("%39s", eingabe);

    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        if (eingabe[i] >= 'a' && eingabe[i] <= 'z')
        {
            kleinbuchstaben_zaehler++;
        }
    }

    printf("%d Kleinbuchstaben", kleinbuchstaben_zaehler);
    return 0;
}