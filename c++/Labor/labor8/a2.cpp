// Ihre Aufgabe:
// In der Bibliothek der Hochschule können sich Personen Medien ausleihen, z.B. Bücher oder DVDs. Die Personen - Dozenten und Studenten - kennen Sie bereits aus Aufgabe 10.

// Programmieren Sie für die Bibliotheksanwendung die Klassen Medium, Buch, DVD und Bibliothek aus. Ergänzen sie ggf. noch Vererbungshierarchien und verwenden Sie Polymorphismus.
// Um eine Kopie eines Mediums zu erzeugen, nutzen sie die clone()-Methode.

// Die für das Programm benötigte Klasse Datum kennen Sie schon aus Aufgabe 9. Hier müssen sie ledigleich 2 neue Konstruktoren hinzufügen.

// TIPP: Das Programm ist etwas umfangreich. Gehen sie daher Schritt für Schritt vor: Beginnen sie mit den ersten Zeilen des Hauptprogramms - z.B. bis Zeile 258 - und implementieren sie alles was sie für die korrekte Ausführung benötigen. Kommentieren sie die weiteren Zeilen zunächst aus, sodass sie frühzeitig ein lauffähiges Programm erzeugen. Tasten sie sich dann durch schrittweises Einkommentieren von Zeilen im Hauptprogramm und entsprechende Implementierung der zugehörigen Klassen / Methoden langsam an die Lösung heran.

// Das endgültige Programm soll die folgende Ausgabe erzeugen:

// Ausgabe:

// Autor:         U. Breymann
// Titel:         C++ - Eine Einführung
// Verlag:        Hanser
// Jahr:          2016
// Ausleiher:     -

// Titel:         The IT Crowd
// Verlag:        2entertain
// Jahr:          2016
// Ausleiher:     -
// Dauer:         600


// Bibliothekskatalog:
// ---------------------------------------

// Medium 0:
// Autor:         U. Breymann
// Titel:         C++ - Eine Einführung
// Verlag:        Hanser
// Jahr:          2016
// Ausleiher:     -

// Medium 1:
// Autor:         U. Breymann
// Titel:         Der C++ Programmierer
// Verlag:        Hanser
// Jahr:          2017
// Ausleiher:     -

// Medium 2:
// Autor:         Rainer Grimm
// Titel:         C++20, Get the details
// Verlag:        Leanpub
// Jahr:          2021
// Ausleiher:     -

// Medium 3:
// Autor:         Bartłomiej Filipek
// Titel:         C++17 in detail
// Verlag:        Leanbub
// Jahr:          2018
// Ausleiher:     -

// Medium 4:
// Autor:         Timothy Gallwey
// Titel:         The Inner Game of Tennis
// Verlag:        Pan
// Jahr:          2015
// Ausleiher:     -

// Medium 5:
// Autor:         Brad Gilbert
// Titel:         Winning Ugly – Mentale Kriegsführung im Tennis
// Verlag:        riva
// Jahr:          2021
// Ausleiher:     -

// Medium 6:
// Titel:         The IT Crowd
// Verlag:        2entertain
// Jahr:          2016
// Ausleiher:     -
// Dauer:         600

// Medium 7:
// Titel:         Mr. Robot
// Verlag:        Universal Pictures UK
// Jahr:          2020
// Ausleiher:     -
// Dauer:         2106

// Medium 8:
// Titel:         Chuck
// Verlag:        Warner Bros (Universal Pictures)
// Jahr:          2013
// Ausleiher:     -
// Dauer:         3774

// Medium 9:
// Titel:         Chuck
// Verlag:        Warner Bros (Universal Pictures)
// Jahr:          2013
// Ausleiher:     -
// Dauer:         3774

// ---------------------------------------

// Suche nach "C++" Ergebnis:
// ---------------------------------------

// Medium 0:
// Autor:         U. Breymann
// Titel:         C++ - Eine Einführung
// Verlag:        Hanser
// Jahr:          2016
// Ausleiher:     -

// Medium 1:
// Autor:         U. Breymann
// Titel:         Der C++ Programmierer
// Verlag:        Hanser
// Jahr:          2017
// Ausleiher:     -

// Medium 2:
// Autor:         Rainer Grimm
// Titel:         C++20, Get the details
// Verlag:        Leanpub
// Jahr:          2021
// Ausleiher:     -

// Medium 3:
// Autor:         Bartłomiej Filipek
// Titel:         C++17 in detail
// Verlag:        Leanbub
// Jahr:          2018
// Ausleiher:     -

// ---------------------------------------

// Suche nach "Tennis" Ergebnis:
// ---------------------------------------

// Medium 4:
// Autor:         Timothy Gallwey
// Titel:         The Inner Game of Tennis
// Verlag:        Pan
// Jahr:          2015
// Ausleiher:     -

// Medium 5:
// Autor:         Brad Gilbert
// Titel:         Winning Ugly – Mentale Kriegsführung im Tennis
// Verlag:        riva
// Jahr:          2021
// Ausleiher:     -

// ---------------------------------------

// Suche nach "The" Ergebnis:
// ---------------------------------------

// Medium 4:
// Autor:         Timothy Gallwey
// Titel:         The Inner Game of Tennis
// Verlag:        Pan
// Jahr:          2015
// Ausleiher:     -

// Medium 6:
// Titel:         The IT Crowd
// Verlag:        2entertain
// Jahr:          2016
// Ausleiher:     -
// Dauer:         600

// ---------------------------------------

// Bibliothekskatalog:
// ---------------------------------------

// Medium 0:
// Autor:         U. Breymann
// Titel:         C++ - Eine Einführung
// Verlag:        Hanser
// Jahr:          2016
// Ausleiher:     -

// Medium 1:
// Autor:         U. Breymann
// Titel:         Der C++ Programmierer
// Verlag:        Hanser
// Jahr:          2017
// Ausleiher:     Peter von: 4.5.2023 bis: 4.6.2023

// Medium 2:
// Autor:         Rainer Grimm
// Titel:         C++20, Get the details
// Verlag:        Leanpub
// Jahr:          2021
// Ausleiher:     -

// Medium 3:
// Autor:         Bartłomiej Filipek
// Titel:         C++17 in detail
// Verlag:        Leanbub
// Jahr:          2018
// Ausleiher:     -

// Medium 4:
// Autor:         Timothy Gallwey
// Titel:         The Inner Game of Tennis
// Verlag:        Pan
// Jahr:          2015
// Ausleiher:     Prof Miller von: 12.10.2023 bis: 12.1.2024

// Medium 5:
// Autor:         Brad Gilbert
// Titel:         Winning Ugly – Mentale Kriegsführung im Tennis
// Verlag:        riva
// Jahr:          2021
// Ausleiher:     -

// Medium 6:
// Titel:         The IT Crowd
// Verlag:        2entertain
// Jahr:          2016
// Ausleiher:     -
// Dauer:         600

// Medium 7:
// Titel:         Mr. Robot
// Verlag:        Universal Pictures UK
// Jahr:          2020
// Ausleiher:     Lisa von: 25.5.2023 bis: 25.6.2023
// Dauer:         2106

// Medium 8:
// Titel:         Chuck
// Verlag:        Warner Bros (Universal Pictures)
// Jahr:          2013
// Ausleiher:     Prof Miller von: 14.3.2023 bis: 14.6.2023
// Dauer:         3774

// Medium 9:
// Titel:         Chuck
// Verlag:        Warner Bros (Universal Pictures)
// Jahr:          2013
// Ausleiher:     -
// Dauer:         3774



#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

// Klasse für alle Personen, die Medien leihen können aus Aufgabe 10
class Person {
    string _name;
    int    _check_out_duration;

  public:
    Person(string name, int check_out_duration = 0);
    int    get_check_out_duration() const;
    string get_name() const;
    void   print() const;
};

Person::Person(string name, int check_out_duration)
    : _name(name), _check_out_duration(check_out_duration) {
}

int Person::get_check_out_duration() const {
    return _check_out_duration;
}

string Person::get_name() const {
    return _name;
}

void Person::print() const {
    cout << _name;
}


class Lecturer : public Person {
    int _examiner_id;

  public:
    Lecturer(string name, int examiner_id);
    void print() const;
};

Lecturer::Lecturer(string name, int examiner_id)
    : Person(name, 90), _examiner_id(examiner_id) {
}

void Lecturer::print() const {
    Person::print();
    cout << ", _examiner_id " << _examiner_id << endl;
}

class Student : public Person {
    int _matriculation_number;

  public:
    Student(string name, int matriculation_number);
    void print() const;
};


Student::Student(string name, int matriculation_number)
    : Person(name, 30), _matriculation_number(matriculation_number) {
}

void Student::print() const {
    Person::print();
    cout << ", Matrikelnummer " << _matriculation_number << endl;
}

// Klasse Datum aus Aufgabe 9
class Date {

    int _day, _month, _year;

  public:
    Date(int = 0, int = 0, int = 0);
    // ** neu **
    // Konvertierkonstruktor für String neu
    Date(const string& s);
    // ** neu **
    // Konvertierkonstruktor für C-String neu
    Date(const char* s);

    Date            operator+(int days);
    friend ostream& operator<<(ostream&, const Date&);
};


Date::Date(int d, int m, int y)
    : _day(d), _month(m), _year(y) {
}

Date::Date(const string& s) {
    // hier Konvertierkonstruktor für String
    char         punkt;
    stringstream ss(s); // es wird als  streameingabe interpretiert also wie cin aus der Tastatur
    // Initialisiert einen Stringstream mit dem Eingabestring
    ss >> _day >> punkt >> _month >> punkt >> _year;
};


Date::Date(const char* s) : Date(string(s)){

    // // hier Konvertierkonstruktor für C-String

    // char         punkt;
    // stringstream ss(s); // es wird als  streameingabe interpretiert also wie cin aus der Tastatur
    // // Initialisiert einen Stringstream mit dem Eingabestring
    // ss >> _day >> punkt >> _month >> punkt >> _year;
};



Date Date::operator+(int days) {
    int abs_date = _day + _month * 30 + _year * 360;
    abs_date += days;
    int y    = abs_date / 360;
    abs_date = abs_date % 360;
    int m    = abs_date / 30;
    abs_date = abs_date % 30;
    int d    = abs_date;

    return Date(d, m, y);
}

ostream& operator<<(ostream& os, const Date& d) {
    os << d._day << "." << d._month << "." << d._year;
    return os;
}


// Klasse für die Medien, die in der Bibliothek ausgeliehen werden
// können
class Medium {

  protected:
    // Titel des Mediums
    const string _title;
    // Verlag, der das Medium herausgibt
    const string _publisher;
    // Jahr, in dem das Medium veröffentlicht wurde
    const int _year_of_publication;
    // ausgeliehen am
    Date _date_of_check_out;
    // ausgeliehen bis
    Date _date_of_return;
    // ausgeliehen von
    Person* _lender;

  public:
    // Konstruktor
    Medium(string title = "", string publisher = "", int year_of_publication = 0);
    virtual ~Medium();
    // Titel zurückliefern
    string get_title() const;
    // Ausleiher zurückliefern
    Person* get_lender() const;
    // das Medium "ausleihen", d.h. Person p, date_of_check_out und date_of_return eintragen
    void check_out(Person& p, Date date_of_check_out, Date date_of_return);
    // Medium in der Konsole ausgeben
    virtual void    print() const;
    virtual Medium* clone() const;
};
Medium::Medium(string title, string publisher, int year_of_publication)
    : _title(title), _publisher(publisher), _year_of_publication(year_of_publication), _lender(nullptr) {
      };
Medium::~Medium() {}

string Medium::get_title() const {
    return _title;
}
Person* Medium::get_lender() const {
    return _lender;
}
void Medium::check_out(Person& p, Date date_of_check_out, Date date_of_return) {
    _lender            = &p;
    _date_of_check_out = date_of_check_out;
    _date_of_return    = date_of_return;
}
void Medium::print() const {
    std::cout << "Titel:         " << _title << endl;
    std::cout << "Verlag:        " << _publisher << endl;
    std::cout << "Jahr:          " << _year_of_publication << endl;
    cout << "Ausleiher:     ";
    if (!_lender) {
        cout << "-" << endl;
    } else {
        // get_lender() ist ein Pointer auf eine Person also nein lender ist eine person also geht da bro

        cout << _lender->get_name() << " von: " << _date_of_check_out << " bis: " << _date_of_return << endl;
    }
}

Medium* Medium::clone() const {
    return new Medium(*this);
}
// gibt einen klon mit new zurück und this und kopierkosntruktor




// Klasse für die Bücher als Spezialisierung von Medium
class Book : public Medium {
    // Autor(en) des Buches
    string _author;

  public:
    // Standardkonstruktor
    Book(string author = "", string title = "", string publisher = "", int year_of_publication = 0);
    // das Buch auf der Konsole ausgeben
    void    print() const override;
    Medium* clone() const override;
};

// hier Konstruktor und Methoden



Book::Book(string author, string title, string publisher, int year_of_publication)
    : Medium(title, publisher, year_of_publication), _author(author) {
    // medium ist protected also kann ich darauf zugreifen nur mit  konstruktor und nciht alleine
}


void Book::print() const {
    // Buch ist ein Medium also kann ich die Methode print() von Medium aufrufen
    cout << "Autor:         " << _author << endl;
    Medium::print();
}
Medium* Book::clone() const {
    return new Book(*this);
}


// Klasse für die DVDs als Spezialisierung von Medium
class DVD : public Medium {
    // Abspieldauer der DVD
    const int _c_play_time;

  public:
    // Standardkonstruktor
    DVD(string title = "", string publisher = "", int year_of_publication = 0, int play_time = 0);

    // die DVD auf der Konsole ausgeben
    void    print() const override; // hhier fehlt das override da wir mit virtual arbeiten
    Medium* clone() const override;
};

DVD::DVD(string title, string publisher, int year_of_publication, int play_time)
    : Medium(title, publisher, year_of_publication), _c_play_time(play_time) {
    // medium ist protected also kann ich darauf zugreifen nur mit  konstruktor und nciht alleine
}
void DVD::print() const {
    Medium::print();
    cout << "Dauer:         " << _c_play_time << endl;
}
Medium* DVD::clone() const {
    return new DVD(*this);
    // gibt einen klon mit new zurück und this und kopierkosntruktor
}
// hier Konstruktor und Methoden




// Die Klasse Library verweist auf alle Medien (Bücher und DVDs),
// die von Personen (Studierende und Dozenten) ausgeliehen werden
// können.
class Library {
    // maximale Anzahl der Medien im Katalog
    const unsigned int _c_maximal_number_of_media;
    // Der Medienkatalog
    vector<Medium*> media;

  public:
    // Standardkonstruktor
    Library(int maximal_number_of_media = 1000);

    // Kopie einer DVD oder eines Buches in den Katalog der Bibliothek eintragen
    // Die maximale Anzahl an Medien darf nicht überschritten werden
    void procure_medium(Medium&);

    // alle Medien auf der Konsole ausgeben,
    // die im Titel das Suchwort enthalten
    void search_medium(string search_word);

    // im Medium mit der Nummer number, die Person p als Ausleiher
    // eintragen mit von-Datum d und bis-Datum d+p.ausleihdauer
    void check_out_medium(size_t number, Person& p, Date d);

    // alle Medien in der Konsole ausgeben
    void print() const;
};
Library::Library(int maximal_number_of_media)
    : _c_maximal_number_of_media(maximal_number_of_media) {
}
void Library::procure_medium(Medium& m) {
    if (media.size() < _c_maximal_number_of_media) {
        media.push_back(m.clone());
    } else {
        cout << "Maximale Anzahl an Medien erreicht!" << endl;
    }
}
void Library::search_medium(string search_word) {
    cout << "Suche nach \"" << search_word << "\" Ergebnis:" << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;
    for (unsigned int i = 0; i < media.size(); i++) {
        if (media[i]->get_title().find(search_word) != string::npos) {
            cout << "Medium " << i << ":" << endl;
            media[i]->print();
            cout << endl;
        }
    }
    cout << "---------------------------------------" << endl;
    cout << endl;

}
void Library::check_out_medium(size_t number, Person& p, Date d) {
    if (number < media.size()) {
        media[number]->check_out(p, d, d + p.get_check_out_duration());
    } else {
        cout << "Medium mit Nummer " << number << " existiert nicht!" << endl;
    }
}
void Library::print() const {
    cout << "Bibliothekskatalog:" << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;
    for (unsigned int i = 0; i < media.size(); i++) {
        cout << "Medium " << i << ":" << endl;
        media[i]->print();
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
    cout << endl;
    
}

// hier Konstruktor und Methoden

int main(int argc, char* argv[]) {
    // Umlaute etc. in der Konsole zulassen
    setlocale(LC_ALL, "");
    // Bibliothek mit 100 Plätzen initialisieren
    Library library(100);
    // Bücher und DVDs erstellen
    Book b1("U. Breymann", "C++ - Eine Einführung", "Hanser", 2016);
    Book b2("U. Breymann", "Der C++ Programmierer", "Hanser", 2017);
    Book b3("Rainer Grimm", "C++20, Get the details", "Leanpub", 2021);
    Book b4("Bartłomiej Filipek", "C++17 in detail", "Leanbub", 2018);
    Book b5("Timothy Gallwey", "The Inner Game of Tennis", "Pan", 2015);
    Book b6("Brad Gilbert", "Winning Ugly – Mentale Kriegsführung im Tennis", "riva", 2021);
    DVD  d1("The IT Crowd", "2entertain", 2016, 600);
    DVD  d2("Mr. Robot", "Universal Pictures UK", 2020, 2106);
    DVD  d3("Chuck", "Warner Bros (Universal Pictures)", 2013, 3774);
    // Ein Buch und eine DVD ausgeben
    b1.print();
    cout << endl;
    d1.print();
    cout << endl;
    cout << endl;
    // Kopien der Bücher und DVDs (Medien) in die Bibliothek
    // einfügen
    library.procure_medium(b1);
    library.procure_medium(b2);
    library.procure_medium(b3);
    library.procure_medium(b4);
    library.procure_medium(b5);
    library.procure_medium(b6);
    library.procure_medium(d1);
    library.procure_medium(d2);
    library.procure_medium(d3);
    library.procure_medium(d3);
    // Bestand der Bibliothek ausgeben
    library.print();
    // Personen anlegen
    Student  p1("Peter", 12345678);
    Student  p2("Lisa", 87654321);
    Lecturer p3("Prof Miller", 4711);
    // Suchen im Bibliotheksbestand durchführen
    library.search_medium("C++");
    library.search_medium("Tennis");
    library.search_medium("The");
    // Medien ausleihen
    library.check_out_medium(1, p1, "4.5.2023");
    library.check_out_medium(7, p2, "25.05.2023");
    library.check_out_medium(4, p3, "12.10.2023");
    library.check_out_medium(8, p3, "14.03.2023");
    // Bestand der Bibliothek ausgeben
    library.print();
}