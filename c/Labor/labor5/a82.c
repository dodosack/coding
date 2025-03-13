#include <stdio.h>
int main()
{
    int index = 0;
    float summe = 0.0;
    float zwischen_summe = 0.0;
    for (int i = 0; i < 10; i++)
    {

       // scanf("%f", &zwischen_summe); man braucht nur einmal das scann f weil es in der if def wird

        if (scanf("%f", &zwischen_summe) != 1)
        {
           break;
        }
        
        if (zwischen_summe < 1.00 || zwischen_summe > 6.00)
        {
            break;
        }
        else
        {
            summe += zwischen_summe;
            index++;
        }
    }
    float durchschnitt = summe / index;
    if (index == 0)
    {
        printf("Durchschnitt (N=0): 0.00\n");
    }

    else
    {
        printf("Durchschnitt (N=%d): %.2f\n", index, durchschnitt);
    }
    return 0;
}