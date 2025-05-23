// Themen:
// Stringformatierung

// Ihre Aufgabe:
// Um die Ausgaben über einen Standard-Stream zu formatieren, stehen eine Reihe von Manipulatoren zur Verfügung (siehe die Folien aus der Vorlesung). Während die meisten Manipulatoren in der Bibliothek iostream enthalten sind, benötigen die Manipulatoren setprecision, setw und setfill die Bibliothek iomanip. Genaue Beschreibungen der Manipulatoren sowie Beispiele finden Sie unter der generell hilfreichen Webadresse http://www.cplusplus.com/reference. Ergänzen Sie das untenstehende Programm an den Stellen /xxx/, so dass es die nachfolgende Ausgabe erzeugt:

//  Nr Oct  Hex String  Fixed     Scientific
//   1  01  0x1 **+++++ +   1.234  1.234E+00
//   2  02  0x2 ***++++ -   2.468 -2.468E+00
//   3  03  0x3 ****+++ +   4.936  4.936E+00
//   4  04  0x4 *****++ -   9.872 -9.872E+00
//   5  05  0x5 *++++++ +  19.744  1.974E+01
//   6  06  0x6 **+++++ -  39.488 -3.949E+01
//   7  07  0x7 ***++++ +  78.976  7.898E+01
//   8 010  0x8 ****+++ - 157.952 -1.580E+02
//   9 011  0x9 *****++ + 315.904  3.159E+02
//  10 012  0xa *++++++ - 631.808 -6.318E+02


// #include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
// #include <sstream>
#include <string>



using namespace std;

int main(int argc, char* argv[]) {
    double d = 1.234;
    cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
    for (int k = 1; k < 11; k++) {
        cout << right<< noshowpos<<std::dec << setw(3) << k; // normal lassen aber man muss auf
        cout << std::setw(4) << nouppercase<< std::oct << std::showbase << right << k;
        cout << std::hex << setw(5) << k << " ";
        cout << setw(7) << left << setfill('+') << string(k % 5 + 1, '*') << " ";
        
        cout << setw(9) <<setfill(' ')<<fixed<< internal<< setprecision(3)<< showpos<<  d;
        cout << noshowpos<<uppercase<< right<<scientific<<setw(11) << d;
        d = d * -2;

        cout << endl;
    }
    return 0;
}
