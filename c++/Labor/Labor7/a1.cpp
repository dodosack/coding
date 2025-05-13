// Themen:
// Templates, Bubble Sort

// Ihre Aufgabe:
// Implementieren Sie eine generische Sortierfunktion auf Basis des Bubble-Sort Algorithmus.
// Die Funktion soll dabei ein Array als Eingabeparameter enthalten und das sortierte Array zurückgeben.

// Der Bubble-Sort Algorithmus durchläuft ein Feld / Array in einer Schleife und vergleicht zwei benachbarte Elemente. Sind diese falsch angeordnet, so werden sie vertauscht.
// Ist man am Ende des Feldes / des Arrays angelangt, so beginnt man wieder von vorne.
// Dieser Vorgang wird so lange wiederholt bis das Feld / Array ein Mal durchlaufen wird, ohne dabei ein einzelnes Element auszutauschen.


// #include <algorithm>
#include <array>
#include <iostream>
using namespace std;

const unsigned int length = 10;
// lengt muss intialisert sein sonst dynamisch

// hier die Funktion 'sort' implementieren

// template um gerenrisch
template <typename T>
std::array<T, length> sort(std::array<T, length> ueberegebenes_array) {
    bool flag;
    do {
        flag = false; // ← ganz wichtig: flag vor jeder Runde zurücksetzen
        // Eine Runde Bubble-Sort über alle Nachbarpaare
        for (unsigned int i = 0; i < length - 1; ++i) {
            if (ueberegebenes_array[i] > ueberegebenes_array[i + 1]) {
                // manueller Tausch
                T tmp                      = ueberegebenes_array[i];
                ueberegebenes_array[i]     = ueberegebenes_array[i + 1];
                ueberegebenes_array[i + 1] = tmp;
                flag                       = true; // ← hier wurde getauscht
            }
        }
        // wenn flag immer noch false ist, wurde in dieser Runde nichts getauscht
    } while (flag);

    return ueberegebenes_array; // ← sortiertes Array zurückgeben
}

int main(int argc, char* argv[]) {
    array<int, length> int_container        = {10, 2, 7, 5, 8, 3, 4, 1, 9, 6};
    array<int, length> sorted_int_container = sort(int_container);

    for (size_t i = 0; i < sorted_int_container.size(); i++) {
        cout << i << ": " << sorted_int_container[i] << endl;
    }

    array<char, length> char_container        = {'j', 'm', 'e', 't', 'k', 'o', 'p', 's', 'a', 'f'};
    array<char, length> sorted_char_container = sort(char_container);

    for (size_t i = 0; i < sorted_char_container.size(); i++) {
        cout << i << ": " << sorted_char_container[i] << endl;
    }

    array<string, length> string_container        = {"Im", "Sommer", "ist", "es", "meistens", "heiß", "und", "es", "regnet", "wenig."};
    array<string, length> sorted_string_container = sort(string_container);

    for (size_t i = 0; i < sorted_string_container.size(); i++) {
        cout << i << ": " << sorted_string_container[i] << endl;
    }
}
