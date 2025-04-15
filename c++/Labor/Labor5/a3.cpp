// Vererbung: Überladen, Verdecken und Redefinieren von Methoden

// Ihre Aufgabe:
// Schauen Sie sich das Programm an.

// a) Sagen Sie für jeden Methodenaufruf im Hauptprogramm voraus, ob der Compiler eine Fehlermeldung meldet oder nicht und Kommentieren Sie dies entsprechend im Programmcode. In Zeile 41 ist dies exemplarisch angegeben.

// b) Sagen Sie die Ausgabe des Hauptprogramms ohne die fehlerhaften Zeilen voraus. In Zeile 41 ist dies exemplarisch angegeben.

// c) Notieren Sie jeweils ein Beispiel dafür, dass eine Methode eine andere Methode i) überlädt, ii) verdeckt und iii) redefiniert. Geben Sie dies in der Tabelle am Ende des Quellcodes an.

// d) Kommentieren Sie die Fehler verursachenden Zeilen aus und überprüfen Sie Ihre Vorhersagen mit einem Compiler.





#include <iostream>
#include <string>
using namespace std;

class A {
  public:
    void method_1() {
        cout << "A::method_1()" << endl;
    }
    void method_2(double d) {
        cout << "A::method_2(double)" << endl;
    }
    void method_2(string s) {
        cout << "A::method_2(string)" << endl;
    }
    void method_3(char c) {
        cout << "A::method_3(char)" << endl;
    }
    void method_3(string s) {
        cout << "A::method_3(string)" << endl;
    }
};

class B : public A {
  public:
    void method_2(int i) {
        cout << "B::method_2(int)" << endl;
    }
    void method_3(int i) {
        cout << "B::method_3(int)" << endl;
    }
    void method_3(string s) {
        cout << "B::method_3(string)" << endl;
    }
};

int main(int argc, char* argv[]) {
    A a;
    B b;
    cout << "a.method_1() ";
    a.method_1(); // a) keine Fehlermeldung;	b) Ausgabe: a.method_1(): A::method_1()
    cout << "b.method_1() ";
    b.method_1(); // a) keine Fehlermeldung; b)   Ausgabe: a.method_1(): A::method_1()
    cout << "a.method_2(1.2) ";
    a.method_2(1.2); // a) keine Fehlermeldung;  b) Ausgabe: a.method_2(1.2); A::method_2(double)
    cout << "b.method_2(1.2) ";
    b.method_2(1.2); // a) keine Fehlermeldung;  b) Ausgabe: b.method_2(1.2); B::method_2(int)
    cout << "a.method_2(1) ";
    a.method_2(1); // a) keine fehlermeldung;  b) Ausgabe: a.method_2(1); A::method_2(double)
    cout << "b.method_2(1) ";
    b.method_2(1); // a) keine fehlermeldung;  b) Ausgabe: b.method_2(1); B::method_2(int)
    cout << "a.method_2('c') ";
    a.method_2('c'); // a) keine fehlermeldung;  b) Ausgabe: a.method_2('c'); A::method_2(double)
    cout << "b.method_2('c') ";
    b.method_2('c'); // a) keine fehlermeldung;  b) Ausgabe: b.method_2('c'); B::method_2(int)
    cout << "a.method_2(''string'') ";
    a.method_2("string"); // a) keine fehlermeldung;  b) Ausgabe: a.method_2('c'); A::method_2(string)
    cout << "b.method_2(''string'') ";
    // b.method_2("string"); // a) fehlermeldung
    cout << "a.method_3(1) ";
    a.method_3(1); // a) fehlermeldung
    cout << "b.method_3(1) ";
    b.method_3(1); // a) keine fehlermeldung;  b) Ausgabe: b.method_3(1); B::method_3(int)
    cout << "a.method_3('c') ";
    a.method_3('c'); // a) keine fehlermeldung;  b) Ausgabe: a.method_3('c'); A::method_3(string)
    cout << "b.method_3('c') ";
    b.method_3('c'); // a) keine fehlermeldung;  b) Ausgabe: b.method_3('c'); B::method_3(string)
    cout << "a.method_3(''string'') ";
    a.method_3("string"); // a) keine fehlermeldung;  b) Ausgabe: a.method_3("String"); A::method_3(string)
    cout << "b.method_3(''string'') ";
    b.method_3("string"); // a) keine fehlermeldung;  b) Ausgabe: b.method_3("String"); B::method_3(string)
    return 0;
}

// Aufgabe c)
// Aufgabe c) – Tabelle:

// Funktion in Klasse B           | Konzept        | Ursprüngliche Funktion in A
// ------------------------------|----------------|------------------------------
// method_2(int)                 | verdeckt       | method_2(double), method_2(string)
// method_3(string)              | redefiniert    | method_3(string)
// method_2(double), method_2(string) | überladen | (in Klasse A selbst)

// method_1 goanix