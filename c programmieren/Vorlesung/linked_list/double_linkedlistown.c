#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    char name[20];
    int prio;
    struct Node *next;
    struct Node *previous;

    /* data */
} Node;

Node *create_new_node(char name[], int prio);
void add(Node **head, char name[], int prio);
void display(Node *head);
void clear(Node **head);

int main()
{

    char name[20];
    int prio;
    int anzahl;
    printf("wie viele Kunden möchten sie hinzufügen?\n");
    scanf("%d", &anzahl);

    // leere Listenkopf
    Node *head = NULL;
    for (int i = 0; i < anzahl; i++)
    {

        printf("Bitte name und nummer eingeben\n");
        scanf("%19s %d", name, &prio);
        add(&head, name, prio);
        /* code */
    }

    display(head);
    clear(&head);
    return 0;
}

Node *create_new_node(char name[], int prio)
{

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Fehler bei der speicher allokierung\n");
        return NULL;
    }
    new_node->prio = prio;
    new_node->next = NULL;
    new_node->previous = NULL;
    strcpy(new_node->name, name);
    return new_node;
};

void add(Node **head, char name[], int prio)
{
    Node *new_node = create_new_node(name, prio); // weitere Prüfung ob allokierung fehlgeschlagen ist Dennis fragen?????oder doch egal kpp ya

    if ((*head) == NULL) // leere liste also erstes elemt
    {
        *head = new_node;
        return;
    }
    // jetzt node an richtife stelle einstzen uund verlinken
    Node *current = *head; // newnode->prio selbe wie prio
    while (current->next != NULL && current->next->prio < prio)
    {
        current = current->next;
    }
    if (prio <= (*head)->prio) // neuer head
    {
        new_node->next = *head;
        (*head)->previous = new_node;
        new_node->previous = NULL;
        *head = new_node;
        return;
    }
    else if (current->next == NULL) // neues ENde der Liste
    {
        current->next = new_node;
        new_node->previous = current;
        new_node->next = NULL;
        return;
    }
    else // zwischen 2 einsetnzen
    {
        new_node->next = current->next;

        if (current->next != NULL) // muss nicht sei aber ist robuster für den code
        {
            current->next->previous = new_node;
        }
        new_node->previous = current;
        current->next = new_node;
        return;
    }
}
void display(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("Prio: %d heist %s\n", current->prio, current->name);
        current = current->next;
    }
    printf("NULL\n");
};
void clear(Node **head)
{
    Node *current = (*head);
    while (current != NULL)
    {
        Node *temp_next = current->next;
        free(current);
        current = temp_next;
    }
    *head = NULL;
};