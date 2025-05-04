// Themen:
// Initialisierung von Objekten, Konstruktoren, Destruktoren

// Ihre Aufgabe:
// Schreiben Sie eine Klasse 'Student' mit den Attributen '_name' und '_first_name' vom Typ String. Schützen Sie die Attribute gegen Zugriff von außen. Die folgenden Methoden implementieren sie außerhalb der Klasse: Die Klasse soll einen parametrisierten Konstruktor haben, der Name und Vorname entgegennimmt und die beiden Attribute '_name' und '_first_name' entsprechend belegt. Verwenden Sie hierzu keine Initialisierungsliste. Schreiben sie get-Methoden für beide Attribute und einen Destruktor. Schreiben Sie zwei print-Methoden, beide ohne Rückgabewert. Eine der beiden Methoden nimmt eine boolsche Variable entgegen, mit der gesteuert werden kann, ob am Ende der Zeile ein Zeilenumbruch erfolgen soll oder nicht. In der anderen Methode erfolgt immer ein Zeilenumbruch.

// Schreiben Sie eine Klasse 'Employee', ebenfalls mit den Attributen '_name' und '_first_name' vom Typ String. Schützen Sie auch diese Attribute gegen einen Zugriff von außen. Die folgenden Methoden implementieren sie innerhalb der Klasse: Die Klasse soll einen parametrisierten Konstruktor haben, der Name und Vorname entgegennimmt und die beiden Attribute '_name' und '_first_name' entsprechend belegt. Verwenden Sie hierzu die Initialisierungsliste. Die Klasse soll einen Standardkonstruktor haben, die den Konstruktoraufruf an den parametrisierten Konstruktor delegiert. Nutzen Sie auch hier die Initialisierungsliste und setzen sie die Werte 'Mustermann' für Name und 'Erika' für Vorname. Schreiben Sie zusätzlich einen Konvertierkonstruktor, der einen Studenten entgegenimmt und die enthaltenen Daten zur Initialisierung von Name und Vorname verwendet. Schreiben sie einen Destruktor. Schreiben Sie auch für diese Klasse zwei print-Methoden, ebenfalls beide ohne Rückgabewert. Eine der beiden Methoden nimmt eine boolsche Variable entgegen, mit der gesteuert werden kann, ob am Ende der Zeile ein Zeilenumbruch erfolgen soll oder nicht. In der anderen Methode erfolgt immer ein Zeilenumbruch.

// Die Methoden der beiden Klassen sollen jeweils eine Ausgabe enthalten, die zur Ausgabe der vorgegebenen main-Methode passt. Die Ausgabe ist unten angegeben.

// Ausgabe:

// Parametrisierter Konstruktor Student: Max Mustermann
// Konvertierungskonstruktor Employee: Max Mustermann
// Parametrisierter Konstruktor Employee: Erika Mustermann
// Standardkonstruktor Employee: Erika Mustermann
// print() ohne Parameter; Student: Max Mustermann
// print() mit Parameter; Student: Max Mustermann
// print() ohne Parameter; Mitarbeiter: Max Mustermann
// print() ohne Parameter; Mitarbeiter: Erika Mustermann
// Block wird betreten
// Parametrisierter Konstruktor Student: Markus Mustermann
// print() mit Parameter; Student: Markus Mustermann
// Block wurde verlassen
// Destruktor Student: Markus Mustermann
// Destruktor Employee: Erika Mustermann
// Destruktor Employee: Max Mustermann
// Destruktor Student: Max Mustermann


#include <iostream>
#include <string>

class Student {
    // private
    std::string _name;
    std::string _first_name;

  public:
    // Konstruktor
    Student(std::string first_name, std::string name) : _name{name}, _first_name{first_name}
// scope bereich deswegen initialiserungsliste 
                                                        {
        std::cout << "Parametrisierter Konstruktor Student: " << _first_name << " " << _name << "\n";
    };

    std::string get_Name() const {
        return _name;
    };
    std::string get_First_Name() const { return _first_name; }; // hier const

    // Destruktor
    ~Student() {
        std::cout << "Destruktor Student: " << _first_name << " " << _name << "\n";
    }

    void print_bool(bool flag) {
        std::cout << "print() mit Parameter; Student: " << _first_name << " " << _name;
        if (flag) {
            std::cout << std::endl;
        }
    };

    void print() {
        std::cout << "print() ohne Parameter; Student: " << _first_name << " " << _name << std::endl;
    }
};

class Employee {
    // private
    std::string _name;
    std::string _first_name;

  public:
    // Konstruktor
    Employee(std::string name = "Mustermann", std::string first_name = "Erika") : _name{name}, _first_name{first_name} {
        if (name == "Mustermann" && first_name == "Erika") {
            std::cout << "Standardkonstruktor Employee: " << _first_name << " " << _name;
        } else {
            std::cout << "Parametrisierter Konstruktor Employee: " << _first_name << " " << _name;
        }
        std::cout << std::endl;
    };

    // // Konvertierungskonstruktor
    // Employee(Student student) { // FEHLER: Das Student-Objekt wird per Wert übergeben, was eine unnötige Kopie erzeugt.
    //     _first_name = student.get_First_Name();
    //     _name       = student.get_Name();
    //     std::cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << std::endl;
    // }

    // KORREKTUR:
    Employee(const Student& student) {
        _first_name = student.get_First_Name();
        _name       = student.get_Name();
        std::cout << "Konvertierungskonstruktor Employee: " << _first_name << " " << _name << std::endl;
    }
    // fehler weil geter methoden nicht cosnst waren



    void print_bool(bool flag) {
        std::cout << "print() mit Parameter; Employee: " << _first_name << " " << _name;
        if (flag) {
            std::cout << std::endl;
        }
    };

    void print() {
        std::cout << "print() ohne Parameter; Employee: " << _first_name << " " << _name << std::endl;
    }

    ~Employee() {
        std::cout << "Destruktor Employee: " << _first_name << " " << _name << "\n";
    }
};

int main() {
    Student  s1("Max", "Mustermann");
    Employee e1(s1); // Hier wird der Konvertierungskonstruktor aufgerufen
    Employee e2;     // Standardkonstruktor
    s1.print();
    s1.print_bool(true);
    e1.print();
    e2.print();
    {
        std::cout << "Block wird betreten" << std::endl;
        Student s2("Markus", "Mustermann");
        s2.print_bool(true);
        std::cout << "Block wurde verlassen" << std::endl;
    } // Destruktor wird hier automatisch aufgerufen
}