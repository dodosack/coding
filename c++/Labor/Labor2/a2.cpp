
// Themen:
// Verkettete Liste, Pointer

// Ihre Aufgabe:
// Ergänzen Sie die Implementierung der Einfach verketteten Liste um die Implementierung der Funktionen: void add_new_tail_element(int id) void print_list()

// Die Ausgabe des Hauptprogramms soll folgendermaßen aussehen:

// 1
// 2
// 9
// 10
// 1
// 9
// 10



#include <iostream>
// #include <string>
using namespace std;

struct ListElement {
    int          id;
    ListElement* p_next;
};

ListElement* p_root = nullptr;

void add_new_head_element(int id) {

    ListElement* p_new_element = new ListElement();
    p_new_element->id          = id;
    p_new_element->p_next      = p_root;
    p_root                     = p_new_element;
}

void add_new_tail_element(int id) {
    // Neues ListenElement erzeugen
    ListElement* p_new = new ListElement();
    p_new->id = id;
    p_new->p_next = nullptr;

    // Wenn die Liste leer ist, wird das neue Element zum Kopf
    if (p_root == nullptr) {
        p_root = p_new;
        return;
    }

    // Ans Ende der Liste navigieren
    ListElement* p_temp = p_root;
    while (p_temp->p_next != nullptr) {
        p_temp = p_temp->p_next;
    }

    // Neues Element anhängen
    p_temp->p_next = p_new;
}
void delete_element(int id) {
    ListElement* p_tmp         = p_root;
    ListElement* p_predecessor = nullptr;

    while (p_tmp != nullptr && p_tmp->id != id) {
        p_predecessor = p_tmp;
        p_tmp         = p_tmp->p_next;
    }
    if (p_tmp != nullptr) {
        if (p_tmp == p_root) {
            p_root = p_tmp->p_next;
        } else {
            p_predecessor->p_next = p_tmp->p_next;
        }
    }
    delete p_tmp;
}

void print_list() {

    // Hier programmieren:
    // Die Liste durchlaufen und jeweils die id des listenElements ausgeben.

    ListElement* p_temp = p_root;
    // std::cout << "Beginn der Liste" << endl;

    while (p_temp != nullptr) {
        std::cout << p_temp->id << std::endl;
        p_temp = p_temp->p_next;
    }
}

int main(int argc, char* argv[]) {
    add_new_tail_element(9);
    add_new_head_element(2);
    add_new_head_element(1);
    add_new_tail_element(10);
    print_list();
    delete_element(2);
    print_list();

    return 0;
};
