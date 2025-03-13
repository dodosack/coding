#include <stdio.h>
int main()
{

    int zeile, spalte, i;
    int n;

    scanf("%d %d", &zeile, &spalte);
    printf("\n");

    for (n = 1; n <= zeile; n++)
    {

        if (n <= zeile)
        {

            for (i = 1; i <= spalte; i++)
            {
                if (i <= spalte)
                {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}