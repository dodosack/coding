#include<iostream>
#include<string>
using namespace std;

// ~~class SetElement {~~
template <typename T>
class SetElement {

    // ~~int element;~~
    T element;

    // ~~SetElement* next = nullptr;~~
    SetElement<T>* next = nullptr;

public:

    // ~~SetElement(int elem):element(elem) {}~~
    SetElement(T elem):element(elem) {}

    // ~~int get_element() {~~
    T get_element() {
        return element;
    }

    // ~~SetElement* get_next() {~~
    SetElement<T>* get_next() {
        return next;
    }

    // ~~void set_next(SetElement* elem) {~~
    void set_next(SetElement<T>* elem) {
        next = elem;
    }
};

// ~~class Set {~~
template <typename T>
class Set {

    // ~~SetElement* root = nullptr;~~
    SetElement<T>* root = nullptr;

public:

    // ~~void add_element(int elem) {~~
    void add_element(T elem) {

        // ~~SetElement* new_element = new SetElement(elem);~~
        SetElement<T>* new_element = new SetElement<T>(elem);

        if(root == nullptr) {
            root = new_element;
        } else {
            SetElement<T>* tmp = root;
            while(tmp->get_next() != nullptr) {
                tmp = tmp->get_next();
            }
            tmp->set_next(new_element);
        }
    }

    // ~~bool contains(int elem) {~~
    bool contains(T elem) {

        SetElement<T>* tmp = root;

        while(tmp != nullptr) {
            if(tmp->get_element() == elem) return true;
            tmp = tmp->get_next();
        }

        return false; // unbedingt hinzufügen!
    }
};

int main(int argc, char *argv[])
{
    // ~~Set int_set;~~
    Set<int> int_set;
    int_set.add_element(1);
    int_set.add_element(7);
    int_set.add_element(3);

    if(int_set.contains(3)) cout << "Zahl 3 enthalten" << endl;

    // Beispiel mit anderen Typen
    Set<string> string_set;
    string_set.add_element("Hallo");
    string_set.add_element("Test");

    if(string_set.contains("Test")) cout << "String 'Test' enthalten" << endl;

    return 0;
}
