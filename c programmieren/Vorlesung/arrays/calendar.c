#include <stdio.h>
#include <stdbool.h>
void printCalendeBody();


int main()
{
    int month, year;
    printf("Bitte geben sie ein jahr ein!\n");
    scanf("%d", &year);
    do
    {
        printf("Bitte geben sie einen Monat ein\n", );
        scanf("%d", &month);

    } while (month < 1 || month > 12);
    
    
    return 0;
} 