#include <stdio.h>

// Deklaration der Funktion
int smallest_numb_arrayindx(double zahl[4]);  

// Array zum Speichern der Zahlen
double zahl[4];
//global nicht machen

int main() {
    // Benutzereingabe für die vier Zahlen
    printf("Geben Sie vier Zahlen ein: ");
    scanf("%lf %lf %lf %lf", zahl, &zahl[1], zahl+2, &zahl[3]); // &addresoperator

    // Berechne den Index der kleinsten Zahl
    int smallest_index = smallest_numb_arrayindx(zahl);

    // Gebe die kleinste Zahl und ihren Index aus
    printf("Kleinste Zahl: %.lf an Index %d\n", zahl[smallest_index], smallest_index);

    return 0; // Beende das Programm
}

// Funktion zur Bestimmung des Index der kleinsten Zahl im Array
int smallest_numb_arrayindx(double zahl[4]) {
    int min_index = 0; // Initialisiere mit dem ersten Element

    // Durchlaufe das Array und finde die kleinste Zahl
    for (int i = 1; i < 4; i++) { // Beginne mit i=1, da min_index bereits auf 0 gesetzt ist
        if (zahl[i] < zahl[min_index]) {
            min_index = i; // Wenn eine kleinere Zahl gefunden wird, aktualisiere min_index
        }
    }

    return min_index; // Gib den Index der kleinsten Zahl zurück
}
