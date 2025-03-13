#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *prev;

    struct Node *next;
} Node;

Node *create(int data);
void add(Node **head, int data);
void diplay(Node *head);
void clear(Node **head);

int main()
{
    Node *head = NULL;

    add(&head, 1);
    add(&head, 2);

    diplay(head);
    clear(&head);
    return 0;
}

Node *create(int data)
{

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Fehler in speicherzuweisung\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
};
void add(Node **head, int data)
{
    Node *new_node = create(data);

    if (*head == NULL) // leere liste
    {
        *head = new_node;
        return;
        /* code */
    }
    // sonst am ende anfügen

    Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
};
void diplay(Node *head){
    Node *current = head;
    while (current != NULL)
    {
        printf("Die Daten sind  %d\n", current->data);
        current = current->next;
    }

    
};
void clear(Node **head){

    Node *current = *head;

    while (current != NULL)
    {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;

};
