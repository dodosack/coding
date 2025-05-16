// Themen:
// Virtuelle Methoden, dynamisches Binden

// Ihre Aufgabe:
// Passen sie das nachfolgende Programm so an, dass die folgende Ausgabe erzeugt wird.

// Ausgabe:

// A::method_1()
// B::method_1()
// C::method_1()
// D::method_2() hier verändern A -> method_2() in D -> method_2()
// D::method_2() B::method_2()
// D::method_2() C::method_2()
// A::method_3()
// B::method_3()
// D::method_3() // C::method_3()
//
//
// A::method_4() D::method_2()             A :mêthod_4 A::method_2()
// C::method_4() D::method_2()             B :mêthod_4 B::method_2()
// C::method_4() D::method_2()             C :: method_4() C::method_2()
//
// Verändern sie dabei das Hauptprogramm nicht, sondern nutzen sie virtuelle Methoden.
// Nutzen Sie die sprachlichen Möglichkeiten von C++, um den Compiler prüfen zu lassen, ob virtuelle Methoden korrekt überschrieben wurden.




#include <iostream>
#include <string>

using namespace std;

void p(string s, bool nl = true) {
    cout << s << " ";
    if (nl) {
        cout << endl;
    }
}

class A {
  public:
    void         method_1() { p("A::method_1()"); }
    virtual void method_2() { p("A::method_2()"); } // virtual machen
    void         method_3() { p("A::method_3()"); }
    void         method_4() {
        p("A::method_4()", false);
        method_2();
    }
};

class B : public A {
  public:
    void         method_1() { p("B::method_1()"); }
    void         method_2() override { p("B::method_2()"); }
    void         method_3() { p("B::method_3()"); }
    virtual void method_4() { // virtual machen
        p("B::method_4()", false);
        method_2();
    }
};

class C : public B {
  public:
    void         method_1() { p("C::method_1()"); }
    void         method_2() override { p("C::method_2()"); }
    virtual void method_3() { p("C::method_3()"); } // virtual
    void         method_4() override {
        p("C::method_4()", false);
        method_2();
    }
};

class D : public C {
  public:
    void method_1() { p("D::method_1()"); }
    void method_2() { p("D::method_2()"); }
    void method_3() { p("D::method_3()"); }
};

int main(int argc, char* argv[]) {
    D  d;
    A* p_a = &d;
    B* p_b = &d;
    C* p_c = &d;
    p_a->method_1();
    p_b->method_1();
    p_c->method_1();

    p_a->method_2();

    p_b->method_2();

    p_c->method_2();

    p_a->method_3();
    p_b->method_3();

    p_c->method_3();

    p_a->method_4();
    p_b->method_4();
    p_c->method_4();
}
