#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{ // knoten mit typedef Node aufrufbar
    int data;
    int priority;
    struct Node *next;
} Node;
Node *create(int data, int priority)
{
    Node *new_node = (Node *)malloc(sizeof(Node)); // speicher reservieren
    if (new_node == NULL)
    {
        printf("Fehler in der speichereservierung\n"); // fehler ausgeben bei fehlgeschkagener speicherallokierung
        return NULL;
    }
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    // werte zuweisen
    return new_node;
};
void add(Node **head, int data, int priority)
{

    Node *new_node = create(data, priority);
    if (new_node == NULL)
    {
        return; // keine weitere ausgabe nötig da bereit in create fehlerausgabe
    }

    else if (*head == NULL || (*head)->priority >= priority) // leere liste oder  ertes elemetn
    {
        new_node->next = *head;
        *head = new_node; // erstes neues element

        return;
    }
    // mitte oder ende anhängen
    Node *current = *head;
    while (current->next != NULL)
    {
        if (current->next->priority >= priority) // gefundene stelle// zwischen 2 stellen einfügen
        {
            new_node->next = current->next;
            current->next = new_node; // knoten einfügen wichtig das current next nach nnewnode next veränderet wird
            return;                   // kann abbrechen und somit laufzeit sparen
        }

        current = current->next; // sonst
    }
    // wenn liste leer ist dann am emde einfügen
    current->next = new_node;
    return;
};
void deleteby_data(Node **head, int data)
{
    if (*head == NULL) // Leere Liste
    {
        printf("Liste ist leer\n");
        return;
    }

    // Kopf löschen, falls er den Wert hat
    if ((*head)->data == data)
    {
        Node *temp = (*head)->next;
        free(*head);
        *head = temp;
        printf("Knoten mit Wert %d gelöscht.\n", data);
        return;
    }

    // Mitte oder Ende löschen
    Node *current = *head;
    while (current->next != NULL)
    {
        if (current->next->data == data) // Gefundener Löschfall
        {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("Knoten mit Wert %d gelöscht.\n", data);
            return; // Element gefunden und gelöscht, Schleife kann beendet werden
        }
        current = current->next; // Weiter zum nächsten Knoten
    }

    // Kein Element gefunden
    printf("Kein Element mit Wert %d gefunden.\n", data);
}

void delete_by_priority(Node **head, int priority)
{
    if (*head == NULL) // Leere Liste
    {
        printf("Liste ist leer\n");
        return;
    }

    // Kopf löschen, wenn er die Priorität hat
    while (*head != NULL && (*head)->priority == priority) // wichtig überprüfen ob leer ist
    {
        Node *temp = *head;
        *head = (*head)->next; // Neuer Kopf
        free(temp);
    }

    // Wenn Liste komplett geleert wurde
    if (*head == NULL)
    {
        printf("Alle Knoten mit Priorität %d wurden gelöscht.\n", priority);
        return;
    }

    // Mitte oder Ende löschen
    Node *current = *head;
    while (current->next != NULL)
    {
        if (current->next->priority == priority) // Gefundener Löschfall
        {
            Node *temp = current->next;
            current->next = current->next->next;
            free(temp);
            printf("Knoten mit Priorität %d gelöscht.\n", priority);
            // Kein `current = current->next;` hier, da wir den neuen `current->next` prüfen
        }
        else
        {
            current = current->next; // Weiter, falls nichts gelöscht wurde
        }
    }
}

void clear(Node **head)
{

    if (*head == NULL)
    {
        printf("Liste bereits gelöscht\n");
        return; // gleich abbrechen um laufzeit zu speichern
    }

    Node *current = *head;
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("Liste erfolgreich gelöscht\n");
};
void display(Node *head)
{

    if (head == NULL)
    {
        printf("Liste ist leer\n");
        return;
    }
    printf("ANFANG\n");
    Node *current = head;
    while (current != NULL)
    {
        printf("Prio %d mit datensatz: %d", current->priority, current->data);
        current = current->next;
    }
    printf("ENDE\n");
};
void search(Node *head, int data)
{

    if (head == NULL)
    {
        printf("Fehler, Liste ist leer\n");
        return;
    }

    Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
        {
            printf("Dein %d existiert und hat die prio %d\n", data, current->priority);
            return;
        }

        current = current->next; // falls es noch weitere gibt damit nicht
    }
    printf("Kein Element mit data : %d gefunden \n", data);
};
void reverse_display(Node *head)
{
    if (head == NULL)
    {
        return; // Basisfall: Liste ist leer oder Ende erreicht
    }

    reverse_display(head->next);                                       // Rekursiver Aufruf zum nächsten Knoten
    printf("Prio %d mit Datensatz: %d\n", head->priority, head->data); // Ausgabe bei Rückkehr
}

int main()
{

    Node *head = NULL; // leere liste erstellt

    add(&head, 1020, 2);
    if (head == NULL)
    {
        printf("Fehler beim aktualisieren von head");
        return 1;
    }
    delete_by_priority(&head, 999); // Priorität nicht vorhanden
    deleteby_data(&head, 42);       // Wert nicht vorhanden
    clear(&head);                   // Liste leeren
    display(head);                  // Leere Liste anzeigen
    search(head, 100);              // Suche in leerer Liste

    add(&head, 10, 1);

    add(&head, 139, 1);
    add(&head, 100, 3);
    add(&head, 102848, 6);
    printf("Liste umgekehrt angezeigt:\n");
    reverse_display(head);

    display(head);
    deleteby_data(&head, 102848);
    delete_by_priority(&head, 1);

    display(head);
    search(head, 100);
    search(head, 10);
    clear(&head);
    return 0;
}
