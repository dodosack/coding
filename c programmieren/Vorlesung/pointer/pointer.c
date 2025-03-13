#include <stdio.h>
#include <string.h>

/*int main (){

    char myString[] = "hallo welt";
    char myString2[] = "lo";
    char ergebnis[10];
    //strcat(myString, myString2);
    

        printf("%x\n", *strstr(myString,myString2));
        printf("%x", &myString2[3]);
    return 0;

}
*/
#include <stdio.h>
#include <stdbool.h> // Für Boolesche Werte

// Funktion zur Berechnung der Werte von a und b
void berechneWerte(int input, bool *a, bool *b) {
    if (input % 2 != 0 && input % 3 != 0 && input % 5 != 0) {
        *a = !(*a); // a wird auf seinen Gegenteilswert gesetzt
    }
    
    if (!(*a)) {
        *b = !(*a); // b wird auf das Gegenteil von a gesetzt
    }
}

int main() {
    bool a = false; // Anfangswert von a
    bool b = false; // Anfangswert von b
    int input;

    // Eingabe des Wertes input
    printf("Bitte geben Sie eine ganze Zahl ein: ");
    scanf("%d", &input);

    // Funktion zur Berechnung aufrufen
    berechneWerte(input, &a, &b);

    // Ergebnisse ausgeben
    printf("Wert von a: %s\n", a ? "true" : "false");
    printf("Wert von b: %s\n", b ? "true" : "false");

    return 0;
}
