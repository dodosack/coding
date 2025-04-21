#include <iostream>
#include "Manager.h"
#include "Worker.h"

using namespace std;

int main() {
    Manager m("Gerd", "Mayer", 1000.00);
    m.print();
    cout << "Gehalt: " << m.get_income() << endl << endl;

    Worker w("Nashwan", "Adam", 15.00, 40);
    w.print();
    cout << "Lohn: " << w.get_income() << endl;

    return 0;
}
