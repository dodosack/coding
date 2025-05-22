#include <iostream>
#include <string>
using namespace std;

// Funktion mit möglicher Ausnahme
double divide(double x1, double x2) {
    if (x2 == 0.0)
        throw string("Fehler: Division durch 0!"); // string-Objekt wird geworfen

    return x1 / x2;
}

int main() {

    try {
        double result = divide(10, 0); // führt zu Fehler
        cout << "Ergebnis: " << result << endl;
    } catch (string& e) { // String wird hier "gefangen"// w
        // wichtig wegen vererbung mit & arbeiten
        cout << "Ausnahme: " << e << endl;
    } catch (...) {
        cout << "Exception aufgetreten" << endl;
    }


    return 0;
}
