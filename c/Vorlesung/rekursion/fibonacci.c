#include <stdio.h>
#include <stdlib.h>
int fibonaci(int zahl);
int fibonaci_iterativ(int zahl);
int main()
{
    int zahl;
    scanf("%d", &zahl);

    printf("Ergebnis : %d\n", fibonaci(zahl));

    printf("Ergebnis : %d", fibonaci_iterativ(zahl));
    return 0;
}

int fibonaci(int zahl)
{

    if (zahl == 1)
    {
        return 1;
    }
    else if (zahl == 0)
    {
        return 0;
    }

    return fibonaci(zahl - 1) + fibonaci(zahl - 2);
};

int fibonaci_iterativ(int zahl)
{
    if (zahl == 1)
    {
        return 1;
        /* code */
    }
    else if (zahl == 0)
    {
        /* code */ return 0;
    }

    int temp1, temp2;
    temp1 = 1;
    temp2 = 0;
    int sum3 = 0;
    for (int i = 2; i <= zahl; i++)
    {
        sum3 = temp1 + temp2;
        temp2 = temp1; // wichitg das temp1 nicht zuerst veränderrt wird
        temp1 = sum3;
    }
    return sum3;
};