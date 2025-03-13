#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

    int data;
    struct Node *next;
} Node;

Node *insert_beginning(Node *head, int data);

void print_list(Node *head);
Node * free_list(Node *head);
int main()
{

    Node *head = NULL;
    head = insert_beginning(head, 1);

    head = insert_beginning(head, 2);
    
    head = insert_beginning(head, 5);
    print_list(head);
    head = free_list(head);
    return 0;
}

Node *insert_beginning(Node *head, int data)
{

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return head;
    }

    new_node->data = data;
    new_node->next = head;

    return new_node; // unser neues head in der main
};

void print_list(Node *head)
{

    while (head != NULL)
    {
        printf("die data ist %d", head->data);
        head = head->next;
    }
};

Node * free_list(Node *head){
    
    while (head != NULL)
    {
        /* code */
     Node *temp = head->next;
     free(head);
     head = temp;
    }
    //free(head);
    return NULL;
     // liste als leeer makieren
};
