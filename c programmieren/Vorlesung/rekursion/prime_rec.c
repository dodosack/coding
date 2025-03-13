#include <stdio.h>
#include <stdbool.h>
#include <math.h> // Für sqrt()

bool is_prime(int zahl, int teiler);
bool is_prime_iterativ(int zahl);

int main()
{
    int eingabe;
    printf("Bitte geben Sie eine Zahl zum Testen ein: ");
    scanf("%d", &eingabe);

    printf("Rekursiv: %d\n", is_prime(eingabe, (int)sqrt(eingabe)));
    printf("Iterativ: %d\n", is_prime_iterativ(eingabe));

    return 0;
}

// Rekursive Funktion zur Primzahlprüfung
bool is_prime(int zahl, int teiler)
{
    if (zahl <= 1) // 0 und 1 sind keine Primzahlen
        return false;

    if (teiler == 1) // Kein Teiler gefunden, Primzahl
        return true;

    if (zahl % teiler == 0) // Teiler gefunden, keine Primzahl
        return false;

    return is_prime(zahl, teiler - 1); // Rekursiver Aufruf
}

// Iterative Funktion zur Primzahlprüfung
bool is_prime_iterativ(int zahl)
{
    if (zahl <= 1) // 0 und 1 sind keine Primzahlen
        return false;

    int limit = (int)sqrt(zahl); // Begrenzung auf sqrt(zahl)

    for (int i = 2; i <= limit; i++)
    {
        if (zahl % i == 0) // Teiler gefunden, keine Primzahl
            return false;
    }
    return true; // Keine Teiler gefunden, Primzahl
}
