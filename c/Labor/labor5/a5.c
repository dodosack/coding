#include <stdio.h>
int main()
{
    // eingabe und einscannen
    char eingabe[41];
    scanf("%40s", eingabe);
    // loop durch jede eingabe index
    for (int i = 0; eingabe[i] != '\0'; i++)
    {
        // for (int a = 0; i < count; i++){/* code */}
        if (eingabe[i] >= 'a' && eingabe[i] <= 'z')
        {
            eingabe[i] = eingabe[i] - 32; // so werden kleinbuchstaben in gross umgewandelt
        }
       else if (eingabe[i] >= 'A' && eingabe[i] <= 'Z') //bei 2 if hat sich die bedingung aufgehoben deswegen else if
        {
            eingabe[i] = eingabe[i] + 32; // grosbuchstabwn in klein verschiebuung nach rechts auf der ascii tabelle
        }
        // else
        //  nichts weil alles sonst gleich bleiben soll
    }
    printf("%s", eingabe);
    return 0;
}
