#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Kundendaten {
    int kundennummer;
    char vorname[50];
    char nachname[50];
};

int main() {
    struct Kundendaten *kunden;

    // Speicher für 2 Kunden reservieren
    kunden = (struct Kundendaten *)malloc(2 * sizeof(struct Kundendaten));
    if (kunden == NULL) {
        fprintf(stderr, "Fehler: Speicherzuweisung fehlgeschlagen.\n");
        return EXIT_FAILURE;
    }

    // Daten für den ersten Kunden festlegen
    kunden[0].kundennummer = 1;
    strcpy(kunden[0].vorname, "Hans");
    strcpy(kunden[0].nachname, "Maurer");

    // Eingabe für den zweiten Kunden
    printf("Geben Sie Kundennummer, Vorname und Nachname ein:\n");
    scanf("%d %49s %49s", &kunden[1].kundennummer, kunden[1].vorname, kunden[1].nachname);

    // Ausgabe der Kundendaten
    printf("\n1: %s %s\n", kunden[0].vorname, kunden[0].nachname);
    printf("2: %s %s\n", kunden[1].vorname, kunden[1].nachname);

    // Speicher freigeben
    free(kunden);
    kunden = NULL;

    return EXIT_SUCCESS;
}
