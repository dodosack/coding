// Point.h
class Point {
    float _x, _y; // Private Member

  public:
    Point(float x, float y) : _x(x), _y(y) {}

    // Deklaration der Freundfunktion
    // Sie ist KEINE Member-Methode, sondern eine globale Funktion.
    // Das 'friend'-Keyword gibt ihr Zugriff auf _x und _y.
    friend ostream& operator<<(ostream& s, const Point& p);
};

// Point.cpp (oder auch direkt im .h, wenn die Funktion klein ist und oft includiert wird)
ostream& operator<<(ostream& s, const Point& p) {
    // Hier hat die Funktion Zugriff auf p._x und p._y,
    // obwohl _x und _y private sind.
    return s << "x = " << p._x << ", y = " << p._y;
}