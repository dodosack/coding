#include <stdio.h>
int main()
{
    int a , k;
    int i = 1;
    unsigned int zahl;
    scanf("%u", &zahl);

    for (i = 1; i <= zahl; i++) // zeile 1
    {

        if (i == 1 || i == zahl)
        {

            for (a = 1; a <= zahl; a++)
            {
                printf("*");
            }
            printf("\n");
        }
        for ( k = 0; k < zahl; k++)
        {
            /* code */

             if (i == 2 + k && i < zahl) // zeile 2
            {

                for (a = 1; a <= zahl; a++)
                {
                    if (a == 1  || a == zahl)
                    {
                        printf("*");
                    }

                    else if (a == i || a == zahl - (1 + k))
                    {
                        printf("*");
                    }
                    else 
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}