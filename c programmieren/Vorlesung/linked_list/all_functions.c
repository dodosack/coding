#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef union
{
    int loyal_points;
    float balance;
} extra_data;
typedef struct Node
{
    int customer_id;
    char name[50];
    char flag; // i für int c für char
    extra_data data;
    struct Node *next;
} customer;

customer *create(int id, char name[], extra_data data, char flag);
void insert_at_head(customer **head, int id, char name[], extra_data data, char flag);
void insert_at_tail(customer **head, int id, char name[], extra_data data, char flag);
void delete(customer **head, int id_to_delete);
void clear(customer **head);
void reverse(customer **head);

void display(customer *head);
customer *search(customer *head, int id_to_search);


int main()
{
    customer *head = NULL;

    // Beispielkunden erstellen
    extra_data data1, data2, data3;
    data1.loyal_points = 100;
    data2.balance = 75.50;
    data3.loyal_points = 300;

    // Kunden hinzufügen
    insert_at_head(&head, 1, "Max Mustermann", data1, 'i');
    insert_at_tail(&head, 2, "Anna Beispiel", data2, 'f');
    insert_at_tail(&head, 3, "Hans Müller", data3, 'i');

    // Liste anzeigen
    printf("Originale Liste:\n");
    display(head);

    // Kunde suchen
    customer *found = search(head, 2);
    if (found != NULL)
    {
        printf("\nGefundener Kunde: %s mit ID %d\n", found->name, found->customer_id);
    }

    // Liste umkehren
    reverse(&head);
    printf("\nUmgekehrte Liste:\n");
    display(head);

    // Kunde löschen
    delete(&head, 2);
    printf("\nNach dem Löschen von ID 2:\n");
    display(head);

    // Speicher freigeben
    clear(&head);
    printf("\nNach dem Löschen der gesamten Liste:\n");
    display(head);

    return 0;
}



customer *create(int id, char name[], extra_data data, char flag)
{

    customer *new_customer = (customer *)malloc(sizeof(customer));
    assert(new_customer != NULL); // abbruch bei fehlgeshlagener speicher allokierung

    new_customer->customer_id = id;
    new_customer->data = data;
    strcpy(new_customer->name, name);
    new_customer->flag = flag;
    new_customer->next = NULL;

    return new_customer;
};
void insert_at_head(customer **head, int id, char name[], extra_data data, char flag)
{
    customer *new_customer = create(id, name, data, flag);
    // keine weiter prüfung notwendig da assert das ganze programm beendet
    if (*head == NULL) // leere lsite fall
    {
        *head = new_customer;
        return;
    }

    new_customer->next = *head;
    *head = new_customer;
};
void insert_at_tail(customer **head, int id, char name[], extra_data data, char flag)
{
    customer *new_customer = create(id, name, data, flag);
    if (*head == NULL) // leere liste
    {
        *head = new_customer;
        return;
    }

    customer *current = *head; // finde tail der liste
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_customer;
};

void delete(customer **head, int id_to_delete)
{

    if (*head == NULL)
    {
        printf("Liste ist leer, gibt nichts zu löschen \n");
        return;
    }

    else if (id_to_delete == (*head)->customer_id)
    {
        customer *temp = (*head)->next;
        free(*head);
        *head = temp;
        return;
    }

    customer *current = *head;

    while (current->next != NULL)

    {

        if (current->next->customer_id == id_to_delete)
        {
            customer *temp = current->next;

            current->next = current->next->next;
            free(temp);
            return;
        }

        current = current->next;
    }
    printf("Es existiert niemand mit dieser Id\n");
};

customer *search(customer *head, int id_to_search)
{
    customer *current = head;
    while (current != NULL)
    {

        if (current->customer_id == id_to_search)
        {

            return current;
        }

        current = current->next;
    }
    printf("existiert nicht\n");
};

void display(customer *head)
{

    if (head == NULL)
    {
        printf("Liste leer\n");
        return;
    }
    customer *current = head;
    while (current != NULL)
    {
        printf("Name %s , ID: %d ", current->name, current->customer_id);

        if (current->flag == 'i')
        {
            printf(" Besitzt %d TreuePunkte\n", current->data.loyal_points);
        }
        else
        {
            printf(" Besitzt %.2f€ Guthaben\n", current->data.balance);
        }
        current = current->next;
    }
};

void clear(customer **head)
{
    if (*head == NULL)
    {
        printf("Liste bereits gelöscht oder leer\n");
    }
    customer *current = *head;
    while (current != NULL)
    {
        customer *temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
};
void reverse(customer **head)
{
    customer *prev = NULL;     // Zeiger auf den vorherigen Knoten
    customer *current = *head; // Zeiger auf den aktuellen Knoten
    customer *next = NULL;     // Zeiger auf den nächsten Knoten

    while (current != NULL)
    {
        next = current->next; // Speichere den nächsten Knoten
        current->next = prev; // Umkehren des Zeigers
        prev = current;       // Verschiebe `prev` um einen Schritt
        current = next;       // Verschiebe `current` um einen Schritt
    }

    *head = prev; // Aktualisiere den Kopf der Liste
};