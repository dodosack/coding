#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char name[20];
    int customer_number;
    struct Node *next;
} Node;
void add_customer(Node **root, int customer_number, char name[]);
Node *create_customer(int customer_number, char name[]);

void print_list(Node *root);

int count_customers(Node *root);
void clear_list(Node **root);
int main()
{

    Node *root = NULL; // leeren Listenkopf
    add_customer(&root, 1, "Hans Maurer");
    add_customer(&root, 2, "Anna-Maria Schmidt");
    add_customer(&root, 3, "Tatjana Roth");
    int count = count_customers(root);
    printf("Momentan sind %d Kunden erfasst.\n", count);
    print_list(root);

    clear_list(&root);
    count = count_customers(root);
    printf("Momentan sind %d Kunden erfasst.", count);

    return 0;
}

Node *create_customer(int customer_number, char name[])
{

    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("Fehler beim speicher zu weisen \n");
        return NULL;
    }

    new_node->customer_number = customer_number;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
};

void add_customer(Node **root, int customer_number, char name[])
{
    Node *new_node = create_customer(customer_number, name); // erstmal einen knoten erstellen



    if (*root == NULL) // wenn die liste leer ist ist root unser neuer kopf
    {
        *root = new_node;
        return;
    }
    // wenn nicht NULL dann muss der knoten an die richtige stelle
    else
    {
        Node *temp_root = *root;
// ende suchen 
        while (temp_root->next != NULL && temp_root->next->customer_number < customer_number)// 
        {
            temp_root = temp_root->next;
        }
        new_node->next = temp_root->next;// zuerst new node ändern bevor temp  sonst fehler !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        temp_root->next = new_node;
    }
};

void print_list(Node *root)
{
    Node *temp_root = root;
    while (temp_root != NULL)
    {
        printf("%d: %s\n", temp_root->customer_number, temp_root->name);
        temp_root = temp_root->next;
    }
};

int count_customers(Node *root)
{
 int count = 0;
    while (root != NULL) {
        count++;
        root = root->next;
    }
    return count;
};
void clear_list(Node **root)
{

    Node *temp_root = *root;
    Node *next = NULL;

    while (temp_root != NULL)
    {
        next = temp_root->next;
        free(temp_root);
        temp_root = next;
    }

    //IMMER WENN LEERE LISTE ROOT NULL HOHLKOPF
    *root = NULL;
};