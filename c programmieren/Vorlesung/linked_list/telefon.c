#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef struct Kontakt
{

    char name[50];
    char telefon[15];
    struct Kontakt *zeiger;
} Kontakt;
// Kontakt hinzufügen: Eine Funktion, um einen neuen Kontakt am Ende der Liste hinzuzufügen.
void add_end(Kontakt **head, char name[], char *telefon);
Kontakt *create(char *name, char *telefon);

// Kontakt anzeigen: Eine Funktion, um alle Kontakte in der Liste auszugeben.
void display(Kontakt *head);

// Kontakt suchen: Eine Funktion, um einen Kontakt anhand des Namens zu suchen und die Telefonnummer anzuzeigen.
void search(Kontakt *head, char name_given[]);

// Kontakt löschen: Eine Funktion, um einen Kontakt anhand des Namens aus der Liste zu löschen.
void delete_kontakt(Kontakt **head, char name_to_delete[]);
// Liste leeren: Eine Funktion, um die gesamte Liste zu leeren und den Speicher freizugeben.
void clear_all(Kontakt **head);

int main()
{

    Kontakt *head = NULL; // leere lsite erstellen

    add_end(&head, "Adam", "123456789");

    add_end(&head, "Nabil", "265726");

    add_end(&head, "Kerim", "123456789");
    display(head);
    delete_kontakt(&head, "Kerim");
    search(head, "Adam");
    display(head);
    clear_all(&head);
    return 0;
}

// Kontakt hinzufügen: Eine Funktion, um einen neuen Kontakt am Ende der Liste hinzuzufügen.
void add_end(Kontakt **head, char name[], char *telefon)
{

    Kontakt *new_node = create(name, telefon);
    // keine prüfung erforderlich da assert ganzes program beendet;
    if (*head == NULL) // fall für leere lsite
    {
        *head = new_node;
        return;
    }
    else
    {
        Kontakt *current = *head;
        while (current->zeiger != NULL) // schleifedie das ende der lsite findet
        {
            current = current->zeiger;
        }
        current->zeiger = new_node; // altes ende zeigt auf neuen knoten
        return;
    }
};

Kontakt *create(char *name, char *telefon)
{
    Kontakt *new_node = (Kontakt *)malloc(sizeof(Kontakt)); // speicher im heap anfragen
    assert(new_node != NULL);                               // bricht bei fehlgechalgener speicherzuweisung ab

    // werte in knoten einfügen
    strcpy(new_node->name, name);
    strcpy(new_node->telefon, telefon);
    new_node->zeiger = NULL;

    return new_node;
};

// Kontakt anzeigen: Eine Funktion, um alle Kontakte in der Liste auszugeben.
void display(Kontakt *head)
{
    Kontakt *current = head;
    while (current != NULL)
    {
        printf("Name: %s\n", current->name);
        current = current->zeiger;
    }
    printf("ENDE\n");
};

// Kontakt suchen: Eine Funktion, um einen Kontakt anhand des Namens zu suchen und die Telefonnummer anzuzeigen.
void search(Kontakt *head, char name_given[])
{

    Kontakt *current = head;
    while (current != NULL)
    {
        if (strcmp(current->name, name_given) == 0)
        {
            printf("Name %s gefunden Telefon : %s!\n", current->name, current->telefon);
            return;
        }
        current = current->zeiger;
    }
    printf("Keinen Kontakt mit mit diesem Namen gefunden\n");
};

// Kontakt löschen: Eine Funktion, um einen Kontakt anhand des Namens aus der Liste zu löschen.
void delete_kontakt(Kontakt **head, char name_to_delete[])
{

    Kontakt *current = *head;
    Kontakt *prev = NULL;

    while (current != NULL)

    {
        if (strcmp(current->name, name_to_delete) == 0)
        {
            if (current == *head)
            {
                Kontakt *temp = (*head)->zeiger;
                *head = temp;
            }
            else
            {
                prev->zeiger = current->zeiger;
            }
            free(current);
            printf("%s wurde aus den Kontakten gelöscht\n", current->name);
            return;
        }
        prev = current;
        current = current->zeiger;
    }
};
// Liste leeren: Eine Funktion, um die gesamte Liste zu leeren und den Speicher freizugeben.
void clear_all(Kontakt **head)
{
    Kontakt *current = *head;
    while (current != NULL)
    {
        Kontakt *temp = current;

        current = current->zeiger;
        free(temp);
    }
    *head = NULL;
};
