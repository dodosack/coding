#include <stdio.h>
#include <stdbool.h>

void sieve_of_eratosthenes(int n)
{
    // Ein Array, um festzustellen, ob eine Zahl eine Primzahl ist
    bool is_prime[n + 1];

    // Initialisiere alle Zahlen als Primzahlen (true)
    for (int i = 0; i <= n; i++)
    {
        is_prime[i] = true;
    }

    // 0 und 1 sind keine Primzahlen
    is_prime[0] = false;
    is_prime[1] = false;

    // Sieb-Prozess
    for (int p = 2; p * p <= n; p++)
    {
        if (is_prime[p])
        { // Wenn `p` eine Primzahl ist
            for (int i = p * p; i <= n; i += p)
            {
                is_prime[i] = false; // Markiere Vielfache von `p` als nicht-Primzahlen
            }
        }
    }

    // Ausgabe der Primzahlen
    printf("Primzahlen bis %d: ", n);
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int n;

    printf("Finde alle Primzahlen bis: ");
    scanf("%d", &n);

    sieve_of_eratosthenes(n);

    return 0;
}
