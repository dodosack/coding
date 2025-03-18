// Analysieren Sie das Programm und kommentieren Sie dann die minimale Anzahl von Funktionsdefinitionen aus, so dass Sie das Programm erfolgreich kompilieren können. Kommentieren Sie keine Zeile im Hauptprogramm aus. Sind mehrere Funktionen gleichwertig, so verwenden sie die erste Funktion und kommentieren die weiteren aus. Nennen Sie die Funktionen, die im Hauptprogramm aufgerufen werden, und erklären Sie Ihre Überlegungen.

// Erst wenn Sie sich Gedanken gemacht haben, verifizieren Sie Ihre Überlegungen durch einen Programmdurchlauf.

// WICHTIG: Lassen Sie nicht den Compiler die Arbeit machen, sondern überlegen Sie selbst, was auszukommentieren ist. In der Prüfung können Sie auch keinen Compiler nutzen!


/*
#include <iostream>
using namespace std;
int function(int i_1)
{
    cout << "Funktion  1: i_1=" << i_1 << endl;
    return 0;
}
// void function(int i_1)
// {
//     cout << "Funktion  2: i_1=" << i_1 << endl;
// }
// char function(int i_1)
// {
//     cout << "Funktion  3: i_1=" << i_1 << endl;
//     return 'a';
// }



// falsche Überladung rückgabe typ nicht gültig alleine





int function(int &i_1) // referenz zählz nicht
{
    cout << "Funktion  4: i_1=" << i_1 << endl;
    return 1;
}
int function(int i_1, int i_2)
{
    cout << "Funktion  5: i_1=" << i_1 << " i_2=" << i_2 << endl;
    return 1;
}
// int function(char c_1, int i_1 = 0)// hier muss default wert rein
// {
//     cout << "Funktion  6: c_1=" << c_1 << " i_1=" << i_1 << endl;
//     return 1;
// }
// int function(int i_1, int i_2 = 0)
// {
//     cout << "Funktion  7: i_1=" << i_1 << " i_2=" << i_2 << endl;
//     return 1;
// }


// identisch zu funktion 2


int function(double d_1, int i_1, char c_1 = 'a')
{
    cout << "Funktion  8: d_1=" << d_1 << " i_1=" << i_1 << " c_1=" << c_1 << endl;
    return 1;
}
int function(double d_1, double d_2 = 1.1, int i_1 = 0)
{
    cout << "Funktion  9: d_1=" << d_1 << " d_2=" << d_2 << " i_1=" << i_1 << endl;
    return 1;
}


// int function(double d_1, double d_2 = 1.1, char c_1)
// {
//     cout << "Funktion 10: d_1=" << d_1 << " d_2=" << d_2 << " c_1=" << c_1 << endl;
//     return 1;
// }7

// falsche default nutzung alle parameter danach müssen default sein


int function(char c_1, char c_2 = 'a', int i_1 = 2, char c_3 = 'c') //  kann man weglassen oder oben den default weg weil identisch durch default
{
    cout << "Funktion 11: c_1=" << c_1 << " c_2=" << c_2 << " i_1=" << i_1 << " c_3=" << c_3 << endl;
    return 1;
}
int main(int argc, char* argv[])
{
    int i = 1;
    char c = 'a';
    function(1);
    function('c');// solte in ''
    function('i');
    c = function('a');// müsste gehen aber refernz übeladung geht nicht
    c = 'a';
    function(1, 2);
    function(c, i);
    function(1.0, 2.0);
    function(1.0, 2.0, 1);
    function(1.0, 1, 'a');
    function(1.0, 1);
    function(1.0, static_cast<double>(i));
    function(c, c, i);
    function(c, i);
    return 0;
}

*/




#include <iostream>
using namespace std;

// Funktion mit einer einzigen int-Variable
int function(int i_1)
{
    cout << "Funktion  1: i_1=" << i_1 << endl;
    return 0;
}

// Funktion mit einem char und einem int
int function(char c_1, int i_1)
{
    cout << "Funktion  6: c_1=" << c_1 << " i_1=" << i_1 << endl;
    return 1;
}

// Funktion mit double, int und char (ohne Default-Wert zur Vermeidung von Mehrdeutigkeiten)
int function(double d_1, int i_1, char c_1)
{
    cout << "Funktion  8: d_1=" << d_1 << " i_1=" << i_1 << " c_1=" << c_1 << endl;
    return 1;
}

// Funktion mit zwei doubles und optionalem int
int function(double d_1, double d_2 = 1.1, int i_1 = 0)
{
    cout << "Funktion  9: d_1=" << d_1 << " d_2=" << d_2 << " i_1=" << i_1 << endl;
    return 1;
}

// Funktion mit mehreren char-Parametern und einem int-Wert
int function(char c_1, char c_2 = 'a', int i_1 = 2, char c_3 = 'c')
{
    cout << "Funktion 11: c_1=" << c_1 << " c_2=" << c_2 << " i_1=" << i_1 << " c_3=" << c_3 << endl;
    return 1;
}

int main(int argc, char* argv[]) 
{
    int i = 1;
    char c = 'a';
    
    function(1); // Aufruf mit int
    function(static_cast<int>('c')); // Explizite Umwandlung zur Vermeidung von Mehrdeutigkeiten
    function(static_cast<int>('i')); // gleich wie oben
    
    c = function(static_cast<int>('a')); // Fehlervermeidung durch Umwandlung
    c = 'a'; // Workaround, um Fehler zu vermeiden
    
    function(c, i); // Nutzung von Funktion 6 anstelle von Funktion 5
    function(c, i); // Explizite Umwandlung für eindeutige Funktionsauswahl
    
    function(1.0, 2.0); // Aufruf mit zwei doubles (Funktion 9)
    function(1.0, 2.0, 1); // explizite Übergabe von 3 Werten an Funktion 9
    function(1.0, 1, 'a'); // passt zur Funktion 8
    function(1.0, 1, 'a'); // Eindeutig zur Funktion 8 passend
    
    function(1.0, static_cast<double>(i)); // double + double (funktion 9)
    function(c, c, i); // char, char, int -> Funktion 11
    function(c, i); // Nutzung von Funktion 6
    
    return 0;
}
