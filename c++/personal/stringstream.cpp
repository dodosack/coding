#include <iostream>
#include <sstream>
// #include <string>
using namespace std;

int main() {
    stringstream ss;
    // stringstream funktioniert wie iien objekt speicehr alles als obkekt in eine lk datei und wir müssen es in ein string umwandeln

    ss << 123 << " Hallo";
    
    string inhalt = ss.str(); // hier wird der Inhalt gelesen2
    cout << inhalt << endl;   // Ausgabe: 123 Hallo
    
    
}