#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    char name[50];
    int priority;
    struct Node *next;
} Node;
typedef Node *ptr_node;
ptr_node create(char name[], int priority)
{
    ptr_node new_node = (ptr_node)malloc(sizeof(Node));
    // man könnte mit assert das ganze programm abbrechen lassen
    if (new_node == NULL)
    {
        printf("Fehler in der Speicherzuweising\n");
        return NULL;
    }
    new_node->priority = priority;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
};
ptr_node add_new(ptr_node head,  int prioty,char name[])
{

    ptr_node new_node = create(name, prioty);
    if (new_node == NULL)
    {
        return head;
    }
    if (head == NULL || prioty <= head->priority) // leere liste oder neues erstes element
    {
        new_node->next = head;
        head = new_node;
        return head; //
    }
    ptr_node current = head;
    
    while (current->next != NULL)
    {
        if (current->next->priority >= prioty)
        {
            new_node->next = current->next;
            current->next = new_node;
            return head;
        }
        // sonst weiter
        current = current->next;
    }
    // wenn nichts findet dann am edne der liste
    current->next = new_node;
    return head;
};
ptr_node delete_priority(ptr_node head, int priority)
{
    if (head == NULL)
    {
        printf("Liste ist Leer\n");
        return head;
    }

    while (head != NULL && head->priority == priority) // falls es mehrere mit höchster prio gibt
    {
        ptr_node temp = head;
        head = head->next;
        printf("Knoten mit Prio %d und Name: %s gelöscht \n", temp->priority, temp->name);
        free(temp);
    }

    if (head == NULL)
    {
        printf("Liste wurde vollständig gelöscht!\n");
        return head;
    }
    bool flag = false;
    ptr_node current = head;

    while (current->next != NULL)
    {
        if (current->next->priority == priority)
        {
            ptr_node temp = current->next;
            current->next = current->next->next;
            printf("Knoten mit Prio %d und Name: %s gelöscht \n", temp->priority, temp->name);
            free(temp);
            flag = true;
            continue;
        }
        else
        {
            // damit bei löschung keine knoten übersprungen werden nur bei nicht löschung current akutalisieren
            current = current->next;
        }
    }if (!flag){
        printf("Keinwn knoten bro\n");
    }
    
    
    return head;
};
void display(ptr_node head)
{

    if (head == NULL)
    {
        printf("Leere Liste\n");
        return; // gleich beenden um laufzeit zu sparen
    }
    ptr_node current = head;
    while (current != NULL)
    {
        printf("Dein Knoten mit prio:%d hat den Namen %s\n", current->priority, current->name);
        current = current->next;
    }
};
ptr_node clear(ptr_node head)
{

    if (head == NULL)
    {
        printf("Liste bereits leer\n");
        return head;
    }
    ptr_node current = head;
    while (current != NULL)
    {
        ptr_node temp = current;

        current = current->next;
        free(temp);

        /* code */
    }
    head = NULL;
    return head;
};

int main()
{

    ptr_node head = NULL;
    head = add_new(head, 4, "Adam");
    head = add_new(head, 4, "Adam_prio ");
    head = add_new(head, 2, "nabiil ");

    display(head);
    head = delete_priority(head, 3);
    head = delete_priority(head, 4);
    head = delete_priority(head, 4);
    display(head);
    head=clear(head);
}