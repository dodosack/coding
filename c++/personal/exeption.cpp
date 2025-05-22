#include <iostream>
using namespace std;

// Eigene Fehlerklasse
class MyException {
    double _x1, _x2;

  public:
    MyException(double x1, double x2) : _x1(x1), _x2(x2) {}

    void print() const {
        cout << "Fehler: Division durch 0 bei Werten x1 = " << _x1
             << " und x2 = " << _x2 << endl;
    }
};

double f(double x1, double x2) {
    if (x2 == 0.0) {

        throw MyException(x1, x2); // wirf die Ausnahme
    }
    return x1 / x2;
}

int main() {
    double x = 10;
    double y = 0;

    try {

        double result = f(x, y); // Versuch, f auszuführen
        cout << "Ergebnis: " << result << endl;
    } catch (MyException& e) { // fängt die Ausnahme ab
        e.print();             // Zeigt Fehlerdetails an
    }

    return 0;
}
