#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Union zur Speicherung von alter oder geburtstag
union data
{
    int alter;
    int geburtstag;
};

// Struktur für den Autor
struct Author
{
    char name_author[30];
    int alter;
};

// Struktur für Bücher
struct Buecher
{
    char name[29];
    int kosten;
    struct Author autor;
    union data info; // Union
    bool flag_age;   // Flag: true = alter, false = geburtstag
};

int main()
{
    struct Buecher *ptr;

    // Speicher für 2 Bücher reservieren
    ptr = (struct Buecher *)malloc(2 * sizeof(struct Buecher));
    if (ptr == NULL)
    {
        fprintf(stderr, "Fehler: Speicherzuweisung fehlgeschlagen.\n");
        return EXIT_FAILURE;
    }

    // Daten für das erste Buch
    ptr[0].kosten = 20;
    strcpy(ptr[0].name, "Mein Kampf");
    ptr[0].autor.alter = 56;
    strcpy(ptr[0].autor.name_author, "Adolf Hitler");
    ptr[0].info.alter = 56; // Alter in die Union speichern
    ptr[0].flag_age = true; // Flag setzen, um Alter zu kennzeichnen

    // Daten für das zweite Buch
    /*(ptr + 1)->kosten = 30;
    strcpy((ptr + 1)->name, "C-Programmierung");
    strcpy((ptr + 1)->autor.name_author, "Dennis Ritchie");
    (ptr + 1)->info.geburtstag = 19410209; // Geburtstag in die Union speichern
    (ptr + 1)->flag_age = false;           // Flag setzen, um Geburtstag zu kennzeichnen
*/
    // zweitees Buch kannn auch wie folgt definiert werden

    struct Buecher[1]
    {
        {};
    };

    // Ausgabe der Bücher
    for (int i = 0; i < 2; i++)
    {
        printf("\nBuch %d:\n", i + 1);
        printf("Titel: %s\n", ptr[i].name);
        printf("Kosten: %d Euro\n", ptr[i].kosten);
        printf("Autor: %s\n", ptr[i].autor.name_author);

        // Prüfen, welches Union-Feld gerade aktiv ist
        if (ptr[i].flag_age)
        {
            printf("Alter: %d Jahre\n", ptr[i].info.alter);
        }
        else
        {
            printf("Geburtstag: %d\n", ptr[i].info.geburtstag);
        }
    }

    // Speicher freigeben
    free(ptr);
    return EXIT_SUCCESS;
}
