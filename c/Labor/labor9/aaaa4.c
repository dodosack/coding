#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct numberItem {
    int data;
    struct numberItem *next_element;
} numberItem;

void append(numberItem **root, int data);
void print(numberItem *root);
void clear(numberItem **root);


void append(numberItem **root, int data) {
    // Lokalisieren des letzten Elements
    while ((*root)->next_element != NULL) {
        *root = (*root)->next_element;
    }

    // Speicher für neues Element allokieren
    numberItem *new_array = (numberItem *)malloc(sizeof(numberItem));
    if (new_array == NULL) {
        printf("Fehler: Speicher konnte nicht allokiert werden.\n");
        exit(1);
    }

    // Neues Element initialisieren
    new_array->data = data;
    new_array->next_element = NULL;

    // Neues Element anhängen
    (*root)->next_element = new_array;
}

void print(numberItem *root) {
    while (root != NULL) { // Traversiere die Liste vollständig
        printf("%d\n", root->data);
        root = root->next_element;
    }
}

void clear(numberItem **root) {
    numberItem *current = *root;
    numberItem *next;

    while (current != NULL) {
        next = current->next_element; // Nächsten Knoten zwischenspeichern
        free(current);                // Speicher freigeben
        current = next;               // Zum nächsten Knoten wechseln
    }

    *root = NULL; // Kopf der Liste zurücksetzen
}
