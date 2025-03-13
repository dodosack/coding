#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int data;
    struct Element *next;
} Node;

// typedef *Node NodePtr;

Node* create_node(int data);
void insert_at_beginning(Node* new_node, int data);
void display(Node *head);
void free_list(Node *head);

int main()
{
    Node *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_beginning(&head, 30);


    display(head);

    free_list(head);
    return EXIT_SUCCESS;
}

Node *create_node(int data){

    Node *new_node = (Node *)malloc(sizeof(Node));
}