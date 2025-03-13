
#include <array>
#include <iostream>

int main() {
    bool flag = false;

    int anzahl;
    std::cout << "Wie viele zahlen moechten sie eingeben?" << std::endl;
    std::cin >> anzahl;
    if (auto i = anzahl; i > 10) {
        flag = true;
    }

    while (flag) {


        std ::cout << "Maximal 10 Zahlen sind zulässig?" << std::endl;
        std::cout << "Nochmal eingeben!" << std::endl;
        std::cin >> anzahl;
        if (auto i = anzahl; i <= 10) {
            flag = false;
            break;
        }
    }

    // Array der groese n erstellen
    std::array<int, 10 > arr;

    for (int i = 0; i < anzahl; i++) {
        std::cout << "Bitte gib dein " << i + 1 << " Element ein" << std::endl;
        std::cin >> arr[i];
    }
    float ergebnis = 0.0;
    for (int i = 0; i < anzahl; i++) {
        ergebnis += arr[i];
    }
    ergebnis = ergebnis / static_cast<double>(anzahl);
    std::cout << "Dein Ergebnis ist " << ergebnis << std::endl;

    return 0;
}