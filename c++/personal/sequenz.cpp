#include <iostream>

int get_value() {
    return 7;
}

int main() {
    // Variable num wird direkt in der if-Bedingung initialisiert (nur C++17+)
    if (auto num = get_value(); num < 10) {
        std::cout << "Die Zahl ist kleiner als 10." << std::endl;
    } else {
        std::cout << "Die Zahl ist 10 oder größer." << std::endl;
    }
    return 0;
}
