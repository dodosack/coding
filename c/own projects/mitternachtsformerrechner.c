#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2;

    // Eingabe der Koeffizienten a, b und c
    printf("Geben Sie die Koeffizienten a, b und c ein (mit Leerzeichen getrennt): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // Überprüfung, ob a gleich null ist
    if (a == 0) {
        printf("Dies ist keine quadratische Gleichung (a darf nicht 0 sein).\n");
        return 1;
    }

    // Berechnung der Diskriminante
    discriminant = b * b - 4 * a * c;

    // Diskriminante überprüfen, um die Art der Wurzeln zu bestimmen
    if (discriminant > 0) {
        // Zwei reale und unterschiedliche Wurzeln
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Die Gleichung hat zwei verschiedene reelle Lösungen: %.2lf und %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        // Eine reale doppelte Wurzel
        root1 = -b / (2 * a);
        printf("Die Gleichung hat eine doppelte reelle Lösung: %.2lf\n", root1);
    } else {
        // Komplexe Wurzeln
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        printf("Die Gleichung hat zwei komplexe Lösungen: %.2lf + %.2lfi und %.2lf - %.2lfi\n",
               realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
