#include <iostream>
using namespace std;

class Beispiel {
private:
    static int s_static_var;
    int instance_var;

public:
    Beispiel(int val) : instance_var(val) {}

    // Statische Methode
    static void staticMethod() {
        cout << "Statische Variable: " << s_static_var << endl;
    }

    // Instanzmethode
    void instanceMethod() {
        cout << "Instanzvariable: " << instance_var << endl;
        cout << "Statische Variable: " << s_static_var << endl;
    }

    // Freundfunktion
    friend void friendFunction(Beispiel& obj);
};

int Beispiel::s_static_var = 42;

// Freundfunktion
void friendFunction(Beispiel& obj) {
    cout << "Freundfunktion Zugriff auf Instanzvariable: " << obj.instance_var << endl;
    cout << "Freundfunktion Zugriff auf statische Variable: " << Beispiel::s_static_var << endl;
}

int main() {
    Beispiel obj(10);

    Beispiel::staticMethod(); // Zugriff auf statische Variable
    obj.instanceMethod(); // Zugriff auf beide Variablen
    friendFunction(obj); // Zugriff auf beide Variablen

    return 0;
}