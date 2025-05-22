#include <exception> // für std::exception
#include <iostream>

using namespace std;

// ✅ Eigene Ausnahme-Klasse, abgeleitet von std::exception
class MeineException : public std::exception {
  public:
    // Überschreibt die what()-Methode
    const char* what() const noexcept override {
        return "Eigene Ausnahme: Etwas ist schiefgelaufen!";
    }
};

// ✅ Funktion, die absichtlich eine Exception wirft
void kritisch() {
    throw MeineException(); // Wirf unsere eigene Exception
}

// ✅ Hauptfunktion
int main() {
    try {
        kritisch(); // Versuch, eine kritische Funktion auszuführen
    } catch (const MeineException& e) {
        // Spezifischer Catch-Block für unsere eigene Exception
        cout << "Fehler abgefangen: " << e.what() << endl;
    } catch (const std::exception& e) {
        // Allgemeiner Catch-Block für alle std::exception-Typen
        cout << "Standard-Fehler: " << e.what() << endl;
    } catch (...) {
        // Catch-Block für alles andere (z. B. int, string, etc.)
        cout << "Unbekannter Fehler!" << endl;
    }

    cout << "Programm läuft weiter." << endl;
    return 0;
}

