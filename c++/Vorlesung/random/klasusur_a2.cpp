#include <iostream>
using namespace std;


class Fahrzeug {
    bool       _ist_gebucht = false;
    static int _anzahl;  //klassenvariabel immer static
    const int  _id;

  public:
    Fahrzeug(int id) : _id(id) {
        ++_anzahl; // andersrum 
    };
    void buche() {
        _ist_gebucht = true;
    }
    bool ist_gebucht() {
        return _ist_gebucht;
    }
    int get_id() const {
        return _id;
    }
    static int get_anzahl() {
        return _anzahl;
    }
    // operator
    virtual void print() {
        cout << "ID: " << _id << endl;
        cout << "Ist gebucht: " << _ist_gebucht << endl;
        
    }
};

int Fahrzeug::_anzahl = 0;
