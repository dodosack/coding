#include <stdio.h>

int potenz_iterativ(int basis, int exponent);

int potenz_rekursiv(int basis, int exponent);

int main()
{

    int basis, potenz;
    scanf("%d %d", &basis, &potenz);
    printf("Ergebnis : %d\n",potenz_rekursiv(basis, potenz) );

    printf("Ergebnis : %d\n", potenz_iterativ(basis, potenz));
    return 0;
}

int potenz_iterativ(int basis, int exponent)
{

    if (exponent == 0&& basis != 0)
    {
        return 1;
    }
    else if (basis == 0 && exponent != 0)
    {
        return 0;
    }
    else if (basis == 0 && exponent == 0)
    {
        printf("Undefiniert\n");
        return 0;
        /* code */
    }

    int ergebnis = basis;

    for (int i = 0; i < exponent - 1; i++)
    {
        ergebnis *= basis;
        /* code */
    }

    return ergebnis;
};

int potenz_rekursiv(int basis, int exponent){
if (exponent == 0)
{
    return 1;
}

return basis * potenz_rekursiv(basis, exponent - 1);
};
