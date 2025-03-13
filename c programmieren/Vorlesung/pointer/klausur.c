#include <stdio.h>
#include <stdbool.h>

void rechner(int input, bool *a, bool *b);
// funnktiondeklaration

int main()
{
    // variabeln deklarieren und zuweisen
    // einscannen
    int input;
    scanf("%d", &input);

    bool a = 0;
    bool b = 0;

    // sofern..

    rechner(input, &a, &b);
    printf("Wert von a: %s\n", a ? "hiiii" : "bnyy");
    printf("Wert von b: %c\n", b ? '0' : '1');
    return 0;
}

void rechner(int input, bool *a, bool *b)
{
    if (input % 2 != 0 && input % 3 == 0 && input % 5 == 0)
    {
        *a = !(*a);
    }
    if (*a == 0)
    {
        *b = !(*a);
    }
}