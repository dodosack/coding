#include <iostream>
#include <array>

int main() {
    int anzahl;

    // Benutzer nach der Anzahl fragen
    std::cout << "Wie viele Zahlen moechten Sie eingeben? (max. 10): ";
    std::cin >> anzahl;

    // Sicherstellen, dass der Benutzer eine gültige Anzahl eingibt
    while (anzahl > 10 || anzahl <= 0) {
        std::cout << "Bitte eine Zahl zwischen 1 und 10 eingeben: ";
        std::cin >> anzahl;
    }

    // Array mit fester Größe von 10 erstellen
    std::array<int, 10> zahlen;
    double summe = 0.0;

    // Zahlen einlesen
    for (int i = 0; i < anzahl; i++) {
        std::cout << "Zahl eingeben: ";
        std::cin >> zahlen[i];
        summe += zahlen[i];
    }

    // Zahlen ausgeben
    std::cout << "\nEingegebene Zahlen:\n";
    for (int i = 0; i < anzahl; i++) {
        std::cout << "Zahl[" << i << "]: " << zahlen[i] << '\n';
    }

    // Durchschnitt berechnen und ausgeben
    std::cout << "Durchschnitt: " << (summe / anzahl) << std::endl;

    return 0;
}
