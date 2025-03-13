#include <stdio.h>

int main() {
    int index = 0;
    float summe = 0.0;
    float zwischen_summe = 0.0;

    for (int i = 0; i < 10; i++) {
        
        
        // Überprüfen, ob `scanf` erfolgreich ist
        if (scanf("%f", &zwischen_summe) != 1) {
            
            break;  // Beendet die Schleife, wenn keine gültige Eingabe erfolgt
        }

        // Bereichsprüfung für die Eingabe
        if (zwischen_summe < 1.00 || zwischen_summe > 6.00) {
           
            break;  // Beendet die Schleife, wenn die Zahl nicht im Bereich 1.00 bis 6.00 liegt
        } else {
            summe += zwischen_summe;
            index++;
        }
    }

    // Verhindern von Division durch null
    if (index > 0) {
        float durchschnitt = summe / index;
        printf("Durchschnitt (N=%d): %.2f\n", index, durchschnitt);
    } else {
       
 printf("Durchschnitt (N=0): 0.00\n");
    }
    return 0;
                    }
