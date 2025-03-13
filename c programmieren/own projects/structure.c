#include <stdio.h>

// Definition einer Struktur
struct Student {
    char name[50];     // Name des Studenten als Array von chars
    int age;           // Alter des Studenten
    float grade;       // Note des Studenten
};

int main() {
    // Deklaration einer Strukturvariable
    struct Student student1;

    // Zuweisung von Werten zu den Strukturmitgliedern
    strcpy(student1.name, "Alice");  // strcpy wird für String-Kopien benötigt
    student1.age = 20;
    student1.grade = 3.5;

    // Zugriff auf die Strukturmitglieder
    printf("Name: %s\n", student1.name);
    printf("Alter: %d\n", student1.age);
    printf("Note: %.2f\n", student1.grade);

    return 0;
}
