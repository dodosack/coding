#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef union
{
    int groesse;
    char geschlecht;
} data;
typedef struct Person
{
    char name[50];
    data groesse_geschlecht;
    bool flag_for_groesse;
    Person *next;
} Person;

int main()
{
    Person list[100];

    strcpy(list[0].name, "Lisa");
    list[0].next = NULL;
    list[0].groesse_geschlecht.geschlecht = 'W';
    list[0].flag_for_groesse = 0;

    strcpy(list[1].name, "Adam");
    list[1].next = NULL;
    list[1].groesse_geschlecht.geschlecht = 'M';
    list[1].flag_for_groesse = 0;

    strcpy(list[2].name, "muhamed");
    list[2].next = NULL;
    list[2].groesse_geschlecht.groesse = 180;
    list[2].flag_for_groesse = 1;

    Person *male = NULL; // lsite für manner
    Person *female = NULL;
    Person *height = NULL;

    for (int i = 0; i < 100; i++)
    {
        if (list[i].groesse_geschlecht.geschlecht == 'M')
        {
            if (male == NULL) // leer
            {
                *male = list[i];
            }

            Person *current = male;
            while (current != NULL) // traversiere bis zum ende liste und setze da neuen Male
            {
                current = current->next;
            }

            *current = list[i];
        }
        else if (list[i].groesse_geschlecht.geschlecht == 'W')
        {
        }
        else
        {
        }
    }

    return 0;
}
