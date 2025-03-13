#include <stdio.h>

int stringlength(char string[]) {
    int length;
    for (length = 0; string[length] != '\0'; length++) {
        // Die Schleife läuft, bis das Nullzeichen '\0' erreicht ist
    }
    return length;
}

int main() {
    char test[] = "Hochschule Esslingen";
    printf("%s hat %d Zeichen", test, stringlength(test));
    return 0;
}
