#include <iostream>
using namespace std;

// 🔶 Abstrakte Basisklasse
class Pizza {
  public:
    // Fester Ablauf für jede Pizza
    void prepare_dough() {
        cout << "Hefeteig machen, kneten, in Form bringen" << endl;
    }

    // Abstrakte Methode – muss von jeder konkreten Pizza überschrieben werden
    virtual void add_topping() = 0;

    void bake() {
        cout << "12 Minuten bei 220 Grad in den Holzofen" << endl;
    }

    void pack() {
        cout << "In die Schachtel legen" << endl;
    }
};

// 🔷 Konkrete Pizza-Klasse 1: Margherita
class PizzaMargherita : public Pizza {
  public:
    void add_topping() override {
        cout << "Tomatensosse: einfach, aber gut." << endl;
    }
};

// 🔷 Konkrete Pizza-Klasse 2: Funghi
class PizzaFunghi : public Pizza {
  public:
    void add_topping() override {
        cout << "Tomaten, Pilze, Salami: mmmmh." << endl;
    }
};

// 🔧 Produktionsfunktion – nutzt Polymorphie
void make_pizza(Pizza& p) {
    p.prepare_dough(); // gemeinsamer Teil
    p.add_topping();   // individueller Teil
    p.bake();          // gemeinsamer Teil
    p.pack();          // gemeinsamer Teil
}

// 🧪 Hauptfunktion zum Testen
int main() {
    PizzaMargherita m;
    PizzaFunghi     f;

    cout << "🍕 Margherita herstellen:\n";
    make_pizza(m);

    cout << "\n🍕 Funghi herstellen:\n";
    make_pizza(f);

    return 0;
}
