#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node *next;
    struct Node *previous;
    int data;
} Node;

Node *create_Node(int data);
Node *insert_at_begining(Node **head, Node * knoten);


int main()
{
    Node *head = NULL;

    Node *Knoten1 = create_node(10);
    head = Knoten1;
    Node *knoten2= create_node(20);

    head = insert_beginning(&head, knoten2);
    return 0;
}
Node *create_Node(int data){

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Fehler bei speicherzuweisung\n");

        return NULL;


        /* code */
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
};

Node *insert_at_begining(Node **head, Node * knoten){

    
};