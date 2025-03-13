#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{ // knoten mit dtaen uns zeiger aufnächstes element

    int priority;
    double data;
    struct Node *next;
} Node;
Node *addNewNode(Node *head, int priority, double data);
Node *deleteNodes(Node *head, int priority);
void display(Node *head);
Node *free_all(Node *head);
int main()
{
    // leere liste
    Node *head = NULL;
    head = addNewNode(head, 2, 2.222);
    head = addNewNode(head, 1, 2.1111);
    display(head);
    head = deleteNodes(head, 1);
    display(head);

    head = free_all(head);
    return 0;
}

Node *addNewNode(Node *head, int priority, double data)
{

    Node *new_node = (Node *)malloc(sizeof(Node)); // speicher im heap und testen
    if (new_node == NULL)                          // fehgeschlagen
    {
        printf("Fehler bei sppeicherzuweisung ");
        return head; // einfacher pointer nicht NULL;
    }
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL; // Nulls etzen um undefineirtes verhalten zu vermeiden und ende der liste

    // verlinken

    if (head == NULL|| priority <= head->priority) // leere liste also an erster stelle
    {
        new_node->next = head;
        return new_node; // neuer head
    }
    // richtige stelle einsetzen
    Node *current = head;
    while (current->next != NULL && current->next->priority < priority) // laeuft bis zur richtigen stelle
    {
        current = current->next;
    }
  

    // mitte oder ende

    new_node->next = current->next;
    current->next = new_node;
    return head;
};
Node *deleteNodes(Node *head, int priority)
{
    Node *current = head;
    Node *prev = NULL;

    while (current != NULL)
    {
        if (current->priority == priority)
        {
            Node *temp = current;
            if (prev == NULL)
            {
                head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }

    return head;
};
void display(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("\ndeine prio : %d, deine daten: %f\n", current->priority, current->data);
        current = current->next;
    }
    printf("Ende\n");
};
Node *free_all(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    return NULL; // damit head NUll wird
};