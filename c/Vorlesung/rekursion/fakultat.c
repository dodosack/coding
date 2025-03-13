#include <stdio.h>
#include <stdlib.h>
int faculty(int number);

int main()
{
    int zahl;
    scanf("%d", &zahl);

    printf("Ergebnis : %d", faculty(zahl));
    return 0;
}

int faculty(int number)
{

    if (number == 0) // geht auch mit 1
    {
        return 1; // damit nicht ganze term 0 wird weil wir ja zahl faculty*... *1
    }
    return number * faculty(number - 1);
};