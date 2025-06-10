class Auto {
  public:
    int geschwindigkeit; // Instanzvariable

    // Klassenvariable (statische Member-Variable)
    // Es gibt nur EINE Kopie von 'anzahlAutos' für ALLE Auto-Objekte.
    static int anzahlAutos;

    Auto() {           // Konstruktor
        anzahlAutos++; // Zähle, wenn ein neues Auto erstellt wird
    }

    ~Auto() {          // Destruktor
        anzahlAutos--; // Zähle, wenn ein Auto gelöscht wird
    }

    void zeigeAnzahlAutos() {
        cout << "Anzahl der aktuell existierenden Autos: " << anzahlAutos << endl;
    }
};

// Wichtig: Statische Member-Variablen müssen AUẞERHALB der Klasse initialisiert werden!
int Auto::anzahlAutos = 0; // Initialisierung der statischen Variable

// Jetzt im main-Programm:
int main() {
    Auto a1;
    a1.geschwindigkeit = 100;
    a1.zeigeAnzahlAutos(); // Ausgabe: Anzahl der aktuell existierenden Autos: 1

    Auto a2;
    a2.geschwindigkeit = 50;
    a2.zeigeAnzahlAutos(); // Ausgabe: Anzahl der aktuell existierenden Autos: 2

    // Du kannst auch direkt über die Klasse zugreifen, ohne ein Objekt:
    cout << "Gesamtanzahl (direkt über Klasse): " << Auto::anzahlAutos << endl; // Ausgabe: Gesamtanzahl (direkt über Klasse): 2

    return 0;
}