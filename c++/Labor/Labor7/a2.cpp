// Themen:
// Komposition, Vektoren

// Ihre Aufgabe:
// Implementieren Sie die Klassen Point und Polygonline (Polygonlinie, Linienzug). Die Objekte der Klasse Polygonline repräsentiert einen Linienzug.
// Ein Linienzug ist durch eine Folge von Punkten defininiert. Die Folge von Punkten wird in Polygonline als ein vector von Punkten realisiert, da wir nicht wissen, wieviele Punkte die Linie haben wird.
// Implementieren Sie die vorgegebenen Konstruktoren und Methoden.

// Die Ausgabe des Hauptprogrammes soll folgendermaßen aussehen:

// Ausgabe 1:
// ||
// |(3, 3)|
// Ausgabe 2:
// |(1, 1) - (2, 2)|
// |(3, 3) - (4, 4) - (5, 5)|
// Ausgabe 3:
// (2.5, 2.5)
// |(1, 1) - (2, 2)|
// |(3, 3) - (4, 4) - (5, 5)|
// Ausgabe 4:
// |(1, 1) - (2, 2) - (3, 3) - (4, 4) - (5, 5)|
// |(3, 3) - (4, 4) - (5, 5)|
// Ausgabe 5:
// |(1, 1.5) - (2, 2.5) - (3, 3.5) - (4, 4.5) - (5, 5.5)|
// |(3, 3) - (4, 4) - (5, 5)|



#include <iostream>
#include <vector>
using namespace std;

class Point {
    double _x;
    double _y;

  public:
    // Konstruktor mit Parametern
    Point(double x = 0.0, double y = 0.0) : _x(x), _y(y) {};
    // Verschiebt einen Punkt
    void move(double dx, double dy) {
        _x += dx;
        _y += dy;
    };
    // gibt den Punkt auf der Konsole aus
    void print(bool nl = true) {
        cout << "(" << _x << ", " << _y << ")";

        if (nl) {
            cout << endl;
        }
    };
};

// Implementierung Konstruktor

// Implementierung Methoden

class Polygonline {
    vector<Point> _points;

  public:
    // Konstruktor
    Polygonline();
    // Konstruktor mit Parameter
    Polygonline(Point& p);
    // gibt die Elemente des Polygons auf der Konsole aus
    void print(bool nl = true);
    // Hängt einen Punkt hinten an
    Polygonline& add_point(Point p);
    // Hängt einen zusätzlichen Polygon hinten an
    void append_polygonline(Polygonline& pl);
    // Verschiebt den gesamten Polygon
    void move(double dx, double dy);
};

// Implementierung Konstruktor
Polygonline::Polygonline() {};
// brauche ich nciht wird extra machen

Polygonline::Polygonline(Point& p) {
    _points.push_back(p);
}


// Implementierung Methoden

Polygonline& Polygonline::add_point(Point p) {
    this->_points.push_back(p);
    return *this; // modifizierters neues objelt alrefernez zuruckgeben
};

void Polygonline::append_polygonline(Polygonline& p1) {
    _points.insert(_points.end(), p1._points.begin(), p1._points.end());
}


void Polygonline::move(double dx, double dy) {

    for (size_t i = 0; i < _points.size(); i++) {
        _points.at(i).move( dx,  dy);
    }
};
void Polygonline::print(bool nl) {
    cout << "|";
                // int i geht nicht weil es beim vergleich zu problemem kommt bro
    for (vector<Point>::size_type i = 0; i < _points.size(); ++i) {
        _points[i].print(false);// aufruf der print von point 
        if (i < _points.size() - 1) {//damit am ende kein - steht
            cout << " - ";
        }
    }

    cout << "|";

    if (nl) {
        cout << endl;
    }
}



int main(int argc, char* argv[]) {
    Point       p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
    Polygonline l1;
    Polygonline l2(p3);
    cout << "Ausgabe 1:" << endl;
    l1.print();
    l2.print();
    l1.add_point(p1).add_point(p2);
    // erster teil ist wegen rückgabewert ein objekt un dadurch kann man .add_point machen
    
    l2.add_point(p4).add_point(p5);
    // doppeltes anhängen wegen rückgabewert

    cout << "Ausgabe 2:" << endl;
    l1.print();
    l2.print();
    p2.move(0.5, 0.5);
    cout << "Ausgabe 3:" << endl;
    p2.print();
    l1.print();
    l2.print();
    l1.append_polygonline(l2);
    cout << "Ausgabe 4:" << endl;
    l1.print();
    l2.print();
    l1.move(0, 0.5);
    cout << "Ausgabe 5:" << endl;
    l1.print();
    l2.print();
    return 0;
}
