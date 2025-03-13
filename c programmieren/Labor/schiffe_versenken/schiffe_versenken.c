#include <stdio.h>
#include <stdbool.h> // fürr bool
#include <string.h>
#include <stdlib.h> //für abs()
#define laenge 11
#define breite 12 // muss eins groesser weil 10 als skalierungszahl

int buchstabe_zu_zahl(char a);

int char_zu_zahl(char a);

int main()
{

    const char abc_array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    const char zahlenarray[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    // int anzahl_schiffe_felder = 14;

    // spielfeld generieren und anzeigen als char  array wegen '.'
    char spielfeld[laenge][breite];

    // alle stellen '.' setzen
    for (int p = 0; p < laenge; p++)
    {
        for (int q = 0; q < breite; q++) // schleife die jede spalte . setzt
        {
            spielfeld[p][q] = '.';
        }
    }

    for (int b = 0; b < 2; b++)
    {

        for (int i = 0; i < laenge; i++)
        {
            spielfeld[i][b] = ' '; // leere ecken links
        }
    }
    /*spielfeld[0][0] = ' '; // leere ecken
    spielfeld[0][1] = ' ';
*/

    for (int i = 0; i < breite - 2; i++) // abcdefghij Reihe
    {
        spielfeld[0][i + 2] = abc_array[i];
    }
    for (int i = 1; i < laenge; i++) // 0 1 2 3 4 reihe
    {
        if (i == laenge - 1)
        {                                     // zehnerzahlen
            spielfeld[i][0] = zahlenarray[1]; // 10 formatiert
            spielfeld[i][1] = zahlenarray[0];
        }
        else
        {
            spielfeld[i][1] = zahlenarray[i];
        }
    }

    // eingabe
    char y_werte1;
    char y_werte2;
    int x_werte1;
    int x_werte2;

    // algorhitmus für die schiffe
    bool beenden = false;
    // Eingabe als string einlesen und erste stelle prüfen
    char koordinaten_eingabe[21][2];

    char eingabe[10]; // genug  puffer mit 10 extra zeichen bzw. schutz vor  buffer overflow
    while (!beenden)  // endlosschleife
    {

        scanf("%9s", eingabe); // begrenzung weil eingabe 10 lang ist

        if (strlen(eingabe) == 1) // wenn mein zeichenkette nur ein 1 zeichen umfasst
        {
            if (eingabe[0] == 'e')
            {

                beenden = true;
                break;
            }
        }

        int y_1 = char_zu_zahl(eingabe[1]);
        int x_1 = buchstabe_zu_zahl(eingabe[0]);

        int y_2 = char_zu_zahl(eingabe[3]);

        int x_2 = buchstabe_zu_zahl(eingabe[4]);
        // selbe Koordinate
        if (y_1 == y_2 && x_1 == x_2)
        {
            spielfeld[y_1][x_1] = '#';
        }
        // vertikal schif zb A1 bis A3 {
        else if (x_1 == x_2 && y_1 != y_2)

        {

            
            for (int i = 0; i <=abs(y_1 - y_2); i++)
            {
                if (y_1 < y_2)
                {
                    int aufzufüllende_y = y_1 + i;
                    spielfeld[aufzufüllende_y][x_1] = '#';
                }
                // wenn y1 grösser sei
               else 
                {
                    int aufzufüllende_y = y_1 - i;
                    spielfeld[aufzufüllende_y][x_1] = '#';
                }
            }
        }

        // horizontal 

        else if (y_1 == y_2  && x_1 != x_2)
        {
            
           
            for (int i = 0; i <=abs(x_1 - x_2); i++)
            {
                if (x_1 < x_2)
                {
                    int aufzufüllende_x = x_1 + i;
                    spielfeld[y_1][aufzufüllende_x] = '#';
                }
                // wenn x1 grösser sei
                else
                {
                    int aufzufüllende_x = x_1 - i;
                    spielfeld[y_1][aufzufüllende_x] = '#';
                }
            }

        }
        
    }

    /*for (; y_werte1 != 'e';)// kann man weglassen
    {

        if ((scanf("%c%d-%c%d", &y_werte1, &x_werte1, &y_werte2, &x_werte2)) == 4) // wenn 4 werte eingescannt werden
        {

            // erfolgreich eingescannt und kann nun weiterverarbeitet werden
            printf("Startpunkt: %c%d, Endpunkt: %c%d\n", y_werte1, x_werte1, y_werte2, x_werte2);
        }

        if (scanf("%c", &eingabe) == 1 && eingabe == 'e')
        {
            break; // schleife wird abgebrochen bzw. einscannen // lieber abbruchbedingung mit break annstatt in der Schleife
        }

        // scanf("%c%d%c%d", &y_werte1, &x_werte1, &y_werte2, &x_werte2);// das hat zur doppelung geführt
    }*/

    // Ausgabe ab hier

    for (int p = 0; p < laenge; p++)
    {
        for (int q = 0; q < breite; q++) // schleife die jede spalte . ausgibt und formatiert
            if (q < 2)
            {

                printf("%c", spielfeld[p][q]); // ersten 2 spalten jeder zeile ohne tab abstand wegen unserer zahlen
                if (q == 1)
                {
                    printf("\t"); // Tab abstand  für optik
                }
            }
            else
            {
                printf("%c\t", spielfeld[p][q]);
            }
    printf("\n\n");
    }
return 0;
}


int buchstabe_zu_zahl(char a)
{
    int rueckgabe;
    rueckgabe = a - 'A' + 2; //  wegen ersten beider spalten verschiebung um 2 nach rechts
    return rueckgabe;
}

int char_zu_zahl(char a)
{

    int rueckgabe;
    rueckgabe = a - '0'; 
    return rueckgabe;
}