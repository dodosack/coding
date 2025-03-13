//gamerulesyy

#include <stdio.h> ///standard output
#include <stdbool.h> // für bool
#include <string.h>      
#include <stdlib.h>           // für abs()
#define laenge 11 // lieber const int machen weil define veraenderbar ist             // vorsicht beim aendern weil nicht genug zahlen und buchstaben besonders bei 10 nur probleme mrk
#define breite 12             // muss eins groesser sein weil 10 als skalierungszahl
#define eingabe_laenge 10     // vorsicht bei scan f ist das mit 9 eingaben limitiert also nicht aendern
#define skalierungs_laenge 10 // ist ein char array und kein string deswegen muss\0 nicht beachtet werden
#define Max_schiffe 5
#define Max_laenge_schiffe 6

int anzahl_schiffe = 0;

// welches schiff //y koordinate //xkordinate // zustand 0 versenkt 1 intakt
int zustand_schiffe[Max_schiffe][laenge][breite] = {0};
bool schiff_versenkt[Max_schiffe] = {false}; // Array um zu speichern, ob jedes Schiff bereits als versenkt gemeldet wurde

int buchstabe_zu_zahl(char a);
int char_zu_zahl(char a);
void spielfeld_ausgeben(char spielfeld[laenge][breite]); //***braucht keinen  wert weil nichts verändert wird// muss die groesse auch angeben
void schiffe_einscannen(char eingabe[eingabe_laenge], char spielfeld[laenge][breite], bool beenden);
void spielfeld_initialisieren(const char abc_array[skalierungs_laenge], const char zahlen_array[skalierungs_laenge], char spielfeld[laenge][breite]); // muss die arrays auch als const uebergeben
float stats_rechner(int *treffer, int *schuesse);
int main()
{
    const char abc_array[skalierungs_laenge] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    const char zahlen_array[skalierungs_laenge] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char spielfeld[laenge][breite];

    // spielfeld initialisieren und skalieren mit funktion
    spielfeld_initialisieren(abc_array, zahlen_array, spielfeld);

    // Eingabe und Platzieren der Schiffe
    bool beenden = false;
    char eingabe[eingabe_laenge]; // Eingabepuffer
    schiffe_einscannen(eingabe, spielfeld, beenden);

    // Ausgabe des Spielfelds
    printf("\n\n\nDeine Schiffe wurden wie folgt gesetzt!\n\n\n");
    spielfeld_ausgeben(spielfeld); // nur einmal um alle schiffe zu zeigen

    beenden = false;

    // jetzt wird geballert
    printf("\nLos Kamerad! Geben sie uns die Koordinaten für die Bomben\n");
    int treffer = 0;
    int schuesse = 0;

    while (!beenden)
    {
        scanf("%9s", eingabe);
        int x_koordinate = buchstabe_zu_zahl(eingabe[0]);
        int y_koordinate = char_zu_zahl(eingabe[1]);

        // Bedingung zum Abbrechen
        if (strlen(eingabe) == 1 && eingabe[0] == 'x')
        {
            printf("\n\nSpiel beendet!\n\n");
            printf("\n\nDeine Stats sind Treffergenauigkeit:%.2f %% \n\n", stats_rechner(&treffer, &schuesse));
            beenden = true;
            break;
        }
        
        
        else if (spielfeld[y_koordinate][x_koordinate] == 'x') // Bereits getroffene Stellen
        {
            printf("\n\nDas Schiff wurde bereits getroffen!!\n\n");
            printf("Schießen Sie weiter\n\n");
            schuesse++;
        }
        else if (spielfeld[y_koordinate][x_koordinate] == '#')
        {
            spielfeld[y_koordinate][x_koordinate] = 'x'; // Treffer anzeigen
            printf("\n\nVolltreffer Kamerad!\n\n");

            spielfeld_ausgeben(spielfeld);
            printf("\n\nSchießen Sie weiter\n\n");
            schuesse++;
            treffer++;

            // Überprüfen, welches Schiff getroffen wurde
            for (int i = 0; i < anzahl_schiffe; i++)
            {
                if (zustand_schiffe[i][y_koordinate][x_koordinate] == 1)
                {
                    zustand_schiffe[i][y_koordinate][x_koordinate] = 0; // Treffer auf das Schiff markieren

                    // Überprüfen, ob das gesamte Schiff versenkt wurde
                    bool versenkt = true;
                    for (int y = 0; y < laenge; y++)
                    {
                        for (int x = 0; x < breite; x++)
                        {
                            if (zustand_schiffe[i][y][x] == 1)
                            {
                                versenkt = false; // Das Schiff hat noch intakte Teile
                                break;
                            }
                        }
                        if (!versenkt)
                        { // es wird nicht weiter geprüft
                            break;
                        }
                    }

                    // Wenn das Schiff vollständig zerstört wurde und noch nicht als versenkt gemeldet wurde
                    if (versenkt && !schiff_versenkt[i])
                    {
                        printf("\n\nDu hast Schiff Nr. %d versenkt, Kamerad!\n\n", i + 1);
                        schiff_versenkt[i] = true; // Markiere das Schiff als bereits gemeldet
                    }
                }
            }
        }
        // Fehlschuss
        else
        {
            spielfeld[y_koordinate][x_koordinate] = 'O';
            printf("\n\nFehlschuss!!\n\n");
            spielfeld_ausgeben(spielfeld);
            printf("\n\nSchießen Sie weiter\n\n");
            schuesse++;
        }
    }

    return 0;
}

int buchstabe_zu_zahl(char a)
{
    return a - 'A' + 2; // Umwandlung der Buchstaben in Spaltenindex, Verschiebung um 2 nach rechts
}

int char_zu_zahl(char a)
{
    return a - '0'; // Umwandlung der Ziffern in Zeilenindex, damit es mit dem Spielfeld passt
}

void spielfeld_ausgeben(char spielfeld[laenge][breite])
{
    for (int p = 0; p < laenge; p++)
    {
        for (int q = 0; q < breite; q++)
        {
            if (q < 2)
            {
                printf("%c", spielfeld[p][q]);
                if (q == 1)
                {
                    printf("\t"); // Tab Abstand für Optik
                }
            }
            else
            {
                printf("%c\t", spielfeld[p][q]);
            }
        }
        printf("\n\n");
    }
}

void schiffe_einscannen(char eingabe[eingabe_laenge], char spielfeld[laenge][breite], bool beenden)
{
    while (!beenden)
    {
        printf("Geben Sie die Koordinaten des Schiffes ein (z.B. A1-A3, A10-D10, 'e' zum Beenden): ");
        scanf("%9s", eingabe); // Begrenzung der Eingabe

        if (strlen(eingabe) == 1 && eingabe[0] == 'e')
        {
            beenden = true;
            break;
        }

        // Koordinaten verarbeiten
        int x_1, y_1, x_2, y_2;

        // Die erste Koordinate ermitteln
        x_1 = buchstabe_zu_zahl(eingabe[0]);
        if (eingabe[1] == '1' && eingabe[2] == '0') // Zweistellige Zahl (10) für y_1
        {
            y_1 = 10;
        }
        else // Einstellige Zahl für y_1
        {
            y_1 = char_zu_zahl(eingabe[1]);
        }

        // Index des Bindestrichs herausfinden
        int minus_index = (y_1 == 10) ? 3 : 2;

        // Die zweite Koordinate ermitteln
        x_2 = buchstabe_zu_zahl(eingabe[minus_index + 1]);
        if (eingabe[minus_index + 2] == '1' && eingabe[minus_index + 3] == '0') // Zweistellige Zahl (10) für y_2
        {
            y_2 = 10;
        }
        else // Einstellige Zahl für y_2
        {
            y_2 = char_zu_zahl(eingabe[minus_index + 2]);
        }

        //  Selbe Koordinate
        if (x_1 == x_2 && y_1 == y_2)
        {
            spielfeld[y_1][x_1] = '#';
            zustand_schiffe[anzahl_schiffe][y_1][x_1] = 1; // Ein Mini-Schiff
            anzahl_schiffe++;                              // Wegen Speicherung bei 0 beginnen
        }
        // Vertikales Schiff
        else if (x_1 == x_2)
        {
            int schrittweite_y = (y_1 < y_2) ? 1 : -1;
            for (int i = y_1; i != y_2 + schrittweite_y; i += schrittweite_y)
            {
                spielfeld[i][x_1] = '#';
                zustand_schiffe[anzahl_schiffe][i][x_1] = 1;
            }
            anzahl_schiffe++; // Erst jetzt erhöhen
        }
        // Horizontales Schiff
        else if (y_1 == y_2)
        {
            int schrittweite_x = (x_1 < x_2) ? 1 : -1;
            for (int i = x_1; i != x_2 + schrittweite_x; i += schrittweite_x)
            {
                spielfeld[y_1][i] = '#';
                zustand_schiffe[anzahl_schiffe][y_1][i] = 1;
            }
            anzahl_schiffe++;
        }
    }
}

void spielfeld_initialisieren(const char abc_array[skalierungs_laenge], const char zahlen_array[skalierungs_laenge], char spielfeld[laenge][breite])
{
    // Spielfeld generieren und als '.' initialisieren
    for (int p = 0; p < laenge; p++)
    {
        for (int q = 0; q < breite; q++)
        {
            spielfeld[p][q] = '.';
        }
    }

    // Leere Ecken links
    for (int b = 0; b < 2; b++)
    {
        for (int i = 0; i < laenge; i++)
        {
            spielfeld[i][b] = ' ';
        }
    }

    // Alphabetische Überschrift
    for (int i = 0; i < breite - 2; i++)
    {
        spielfeld[0][i + 2] = abc_array[i];
    }

    // Numerische Seitenbeschriftung
    for (int i = 1; i < laenge; i++)
    {
        if (i == laenge - 1)
        {
            spielfeld[i][0] = zahlen_array[1]; // '1' für 10
            spielfeld[i][1] = zahlen_array[0]; // '0' für 10
        }
        else
        {
            spielfeld[i][1] = zahlen_array[i];
        }
    }
}
float stats_rechner(int *treffer, int *schuesse){

    float return_wert = ((float)*treffer)/(*schuesse)*100;
    return return_wert;
}