#include <string>
#include <iostream>
using namespace std;

// Klasse Student
class Student {
private:
    string _name;
    string _first_name;

public:
    Student(string name, string first_name) {
        _name = name;
        _first_name = first_name;
        cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << endl;
    }

    ~Student() {
        cout << "Destruktor Student: " << _first_name << " " << _name << endl;
    }

    string getName() const { return _name; }
    string getFirstName() const { return _first_name; }

    void print() const {
        cout << "print() ohne Parameter; Student: " << _first_name << " " << _name << endl;
    }

    void print(bool newline) const {
        cout << "print() mit Parameter; Student: " << _first_name << " " << _name;
        if (newline)
            cout << endl;
    }
};

// Klasse Employee
class Employee {
private:
    string _name;
    string _first_name;

public:
    Employee(string name, string first_name) : _name(name), _first_name(first_name) {
        cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name << endl;
    }

    Employee() : Employee("Mustermann", "Erika") {
        cout << "Standardkonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    Employee(const Student& student) : _name(student.getName()), _first_name(student.getFirstName()) {
        cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << endl;
    }

    ~Employee() {
        cout << "Destruktor Employee: " << _first_name << " " << _name << endl;
    }

    void print() const {
        cout << "print() ohne Parameter; Mitarbeiter: " << _first_name << " " << _name << endl;
    }

    void print(bool newline) const {
        cout << "print() mit Parameter; Mitarbeiter: " << _first_name << " " << _name;
        if (newline)
            cout << endl;
    }
};

int main(int argc, char *argv[]) {
    Student stud_mustermann("Mustermann", "Max");
    Employee empl_mustermann(stud_mustermann);
    Employee mit_default;
    stud_mustermann.print();
    stud_mustermann.print(true);
    empl_mustermann.print();
    mit_default.print();
    Student *p_stud_mustermann = nullptr;
    cout << "Block wird betreten" << endl;
    {
        p_stud_mustermann = new Student("Mustermann", "Markus");
        p_stud_mustermann->print(true);
    }
    cout << "Block wurde verlassen" << endl;
    delete p_stud_mustermann;
    return 0;
}