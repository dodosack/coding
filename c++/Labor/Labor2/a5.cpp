// Themen:
// Klassen, Attribute, Methoden

// Ihre Aufgabe:
// Ergänzen Sie das Programmgerippe um die Klasse Punkt mit den Koordinaten x und y vom Typ double. Schreiben sie für die Klasse Punkt die Methode print() sowie getter- und setter-Methoden für die Koordinaten x und y, sodass das Hauptprogramm folgende Ausgabe erzeugt:

// print-Methode:
// X = 1
// Y = 10.5
// X ohne print(): 5
// Y ohne print(): 10.5





#include <iostream>

using namespace std;

// hier die Klasse Punkt implementieren
class Point {

    double _x, _y;

  public:
    // methoden
    void print() {
        std ::cout <<"print-Methode: "<<std::endl;
        std::cout << "X = " << _x << std::endl;
        std::cout << "Y = " << _y << std::endl;
    };
    void set_x(double x) {
        _x = x;
    };
    void set_y(double y) {
        _y = y;
    };
    double get_x() {
        return _x;
    };
    double get_y() {
        return _y;
    };
};

int main(int argc, char* argv[]) {
    Point p;
    p.set_x(1);
    p.set_y(10.5);
    p.print();
    p.set_x(5);
    cout << "X ohne print(): " << p.get_x() << endl;
    cout << "Y ohne print(): " << p.get_y() << endl;
    return 0;
}
