#include <stdio.h>
int main()
{
    // eingabe und direkt alles in kleinbuchstaben umformatieren
    int vokale_zaehler= 0;
    char eingabe[40];
    char vokale[] = "AaEeIiOoUu";
    scanf("%39s", eingabe);

    for (int i = 0; eingabe[i] != '\0'; i++)
    {

        for (int vokal_index = 0; vokale[vokal_index] != '\0'; vokal_index++)
        {

            {
                if (eingabe[i] == vokale[vokal_index])
                {
                    vokale_zaehler += 1;
                }
            }
        }
    }
    printf("%d Vokale", vokale_zaehler);
    return 0;
}