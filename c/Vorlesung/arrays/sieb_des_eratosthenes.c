#include <stdio.h>   //eingabe ausgabe
#include <stdbool.h> //true false

#define MAX_n 1000 // max groeße an array fuer den primzahltest

void logic_of_erasthenes(int n);

// man eliminiert jedes vielfache der primzahlen
int main()
{
    int n = 0;
    // benutzer nach n fragen n=max anzahl an primzahlen

    printf("WIe viele primzahlen möchten sie\n");
    scanf("%d", &n);
    logic_of_erasthenes(n);
    return 0;
}

// ausimplementierung der logik der primzahlfinden
void logic_of_erasthenes(int n)
{
    // array das wahr falsch

    bool is_prime[n];
    for (size_t i = 0; i < n; i++)
    {
        is_prime[i];
    }
    // 0 und 1 kwinw primwzahlen
    is_prime[0] = false;
    is_prime[1] = false;

    // logik Sieb der erasthemes
    // abbruckbedingung bis quadrat wurzel
    // alle vielfache eliminieren

    for (int i = 2; i * i <= n; i++)
    {

        if (is_prime[i])
        {
            /* code */
        }

        // scjöeife um alle vielfachen vo i zu testen
        // keine primezahlen markieren
        for (int j = i; j <= n; j += i)
        {
            is_prime[j] = false;
        }
    }
}
