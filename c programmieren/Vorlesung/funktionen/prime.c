#include <stdio.h>
#include <stdbool.h>

bool isPrime(int numbertotest) {
    if (numbertotest < 2) {
        return false;
    }
    if (numbertotest == 2) {
        return true;
    }
    for (int divisor = 2; divisor <= numbertotest / 2; divisor++) {
        if (numbertotest % divisor == 0) {
            return false;
        }
    }
    return true;
}

void ausgabe(int maxprimzahlausgabeaufkonsole) {
    int counter = 0;
    int numbertotest = 1;  // Start at 1 because 2 is the first prime number
    while (counter < maxprimzahlausgabeaufkonsole) {
        numbertotest++;
        bool isprime = isPrime(numbertotest);
        if (isprime) {
            counter++;
            printf("%d ", numbertotest);
            if (counter % 10 == 0) {
                printf("\n");
            }
        }
    }
}

int main() {
    int maxprime = 50;

    printf("Bitte Zahl eingeben: ");
    scanf("%d", &maxprime);

    // Call function to print prime numbers
    ausgabe(maxprime);

    // Initialize a character array to demonstrate the array input
    char string[40];
    printf("\n\nBitte Zeichenkette eingeben: ");
    scanf("%39s", string);  // Limiting input to 39 characters to prevent overflow

    printf("Eingegebene Zeichenkette: %s\n", string);
    return 0;
}
