#include <iostream>

class Intarrayelement {
    int              _data;
    Intarrayelement* _p_next;

    int get_data() {
        return _data;
    }

  public:
    std::cout << "InrArrEleemt erzeugst.\n";
    Intarrayelement* get_next() {
        return p_next;
    }

    void set_data(int data) {
        _data = data;
        // this get auch
    }



    void set_next(Intarrayelement* next) {


        _p_next = next;
    }
};

class DynIntArray {
    Intarrayelement* _root;

  public:
    void push_back(int data) {
        Intarrayelement* new_element = new Intarrayelement();
        new_element->set_data(data);
        new_element->set_next(nullptr);

        if (_root == nullptr) {
            _root = new_element;

        } else {
            Intarrayelement* temp = _root;
            while (temp->get_next() != nullptr) {
                temp = temp->get_next();
            }
            temp->set_next(new_element);
        }
    };
    int size() {

        int              i    = 0;
        Intarrayelement* temp = _root;
        while (temp != nullptr) {
            temp = temp->get_next();
            i++;
        }
        return i;
    };
    int at(int index) {

        Intarrayelement* temp = _root;
        int              i    = 0;

        while (index != i) {
            temp = temp->get_next();
            i++;
        }
        return temp->set_data();
    };
};

int main() {

    std::cout << "Gleich geht es los" << std::endl;
    DynIntArray int_arr;
    int_arr.push_back;
}