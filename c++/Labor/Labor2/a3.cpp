// Themen:
// Default Parameter

// Ihre Aufgabe:
// Ergänzen Sie das Programmgerippe um eine Funktion print_rectangle, die zwei Parameter entgegennimmt und ein Rechteck auf der Konsole ausgibt. Die Kantenlängen des Rechtecks entsprechen den jeweils übergebenen Parametern. Wird nur ein Parameter übergeben, so soll ein Quadrat ausgegeben werden, dessen Kantenlängen dem übergebenen Parameter entspricht.

// Nutzen sie kein Überladen. Verwenden Sie für die Lösung geeignete Defaultwerte für Parameter.

// Der Aufruf der print_rectangle()-Funktion mit den Werten 2 und 5 führt z.B. zu folgender Ausgabe:

// X X
// X X
// X X
// X X
// X X
// Der Aufruf der print_rectangle()-Funktion mit dem Wert 4 führt z.B. zu folgender Ausgabe:

// X X X X
// X X X X
// X X X X
// X X X X^





#include <iostream>

// funktionsprototypen
void print_rectangle(int x, int y = -1);


int main(int argc, char* argv[]) {
    std::cout << "x = 2, y = 5: " << std::endl;
    print_rectangle(2, 5);

    std::cout << "x = 3, y = 3: " << std::endl;
    print_rectangle(3, 3);

    std::cout << "x = 4: " << std::endl;
    print_rectangle(4);

    return 0;
};

void print_rectangle(int x, int y ) {
    if (y == -1) { // quadrat
        y = x;     // y und x gleich groß
    }
    // else nicht notwendig
    // jetzt zur ausgabe
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << "X "; // gibt zeile aus mit leerzeichen
        }
      std::cout << std::endl; // um neue spalte zu machen bzw in eine neue zeile
    }

    std::cout<< "\n"; // formatierung
};
