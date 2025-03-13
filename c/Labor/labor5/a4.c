#include <stdio.h>
// eingabe und einscannen der variable
int main()
{
    char vowel;
    char str[40]; // var deklaration
    char vokale[] = "AaEeIiOoUu";

    scanf(" %c %39s", &vowel, str);
    for (int i = 0; str[i] != '\0'; i++) // aussere schleife für unser str string bis zum \0 terminator
    {
        // prüfen auf vokale bei jedem durchlaufe
        for (int a = 0; vokale[a] != '\0'; a++)
        {
            if (str[i] == vokale[a])
            {
                str[i] = vowel;
                break;
        }
            }
    }

int index = 0;

    while (str[index] != '\0')
    {
        printf("%c", str[index]);
        index++;

  
    }
    return 0;
}