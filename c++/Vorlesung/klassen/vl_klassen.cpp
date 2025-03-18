#include <iostream>
#include <string>
using namespace std;


class Person {
    string _name;

  public:
    void set_name(string name) {
        _name = name;
    }
    string get_name() {
        return _name;
    }
    void print() {
        std::cout << "Name: " << _name << std::endl;
    }
};

int main() {

    Person p_1;
    p_1.set_name("Adam");
    std ::cout << p_1.get_name() << std::endl;
p_1.print();

    return 0;
}