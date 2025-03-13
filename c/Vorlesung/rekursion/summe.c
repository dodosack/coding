#include <stdio.h>

int summe_iterativ(int n );

int summe_rekursiv(int n);

int main()
{

    int n, potenz;
    scanf("%d", &n);
    printf("Ergebnis : %d\n",summe_iterativ(n) );

    printf("Ergebnis : %d\n", summe_rekursiv(n));
    return 0;
}
int summe_iterativ(int n ){

    int sum = 0;

    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
};

int summe_rekursiv(int n){
    if (n == 0)
    {
        return 0;
    }

    return n + summe_rekursiv(n-1);
};
