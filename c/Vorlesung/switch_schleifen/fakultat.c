#include <stdio.h>
int main()
{

    int zahl, i, a;
    a = 1;
    printf("Zahl eingeben\n");
    scanf("%d", &zahl);


    for ( i = 1; i <= zahl; i++)
    {
        a = a * i;
    }
    printf("%d", a);
    return 0;
}