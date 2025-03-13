#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int age;

    char name[20];
    struct Node *ptr;
} Node;
void print_list(Node *node);
int main()
{

    Node* node1 = (Node *)malloc(sizeof(Node));
    if (node1 == NULL)
    {
        printf("Fail");
        return 1;
    }
    //dynamische speicherverwaltung
    Node* node2 =(Node*)malloc(sizeof(Node));
    // node3;
if (node2 == NULL)
    {
        free(node1);
        printf("Fail");
        return 1;
    }
    // werte zuweisenn
    node1->age = 10;
    strcpy(node1->name, "adam");
    node1->ptr = node2;
    node2->age = 20;
    strcpy(node2->name, "Eva");
    (*node2).ptr = NULL;

    print_list(node1);

    free(node1);
    node1 = NULL;

    
    free(node2);
    node2 = NULL;
    return 0;
}

void print_list(Node *node) {

while (node != NULL)
{
    printf("%s ist %d Jahre alt\n",node->name, node->age);

    node = node->ptr;
}


};