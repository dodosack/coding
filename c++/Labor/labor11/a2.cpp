// Themen:
// Interfaces, Dependency Inversion Principle, Composite Pattern, Exceptions

// Ihre Aufgabe:
// Implementieren Sie das Observer Pattern, vgl. Foliensatz "11-1_Pattern", Folie 38 bis 41.

// Implementieren Sie das Interface ISubscriber mit der rein virtuellen Methode update, die einen String als Parameter entgegennimmt. Implementieren Sie die Klassen Customer und GoldCustomer, die jeweils das Interface ISubscribers implementieren. Jedes Objekt der Klasse Customer und auch jedes Objekt der Klasse GoldCustomer soll eine eindeutige ID erhalten. Nutzen sie zur Erzeugung der IDs jeweils eine statische Variable.

// Implementieren sie die Methoden subscribe, unsubscribe, notify_subscribers, deliver_products und sell_products der Klasse Store.

// Die Methode deliver_products soll ausgeben, wie viele Artikel bisher verfügabr waren, wie viele Artikel ausgeliefert wurden und wie der neue Bestand ist. Waren vor der Lieferung keine Produkte verfügbar waren, sollen die Kunden darüber informiert werden.

// Die Methode sell_products soll zunächst prüfen ob die angegebene Anzahl an Produkten verkauft werden kann. ist dies nicht der Fall, so soll eine OutOfStockException geworfen werden, die von der Standardexception erbt und die what-Methode überschreibt. Die letzte Zeile der Ausgabe unten zeigt die Fehlermeldung, die durch die Exception ausgelöst wird. Kann die angegebene Anzahl an Produkten verkauft werden, so soll die Methode ausgeben, wie viele Artikel bisher verfügabr waren, wie viele Artikel verkauft wurden und wie der neue Bestand ist. Sind nach dem Verkauf keine Produkte mehr verfügbar, sollen die Kunden darüber informiert werden.

// Das gegebene Programm soll die folgende Ausgabe erzeugen:

// Vorrätige Artikel vom Typ iPhone: 0
// Ausgelieferte Artikel vom Typ iPhone: 5
// Neuer Bestand: 5
// Customer 101: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
// GoldCustomer 1: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
// GoldCustomer 2: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
// Vorrätige Artikel vom Typ iPhone: 5
// Verkaufte Artikel vom Typ iPhone: 3
// Neuer Bestand: 2
// Vorrätige Artikel vom Typ iPhone: 2
// Ausgelieferte Artikel vom Typ iPhone: 5
// Neuer Bestand: 7
// Vorrätige Artikel vom Typ iPhone: 7
// Verkaufte Artikel vom Typ iPhone: 7
// Neuer Bestand: 0
// Customer 101: neue Nachricht verfügbar --> Artikel vom Typ iPhone nicht mehr verfügbar
// GoldCustomer 1: neue Nachricht verfügbar --> Artikel vom Typ iPhone nicht mehr verfügbar
// Customer 102: neue Nachricht verfügbar --> Artikel vom Typ iPhone nicht mehr verfügbar
// Vorrätige Artikel vom Typ iPhone: 0
// Ausgelieferte Artikel vom Typ iPhone: 15
// Neuer Bestand: 15
// GoldCustomer 1: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
// Customer 102: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
// GoldCustomer 3: neue Nachricht verfügbar --> Neue Artikel vom Typ iPhone verfügbar.
// Es sind 5 Artikel vom Typ Galaxy verfügbar. Es können nicht 8 Artikel verkauft
#include <exception>
#include <iostream>
#include <list>
#include <map>
#include <string>


using namespace std;

class OutOfStockException : public exception {
    int _inStock;
    int _needed;


  public:
    OutOfStockException(int inStock, int needed) : _inStock(inStock), _needed(needed) {}

    const char* what() const noexcept override {
        
        cout << "Es sind " << _inStock << " Artikel vom Typ Galaxy verfügbar. Es können nicht " << _needed << " Artikel verkauft werden." << endl;
        return "";
    }
};

class ISubscriber {
  public:
    virtual void update(const string& message) = 0;
    virtual ~ISubscriber() {} // WICHTIG!
};

class Customer : public ISubscriber {
    static int _id_generator;
    int        id;

  public:
    Customer() {
        id = _id_generator++;
    }

    void update(const string& message) override {
        cout << "Customer " << id << ": neue Nachricht verfügbar --> " << message << endl;
    }
};

class GoldCustomer : public ISubscriber {
    static int _id_generator;
    int        id;

  public:
    GoldCustomer() {
        id = _id_generator++;
    }

    void update(const string& message) override {
        cout << "GoldCustomer " << id << ": neue Nachricht verfügbar --> " << message << endl;
    }
};

class Store {
  public:
    void subscribe(ISubscriber* subscriber) {
        _subscribers.push_back(subscriber);
    }

    void unsubscribe(ISubscriber* subscriber) {
        _subscribers.remove(subscriber);
    }

    void notify_subscribers(const string& message) {
        for (auto subscriber : _subscribers) {
            subscriber->update(message);
        }
    }

    void deliver_products(const string& modell, unsigned int available) {
        cout << "Vorrätige Artikel vom Typ " << modell << ": " << _product_availability[modell] << endl;
        cout << "Ausgelieferte Artikel vom Typ " << modell << ": " << available << endl;
        _product_availability[modell] += available;
        cout << "Neuer Bestand: " << _product_availability[modell] << endl;

        if (available > 0 && _product_availability[modell] == available) {
            notify_subscribers("Neue Artikel vom Typ " + modell + " verfügbar.");
        }
    }

    void sell_products(const string& modell, unsigned int quantity) {
        if (_product_availability[modell] < quantity) {
            throw OutOfStockException(_product_availability[modell], quantity);
        }

        if (_product_availability.find(modell) != _product_availability.end()) {
            cout << "Vorrätige Artikel vom Typ " << modell << ": " << _product_availability[modell] << endl;
            cout << "Verkaufte Artikel vom Typ " << modell << ": " << quantity << endl;
            _product_availability[modell] -= quantity;
            cout << "Neuer Bestand: " << _product_availability[modell] << endl;

            if (_product_availability[modell] == 0) {
                notify_subscribers("Artikel vom Typ " + modell + " nicht mehr verfügbar");
            }
        } else {
            cout << "Produkt nicht gefunden." << endl;
        }
    }

  private:
    list<ISubscriber*>        _subscribers;
    map<string, unsigned int> _product_availability{{"iPhone", 0}, {"Galaxy", 5}};
};

int Customer::_id_generator     = 101;
int GoldCustomer::_id_generator = 1;

void manage_store() {
    try {
        Store*       store      = new Store;
        ISubscriber* customer_1 = new Customer();
        store->subscribe(customer_1);
        ISubscriber* customer_2 = new GoldCustomer();
        store->subscribe(customer_2);
        ISubscriber* customer_3 = new GoldCustomer();
        store->subscribe(customer_3);
        store->deliver_products("iPhone", 5);
        store->unsubscribe(customer_3);
        store->sell_products("iPhone", 3);
        ISubscriber* customer_4 = new Customer();
        store->subscribe(customer_4);
        store->deliver_products("iPhone", 5);
        store->sell_products("iPhone", 7);
        store->unsubscribe(customer_1);
        ISubscriber* customer_5 = new GoldCustomer();
        store->subscribe(customer_5);
        store->deliver_products("iPhone", 15);
        store->sell_products("Galaxy", 8);
    } catch (exception& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "Ein unbekannter Fehler ist aufgetreten." << endl;
    }
}

int main(int argc, char* argv[]) {
    manage_store();
    return 0;
}
