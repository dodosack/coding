#include <iostream>
using namespace std;

class Beispiel {
  public:
    Beispiel() {
        cout << "Objekt erstellt.\n";
    }

    ~Beispiel() {
        cout << "Objekt zerstört.\n";
    }
};

void funktion() {
    Beispiel lokalesObjekt; // Wird beim Betreten der Funktion erstellt
    cout << "Innerhalb der Funktion.\n";
} // lokalesObjekt wird hier zerstört, wenn die Funktion endet

int main() {
    cout << "Programmstart.\n";

    Beispiel globalesObjekt; // Wird beim Start des Programms erstellt

    cout << "Vor der Funktion.\n";
    funktion(); // Funktion wird aufgerufen
    cout << "Nach der Funktion.\n";

    Beispiel* dynamischesObjekt = new Beispiel(); // Dynamisch erstellt
    cout << "Dynamisches Objekt erstellt.\n";

    delete dynamischesObjekt; // Dynamisches Objekt explizit zerstört
    cout << "Dynamisches Objekt zerstört.\n";

    cout << "Programmende.\n";
    return 0;
} // globalesObjekt wird hier zerstört, wenn das Programm endet