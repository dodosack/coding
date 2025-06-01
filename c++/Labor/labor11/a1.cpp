// Themen:
// Interfaces, Dependency Inversion Principle, Composite Pattern

// Ihre Aufgabe:
// Der Preis für ein einzelnes Produkt soll auf die gleiche Art und Weise abgefragt werden können wie für ein Paket in dem Produkte und/oder weitere Pakete enthalten sein können,
// die wiederum Produkte und/oder weitere Pakete enthalten können. Nutzen Sie hierzu das Composite Pattern.
// Implementieren sie das Interface IComponent sowie die Klassen Product und Box, sodass das gegebene Hauptprogramm die folgende Ausgabe erzeugt:

// Preisermittlung für ein einfaches Produkt:
// Preis: 10

// Preisermittlung für eine verschachtelte Box:
// Preis: 19

// Preisermittlung für eine erweiterte verschachtelte Box:
// Preis: 26

 



#include <iostream>
#include <vector>
// #include <memory>

using namespace std;

// Interface
class IComponent {
public:
    virtual ~IComponent() {}
    virtual int get_price() const = 0;
    virtual void add(IComponent* component) {
        throw runtime_error("Cannot add component to this type");
    }
};

// Leaf: Product
class Product : public IComponent {
private:
    int price;

public:
    Product(int price) : price(price) {}

    int get_price() const override {
        return price;
    }
};

// Composite: Box
class Box : public IComponent {
private:
    vector<IComponent*> components;

public:
    ~Box() {
        for (IComponent* component : components) {
            delete component;
        }
    }

    int get_price() const override {
        int total_price = 0;
        for (const IComponent* component : components) {
            total_price += component->get_price();
        }
        return total_price;
    }

    void add(IComponent* component) override {
        components.push_back(component);
    }
};

// Preisberechnung
void calculate_price(IComponent* component) {
    cout << "Preis: " << component->get_price() << endl;
}

int main() {
    cout << "Preisermittlung f\u00fcr ein einfaches Produkt: " << endl;
    IComponent* product = new Product(10);
    calculate_price(product);
    delete product;
    cout << endl;

    cout << "Preisermittlung f\u00fcr eine verschachtelte Box: " << endl;
    IComponent* outer_box = new Box;
    IComponent* inner_box_1 = new Box;
    IComponent* product_1 = new Product(10);
    IComponent* product_2 = new Product(5);
    IComponent* product_3 = new Product(4);

    inner_box_1->add(product_1);
    inner_box_1->add(product_2);

    IComponent* inner_box_2 = new Box;
    inner_box_2->add(product_3);

    outer_box->add(inner_box_1);
    outer_box->add(inner_box_2);
    calculate_price(outer_box);
    cout << endl;

    cout << "Preisermittlung f\u00fcr eine erweiterte verschachtelte Box: " << endl;
    IComponent* product_4 = new Product(7);
    inner_box_2->add(product_4);
    calculate_price(outer_box);
    cout << endl;

    delete outer_box;

    return 0;
}
