#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node
{

    int prime_number;
    struct Node *next;
} Node;

bool is_prime(int zahl);
void add_new_Node(Node **head, int zahl);
Node *create_new_node(int prime_number);
void clear(Node **head);
void display(Node *head, int eingabe);
int sum_list(Node *head);

int main()
{

    int eingabe;
    printf("Bitte geben sie eine Zahl ein\n");
    scanf("%d", &eingabe);

    Node *head = NULL; // leere liste erstellen
    for (int i = 0; i <= eingabe; i++)
    {
        if (is_prime(i))
        {
            add_new_Node(&head, i); // adresse von head nicht normale head wegen  des doppelpointers
        }
    }
    display(head, eingabe);
    clear(&head);// wichitg doppelpointer 
}

bool is_prime(int zahl)
{

    if (zahl <= 1)
    {
        return false;
    }

    int teiler = (int)sqrt(zahl);

    for (int i = 2; i <= teiler; i++) // muss 2 1 wäre falsch
    {
        if ( zahl % i == 0)
        {
            
        return false;
        }
        
    }
    return true;
};
Node *create_new_node(int prime_number)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf(" Fehler in der speicher zuweisung in der create func!!\n");
        return NULL;
    }
    new_node->prime_number = prime_number;
    new_node->next = NULL;
    return new_node;
};

void add_new_Node(Node **head, int zahl)
{
    Node *new_node = create_new_node(zahl);
    if (new_node == NULL)
    {
        return;
    }

    if (*head == NULL) // leere lsite
    {
        *head = new_node;
    }
    else
    { // sonst ans ende der liste
        Node *current = *head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = new_node;
    }
};
void clear(Node **head)
{
    if (*head == NULL)
    {
        printf("Liste bereits leer\n");
        return;
        /* code */
    }
    else
    {
        Node *current = *head;
        Node *temp = NULL;

        while (current != NULL)
        {
            temp = current->next;
            free(current);

            current = temp;
        }
        *head = NULL; // wichtig immer am ende nicht vergessen
    }
};
void display(Node *head, int eingabe)
{
    if (head == NULL)
    {
        printf("\nKeine Primzahlen bis %d!", eingabe);
        return; // entweder return oder else !!!!! sonst stecktst du fest
    }
    else
    {
        Node *current = head;
        printf("Primzahlen bis %d\n", eingabe);
        while (current != NULL)
        {
            printf("%d\t", current->prime_number);
            current = current->next;
        }

        printf("\nSumme der Primzahlen: %d\n", sum_list(head));
    }
};
int sum_list(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int sum = 0;
        Node *current = head;
        while (current != NULL)
        {
            sum += current->prime_number;
            current = current->next;
        }

        return sum;
    }
};