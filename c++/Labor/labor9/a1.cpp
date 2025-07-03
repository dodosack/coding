// Themen:
// Polymorphismus, abstract classes

// Ihre Aufgabe:
// Schreiben Sie die abstrakte Basisklasse 'Meal' mit den Methoden 'add_topping' und 'prepare'.
// Implementieren sie die Klassen Pizza und Burger, sodass das vorhandene Programmfragment kompiliert werden und mittels der Zeile *[1] folgendes auf der Konsole ausgegeben werden kann:

// Pizza Mista. Pizzaboden, belegt mit:
// - Salami
// - Pilzen
// Pizza Hawaii. Pizzaboden, belegt mit:
// - Schinken
// - Ananas
// Hamburger. Brötchen mit:
// - Hackfleisch
// Cheesburger. Brötchen mit:
// - Hackfleisch
// - Käse
// Nutzen Sie die Vererbung von Instanzvariablen und Instanzmethoden entsprechend.

#include <array>
#include <iostream>
#include <string>

using namespace std;

// abstrakte klasse meal
class Meal {
  protected:
    array<string, 5> _belegung;
    unsigned int          count = 0;
    string                _name;

  public:               // muss public sein
    virtual ~Meal() {}; // virtuellen desttuktor wichtig bro
    Meal(string s) : _name(s) {};


    virtual void add_topping(std::string s) { // muss virtual sein damit wir die in der abgeleiteenden klasse nutzen können
        if (count < _belegung.size()) {
            _belegung.at(count) = s;
            count++;
        } else {
            cout << "too many ingredients" << endl;
        }
    }
    virtual void prepare() = 0; // das könnte  polymorph genutz werde
};




class Pizza : public Meal {
  public:
    Pizza(string s) : Meal(s) {};

    void prepare() override {
        cout << "Pizza " << _name << ". Pizzaboden, belegt mit:" << endl;
        for (unsigned int i = 0; i < count; ++i) {
            cout << "- " << _belegung[i] << endl;
        }
    };
};


class Burger : public Meal {
  public:
    Burger(string s) : Meal(s) {};
    void prepare() override {

        cout << _name << ". Brötchen mit:" << endl;
        for (unsigned int i = 0; i < count; ++i) {
            cout << "- " << _belegung[i] << endl;
        }
    };
};




int main(int argc, char* argv[]) {
    Pizza* mista = new Pizza("Mista");
    mista->add_topping("Salami");
    mista->add_topping("Pilzen");
    Meal* hawaii = new Pizza("Hawaii");
    hawaii->add_topping("Schinken");
    hawaii->add_topping("Ananas");
    Burger* hamburger = new Burger("Hamburger");
    hamburger->add_topping("Hackfleisch");
    Meal* cheesburger = new Burger("Cheesburger");
    cheesburger->add_topping("Hackfleisch");
    cheesburger->add_topping("Käse");
    array<Meal*, 4> menu = {mista, hawaii, hamburger, cheesburger};
    for (Meal* g : menu) {
        g->prepare(); //*[1]
    }
    return 0;
}
