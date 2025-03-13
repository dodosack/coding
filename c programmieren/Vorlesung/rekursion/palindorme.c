#include <stdio.h>
#include <string.h>

// Rekursive Funktion zur Palindromprüfung
int isPalindromeRecursive(char str[], int start, int end)
{
    // Basisfall: Wenn Startindex >= Endindex, ist der String ein Palindrom
    if (start >= end)
    {
        return 1; // True
    }

    // Prüfe, ob das erste und das letzte Zeichen gleich sind
    if (str[start] != str[end])
    {
        return 0; // False
    }

    // Rekursiver Aufruf: Prüfe den nächsten inneren Bereichx1
    return isPalindromeRecursive(str, start + 1, end - 1);
}

// Iterative Funktion zur Palindromprüfung
int isPalindromeIterative(char str[])
{
    int start = 0;             // Startindex
    int end = strlen(str) - 1; // Endindex

    // Solange die Indizes sich nicht überschneiden
    while (start < end)
    {
        // Prüfe, ob die Zeichen am Start und Ende unterschiedlich sind
        if (str[start] != str[end])
        {
            return 0; // False
        }

        // Bewege die Indizes näher zueinander
        start++;
        end--;
    }

    return 1; // True
}

int main()
{
    char str[100]; // Eingabe-String

    printf("Geben Sie einen String ein: ");
    scanf("%s", str);

    // Rekursive Methode
    if (isPalindromeRecursive(str, 0, strlen(str) - 1))
    {
        printf("Rekursiv: Der String \"%s\" ist ein Palindrom.\n", str);
    }
    else
    {
        printf("Rekursiv: Der String \"%s\" ist kein Palindrom.\n", str);
    }

    // Iterative Methode
    if (isPalindromeIterative(str))
    {
        printf("Iterativ: Der String \"%s\" ist ein Palindrom.\n", str);
    }
    else
    {
        printf("Iterativ: Der String \"%s\" ist kein Palindrom.\n", str);
    }

    return 0;
}
