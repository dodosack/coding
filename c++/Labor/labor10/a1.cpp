// Themen:
// Exception Handling, Polymorphie

// Ihre Aufgabe:
// a) Leiten Sie von der Standardexceptionklasse exception eine eigene Klasse MyException ab.

// Schreiben Sie einen parametrisierten Konstruktor,
// der in seperaten Parametern den Dateinamen und die Zeilennummer entgegegennimmt,
// in der eine Ausnahme auftritt.
//
// Zusätzlich soll ein dritter Parameter übergeben werden können, der den Namen bzw. eine Beschreibung der Ausnahme enthält.

// Um die Zeile und den Dateinamen zu ermitteln sollen die Präprozessormakros __LINE__ und __FILE__ im Aufruf des Konstruktors genutzt werden.
// Stimmt die durch das Makro __LINE__ zurückgegebene Zeilennummer nicht mit der erwarteten überein,
// kann entsprechen hinzuaddiert / substrahiert werden, z.B.: throw MyException(__FILE__, __LINE__ + 7 , "Zooname zu kurz");

// Überschreiben sie zusätzlich die Methode what() der Standardexception,
// die eine Beschreibung des Fehlers - bestehend aus der Angabe der Datei, der Zeile und des Namens des Fehlers - zurückgibt.

// b) Ergänzen Sie den Programmcode an den gekennzeichneten Stellen (//HIER).



// #include <cstdio>
#include <exception>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

// Eigene Exceptionklasse "MyException"
// abgeleitet von Exception
class MyException : public exception {
    int    _line;
    string _filename;
    string _exceptionname;
    string _fullMessage; // wichtig: speichern für Rückgabe

  public:
    MyException(int line, const char* file, string exceptionname = "")
        : _line(line), _filename(file), _exceptionname(exceptionname) {
        // vollständige Fehlermeldung zusammensetzen
        _fullMessage = "Fehler " + _exceptionname + " aufgetreten"
                                                    " in Datei " +
                       _filename +
                       ", Zeile: " + to_string(_line+28 ) + ".";
    }

    const char* what() const noexcept override {
        return _fullMessage.c_str(); // wichtig: Speicher bleibt gültig
    }
};


// Eigene Exceptionklasse "ElefantMeetsMouse"
// abgeleitet von MyException
class ElefantMeetsMouse : public MyException {

    // public nicht vergesen zum 1o000000 mal

  public:
    ElefantMeetsMouse(int line, const char* file) : MyException(line - 11, file, "'Elefant trifft auf Maus'") {};
};

// Klasse der Tiere
class Animal {
    // Name des Tiers
    string _name;

  public:
    // Konstruktor
    Animal() {
        cout << "Bitte Namen des Tieres eingeben: ";
        cin >> _name;
    };
    // virtuelle print-Funktion
    virtual void print(bool nl) const { // wieso virtual??
        cout << _name;
        if (nl) {
            cout << endl;
        }
    }
    virtual Animal* clone() const = 0;
};

// Klasse "Elefant"
// abgeleitet von Animal
class Elefant : public Animal {
    Animal* clone() const override {
        return new Elefant(*this); // merken wiewso man pointer zuruückgeben muss
    }
};

// Klasse "Tiger"
// abgeleitet von Animal
class Tiger : public Animal {
    // HIER

    Animal* clone() const override {
        return new Tiger(*this);
    }
};

// Klasse "Mouse"
// abgeleitet von Animal
class Mouse : public Animal {
    Animal* clone() const override {
        return new Mouse(*this);
    }
};

class Zoo {
    // Name des Zoos
    string _name;
    // Die Tiere werden in einem Vektor gespeichert
    vector<Animal*> _animals;

  public:
    // Konstruktor
    Zoo() {
        // Name zuweisen
        cout << "Bitte Name des Zoos eingeben: ";
        cin >> _name;
        // Wenn der String kuerzer als 4 Zeichen ist,
        // dann MyException werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        // HIER
        if (_name.length() < 4) {
            throw MyException(__LINE__ , __FILE__, "'Zooname zu kurz'");
        }

        // Ansonsten, den 5. Buchstaben des Namens gross machen
        _name.at(4) = toupper(_name.at(4));
    }

    // Ein Tier dem Zoo hinzufuegen
    void add_animal(const Animal& animal) {
        // Wenn ein Elefant nach einer Maus eingefuegt wird, oder anders herum
        // dann Ausnahme werfen
        // Nutzen Sie die Praeprozessormakros __LINE__ und __FILE__
        // HIER


        // wir haben Animals als vector und pointer gespeichert deswegen wissen wir nur das wir animals haben aber nicht welche genau
        // mit dynamic cast bekommt man wenn man die versucht zu pointern zu machen

        if (!_animals.empty()) {
            Animal* last_potential_mouse    = dynamic_cast<Mouse*>(_animals.back()); // wichtig mouse als pointer und gibt nullptr zuruck wenn keine mouse
            Animal* last_potential_elephant = dynamic_cast<Elefant*>(_animals.back());


            //            Animal* nichtKonstant = const_cast<Animal*>(&animal); geht auch aber unsauber weil aus cosnt nicht const wird

            const Animal* current_potential_elephant = dynamic_cast<const Elefant*>(&animal); // wichtig das man const beibehält beim casten und typ und die referenz ncit vergessen
            const Animal* current_potential_mouse    = dynamic_cast<const Mouse*>(&animal);

            if ((last_potential_elephant && current_potential_mouse) || (last_potential_mouse && current_potential_elephant)) {

                throw ElefantMeetsMouse(__LINE__, __FILE__);
            }



                // KEIN ELSE SONST TUT ER DANACH NCIHT EINLESEN DU DUMMKOPF!!!!
        } //else {_animals.push_back(animal.clone()); }

_animals.push_back(animal.clone());


        // sonst Tier hinzufuegen
        // HIER
    }
    // Alle Zootiere ausgeben
    void print() const {                                // const weil diese funkrion die tiere nifht verändern soll
        for (const Animal* current_animal : _animals) { // tiere soll nciht verändert werden
            current_animal->print(true);
        }
        // cout << endl;
    }
};

int main(int argc, char* argv[]) {
    char   choice;
    string name;

    // Ausnahmepruefung aktivieren
    // HIER
    try {

        Zoo zoo;
        do {
            cout << endl
                 << "Bitte Tierart auswaehlen:" << endl;
            cout << "1 = Elefant" << endl;
            cout << "2 = Tiger" << endl;
            cout << "3 = Maus" << endl;
            cout << "e = Ende mit Eingabe" << endl;
            cout << "Eingabe: ";
            cin >> choice;
            switch (choice) {
            case '1': {
                Elefant elefant = Elefant();
                zoo.add_animal(elefant);
                break;
            }
            case '2': {
                Tiger tiger = Tiger();
                zoo.add_animal(tiger);
                break;
            }
            case '3': {
                Mouse mouse = Mouse();
                zoo.add_animal(mouse);
                break;
            }
            case 'e':
                break;
            default:
                cout << "Fehlerhafte Eingabe!" << endl;
                 return 1; // Programm beenden bei fehlerhafter Eingabe
            }

            cout << endl;
            zoo.print();
        } while (choice != 'e');
    }

    // Ausnahmen auffangen
    // Speziellste Ausnahme auffangen und ausgeben

    catch (ElefantMeetsMouse& e) {
        cout << e.what() << endl;


    } catch (MyException& e) {// const machen damit die referenz nciht veröndert wird 
        cout<< e.what()<<endl;

    } catch (const exception& e) {//wichtig das wir mit referenz arbeiten 
          cout << "Standardausnahme: " << e.what() << endl;
    } catch (const string e) {
          cout << "String Exception: " << e << endl; // wichtig e weil es bereits ein string ist ein anonymes objekt
    } catch (...) {
         cout << "Unbekannte Ausnahme aufgetreten." << endl;
        }
        // MyException auffangen und ausgeben
        // HIER


        // Alle anderen Standardausnahmen auffangen und ausgeben
        // HIER


        // Alle Strings auffangen und ausgeben
        // HIER


        // Alle anderen Ausnahmen auffangen
        // HIER


    return 0;
}
